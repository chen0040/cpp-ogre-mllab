package ann.mlp.application.regression;

import ml.lang.SampleSet;
import ml.lang.FeatureVector;
import ann.mlp.*;
import visualizer.simpleui.SimpleUI;
import ml.lang.functions.FunctionX;
import ml.lang.functions.BiPolarLogSig;
import java.awt.Color;

class ModelFunc implements FunctionX
{
	public double calculate(double x)
	{
		double y=0;
		y=0.05*x*x*x-0.2*x*x-3*x+20;
		
		return y;
	}
}

public class LinearRegression {
	
	
	public static void main(String[] args)
	{
		MLPNet net=new MLPNet();
		
		net.create_layer(1);
		net.create_layer(5);
		net.create_layer(5);
		net.create_layer(1, new BiPolarLogSig());
		
		ModelFunc func=new ModelFunc();
		
		double minX=-15;
		double maxX=15;
		double minY=func.calculate(minX);
		double maxY=func.calculate(maxX);
		
		SampleSet trainset=new SampleSet(1, 1);
		SampleSet testset=new SampleSet(1, 1);
		
		for(double x=minX; x<maxX; x+=0.2)
		{
			double nx=(x-minX) / (maxX-minX);
			double y=func.calculate(x);
			double ny=(y-minY) / (maxY-minY);
			trainset.addSample(new FeatureVector(nx), new FeatureVector(ny));
		}
		
		for(double x=minX; x<=maxX; x+=0.3)
		{
			double nx=(x-minX) / (maxX-minX); //normalize x to be in the range of [0, 1]
			double y=func.calculate(x);
			double ny=(y-minY) / (maxY-minY); //normalize y to be in the range of [0, 1]
			
			testset.addSample(new FeatureVector(nx), new FeatureVector(ny));
		}
		
		MLPTrainParam params=new MLPTrainParam();
		params.max_epoches=2000;
		params.max_stagnation_epoches=2000;
		params.training_epoches=1;
		params.min_test_error=0.01;
		net.train(trainset, testset, params);
		
		System.out.println("final test error: "+net.test(testset));
		
		SimpleUI.instance().plotFunc(minX, maxX, 0.1, func, Color.blue, "Demo");
		
		for(double x=-15; x<=15; x+=3)
		{
			double nx=(x-minX) / (maxX-minX);
			FeatureVector input=new FeatureVector(nx);
			FeatureVector output=new FeatureVector(0);
			net.predict(input, output);
			
			double ny=output.get(0);
			double y=(maxY-minY) * ny + minY;
			
			System.out.println("input: "+(x)+" output:"+(y));
			
			SimpleUI.instance().plotPoint(x, y, Color.red, "Demo");
		}
	}
}


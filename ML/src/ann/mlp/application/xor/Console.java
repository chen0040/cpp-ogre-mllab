package ann.mlp.application.xor;

import ann.mlp.MLPNet;
import ann.mlp.MLPTrainParam;
import ml.lang.FeatureVector;
import ml.lang.SampleSet;

public class Console {
	public static void main(String[] args)
	{
		SampleSet ss=new SampleSet(2, 1);
		
		//the sample set consist input-output pair of a xor gate
		ss.addSample(new FeatureVector(new int[]{0, 0}), new FeatureVector(0));
		ss.addSample(new FeatureVector(new int[]{0, 1}), new FeatureVector(1));
		ss.addSample(new FeatureVector(new int[]{1, 0}), new FeatureVector(1));
		ss.addSample(new FeatureVector(new int[]{1, 1}), new FeatureVector(0));
		
		MLPNet net=new MLPNet();
		net.create_layer(2);
		net.create_layer(5);
		net.create_layer(5);
		net.create_layer(1);
		
		MLPTrainParam params=new MLPTrainParam();
		params.max_epoches=20000;
		params.max_stagnation_epoches=10000;
		params.training_epoches=10;
		params.min_test_error=0.01;
		net.train(ss, ss, params);
		
		System.out.println("final error: "+net.test(ss));
		
		FeatureVector output=new FeatureVector(1, 0, 1);
		for(int i=0; i<ss.size(); i++)
		{
			net.predict(ss.getSample(i), output);
			
			System.out.println(ss.getSample(i).get(0)+" (xor) "+ss.getSample(i).get(1)+": "+output.get(0)+"("+ss.getSampleTarget(i).get(0)+")");
		}
	}
}	



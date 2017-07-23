package ann.mlp;

import ann.mlp.MLPNet;
import ann.mlp.MLPTrainParam;
import ml.lang.FeatureVector;
import ml.lang.SampleSet;

public class Console {
	public static void main(String[] args)
	{
		int InputDimension=13;
		int OutputDimension=5;
		SampleSet ss=new SampleSet(InputDimension, OutputDimension);
		
		//the sample set consist input-output pair of a xor gate
		\begin{repeat}[\param{TrainingSampleCount}]
		ss.addSample(new FeatureVector(new int[]{\array[discrete][13]{0,1}}), new FeatureVector(new int[]{\array[discrete][5]{0,1}}));
		\end{repeat}
		
		MLPNet net=new MLPNet();
		net.set_learning_rate(\param{LearningRate});
		net.create_layer(InputDimension);
		\begin{template}[HiddenLayers]
		net.create_layer(\param{LayerNeuronCount});
		\end{template}
		net.create_layer(OutputDimension);
		
		
		MLPTrainParam params=new MLPTrainParam();
		params.max_epoches=\param{MaxEpoches};
		params.max_stagnation_epoches=10000;
		params.training_epoches=10;
		params.min_test_error=\param{MinErrorThreshold};
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



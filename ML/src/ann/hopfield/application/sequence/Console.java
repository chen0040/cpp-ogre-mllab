package ann.hopfield.application.sequence;

import ann.hopfield.HopfieldNet;
import ml.lang.BinaryFeatureVector;

public class Console {
	public static void main(String[] args)
	{
		//Xianshun says:
		//remember that Hopfield can only store 0.14N patterns if N is large, where N is the input dimension
		HopfieldNet hf=new HopfieldNet(6);
		
		hf.initialize();
		
		//first pattern to memorize is 0101
		BinaryFeatureVector pattern=new BinaryFeatureVector(new int[]{1, 0, 1, 0, 1, 0});
		hf.train(pattern);
		print_pattern(pattern, "trained pattern");
		
		//second pattern to memorize is 1001
		pattern=new BinaryFeatureVector(new int[]{0, 1, 0, 0, 1, 0});
		hf.train(pattern);
		print_pattern(pattern, "trained pattern");
		
		//third pattern to memorize is 1001
		pattern=new BinaryFeatureVector(new int[]{1, 1, 0, 0, 0, 1});
		hf.train(pattern);
		print_pattern(pattern, "trained pattern");
		
		//fourth pattern to memorize is 1001
		pattern=new BinaryFeatureVector(new int[]{1, 0, 1, 1, 0, 0});
		hf.train(pattern);
		print_pattern(pattern, "trained pattern");
		
		System.out.println("");
		
		//first corrupted pattern 
		pattern=new BinaryFeatureVector(new int[]{1, 0, 1, 0, 1, 0});
		print_pattern(pattern, "corrupted input");
		hf.predict(pattern);
		print_pattern(pattern, "retrieved output");
		
		System.out.println("");
		
		//second corrupt pattern
		pattern=new BinaryFeatureVector(new int[]{1, 1, 0, 0, 1, 0});
		print_pattern(pattern, "corrupted input");
		hf.predict(pattern);
		print_pattern(pattern, "retrieved output");
	}
	
	public static void print_pattern(BinaryFeatureVector pattern, String caption)
	{
		System.out.println(caption+": "+pattern.toString());
	}
	
	
}



package ann.hopfield.application.image;

import ann.hopfield.HopfieldNet;
import visualizer.simpleui.SimpleUI;

public class ImageRetreival {
	public static void main(String[] args)
	{
		BinaryImage img=new BinaryImage("A.bmp");
		
		HopfieldNet hf=new HopfieldNet(img.size());
		hf.initialize();
		
		hf.train(img);
		
		img=new BinaryImage("B.bmp");
		hf.train(img);
		
		img=new BinaryImage("C.bmp");
		hf.train(img);

		
		img=new BinaryImage("A.bmp");
		img.mutate(0.1);
		
		img.save("A1.bmp");
		
		hf.predict(img);
		
		img.save("A2.bmp");
		
		SimpleUI.display("A1.bmp", "A2.bmp", "Hopfield Network Image Retrieval");
	}
}

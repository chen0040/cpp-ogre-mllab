package ann.som.kohonen.application.image;

import imagex.PixelRGB;
import imagex.PixelFactory;
import imagex.PixelType;

import javax.imageio.ImageIO;

import ann.som.kohonen.SOFMNet;
import ann.som.kohonen.SOFMNeuron;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Random;
import visualizer.simpleui.SimpleUI;

public class ImageSegmentation {
	public static void main(String[] args)
	{
		int SEED=100;
		Random rand=new Random(SEED);
		
		
		BufferedImage img=null;
		try{
			img=ImageIO.read(new File("1.jpg"));
		}catch(IOException ie)
		{
			ie.printStackTrace();
		}
		
		int ROWS=5;
		int COLS=5;
		PixelType inputType=PixelType.PixelType_RGBL;
		SOFMNet net=new SOFMNet(ROWS, COLS, PixelFactory.instance().getPixelDimension(inputType));
		
		net.initialize(PixelFactory.instance().getLowerBounds(img,inputType), PixelFactory.instance().getUpperBounds(img, inputType));
		
		for(int r=0; r<ROWS; ++r)
		{
			for(int c=0; c<COLS; ++c)
			{				
				net.get_neuron(r, c).set_output(new PixelRGB(rand.nextInt(255), rand.nextInt(255), rand.nextInt(255)));
			}
		}
		
		for(int i=0; i < 3000; i++)
		{
			int x1=rand.nextInt(img.getWidth());
			int y1=rand.nextInt(img.getHeight());
			PixelRGB pixel=PixelFactory.instance().getPixel(img, x1, y1, inputType);
		    net.train(pixel);
		}
		
		BufferedImage class_img=new BufferedImage(img.getWidth(), img.getHeight(), img.getType());
		for(int x=0; x<img.getWidth(); x++)
		{
			for(int y=0; y<img.getHeight(); y++)
			{
				int rgb=img.getRGB(x, y);
				int alpha = ((rgb >> 24) & 0xff); 
			    
				PixelRGB pixel=PixelFactory.instance().getPixel(img, x, y, inputType);
			    SOFMNeuron winner=net.predict(pixel);
			    PixelRGB output=(PixelRGB)(winner.get_output());
			    
			    int r=output.get_r();
			    int g=output.get_g();
			    int b=output.get_b();
				
			    rgb = (alpha << 24) | (r << 16) | (g << 8) | b; 
			    class_img.setRGB(x, y, rgb);
			}
		}
		try{
			File ofile=new File("1_class.jpg");
			ImageIO.write(class_img, "jpg", ofile);
		}catch(IOException ie)
		{
			ie.printStackTrace();
		}
		
		SimpleUI.display(img, class_img, "SOM Image Segmentation");
	
	}
}

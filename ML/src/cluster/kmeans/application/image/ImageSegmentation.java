package cluster.kmeans.application.image;

import javax.imageio.ImageIO;

import cluster.kmeans.KCluster;
import cluster.kmeans.KMeans;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Random;
import visualizer.simpleui.SimpleUI;
import imagex.PixelFactory;
import imagex.PixelType;
import imagex.PixelRGB;

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
		
		PixelType inputType=PixelType.PixelType_RGB;
		
		KMeans km=new KMeans();
		for(int y=0; y<img.getHeight(); ++y)
		{
			for(int x=0; x<img.getWidth(); ++x)
			{			    
				PixelRGB color=PixelFactory.instance().getPixel(img, x, y, inputType);
				km.add_point(new KPixelRGBFacade(color, x, y));
			}
		}
		
		int cluster_count=10;
		for(int k=0; k<cluster_count; ++k)
		{
			KCluster cluster=new KCluster();
			int x=rand.nextInt(img.getWidth());
			int y=rand.nextInt(img.getHeight());
		    
		    PixelRGB color=PixelFactory.instance().getPixel(img, x, y, inputType);
			cluster.set_center(new KPixelRGBFacade(color, x, y));
			
			km.add_cluster(cluster);
		}
		
		int epoch_count=50;
		for(int epoch=0; epoch<epoch_count; epoch++)
		{
			km.cluster();
		}
		
		BufferedImage class_img=new BufferedImage(img.getWidth(), img.getHeight(), img.getType());
		//System.out.println(km.get_cluster_count());
		for(int i=0; i<km.get_cluster_count(); ++i)
		{
			KCluster cluster=km.get_cluster(i);
			//System.out.println(cluster.get_point_count());
			int r=rand.nextInt(255);
			int g=rand.nextInt(255);
			int b=rand.nextInt(255);
			for(int j=0; j<cluster.get_point_count(); ++j)
			{
				KPixelRGBFacade point=(KPixelRGBFacade)(cluster.get_point(j));
				int x=point.get_x();
				int y=point.get_y();
				
				int rgb=img.getRGB(x, y);
				int alpha = ((rgb >> 24) & 0xff); 
			
			    class_img.setRGB(x, y, PixelRGB.get_rgb(alpha, r, g, b));
			}
		}
		try{
			File ofile=new File("1_class.jpg");
			ImageIO.write(class_img, "jpg", ofile);
		}catch(IOException ie)
		{
			ie.printStackTrace();
		}
		
		SimpleUI.display(img, class_img, "KMeans Image Segmentation");
		
	
	}
}
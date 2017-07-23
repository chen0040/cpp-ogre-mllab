package imagex;

import java.awt.image.BufferedImage;
import java.io.IOException;
import java.io.File;
import javax.imageio.ImageIO;
import visualizer.simpleui.SimpleUI;

public class ImageX {
	protected static ImageX m_instance=null;
	
	private ImageX()
	{
		
	}
	
	public static ImageX instance()
	{
		if(m_instance == null)
		{
			m_instance=new ImageX();
		}
		return m_instance;
	}
	
	public static BufferedImage get_gray_image(BufferedImage source)
	{
		BufferedImage gray_image=new BufferedImage(source.getWidth(), source.getHeight(),source.getType());
		for(int x=0; x<source.getWidth(); ++x)
		{
			for(int y=0; y<source.getHeight(); ++y)
			{
				int rgb=source.getRGB(x, y);
				
				int alpha=((rgb >> 24) & 0xff);
				
				int gray=PixelRGB.get_luminance(rgb);
				int r=gray;
				int g=gray;
				int b=gray;
				
				rgb=(alpha << 24) | (r << 16) | (g << 8) | b; 
				gray_image.setRGB(x, y, rgb);
			}
		}
		
		return gray_image;
	}
	
	
	
	public static void main(String[] args)
	{
		BufferedImage source=null;
		try{
			source=ImageIO.read(new File("1.jpg"));
		}catch(IOException ie)
		{
			ie.printStackTrace();
		}
		
		BufferedImage gray_image=get_gray_image(source);
		
		SimpleUI.display(source, gray_image, "display gray image");
	}
}

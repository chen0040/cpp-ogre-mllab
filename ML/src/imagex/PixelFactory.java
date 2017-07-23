package imagex;
import java.awt.image.BufferedImage;
import java.util.Vector;

public class PixelFactory {
	private static PixelFactory m_instance=null;
	
	
	public static PixelFactory instance()
	{
		if(m_instance==null)
		{
			m_instance=new PixelFactory();
		}
		return m_instance;
	}
	
	public PixelRGB getPixel(BufferedImage img, int x, int y, PixelType type)
	{
		switch(type)
		{
		case PixelType_RGB:
			return new PixelRGB(img, x, y);
		case PixelType_RGBL:
			return new PixelRGBL(img, x, y);
		case PixelType_RGBLXY:
			return new PixelRGBLXY(img, x, y);
		default:
			return null;
		}
	}
	
	public Vector<Double> getLowerBounds(BufferedImage img, PixelType type)
	{
		int x=0;
		int y=0;
		
		switch(type)
		{
		case PixelType_RGB:
			return new PixelRGB(img, x, y).getLowerBounds();
		case PixelType_RGBL:
			return new PixelRGBL(img, x, y).getLowerBounds();
		case PixelType_RGBLXY:
			return new PixelRGBLXY(img, x, y).getLowerBounds();
		default:
			return null;
		}
	}
	
	public Vector<Double> getUpperBounds(BufferedImage img, PixelType type)
	{
		int x=0;
		int y=0;
		
		switch(type)
		{
		case PixelType_RGB:
			return new PixelRGB(img, x, y).getUpperBounds();
		case PixelType_RGBL:
			return new PixelRGBL(img, x, y).getUpperBounds();
		case PixelType_RGBLXY:
			return new PixelRGBLXY(img, x, y).getUpperBounds();
		default:
			return null;
		}
	}
	
	public int getPixelDimension(PixelType type)
	{
		switch(type)
		{
		case PixelType_RGB:
			return 3;
		case PixelType_RGBL:
			return 4;
		case PixelType_RGBLXY:
			return 6;
		default:
			return -1;
		}
	}
	
}

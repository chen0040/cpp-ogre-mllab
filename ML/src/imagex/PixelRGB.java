package imagex;

import java.util.Vector;

import ml.lang.DataPoint;
import java.awt.image.BufferedImage;

public class PixelRGB extends DataPoint{
	protected int m_r, m_b, m_g;
	
	public PixelRGB()
	{
		
	}
	
	public PixelRGB(int r, int g, int b)
	{
		m_r=r;
		m_g=g;
		m_b=b;
	}
	
	public PixelRGB(BufferedImage img, int x, int y)
	{
		int rgb=img.getRGB(x, y);
		m_r=(rgb >> 16) & 0xff;
		m_g=(rgb >> 8) & 0xff;
		m_b=rgb & 0xff;
	}
	
	public static int get_rgb(int alpha, int r, int g, int b)
	{
		return (alpha << 24) | (r << 16) | (g << 8) | b;
	}
	
	public static int get_r(int rgb)
	{
		return (rgb >> 16) & 0xff;
	}
	
	public static int get_b(int rgb)
	{
		return (rgb & 0xff);
	}
	
	public static int get_g(int rgb)
	{
		return (rgb >> 8) & 0xff;
	}
	
	public static int get_luminance(int r, int g, int b)
	{
		return (int)(r * 0.3+ g * 0.59 + b * 0.11);
	}
	
	public static int get_luminance(int rgb)
	{
		int r=((rgb >> 16) & 0xff);
		int g=((rgb >> 8) & 0xff);
		int b=(rgb & 0xff);
		
		int gray=get_luminance(r, g, b);
		
		return gray;
	}
	
	public PixelRGB(int rgb)
	{
		m_r=(rgb >> 16) & 0xff;
		m_g=(rgb >> 8) & 0xff;
		m_b=rgb & 0xff;
	}
	
	public int get_r() { return m_r; }
	public int get_b() { return m_b; }
	public int get_g() { return m_g; }
	
	public int size()
	{
		return 3;
	}
	
	public double get(int index)
	{
		switch(index)
		{
		case 0:
			return m_r;
		case 1:
			return m_g;
		case 2:
			return m_b;
		default:
			return -1;
		}
	}
	
	public void set(int index, double value)
	{
		switch(index)
		{
		case 0:
			m_r=(int)value;
		case 1:
			m_g=(int)value;
		case 2:
			m_b=(int)value;
		default:
			//do nothing
		}
	}
	
	public Vector<Double> getLowerBounds()
	{
		Vector<Double> v=new Vector<Double>();
		v.add(new Double(0));
		v.add(new Double(0));
		v.add(new Double(0));
		return v;
	}
	
	public Vector<Double> getUpperBounds()
	{
		Vector<Double> v=new Vector<Double>();
		v.add(new Double(255));
		v.add(new Double(255));
		v.add(new Double(255));
		return v;
	}
	
	public DataPoint clone()
	{
		PixelRGB pt=new PixelRGB(m_r, m_g, m_b);
		return pt;
	}
}

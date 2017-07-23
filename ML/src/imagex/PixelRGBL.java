package imagex;

import java.util.Vector;
import java.awt.image.BufferedImage;
import ml.lang.DataPoint;

public class PixelRGBL extends PixelRGB{
	protected int m_l;
	
	public PixelRGBL(BufferedImage img, int x, int y)
	{
		super(img, x, y);
		int rgb=img.getRGB(x, y);
		m_l=get_luminance(rgb);
	}
	
	public PixelRGBL(int r, int g, int b, int l)
	{
		super(r, g, b);
		m_l=l;
	}
	
	public PixelRGBL(int r, int g, int b)
	{
		super(r, g, b);
		m_l=get_luminance(r, g, b);
	}
	
	public PixelRGBL(int rgb)
	{
		super(rgb);
		m_l=get_luminance(rgb);
	}
	
	public int size()
	{
		return super.size()+1;
	}
	
	public Vector<Double> getLowerBounds()
	{
		Vector<Double> v=super.getLowerBounds();
		v.add(new Double(0));
		return v;
	}
	
	public Vector<Double> getUpperBounds()
	{
		Vector<Double> v=super.getUpperBounds();
		v.add(new Double(255));
		return v;
	}
	
	public double get(int index)
	{
		if(index < super.size())
		{
			return super.get(index);
		}
		return m_l;
	}
	
	public void set(int index, double value)
	{
		if(index < super.size())
		{
			super.set(index, value);
		}
		else if(index==super.size())
		{
			m_l=(int)value;
		}
	}
	
	public DataPoint clone()
	{
		PixelRGBL pt=new PixelRGBL(m_r, m_g, m_b, m_l);
		return pt;
	}
	
	public int get_luminance()
	{
		return m_l;
	}
}

package imagex;

import java.util.Vector;
import ml.lang.DataPoint;
import java.awt.image.BufferedImage;

public class PixelRGBLXY extends PixelRGBL{
	protected int m_x;
	protected int m_y;
	protected int m_x_lower_bound=0;
	protected int m_y_lower_bound=0;
	protected int m_x_upper_bound=1000;
	protected int m_y_upper_bound=1000;
	
	public PixelRGBLXY(BufferedImage img, int x, int y)
	{
		super(img, x, y);
		m_x=x;
		m_y=y;
	}
	
	public PixelRGBLXY(int r, int g, int b, int luminance, int x, int y)
	{
		super(r, g, b, luminance);
		m_x=x;
		m_y=y;
	}
	
	public PixelRGBLXY(int r, int g, int b, int x, int y)
	{
		super(r, g, b);
		m_x=x;
		m_y=y;
	}
	
	public PixelRGBLXY(int rgb, int x, int y)
	{
		super(rgb);
		m_x=x;
		m_y=y;
	}
	
	public int size()
	{
		return super.size()+2;
	}
	
	public void setImageBounds(int x_lower, int x_upper, int y_lower, int y_upper)
	{
		m_x_lower_bound=x_lower;
		m_x_upper_bound=x_upper;
		m_y_lower_bound=y_lower;
		m_y_upper_bound=y_upper;
	}
	
	public Vector<Double> getLowerBounds()
	{
		Vector<Double> v=super.getLowerBounds();
		v.add(new Double(m_x_lower_bound));
		v.add(new Double(m_y_lower_bound));
		return v;
	}
	
	public Vector<Double> getUpperBounds()
	{
		Vector<Double> v=super.getUpperBounds();
		v.add(new Double(m_x_upper_bound));
		v.add(new Double(m_y_upper_bound));
		return v;
	}
	
	public double get(int index)
	{
		int ssize=super.size();
		if(index < ssize)
		{
			return super.get(index);
		}
		else if(index==ssize)
		{
			return m_x;
		}
		else
		{
			return m_y;
		}
	}
	
	public void set(int index, double value)
	{
		int ssize=super.size();
		if(index < ssize)
		{
			super.set(index, value);
		}
		else if(index==ssize)
		{
			m_x=(int)value;
		}
		else if(index==ssize+1)
		{
			m_y=(int)value;
		}
	}
	
	public DataPoint clone()
	{
		PixelRGBLXY pt=new PixelRGBLXY(m_r, m_g, m_b, m_l, m_x, m_y);
		return pt;
	}
	
	public int get_x() 
	{
		return m_x;
	}
	
	public int get_y()
	{
		return m_y;
	}
}

package cluster.kmeans.application.image;

import java.util.Vector;

import ml.lang.DataPoint;
import imagex.PixelRGB;

public class KPixelRGBFacade extends PixelRGB {
	protected int m_x;
	protected int m_y;
	PixelRGB m_color;
	
	KPixelRGBFacade(PixelRGB color, int x, int y)
	{
		m_color=color;
		m_x=x;
		m_y=y;
	}
	
	public final int get_x()
	{
		return m_x;
	}
	
	public final int get_y()
	{
		return m_y;
	}
	
	public int get_r()
	{
		return m_color.get_r();
	}
	
	public int get_g()
	{
		return m_color.get_g();
	}
	
	public int get_b()
	{
		return m_color.get_b();
	}
	
	public void set(int index, double value)
	{
		m_color.set(index, value);
	}
	
	public double get(int index)
	{
		return m_color.get(index);
	}
	
	public int size()
	{
		return m_color.size();
	}
	
	public double distance(DataPoint pt)
	{
		return m_color.distance(pt);
	}
	
	public DataPoint clone()
	{
		return new KPixelRGBFacade(m_color, m_x, m_y);
	}
	
	public Vector<Double> getLowerBounds()
	{
		return m_color.getLowerBounds();
	}
	
	public Vector<Double> getUpperBounds()
	{
		return m_color.getUpperBounds();
	}
}

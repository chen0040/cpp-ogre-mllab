package visualizer.simpleui;
import java.awt.Color;
import java.awt.Graphics;

public abstract class Plot2D {
	
	protected ChartX m_chart;
	protected Color m_color=Color.black;
	protected double m_minX;
	protected double m_maxX;
	protected double m_minY;
	protected double m_maxY;
	
	public Plot2D(ChartX chart, Color color)
	{
		m_color=color;
		m_chart=chart;
	}
	
	public double get_minX()
	{
		return m_minX;
	}
	
	public double get_maxX()
	{
		return m_maxX;
	}
	
	public double get_minY()
	{
		return m_minY;
	}
	
	public double get_maxY()
	{
		return m_maxY;
	}
	
	public abstract void draw(Graphics g, int minGX, int maxGX, int minGY, int maxGY);
	
	protected int projectX(double x, int minGX, int maxGX)
	{
		double minX=m_chart.get_minX();
		double maxX=m_chart.get_maxX();
		
		double dX=maxX-minX;		
		double dGX=maxGX-minGX;
	
		return (int)((x-minX) * dGX / dX+minGX);		
	}
	
	protected int projectY(double y, int minGY, int maxGY)
	{
		double minY=m_chart.get_minY();
		double maxY=m_chart.get_maxY();
		
		double dY=maxY-minY;		
		double dGY=maxGY-minGY;
		
		return (int)(dGY-(y-minY) * dGY / dY+minGY);
	}
}

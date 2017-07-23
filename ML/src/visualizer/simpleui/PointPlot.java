package visualizer.simpleui;

import java.awt.Color;
import java.awt.Graphics;

public class PointPlot extends Plot2D {
	protected double m_x;
	protected double m_y;
	protected boolean m_first;
	
	public PointPlot(double x, double y, ChartX chart, Color color)
	{
		super(chart, color);
		m_maxX=m_minX=m_x=x;
		m_maxY=m_minY=m_y=y;
	}
	
	public void draw(Graphics g, int minGX, int maxGX, int minGY, int maxGY)
	{
		g.setColor(m_color);
		
		int GX=projectX(m_x, minGX, maxGX);
		int GY=projectY(m_y, minGY, maxGY);
		g.fillOval(GX-5, GY-5, 10, 10);
	}
	
	

}

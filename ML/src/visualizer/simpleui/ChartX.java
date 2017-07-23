package visualizer.simpleui;

import java.awt.Graphics;
import java.util.Vector;
import java.awt.Color;

public class ChartX {
	protected Vector<Plot2D> m_plots=new Vector<Plot2D>();
	protected double m_minX=Double.MAX_VALUE;
	protected double m_maxX=Double.NEGATIVE_INFINITY;
	protected double m_minY=Double.MAX_VALUE;
	protected double m_maxY=Double.NEGATIVE_INFINITY;	
	protected int m_majorXTickCount=4;
	protected int m_majorYTickCount=4;
	
	public ChartX()
	{
		
	}
	
	public void setMajorXTickCount(int tickCount)
	{
		m_majorXTickCount=tickCount;
	}
	
	public void setMajorYTickCount(int tickCount)
	{
		m_majorYTickCount=tickCount;
	}
	
	public void paint(Graphics g, int minGX, int maxGX, int minGY, int maxGY)
	{
		
		for(int i=0; i<m_plots.size(); i++)
		{
			m_plots.get(i).draw(g, minGX, maxGX, minGY, maxGY);
		}
		
		drawFrame(g, minGX, maxGX, minGY, maxGY);
	}
	
	protected void drawFrame(Graphics g, int minGX, int maxGX, int minGY, int maxGY)
	{
		g.setColor(Color.black);
		g.draw3DRect(minGX, minGY, maxGX-minGX, maxGY-minGY, false);
		
		int yOffset=g.getFontMetrics().getHeight()/2;
		
		int majorTickXInterval=(maxGX-minGX) / m_majorXTickCount;
		double XInterval=(get_maxX()-get_minX()) / m_majorXTickCount;
		for(int i=1; i<m_majorXTickCount; ++i)
		{
			int GX=i*majorTickXInterval+minGX;
			double x=XInterval * (m_majorXTickCount-i) + get_minX();
			g.drawLine(GX, maxGY-5, GX, maxGY+5);
			g.drawString(""+x, GX, maxGY-yOffset);
		}
		
		int majorTickYInterval=(maxGY-minGY) / m_majorYTickCount;
		double YInterval=(get_maxY()-get_minY()) / m_majorYTickCount;
		for(int i=1; i<m_majorYTickCount; ++i)
		{
			int GY=i*majorTickYInterval+minGY;
			double y=YInterval * (m_majorYTickCount-i) + get_minY();
			g.drawLine(minGX-5, GY, minGX+5, GY);
			g.drawString(""+y, minGX+5, GY+yOffset);
		}
		
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
	
	protected void computeBounds(Plot2D plot)
	{
		if(m_minX > plot.get_minX()) m_minX=plot.get_minX();
		if(m_maxX < plot.get_maxX()) m_maxX=plot.get_maxX();
		if(m_minY > plot.get_minY()) m_minY=plot.get_minY();
		if(m_maxY < plot.get_maxY()) m_maxY=plot.get_maxY();
	}
	
	public void addPlot(Plot2D plot)
	{
		computeBounds(plot);
		m_plots.add(plot);
	}
}

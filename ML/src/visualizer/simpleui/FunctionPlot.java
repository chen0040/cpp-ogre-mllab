package visualizer.simpleui;

import java.awt.Color;
import java.awt.Graphics;

import ml.lang.functions.FunctionX;

public class FunctionPlot extends Plot2D{
	protected FunctionX m_func;
	
	protected double m_dx;
	protected double m_x;
	
	public FunctionPlot(double min, double max, double dx, FunctionX func, ChartX chart, Color color)
	{
		super(chart, color);
		
		m_minX=min;
		m_maxX=max;
		m_dx=dx;
		m_func=func;
		
		double y=0;
		m_minY=Double.MAX_VALUE;
		m_maxY=Double.NEGATIVE_INFINITY;
		for(double x=m_minX; x<=m_maxX; x+=m_dx)
		{
			y=m_func.calculate(x);
			if(m_minY > y)
			{
				m_minY=y;
			}
			if(m_maxY < y)
			{
				m_maxY=y;
			}
		}
	}
	
	public void draw(Graphics g, int minGX, int maxGX, int minGY, int maxGY)
	{
		g.setColor(m_color);
		
		double y=0;
		int pGx=0;
		int pGy=0;
		int Gx=0;
		int Gy=0;
		boolean first_point=true;
		for(double x=m_minX; x<=m_maxX; x+=m_dx)
		{
			y=m_func.calculate(x);
			Gx=projectX(x, minGX, maxGX);
			Gy=projectY(y, minGY, maxGY);
			
			if(first_point)
			{
				first_point=false;
			}
			else
			{
				g.drawLine(pGx, pGy, Gx, Gy);
			}
			pGx=Gx;
			pGy=Gy;
		}
	}
}

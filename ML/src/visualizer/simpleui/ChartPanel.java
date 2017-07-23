package visualizer.simpleui;

import javax.swing.JPanel;
import java.awt.Graphics;

import ml.lang.functions.FunctionX;

import java.util.Vector;
import java.awt.Color;

public class ChartPanel extends JPanel{
	/**
	 * 
	 */
	private static final long serialVersionUID = 7607461543445903378L;
	protected Vector<Plot2D> m_plots=new Vector<Plot2D>();	
	protected ChartX m_chart=new ChartX();
	
	public ChartPanel()
	{
		
	}
	
	public void paint(Graphics g)
	{
		m_chart.paint(g, 10, this.getWidth()-10, 10, this.getHeight()-10);
	}
	
	public void addFuncPlot(double min, double max, double dx, FunctionX func, Color color)
	{
		Plot2D plot=new FunctionPlot(min, max, dx, func, m_chart, color);
		m_chart.addPlot(plot);
	}
	
	public void addPointPlot(double x, double y, Color color)
	{
		Plot2D plot=new PointPlot(x, y, m_chart, color);
		m_chart.addPlot(plot);
	}
}

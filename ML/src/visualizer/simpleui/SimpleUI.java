package visualizer.simpleui;

import java.awt.image.BufferedImage;
import java.awt.Color;
import java.io.IOException;
import java.io.File;
import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import java.util.HashMap;

import ml.lang.functions.FunctionX;


public class SimpleUI {
	protected static SimpleUI m_instance=null;
	protected HashMap<String, JFrame> m_figures=new HashMap<String, JFrame>();
	
	private SimpleUI()
	{
		
	}
	
	public static SimpleUI instance()
	{
		if(m_instance==null)
		{
			m_instance=new SimpleUI();
		}
		return m_instance;
	}
	
	public static void display(JPanel canvas)
	{
		display(canvas, 500, 400);
	}
	
	public static void display(JPanel canvas, int width, int height)
	{
		JFrame frame=new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setBounds(10, 10, width, height);
		frame.setContentPane(canvas);
		frame.setVisible(true);
	}
	
	public void plotFunc(double min, double max, double dx, FunctionX func, Color color, String figure)
	{
		JFrame frame=null;
		ChartPanel pn=null;
		if(m_figures.containsKey(figure))
		{
			frame=m_figures.get(figure);
			pn=(ChartPanel)(frame.getContentPane());
		}
		else
		{
			frame=new JFrame(figure);
			frame.setBounds(10, 10, 500, 400);
			pn=new ChartPanel();
			frame.setContentPane(pn);
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			m_figures.put(figure, frame);
		}
		
		pn.addFuncPlot(min, max, dx, func, color);
		
		if(frame.isVisible())
		{
			frame.invalidate();
		}
		else
		{
			frame.setVisible(true);
		}
	}
	
	public void plotPoint(double x, double y, Color color, String figure)
	{
		JFrame frame=null;
		ChartPanel pn=null;
		if(m_figures.containsKey(figure))
		{
			frame=m_figures.get(figure);
			pn=(ChartPanel)(frame.getContentPane());
		}
		else
		{
			frame=new JFrame(figure);
			frame.setBounds(10, 10, 500, 400);
			pn=new ChartPanel();
			frame.setContentPane(pn);
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			m_figures.put(figure, frame);
		}
		
		pn.addPointPlot(x, y, color);
		
		if(frame.isVisible())
		{
			frame.invalidate();
		}
		else
		{
			frame.setVisible(true);
		}
	}
	
	public static void display(BufferedImage source, BufferedImage result, String title)
	{
		JFrame frame=new JFrame(title);
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel=new JPanel();
		panel.add(new JLabel(new ImageIcon(source)));
		panel.add(new JLabel(new ImageIcon(result)));
		
		frame.setContentPane(panel);
		
		
		frame.pack();
		frame.setVisible(true);
	}
	
	public static void display(String source_file, String result_file, String title)
	{
		BufferedImage source=null;
		BufferedImage result=null;
		try{
			source=ImageIO.read(new File(source_file));
			result=ImageIO.read(new File(result_file));
		}catch(IOException ie)
		{
			ie.printStackTrace();
		}
		display(source, result, title);
	}
}



package fuzzylogic.gui;

//import javax.swing.JFrame;
import javax.swing.JPanel;
import fuzzylogic.FuzzySet;
import java.awt.Graphics;

public class FuzzySetCanvas extends JPanel {
	/**
	 * 
	 */
	private static final long serialVersionUID = -3466408925740484510L;
	FuzzySet m_fset;
	
	public FuzzySetCanvas(String title, FuzzySet fset)
	{
		m_fset=fset;
	}
	
	public void paint(Graphics g)
	{
		m_fset.paint(g, 20, this.getWidth()-20, 20, this.getHeight()-20);
	}
}

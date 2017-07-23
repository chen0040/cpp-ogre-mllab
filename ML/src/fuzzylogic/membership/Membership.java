package fuzzylogic.membership;

import java.awt.Color;

public abstract class Membership {
	protected Color m_color;
	public Membership(Color c)
	{
		m_color=c;
	}
	
	public Color getColor()
	{
		return m_color;
	}
	
	public abstract double degree(double x);
}

package fuzzylogic.membership;

import java.awt.Color;

public class FuzzyReverseGrade extends Membership {
	public double m_x0;
	public double m_x1;
	public Color m_color=Color.red;
	
	public FuzzyReverseGrade(double x0, double x1)
	{
		super(Color.red);
		m_x0=x0;
		m_x1=x1;
	}
	
	public FuzzyReverseGrade(double x0, double x1, Color c)
	{
		super(c);
		m_x0=x0;
		m_x1=x1;
	}
	
	public double degree(double x)
	{
		if(x <= m_x0)
		{
			return 1;
		}
		else if(x < m_x1)
		{
			return (m_x1-x)/(m_x1-m_x0);
		}
		else
		{
			return 0;
		}
	}
}

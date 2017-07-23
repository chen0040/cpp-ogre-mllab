package fuzzylogic;

import java.util.HashMap;
import java.awt.Color;
import java.awt.Graphics;
import java.util.Iterator;
import fuzzylogic.membership.*;

import java.util.Vector;
import java.text.DecimalFormat;

public class FuzzySet {
	protected HashMap<String, Membership> m_memberships=new HashMap<String, Membership>();
	protected Vector<String> m_values=new Vector<String>();
	double m_minX=0;
	double m_maxX=1;
	double m_dX=0.0001;
	String m_name=null;
	double m_valX=0;
	
	public FuzzySet(String name, double lower_bound, double upper_bound, double dX)
	{
		m_name=name;
		m_minX=lower_bound;
		m_maxX=upper_bound;
		m_dX=dX;
	}
	
	public FuzzySet(String name, double lower_bound, double upper_bound)
	{
		m_name=name;
		m_minX=lower_bound;
		m_maxX=upper_bound;
	}
	
	public Membership getMembership(String value)
	{
		return m_memberships.get(value);
	}
	
	public int getMembershipCount()
	{
		return m_values.size();
	}
	
	public Membership getMembership(int index)
	{
		return getMembership(m_values.get(index));
	}
	
	public void setX(double value)
	{
		m_valX=value;
	}
	
	public double getX()
	{
		return m_valX;
	}
	
	public String getName()
	{
		return m_name;
	}
	
	public double getMinX()
	{
		return m_minX;
	}
	
	public double getMaxX()
	{
		return m_maxX;
	}
	
	public void addMembership(String membershipname, Membership membership)
	{
		m_values.add(membershipname);
		m_memberships.put(membershipname, membership);
	}
	
	public void paint(Graphics g, int xLower, int xUpper, int yLower, int yUpper)
	{
		int xLen=xUpper-xLower;
		int yLen=yUpper-yLower;
		g.drawRect(xLower, yLower, xLen, yLen);
		
		
		g.setColor(Color.lightGray);
		g.drawLine(xLower, yLower+20, xUpper, yLower+20);
		
		boolean first=true;
		int Gpx=0;
		int Gpy=0;
		int Gx=0;
		int Gy=0;
		Iterator<String> is=m_memberships.keySet().iterator();
		while(is.hasNext())
		{
			String kis=is.next();
			first=true;
			Membership ms=m_memberships.get(kis);
			g.setColor(ms.getColor());
			for(double x=m_minX; x<=m_maxX; x+=m_dX)
			{
				double y=ms.degree(x);

				Gx=(int)((x-m_minX) / (m_maxX - m_minX) * xLen+xLower);
				Gy=(int)((1-y)  * (yLen-20)+(yLower+20));
				if(first==true)
				{
					first=false;
				}
				else
				{
					g.drawLine(Gpx, Gpy, Gx, Gy);
				}
				
				Gpx=Gx;
				Gpy=Gy;
			}
		}
		
		g.setColor(Color.black);
		
		for(int y=0; y<=10; y+=1)
		{
			Gy=(int)((10.0-y) * 0.1  * (yLen-20)+(yLower+20));
			g.drawString(""+(y/10.0), 10, Gy);
		}
		
		double xInt=m_maxX-m_minX;
		double xD=xInt/10;
		DecimalFormat fmt=new DecimalFormat("0.00");
		for(double x=m_minX; x<=m_maxX; x+=xD)
		{
			Gx=(int)((x-m_minX) / (m_maxX - m_minX) * xLen+xLower);
			g.drawString(fmt.format(x), Gx, yUpper);
		}
	}
	
	public void fire(Vector<Rule> rules)
	{
		HashMap<String, Vector<Double>> degrees=new HashMap<String, Vector<Double>>();
		for(int i=0; i<m_values.size(); ++i)
		{
			degrees.put(m_values.get(i), new Vector<Double>());
		}
		
		for(int i=0; i<rules.size(); ++i)
		{
			Rule rule=rules.get(i);
			Clause consequent=rule.getConsequent();
			if(consequent.getVariable()==this)
			{
				double y=1;
				
				for(int j=0; j<rule.getAntecedentCount(); ++j)
				{
					Clause antecedent=rule.getAntecedent(j);
					FuzzySet variable=antecedent.getVariable();
					String value=antecedent.getValue();
					Membership ms=variable.getMembership(value);
					double degree=ms.degree(variable.getX());
					if(y > degree)
					{
						y=degree;
					}
					
				}
				degrees.get(consequent.getValue()).add(y);
			}
		}
		
		HashMap<String, Double> consequent_degrees=getRootSumSquare(degrees);
		
		m_valX=getAreaCentroid(consequent_degrees);
	}
	
	public HashMap<String, Double> getRootSumSquare(HashMap<String, Vector<Double>> degrees)
	{
		HashMap<String, Double> results=new HashMap<String, Double>();
		
		Iterator<String> valIter=degrees.keySet().iterator();
		while(valIter.hasNext())
		{
			String value=valIter.next();
			Vector<Double> de=degrees.get(value);
			double squareSum=0;
			for(int i=0; i<de.size(); ++i)
			{
				double v=de.get(i).doubleValue();
				squareSum+=v*v;
			}
			results.put(value, Math.sqrt(squareSum));
		}
		
		return results;
	}
	
	/*
	public double getFuzzyCentroid(HashMap<String, Double> degrees)
	{
		double sumxy=0;
		double sumy=0;
		for(int i=0; i<m_values.size(); i++)
		{
			String value=m_values.get(i);
			double y=degrees.get(value).doubleValue();
			double x=m_memberships.get(value).getCentroidX();
			sumxy=
			sumy+=y;
		}
	}
	*/
	
	public double getAreaCentroid(HashMap<String, Double> degrees)
	{
		double sumxy=0;
		double sumy=0;
		for(double x=m_minX; x <= m_maxX; x+=m_dX)
		{
			for(int i=0; i<m_values.size(); ++i)
			{
				Membership ms=m_memberships.get(m_values.get(i));
				double d1=degrees.get(m_values.get(i)).doubleValue();
				double d2=ms.degree(x);
				double y=d1 > d2 ? d2 : d1;			
				
				sumxy+=(x*y);
				sumy+=y;
			}
		}
		
		return sumxy/sumy;
	}
	
}

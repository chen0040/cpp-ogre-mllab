package fuzzylogic;

import java.util.Vector;

public class Rule {
	protected Vector<Clause> m_antecedents=new Vector<Clause>();
	protected Clause m_consequent=null;
	String m_name;
	
	public Rule(String name)
	{
		m_name=name;
	}
	
	public void setConsequent(Clause consequent)
	{
		m_consequent=consequent;
	}
	
	public void addAntecedent(Clause antecedent)
	{
		m_antecedents.add(antecedent);
	}
	
	public Clause getAntecedent(int index)
	{
		return m_antecedents.get(index);
	}
	
	public Clause getConsequent()
	{
		return m_consequent;
	}
	
	public int getAntecedentCount()
	{
		return m_antecedents.size();
	}
	
	/*
	public void fire()
	{
		double Ad=1;
		for(int i=0; i<m_antecedents.size(); ++i)
		{
			FuzzySet variable=m_antecedents.get(i).getVariable();
			String value=m_antecedents.get(i).getValue();
			Membership ms=variable.getMembership(value);
			if(!ms.hasValidX())
			{
				Ad=0;
				break;
			}
			double xVal=ms.getX();
			if(xVal >= variable.getMinX() && xVal <= variable.getMaxX())
			{
				double degree=ms.degree(xVal);
				if(degree < Ad)
				{
					Ad=degree;
				}
			}
			else
			{
				Ad=0;
				break;
			}
		}
		
		Membership ms2=m_consequent.getVariable().getMembership(m_consequent.getValue());
		
		double Ad0=ms2.getDegree();
		if(Ad0 > Ad)
		{
			ms2.setDegree(Ad);
		}
		
		System.out.println(m_name+": "+ms2.getDegree());
	}
	*/
}

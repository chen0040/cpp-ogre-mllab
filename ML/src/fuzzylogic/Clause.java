package fuzzylogic;

public class Clause {	
	FuzzySet m_variable;
	String m_value;
	String m_condition;
	
	public Clause(FuzzySet variable, String condition, String value)
	{
		m_variable=variable;
		m_value=value;
		m_condition=condition;
	}
	
	public String toString()
	{
		return m_variable.getName()+" "+m_condition+" "+m_value;
	}	
	
	public FuzzySet getVariable()
	{
		return m_variable;
	}
	
	public String getValue()
	{
		return m_value;
	}
}

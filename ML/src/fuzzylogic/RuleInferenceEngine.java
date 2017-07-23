package fuzzylogic;

import java.util.Vector;
import java.util.HashMap;

public class RuleInferenceEngine {
	Vector<String> m_variables=new Vector<String>();
	HashMap<String, FuzzySet> m_workingMemory=new HashMap<String, FuzzySet>();
	Vector<Rule> m_rules=new Vector<Rule>();
	
	public void addFuzzySet(String variable, FuzzySet set)
	{
		m_variables.add(variable);
		m_workingMemory.put(variable, set);
	}
	
	public int getFuzzySetCount()
	{
		return m_variables.size();
	}
	
	public void AddRule(Rule fr)
	{
		m_rules.add(fr);
	}
	
	public void setVariable(String variable, double crispValue)
	{
		m_workingMemory.get(variable).setX(crispValue);
	}
	
	public double getVariable(String variable)
	{
		return m_workingMemory.get(variable).getX();
	}
	
	public void infer(FuzzySet output)
	{
		output.fire(m_rules);
	}
	
	
}

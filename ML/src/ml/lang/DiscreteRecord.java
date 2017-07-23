package ml.lang;

import java.util.HashMap;
import java.util.Vector;


public class DiscreteRecord implements Record{
	protected HashMap<String, String> m_map=new HashMap<String, String>();
	protected Vector<String> m_fields=new Vector<String>();
	
	public DiscreteRecord()
	{
		
	}
	
	public void put(String name, String value)
	{
		m_map.put(name, value);
		m_fields.add(name);
	}
	
	public String getValue(String name)
	{
		return m_map.get(name);
	}
	
	public int size()
	{
		return m_map.size();
	}
	
	public String getField(int index)
	{
		return m_fields.get(index);
	}
	
}

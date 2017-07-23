package ml.lang;

public class BinaryFeatureVector implements BinaryDataPoint {
	
	boolean[] m_pattern=null;
	
	public BinaryFeatureVector(int[] pattern)
	{
		m_pattern=new boolean[pattern.length];
		for(int i=0; i<pattern.length; i++)
		{
			if(pattern[i]==0)
			{
				m_pattern[i]=false;
			}
			else
			{
				m_pattern[i]=true;
			}
		}
	}

	public boolean get(int index)
	{
		return m_pattern[index];
	}
	
	public void set(int index, boolean value)
	{
		m_pattern[index]=value;
	}
	
	public int size()
	{
		return m_pattern.length;
	}
	
	public String toString()
	{
		StringBuffer sb=new StringBuffer();
		for(int i=0; i<m_pattern.length; i++)
		{
			if(m_pattern[i])
			{
				sb.append("1 ");
			}
			else
			{
				sb.append("0 ");
			}
		}
		
		return sb.toString();
	}
}

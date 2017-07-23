package ml.lang;

import java.util.Random;

public class RandGen {
	
	protected Random m_random; 
	protected static RandGen m_instance=null;
	
	private RandGen()
	{
		m_random=new Random();;
	}
	
	public static RandGen instance()
	{
		if(m_instance==null)
		{
			m_instance=new RandGen();
		}
		
		return m_instance;
	}
	
	public double nextDouble(double min, double max)
	{
		return min+m_random.nextDouble()*(max-min);
	}
	
	public double nextDouble()
	{
		return m_random.nextDouble();
	}
	
	public double nextGaussian()
	{
		return m_random.nextGaussian();
	}
	
	public int nextInt()
	{
		return m_random.nextInt();
	}
	
	public int nextInt(int upper_bound)
	{
		return m_random.nextInt(upper_bound);
	}
	
	public boolean nextBoolean()
	{
		return m_random.nextBoolean();	
	}
	
	public long nextLong()
	{
		return m_random.nextLong();
	}
}

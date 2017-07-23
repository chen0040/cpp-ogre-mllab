package ml.lang;

import java.util.Vector;

public class FeatureVector extends DataPoint
{
	protected double [] m_data; 
	protected double [] m_lower_bound;
	protected double [] m_upper_bound;
	
	public FeatureVector(int data)
	{
		m_data=new double[1];
		m_lower_bound=new double[1];
		m_upper_bound=new double[1];
		m_data[0]=data;
		m_lower_bound[0]=Double.NEGATIVE_INFINITY;
		m_upper_bound[0]=Double.POSITIVE_INFINITY;
	}
	
	public FeatureVector(double data)
	{
		m_data=new double[1];
		m_lower_bound=new double[1];
		m_upper_bound=new double[1];
		m_data[0]=data;
		m_lower_bound[0]=Double.NEGATIVE_INFINITY;
		m_upper_bound[0]=Double.POSITIVE_INFINITY;
	}
	
	public FeatureVector(int[] data)
	{
		m_data=new double[data.length];
		m_lower_bound=new double[data.length];
		m_upper_bound=new double[data.length];
		for(int i=0; i<data.length; ++i)
		{
			m_data[i]=data[i];
			m_lower_bound[i]=Double.NEGATIVE_INFINITY;
			m_upper_bound[i]=Double.POSITIVE_INFINITY;
		}
	}
	
	public FeatureVector(double[] data)
	{
		m_data=new double[data.length];
		m_lower_bound=new double[data.length];
		m_upper_bound=new double[data.length];
		for(int i=0; i<data.length; ++i)
		{
			m_data[i]=data[i];
			m_lower_bound[i]=Double.NEGATIVE_INFINITY;
			m_upper_bound[i]=Double.POSITIVE_INFINITY;
		}
	}
	
	public FeatureVector(int[] data, int[] lower_bound, int[] upper_bound)
	{
		m_data=new double[data.length];
		m_lower_bound=new double[data.length];
		m_upper_bound=new double[data.length];
		for(int i=0; i<data.length; ++i)
		{
			m_data[i]=data[i];
			m_lower_bound[i]=lower_bound[i];
			m_upper_bound[i]=upper_bound[i];
		}
		
	}
	
	public FeatureVector(int data, int lower_bound, int upper_bound)
	{
		m_data=new double[1];
		m_lower_bound=new double[1];
		m_upper_bound=new double[1];
		
		m_data[0]=data;
		m_lower_bound[0]=lower_bound;
		m_upper_bound[0]=upper_bound;
	}
	
	public FeatureVector(double data, double lower_bound, double upper_bound)
	{
		m_data=new double[1];
		m_lower_bound=new double[1];
		m_upper_bound=new double[1];
		
		m_data[0]=data;
		m_lower_bound[0]=lower_bound;
		m_upper_bound[0]=upper_bound;
	}
	
	public FeatureVector(double[] data, double[] lower_bound, double[] upper_bound)
	{
		m_data=new double[data.length];
		m_lower_bound=new double[data.length];
		m_upper_bound=new double[data.length];
		for(int i=0; i<data.length; ++i)
		{
			m_data[i]=data[i];
			m_lower_bound[i]=lower_bound[i];
			m_upper_bound[i]=upper_bound[i];
		}
	}
	
	public double get(int index)
	{
		return m_data[index];
	}
	
	public int size()
	{
		return m_data.length;
	}

	public Vector<Double> getLowerBounds()
	{
		Vector<Double> lower_bounds=new Vector<Double>();
		for(int i=0; i<m_lower_bound.length; i++)
		{
			lower_bounds.add(new Double(m_lower_bound[i]));
		}
		return lower_bounds;
	}
	
	public Vector<Double> getUpperBounds()
	{
		Vector<Double> upper_bounds=new Vector<Double>();
		for(int i=0; i<m_upper_bound.length; i++)
		{
			upper_bounds.add(new Double(m_upper_bound[i]));
		}
		
		return upper_bounds;
	}
	
	public DataPoint clone()
	{
		FeatureVector pt=new FeatureVector(m_data, m_lower_bound, m_upper_bound); 
		return pt;
	}
	
	public void set(int index, double value)
	{
		m_data[index]=value;
	}
}
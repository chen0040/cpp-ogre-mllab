package ml.lang;

import java.util.Vector;

public class SampleSet {
	protected Vector<DataPoint> m_inputs=null;
	protected Vector<DataPoint> m_targets=null;
	protected int m_input_dim;
	protected int m_output_dim;
	
	public SampleSet(int input_dim, int output_dim)
	{
		m_input_dim=input_dim;
		m_output_dim=output_dim;
		
		m_inputs=new Vector<DataPoint>();
		m_targets=new Vector<DataPoint>();
	}
	
	public SampleSet(int input_dim)
	{
		m_input_dim=input_dim;
		m_output_dim=-1;
		m_inputs=new Vector<DataPoint>();
	}
	
	public int size()
	{
		return m_inputs.size();
	}
	
	public void addSample(DataPoint input, DataPoint target)
	{
		m_inputs.add(input);
		m_targets.add(target);
	}
	
	public DataPoint getSample(int index)
	{
		return m_inputs.get(index);
	}
	
	public DataPoint getSampleTarget(int index)
	{
		return m_targets.get(index);
	}
}

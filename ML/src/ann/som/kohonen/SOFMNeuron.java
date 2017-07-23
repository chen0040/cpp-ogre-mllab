package ann.som.kohonen;

import ml.lang.DataPoint;
import ann.Neuron;

public class SOFMNeuron extends Neuron<SOFMSynapse, SOFMSynapse, SOFMLayer>{
	protected int m_x;
	protected int m_y;
	protected DataPoint m_output;
	protected DataPoint m_input;
	
	public SOFMNeuron(SOFMLayer layer)
	{
		super(layer);
		layer.register_neuron(this);
	}
	
	public void create_input_synapse()
	{
		new SOFMSynapse(this);
	}
	
	public void set_output(DataPoint pt)
	{
		m_output=pt;
	}
	
	public void set_input(DataPoint pt)
	{
		m_input=pt;
	}
	
	public DataPoint get_input()
	{
		return m_input;
	}
	
	public DataPoint get_output()
	{
		return m_output;
	}
	public int get_x()
	{
		return m_x;
	}
	
	public int get_y()
	{
		return m_y;
	}
	
	public void set_x(int x)
	{
		m_x=x;
	}
	
	public void set_y(int y)
	{
		m_y=y;
	}
	
	public double get_distance(SOFMNeuron rhs)
	{
		double dx=rhs.get_x() - m_x;
		double dy=rhs.get_y() - m_y;
		return Math.sqrt(dx*dx + dy*dy);
	}
}

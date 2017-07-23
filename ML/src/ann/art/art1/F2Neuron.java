package ann.art.art1;

import ann.Neuron;

public class F2Neuron extends Neuron<F2InputSynapse, F1InputSynapse, F2> {
	protected boolean m_inhibited=false;
	protected int m_input=0;
	protected int m_output=0;
	
	public F2Neuron(F2 layer)
	{
		super(layer);
		layer.register_neuron(this);
	}
	
	public void set_input(int value)
	{
		m_input=value;
	}
	
	public int get_input()
	{
		return m_input;
	}
	
	public void set_output(int value)
	{
		m_output=value;
	}
	
	public int get_output()
	{
		return m_output;
	}
	
	public boolean inhibited()
	{
		return m_inhibited;
	}
	
	public void inhibit(boolean inhibited)
	{
		m_inhibited=inhibited;
	}
	
	public void create_input_synapse(F1Neuron source)
	{
		new F2InputSynapse(this, source);
	}
}

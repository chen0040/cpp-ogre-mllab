package ann.art.art1;
import ann.Neuron;

public class F1Neuron extends Neuron<F1InputSynapse, F2InputSynapse, F1>{
	protected int m_input=0;
	protected int m_output=0;
	
	public F1Neuron(F1 layer)
	{
		super(layer);
		layer.register_neuron(this);
	}
	
	public void create_input_synapse(F2Neuron source)
	{
		new F1InputSynapse(this, source);
	}
	
	public void set_input(int value)
	{
		m_input=value;
	}
	
	public void set_output(int value)
	{
		m_output=value;
	}
	
	public int get_output()
	{
		return m_output;
	}
	
	public int get_input()
	{
		return m_input;
	}
}

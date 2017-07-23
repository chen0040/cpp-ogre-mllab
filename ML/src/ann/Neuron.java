package ann;
import java.util.Vector;

public class Neuron<InputSynapse, OutputSynapse, L> {
	protected Vector<InputSynapse> m_input_synapses=new Vector<InputSynapse>();
	protected Vector<OutputSynapse> m_output_synapses=new Vector<OutputSynapse>();
	protected L m_layer;
	
	public Neuron(L layer)
	{
		m_layer=layer;
	}
	
	public void register_input_synapse(InputSynapse synapse)
	{
		if(!m_input_synapses.contains(synapse))
		{
			m_input_synapses.add(synapse);
		}
	}
	
	public void register_output_synapse(OutputSynapse synapse)
	{
		if(!m_output_synapses.contains(synapse))
		{
			m_output_synapses.add(synapse);
		}
	}
	
	public int get_input_synapse_count()
	{
		return m_input_synapses.size();
	}
	
	public int get_output_synapse_count()
	{
		return m_output_synapses.size();
	}
	
	public InputSynapse get_input_synapse(int index)
	{
		return m_input_synapses.get(index);
	}
	
	public OutputSynapse get_output_synapse(int index)
	{
		return m_output_synapses.get(index);
	}
	
	public void clear_input_synapses()
	{
		m_input_synapses.clear();
	}
	
	public void clear_output_synapses()
	{
		m_output_synapses.clear();
	}
}

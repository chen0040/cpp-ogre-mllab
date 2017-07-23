package ann.art.art1;

import ann.NeuralLayer;

public class F2 extends NeuralLayer<ARTNN, F2Neuron> {
	protected F2Neuron m_winner=null;
	
	public F2(ARTNN net, int neuron_count)
	{
		super(net);
		
		for(int i=0; i<neuron_count; ++i)
		{
			new F2Neuron(this);
		}
	}
	
	public F2Neuron get_winner()
	{
		return m_winner;
	}
	
	public final int get_winner_index()
	{
		for(int i=0; i<m_neurons.size(); ++i)
		{
			if(m_neurons.get(i)==m_winner)
			{
				return i;
			}
		}
		return -1;
	}
	
	public void determine_winner_neuron()
	{
		m_winner=null;
		double max_sum=Double.NEGATIVE_INFINITY;
		
		for(int i=0; i<m_neurons.size(); ++i)
		{
			F2Neuron neuron=m_neurons.get(i);
			if(!neuron.inhibited())
			{
				double sum=0;
				for(int j=0; j<neuron.get_input_synapse_count(); ++j)
				{
					F2InputSynapse synapse=neuron.get_input_synapse(j);
					sum+=synapse.get_weight() * synapse.get_source().get_output();
				}
				if(sum > max_sum)
				{
					max_sum=sum;
					m_winner=neuron;
				}
			}
		}
		
		for(int i=0; i<m_neurons.size(); ++i)
		{
			m_neurons.get(i).set_output(new Integer(0));
		}
		
		if(m_winner != null)
		{
			m_winner.set_output(new Integer(1));
		}
	}
	
	public void update_weights_to_winner_neuron()
	{	
		if(m_winner == null) return;
		
		double out_mag=0;
		for(int i=0; i<m_winner.get_input_synapse_count(); ++i)
		{
			F2InputSynapse synapse=m_winner.get_input_synapse(i);
			out_mag+=synapse.get_source().get_output();
		}
		
		for(int i=0; i<m_winner.get_input_synapse_count(); ++i)
		{
			F2InputSynapse synapse=m_winner.get_input_synapse(i);
			if(synapse.get_source().get_output()==1)
			{
				synapse.set_weight(m_net.L / (m_net.L-1+out_mag));
			}
			else
			{
				synapse.set_weight(0);
			}
		}
		
		for(int i=0; i<m_winner.get_output_synapse_count(); ++i)
		{
			F1InputSynapse synapse=m_winner.get_output_synapse(i);
			if(synapse.get_sink().get_output()==1)
			{
				synapse.set_weight(1);
			}
			else
			{
				synapse.set_weight(0);
			}
		}
	}
}

package ann.art.art1;

import ann.NeuralLayer;
import java.util.Vector;

public class F1 extends NeuralLayer<ARTNN, F1Neuron> {
	
	public F1(ARTNN net, int neuron_count)
	{
		super(net);
		
		for(int i=0; i<neuron_count; ++i)
		{
			new F1Neuron(this);
		}
	}
	
	public void calc_output()
	{
		double activation=0;
		double input_entry=0;
		int output_entry=0;
		for(int i=0; i<m_neurons.size(); ++i)
		{
			F1Neuron neuron=m_neurons.get(i);
			input_entry=neuron.get_input();
			activation= input_entry / (1+m_net.A * (input_entry+m_net.B)+m_net.C);
			output_entry=(activation > 0) ? 1 : 0;			
			neuron.set_output(new Integer(output_entry));
		}
	}
	
	public final double get_output_to_input_ratio()
	{
		double input_sum=0;
		double output_sum=0;
		for(int i=0; i<m_neurons.size(); ++i)
		{
			F1Neuron neuron=m_neurons.get(i);

			input_sum+=neuron.get_input();
			output_sum+=neuron.get_output();
		}
		return output_sum / input_sum;
	}
	
	public void set_input(Vector<Integer> input)
	{
		for(int i=0; i<m_neurons.size(); ++i)
		{
			m_neurons.get(i).set_input(input.get(i));
		}
	}
	
	public void update()
	{
		double input_entry=0;
		double sum=0;
		double activation=0;
		int output_entry=0;
		
		for(int i=0; i<m_neurons.size(); ++i)
		{
			F1Neuron neuron=m_neurons.get(i);
			sum=0;
			for(int j=0; j<neuron.get_input_synapse_count(); ++j)
			{
				F1InputSynapse synapse = neuron.get_input_synapse(j);
				F2Neuron source=synapse.get_source();
				sum+=source.get_output() * synapse.get_weight();
			}
			input_entry=neuron.get_input();
			activation=(input_entry + m_net.D * sum - m_net.B) / (1+m_net.A*(input_entry+m_net.D * sum)+m_net.C);
			output_entry=(activation > 0) ? 1 : 0;
			neuron.set_output(new Integer(output_entry));
		}
	}
}

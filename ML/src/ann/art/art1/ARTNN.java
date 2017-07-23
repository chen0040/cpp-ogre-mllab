package ann.art.art1;

import java.util.Vector;

public class ARTNN {
	public double A = 1;
	public double B = 1.5;
	public double C = 5;
	public double D = 0.9;
	public double L = 3;
	public double rho = 0.9;
	protected F1 m_F1;
	protected F2 m_F2;

	public void addNeuron2F1(F1Neuron neuron) {
		m_F1.register_neuron(neuron);
	}

	public ARTNN(int F1_neuron_count, int F2_neuron_count) {
		m_F1 = new F1(this, F1_neuron_count);
		m_F2 = new F2(this, F2_neuron_count);
		
		// create denrites between layers
		for (int i = 0; i < m_F1.get_neuron_count(); ++i) {
			for (int j = 0; j < m_F2.get_neuron_count(); ++j) {
				m_F1.get_neuron(i).create_input_synapse(m_F2.get_neuron(j));
				m_F2.get_neuron(j).create_input_synapse(m_F1.get_neuron(i));
			}
		}
	}

	public void initialize() {
		// initialize weights on the synapses of neurons in F1 that are
		// connected to F2
		double weight = (B - 1) / D + 0.2;
		for (int i = 0; i < m_F1.get_neuron_count(); i++) {
			F1Neuron neuron = m_F1.get_neuron(i);
			for (int j = 0; j < neuron.get_input_synapse_count(); j++) {
				
				neuron.get_input_synapse(j).set_weight(weight);
			}
		}

		// initialize weights on the synapses of neurons in F2 that are
		// connected to F1
		weight = L / (L - 1 + m_F1.get_neuron_count()) - 0.1;
		for (int i = 0; i < m_F2.get_neuron_count(); i++) {
			F2Neuron neuron = m_F2.get_neuron(i);
			for (int j = 0; j < neuron.get_input_synapse_count(); j++) 
			{
				neuron.get_input_synapse(j).set_weight(weight);
			}
		}
	}
	
	public int simulate(int[] input_array)
	{
		Vector<Integer> inarr=new Vector<Integer>();
		for(int i=0; i<input.length; ++i)
		{
			inarr.add(new Integer(input_array[i]));
		}
		return this.simulate(inarr);
	}

	public int simulate(Vector<Integer> input)
	{
		m_F1.set_input(input);
		
		for(int i=0; i< m_F2.get_neuron_count(); ++i)
		{
			m_F2.get_neuron(i).inhibit(false);
		}
		
		boolean resonance=false;
		boolean exhausted=false;
		
		while(!(resonance || exhausted))
		{
			m_F1.calc_output();
			m_F2.determine_winner_neuron();
			if(m_F2.get_winner() != null)
			{
				m_F1.update();
				if(m_F1.get_output_to_input_ratio() < rho)
				{
					m_F2.get_winner().inhibit(true);
				}
				else
				{
					resonance=true;
				}
			}
			else
			{
				exhausted=true;
			}
		}
		 
		if(resonance)
		{
			m_F2.update_weights_to_winner_neuron();
		}
		
		return m_F2.get_winner_index();
		
	}
}

package ann.hopfield;

import ml.lang.BinaryDataPoint;
import ann.NeuralLayer;

public class HopfieldLayer extends NeuralLayer<HopfieldNet, HopfieldNeuron>{
	protected double m_lambda=1.0; 
	
	
	public HopfieldLayer(HopfieldNet net, int neuron_count)
	{
		super(net);
		
		for(int i=0; i<neuron_count; i++)
		{
			new HopfieldNeuron(this);
		}
		
		for(int i=0; i<neuron_count; i++)
		{
			HopfieldNeuron neuron1=m_neurons.get(i);
			for(int j=0; j<neuron_count; j++)
			{
				if(i==j) continue;
				HopfieldNeuron neuron2=m_neurons.get(j);
				neuron1.create_input_synapse(neuron2);
			}
		}
	}
	
	public void initialize()
	{
		for(int i=0; i<m_neurons.size(); i++)
		{
			HopfieldNeuron neuron=m_neurons.get(i);
			for(int j=0; j<neuron.get_input_synapse_count(); ++j)
			{
				HopfieldSynapse synapse=neuron.get_input_synapse(j);
				synapse.set_weight(0);
			}
		}
	}
	
	//train to memorize input
	public void train(BinaryDataPoint data)
	{
		for(int i=0; i<m_neurons.size(); i++)
		{
			if(data.get(i))
			{
				m_neurons.get(i).set_input(new Integer(1));
			}
			else
			{
				m_neurons.get(i).set_input(new Integer(-1));
			}
		}
		
		for(int i=0; i<m_neurons.size(); i++)
		{
			m_neurons.get(i).train(data);
		}
	}
	
	//return a memorized pattern from the incomplete input
	public void retrieve(BinaryDataPoint data)
	{
		for(int i=0; i<m_neurons.size(); i++)
		{
			if(data.get(i))
			{
				m_neurons.get(i).set_input(1);
			}
			else
			{
				m_neurons.get(i).set_input(-1);
			}
		}
		
		boolean stable=false;
		while(!stable)
		{
			for(int i=0; i<m_neurons.size(); i++)
			{
				HopfieldNeuron neuron=m_neurons.get(i);
				double activation=neuron.get_activation();
				if(threshold(activation))
				{
					neuron.set_output(1);
				}
				else
				{
					neuron.set_output(-1);
				}
			}
			
			stable=true;
			for(int i=0; i<m_neurons.size(); i++)
			{
				HopfieldNeuron neuron=m_neurons.get(i);
				int input=neuron.get_input();
				int output=neuron.get_output();
				if(input != output)
				{
					stable=false;
					break;
				}
			}
			
			for(int j=0; j<m_neurons.size(); ++j)
			{
				HopfieldNeuron neuron=m_neurons.get(j);
				neuron.set_input(neuron.get_output());
			}
			
			
		}
		
		for(int i=0; i<m_neurons.size(); i++)
		{
			data.set(i, m_neurons.get(i).get_input() == 1);
		}
	}
	
	protected boolean threshold(double k)
	{
		/*
		double kk=m_lambda * k;
		double a = Math.exp( kk );
		double b = Math.exp( -kk );
		double tanh = (a-b)/(a+b);
		return tanh>=0;
		//*/
		
		return k >= 0;
	} 
	
	
}

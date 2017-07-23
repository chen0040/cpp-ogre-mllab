package ann.hopfield;

import ml.lang.BinaryDataPoint;
import ann.Neuron;

public class HopfieldNeuron extends Neuron<HopfieldSynapse, HopfieldSynapse, HopfieldLayer> {
	
	protected int m_input;
	protected int m_output;
	
	HopfieldNeuron(HopfieldLayer layer)
	{
		super(layer);
		layer.register_neuron(this);
	}
	
	public void create_input_synapse(HopfieldNeuron source)
	{
		new HopfieldSynapse(this, source);
	}
	
	public void set_output(int value)
	{
		m_output=value;
	}
	
	public void set_input(int value)
	{
		m_input=value;
	}
	
	public int get_input()
	{
		return m_input;
	}
	
	public int get_output()
	{
		return m_output;
	}
	
	public void train(final BinaryDataPoint input)
	{
		double N=input.size();
		
		int input1=this.get_input();
		
		for(int j=0; j<this.get_input_synapse_count(); j++)
		{
			HopfieldSynapse synapse=this.get_input_synapse(j);
			double current_weight=synapse.get_weight();
			double input2=synapse.get_source().get_input();
			
			current_weight+=input1*input2 / N; 
			synapse.set_weight(current_weight);
		}
	}
	
	protected double get_activation()
	{
		double activation=0;
		for(int j=0; j<this.get_input_synapse_count(); ++j)
		{
			HopfieldSynapse synapse=this.get_input_synapse(j);
			HopfieldNeuron neuron2=synapse.get_source();
			activation+=synapse.get_weight() * neuron2.get_input();
		}
		return activation;
	}
}

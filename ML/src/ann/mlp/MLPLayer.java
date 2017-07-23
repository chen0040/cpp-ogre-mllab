package ann.mlp;

import ann.NeuralLayer;
import ml.lang.functions.LogSig;
import ml.lang.functions.FunctionX;
import ml.lang.DataPoint;
import ml.lang.RandGen;

//default network assumes input and output are in the range of [0, 1] 
public class MLPLayer extends NeuralLayer<MLPNet, MLPNeuron> {
	MLPLayer m_source_layer=null;
	MLPLayer m_sink_layer=null;
	FunctionX m_transfer=new LogSig();
	
	
	MLPLayer(MLPNet net, int neuron_count)
	{
		super(net);
		
		for(int i=0; i<neuron_count; i++)
		{
			new MLPNeuron(this);
		}
	}
	
	public void randomize_weights()
	{
		for(int i=0; i<m_neurons.size(); i++)
		{
			MLPNeuron neuron=m_neurons.get(i);
			for(int j=0; j<neuron.get_input_synapse_count(); j++)
			{
				MLPSynapse synapse=neuron.get_input_synapse(j);
				synapse.randomize_weight();
				neuron.set_w0(RandGen.instance().nextDouble()-0.5);
			}
		}
	}
	
	public void set_transfer_function(FunctionX transfer)
	{
		m_transfer=transfer;
	}
	
	public void register_sink_layer(MLPLayer sink_layer)
	{
		m_sink_layer=sink_layer;
	}
	
	public void register_source_layer(MLPLayer source_layer)
	{
		m_source_layer=source_layer;
	}
	
	public void clear_input_synapses()
	{
		for(int i=0; i<m_neurons.size(); ++i)
		{
			m_neurons.get(i).clear_input_synapses();
		}
	}
	
	public void save_weights()
	{
		for(int i=0; i<m_neurons.size(); ++i)
		{
			m_neurons.get(i).save_weights();
		}
	}
	
	public void restore_weights()
	{
		for(int i=0; i<m_neurons.size(); ++i)
		{
			m_neurons.get(i).restore_weights();
		}
	}
	
	public void clear_output_synapses()
	{
		for(int i=0; i<m_neurons.size(); ++i)
		{
			m_neurons.get(i).clear_output_synapses();
		}
	}
	
	public void create_input_synapses(MLPLayer source_layer)
	{
		for(int i=0; i<m_neurons.size(); ++i)
		{
			MLPNeuron neuron=m_neurons.get(i);
			for(int j=0; j<source_layer.get_neuron_count(); ++j)
			{
				neuron.create_input_synapse(source_layer.get_neuron(j));
			}
		}
	}	
	
	public void forward_propagate(DataPoint input)
	{
		if(m_source_layer != null)
		{
			for(int i=0; i<m_neurons.size(); i++)
			{
				MLPNeuron neuron=m_neurons.get(i);
				neuron.set_output(m_transfer.calculate(neuron.get_v()));
			}
		}
		else //layer is an input layer
		{
			for(int i=0; i<m_neurons.size(); i++)
			{
				m_neurons.get(i).set_output(input.get(i));
			}
		}
		
		if(m_sink_layer!=null)
		{
			m_sink_layer.forward_propagate(input);
		}
	}
	
	protected void adjust_weights()
	{
		if(m_sink_layer != null)
		{
			double learning_rate=m_net.get_learning_rate();
			double momentum=m_net.get_momentum();
			for(int i=0; i<m_neurons.size(); i++)
			{
				MLPNeuron source_neuron=m_neurons.get(i);
				double source_output=source_neuron.get_output();
				for(int j=0; j<source_neuron.get_output_synapse_count(); ++j)
				{
					MLPSynapse synapse=source_neuron.get_output_synapse(j);
					MLPNeuron sink_neuron=synapse.get_sink();
					double sink_error=sink_neuron.get_error();
					double dWeight=synapse.get_dWeight();
					double weight=synapse.get_weight();
					double dw=learning_rate * sink_error * source_output;
					weight+=(dw + momentum * dWeight);
					dWeight=dw;
					synapse.set_dWeight(dWeight);
					synapse.set_weight(weight);			
				}
			}
			
			for(int j=0; j<m_sink_layer.get_neuron_count(); j++)
			{
				MLPNeuron sink_neuron=m_sink_layer.get_neuron(j);
				double sink_w0=sink_neuron.get_w0();
				double sink_error=sink_neuron.get_error();
				sink_w0+=learning_rate * sink_error;
				sink_neuron.set_w0(sink_w0);
			}
		}
		
		if(m_source_layer != null)
		{
			m_source_layer.adjust_weights();
		}
	}
	
	public void back_propagate(DataPoint target)
	{			
		if(m_sink_layer !=null) 
		{
			for(int i=0; i<m_neurons.size(); i++)
			{
				MLPNeuron source_neuron=m_neurons.get(i);
				double source_output=source_neuron.get_output();
				double error_sum=0;
				for(int j=0; j<source_neuron.get_output_synapse_count(); j++)
				{
					MLPSynapse synapse=source_neuron.get_output_synapse(j);
					MLPNeuron sink_neuron=synapse.get_sink();
					double weight=synapse.get_weight();
					double sink_error=sink_neuron.get_error();
					error_sum+=(weight*sink_error);
				}
				double source_error= source_output * (1-source_output) * error_sum;
				source_neuron.set_error(source_error);
			}
		}
		else //layer is an output layer
		{
			for(int i=0; i<m_neurons.size(); i++)
			{
				MLPNeuron neuron=m_neurons.get(i);
				double y=neuron.get_output();
				double d=target.get(i);
				double error=y * (1-y) * (d-y);
				neuron.set_error(error);
			}
		}
		
		if(m_source_layer != null)
		{
			m_source_layer.back_propagate(target);
		}
	}
}

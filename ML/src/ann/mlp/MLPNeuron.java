package ann.mlp;

import ml.lang.RandGen;
import ann.Neuron;

public class MLPNeuron extends Neuron<MLPSynapse, MLPSynapse, MLPLayer> {
	protected double m_w0=0;
	protected double m_input0=0;
	protected double m_output=0;
	protected double m_error=0;
	protected double m_dSaveW0=0;
	
	MLPNeuron(MLPLayer layer)
	{
		super(layer);
		layer.register_neuron(this);
		m_w0=RandGen.instance().nextDouble()-0.5;
		m_input0=-1;
		m_dSaveW0=m_w0;
	}
	
	public void create_input_synapse(MLPNeuron source)
	{
		new MLPSynapse(this, source);
	}
	
	public void set_output(double value)
	{
		m_output=value;
	}
	
	public void save_weights()
	{
		for(int j=0; j<this.get_input_synapse_count(); ++j)
		{
			this.get_input_synapse(j).save_weight();
			
		}
		m_dSaveW0=m_w0;
	}
	
	public void restore_weights()
	{
		for(int j=0; j<this.get_input_synapse_count(); ++j)
		{
			this.get_input_synapse(j).restore_weight();
			
		}
		m_w0=m_dSaveW0;
	}
	
	public double get_output()
	{
		return m_output;
	}
	
	public double get_error()
	{
		return m_error;
	}
	
	public void set_error(double err)
	{
		m_error=err;
	}
	
	public void set_w0(double w0)
	{
		m_w0=w0;
	}
	
	public final double get_w0()
	{
		return m_w0;
	}
	
	public final double get_input0()
	{
		return m_input0;
	}
	
	public final double get_v()
	{
		double sum=0;
		for(int i=0; i<this.get_input_synapse_count(); i++)
		{
			MLPSynapse synapse=this.get_input_synapse(i);
			MLPNeuron source=synapse.get_source();
			double input=source.get_output();
			double weight=synapse.get_weight();
			sum+=(input*weight);
			
		}
		sum+=(m_w0*m_input0);
		return sum;
	}
}

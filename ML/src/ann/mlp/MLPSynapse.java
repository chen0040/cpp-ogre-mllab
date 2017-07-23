package ann.mlp;

import ann.Synapse;
import ml.lang.RandGen;

public class MLPSynapse extends Synapse<MLPNeuron, MLPNeuron>{
	protected double m_dWeight=0;
	protected double m_dSavedWeight=0;
	
	MLPSynapse(MLPNeuron sink, MLPNeuron source)
	{
		super(sink, source);
		sink.register_input_synapse(this);
		source.register_output_synapse(this);
		randomize_weight();
		m_dSavedWeight=RandGen.instance().nextDouble()-0.5;
	}
	
	public void randomize_weight()
	{
		m_weight=RandGen.instance().nextDouble()-0.5;
		m_dWeight=RandGen.instance().nextDouble()-0.5;
	}
	
	public double get_dWeight()
	{
		return m_dWeight;
	}
	
	public void set_dWeight(double dWeight)
	{
		m_dWeight=dWeight;
	}
	
	public void save_weight()
	{
		m_dSavedWeight=m_weight;
	}
	
	public void restore_weight()
	{
		m_weight=m_dSavedWeight;
	}
}

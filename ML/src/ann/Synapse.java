package ann;

public class Synapse<SinkNeuron, SourceNeuron> {
	protected SinkNeuron m_sink;
	protected SourceNeuron m_source;
	protected double m_weight=0;
	
	public Synapse(SinkNeuron sink, SourceNeuron source)
	{
		m_sink=sink;
		m_source=source;
	}
	
	public void set_weight(double weight)
	{
		m_weight=weight;
	}
	
	public double get_weight()
	{
		return m_weight;
	}
	
	public SinkNeuron get_sink()
	{
		return m_sink;
	}
	
	public SourceNeuron get_source()
	{
		return m_source;
	}
	
}

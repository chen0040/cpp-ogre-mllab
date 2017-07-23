package ann;
import java.util.Vector;

public class NeuralLayer<NN, N> {
	protected Vector<N> m_neurons=new Vector<N>();
	protected NN m_net;
	
	public NeuralLayer(NN net)
	{
		m_net=net;
	}
	
	public void register_neuron(N neuron)
	{
		m_neurons.add(neuron);
	}
	
	public int get_neuron_count()
	{
		return m_neurons.size();
	}
	
	public N get_neuron(int index)
	{
		return m_neurons.get(index);
	}
	
	public NN get_net()
	{
		return m_net;
	}
	
}

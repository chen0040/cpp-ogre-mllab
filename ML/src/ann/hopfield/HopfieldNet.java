package ann.hopfield;

import ml.lang.BinaryDataPoint;



//Xianshun says:
//Hopfield can store up to 0.14N patterns if N is large, where N is the dimension of input
public class HopfieldNet{
	HopfieldLayer m_layer;
	
	public HopfieldNet(int neuron_count)
	{
		m_layer=new HopfieldLayer(this, neuron_count);
	}
	
	public void initialize()
	{
		m_layer.initialize();
	}
	
	//train to memorize input
	public void train(BinaryDataPoint input)
	{
		m_layer.train(input);
	}
	
	//return a memorized pattern from the incomplete input
	public void predict(BinaryDataPoint data)
	{
		m_layer.retrieve(data);
	}
	
}

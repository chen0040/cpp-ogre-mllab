package ann.som.kohonen;

import ml.lang.DataPoint;
import java.util.Vector;

public class SOFMNet {
	protected SOFMLayer m_layer;
	
	//input_size should be smaller or equal to the actual input size
	public SOFMNet(int neuron_count, int input_size)
	{
		m_layer=new SOFMLayer(this, neuron_count, 1, input_size);
	}
	
	public SOFMNet(int rows, int cols, int input_size)
	{
		m_layer=new SOFMLayer(this, rows, cols, input_size);
	}
	
	public void setEta0(double eta0)
	{
		m_layer.setEta0(eta0);
	}
	
	public void setEpochesForSelfOrganizingPhase(int epoches)
	{
		m_layer.setEpochesForSelfOrganizingPhase(epoches);
	}
	
	public void train(DataPoint input)
	{
		m_layer.train(input);
	}
	
	public SOFMNeuron predict(DataPoint input)
	{
		return m_layer.classify(input);
	}
	
	public void initialize(Vector<Double> lowest_weight, Vector<Double> highest_weight)
	{
		m_layer.initialize(lowest_weight, highest_weight);
	}
	
	public void initialize(double[] weight_lower_bounds, double[] weight_upper_weight)
	{
		Vector<Double> w1=new Vector<Double>();
		for(int k=0; k<weight_lower_bounds.size(); k++)
		{
			w1.add(new Double(weight_lower_bounds[k]));
		}
		Vector<Double> w2=new Vector<Double>();
		for(int k=0; k<weight_upper_bounds.size(); k++)
		{
			w2.add(new Double(weight_upper_bounds[k]));
		}
		this.initialize(w1, w2);
	}
	
	public SOFMNeuron get_neuron(int row, int col)
	{
		return m_layer.get_neuron(row, col); 
	}
}

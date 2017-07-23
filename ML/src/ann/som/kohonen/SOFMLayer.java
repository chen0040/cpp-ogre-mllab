package ann.som.kohonen;

import java.util.Random;
import ml.lang.DataPoint;
import ann.NeuralLayer;
import java.util.Vector;

public class SOFMLayer extends NeuralLayer<SOFMNet, SOFMNeuron> {
	SOFMNeuron m_winner=null;
	int m_rows;
	int m_cols;
	protected Random m_random;
	protected double m_sigma_0;
	protected double m_tau_1;
	protected int m_sop_epoches=1000; //the iteration number in the phase 1: self-organizing phase
	protected int m_epoch=0;
	protected double m_eta_0=0.1;
	protected int m_input_dimension=0;
	
	public void setEta0(double eta0)
	{
		m_eta_0=eta0;
	}
	
	public void setEpochesForSelfOrganizingPhase(int epoches)
	{
		m_sop_epoches=epoches;
	}
	
	public void set_self_organizing_phase_epoch_count(int sop)
	{
		m_sop_epoches=sop;
	}
	
	public SOFMNeuron get_neuron(int row, int col)
	{
		return m_neurons.get(row * m_cols + col);
	}
	
	public void set_eta_0(double eta_0)
	{
		m_eta_0=eta_0;
	}
	
	public SOFMNeuron get_winner()
	{
		return m_winner;
	}
	
	//input_size should be smaller or equal to the actual input size
	public SOFMLayer(SOFMNet net, int rows, int cols, int input_dimension)
	{
		super(net);
		m_random=new Random();
		
		m_rows=rows;
		m_cols=cols;
		m_input_dimension=input_dimension;
		
		for(int y=0; y<m_rows; ++y)
		{
			for(int x=0; x<m_cols; ++x)
			{
				SOFMNeuron neuron=new SOFMNeuron(this);
				neuron.set_x(x);
				neuron.set_y(y);
				for(int j=0; j<input_dimension; ++j)
				{
					neuron.create_input_synapse();
				}
			}
		}
		
		m_sigma_0 = 0.707*Math.sqrt((m_rows-1)*(m_rows-1)+(m_cols-1)*(m_cols-1));
		m_tau_1 = 1000 / Math.log(m_sigma_0);
	} 
	
	public void initialize(Vector<Double> lowest_weight, Vector<Double> highest_weight)
	{
		int [] seq=new int[m_neurons.size()];
		for(int i=0; i<m_neurons.size(); ++i)
		{
			seq[i]=i;
		}
		
		
		for(int j=0; j<m_input_dimension; ++j)
		{
			double inc=(highest_weight.get(j).doubleValue() - lowest_weight.get(j).doubleValue()) / m_neurons.size();
			
			for(int i=0; i<m_neurons.size(); ++i)
			{
				int k=m_random.nextInt(m_neurons.size());
				int tmp=seq[i];
				seq[i]=seq[k];
				seq[k]=tmp;
			}
			
			for(int i=0; i<m_neurons.size(); ++i)
			{
				SOFMNeuron neuron=m_neurons.get(i);
				neuron.get_input_synapse(j).set_weight(lowest_weight.get(j).doubleValue()+inc*seq[i]+inc*m_random.nextDouble());
			}
		}
		
		/*
		for(int i=0; i<m_neurons.size(); ++i)
		{
			KNeuron neuron=m_neurons.get(i);
			System.out.println("neuron: ("+neuron.get_x()+", "+neuron.get_y()+"): ("
					+neuron.get_input_synapse(0).get_weight()+", "
					+neuron.get_input_synapse(1).get_weight()+", "
					+neuron.get_input_synapse(2).get_weight()
					);
		}
		*/
		
		m_epoch=0;
	}
	
	protected double eta(int n)
	{
		//if(n < m_sop_epoches) //self-oganizing phase
		//{
			double result= m_eta_0 * Math.exp(-n/m_tau_1);
			if(result < 0.01) result=0.01;
			return result; 
		//}
		//else //convergence phase
		//{
		//	return 0.01;
		//}
	}
	
	protected double h(double distance, int n)
	{
		if(n < m_sop_epoches) //self-organizing phase
		{
			double sigma=m_sigma_0 * Math.exp(- n / m_tau_1);
			return Math.exp(-distance * distance / (2*sigma*sigma));
		}
		else //convergence phase
		{
			return 1;
		}
	}
	
	public void train(DataPoint input)
	{
		//determine the winner neuron
		m_winner=null;
		double max_sum=Double.MAX_VALUE;
		for(int i=0; i<m_neurons.size(); i++)
		{
			SOFMNeuron neuron=m_neurons.get(i);
			double sum=0;
			for(int j=0; j<m_input_dimension; j++)
			{
				double d=input.get(j) - neuron.get_input_synapse(j).get_weight();
				sum+=d*d;
			}
			if(sum < max_sum)
			{
				m_winner=neuron;
				max_sum=sum;
				//System.out.println("i: "+i+" sum="+sum);
			}
		}
		
		/*
		System.out.println("winner neuron: ("+m_winner.get_x()+", "+m_winner.get_y()+"): "
				+m_winner.get_input_synapse(0).get_weight()+", "
				+m_winner.get_input_synapse(1).get_weight()+", "
				+m_winner.get_input_synapse(2).get_weight()
		);
		*/
		
		//update neuron weights
		for(int i=0; i<m_neurons.size(); ++i)
		{
			SOFMNeuron neuron=m_neurons.get(i);
			if(neuron == m_winner) continue;
			double d=neuron.get_distance(m_winner);
			//System.out.println("distance: "+d);
			for(int j=0; j<m_input_dimension; ++j)
			{
				double current_weight=neuron.get_input_synapse(j).get_weight();
				double weight_delta=eta(m_epoch) * h(d, m_epoch) * (input.get(j) - current_weight);
				neuron.get_input_synapse(j).set_weight(current_weight+weight_delta);
			}
		}
		
		
		m_epoch++;
	}
	
	public SOFMNeuron classify(DataPoint input)
	{
		m_winner=null;
		double max_sum=Double.MAX_VALUE;
		for(int i=0; i<m_neurons.size(); i++)
		{
			SOFMNeuron neuron=m_neurons.get(i);
			double sum=0;
			for(int j=0; j<m_input_dimension; j++)
			{
				double d=input.get(j) - neuron.get_input_synapse(j).get_weight();
				sum+=d*d;
			}
			if(sum < max_sum)
			{
				m_winner=neuron;
				max_sum=sum;
			}
		}
		//System.out.println("winner: ("+m_winner.get_x()+", "+m_winner.get_y()+")");
		return m_winner;
	}
}

package ann.mlp;

import java.util.Vector;
import ml.lang.DataPoint;
import ml.lang.functions.FunctionX;
import ml.lang.SampleSet;

//default network assumes input and output are in the range of [0, 1] 
public class MLPNet {
	protected MLPLayer m_input_layer=null;
	protected MLPLayer m_output_layer=null;
	protected Vector<MLPLayer> m_layers=new Vector<MLPLayer>();
	protected double m_learning_rate=0.25; //learning rate
	protected double m_momentum=0.9; //momentum term for \Delta w[i][j]
	
	public MLPNet()
	{
		
	}
	
	public void randomize_weights()
	{
		for(int i=0; i<m_layers.size(); i++)
		{
			m_layers.get(i).randomize_weights();
		}
	}
	
	protected void register_layer(MLPLayer layer)
	{
		if(m_output_layer != null)
		{
			m_output_layer.register_sink_layer(layer);
			layer.register_source_layer(m_output_layer);
			
			layer.create_input_synapses(m_output_layer);
		}
		else
		{
			m_input_layer=layer;
		}
		
		m_layers.add(layer);
		m_output_layer=layer;
	}
	
	public void train(SampleSet trainss, SampleSet testss)
	{
		this.train(trainss, testss, new MLPTrainParam());
	}
	
	public void train(SampleSet trainss, SampleSet testss, MLPTrainParam params)
	{
		boolean stop=false;
		double min_err=Double.MAX_VALUE;
		int epoch=0;
		int stagnation_epoch=0;
		while(!stop)
		{
			this.train(trainss, params.training_epoches);
			epoch+=params.training_epoches;
			
			double err=this.test(testss);
		
			if(epoch >= params.max_epoches || err < params.min_test_error)
			{
				this.restore_weights();
				stop=true;
			}
			else if(err < min_err)
			{
				//System.out.println("error: "+err);
				min_err=err;
				this.save_weights();
			}
			else 
			{
				stagnation_epoch+=epoch;
				if(stagnation_epoch > params.max_stagnation_epoches)
				{
					this.randomize_weights();
					stagnation_epoch=0;
				}
			}
		}
	}
	
	public void save_weights()
	{
		for(int i=0; i<m_layers.size(); i++)
		{
			m_layers.get(i).save_weights();
		}
	}
	
	public void restore_weights()
	{
		for(int i=0; i<m_layers.size(); i++)
		{
			m_layers.get(i).restore_weights();
		}
	}
	
	public void train(SampleSet ss, int training_epoches)
	{
		for(int count=0; count<training_epoches; ++count)
		{
			for(int i=0; i<ss.size(); i++)
			{				
				train(ss.getSample(i), ss.getSampleTarget(i));
			} 
		}
	}
	
	public double test(SampleSet ss)
	{
		double test_error=0;
		for(int i=0; i<ss.size(); i++)
		{
			test_error+=test(ss.getSample(i), ss.getSampleTarget(i));
		}
		
		return test_error;
	}
	
	public double get_learning_rate()
	{
		return m_learning_rate;
	}
	
	public double get_momentum()
	{
		return m_momentum;
	}
	
	public void set_momentum(double alpha)
	{
		m_momentum=alpha;
	}
	
	public void set_learning_rate(double eta)
	{
		m_learning_rate=eta;
	}
	
	public void create_layer(int neuron_count)
	{
		MLPLayer layer=new MLPLayer(this, neuron_count);
		this.register_layer(layer);
	}
	
	public void create_layer(int neuron_count, FunctionX transfer_function)
	{
		MLPLayer layer=new MLPLayer(this, neuron_count);
		layer.set_transfer_function(transfer_function);
		this.register_layer(layer);
	}
	
	public double train(DataPoint input, DataPoint target)
	{
		//forward propagate
		m_input_layer.forward_propagate(input);
		
		double error=get_target_error(target);
		
		//backward propagate
		m_output_layer.back_propagate(target);
		m_output_layer.adjust_weights();
		
		return error; 
	}
	
	protected double get_target_error(DataPoint target)
	{
		double t_error=0;
		double error=0;
		for(int i=0; i<m_output_layer.get_neuron_count(); i++)
		{
			error=target.get(i)-m_output_layer.get_neuron(i).get_output();
			t_error+=(0.5 * error * error);
		}
		
		return t_error;
	}
	
	public double test(DataPoint input, DataPoint target)
	{		
		m_input_layer.forward_propagate(input);
		
		return get_target_error(target);
	}
	
	public void predict(DataPoint input, DataPoint output)
	{
		m_input_layer.forward_propagate(input);	
		for(int i=0; i<m_output_layer.get_neuron_count(); i++)
		{
			output.set(i, m_output_layer.get_neuron(i).get_output());
		}
	}
	
}

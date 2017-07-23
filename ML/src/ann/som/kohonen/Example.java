package ann.som.kohonen;

import ann.som.kohonen.SOFMNet;
import ann.som.kohonen.SOFMNeuron;

import ml.lang.DataPoint;

//input must be extended from ml.lang.DataPoint
class ExampleInput extends DataPoint
{
	private double[] data=new double[\param{InputDimension}];
	
	public ExampleInput(double[] _data)
	{
		for(int k=0; k<_data.length; ++k)
		{
			data[k]=_data[k];
		}
	}
	
	public int size()
	{
		return data.length;
	}
	
	public double get(int index)
	{
		return data[index];
	}
	
	public void set(int index, double value)
	{
		data[index]=value;
	}
	
	public Vector<Double> getLowerBounds()
	{
		Vector<Double> v=new Vector<Double>();
		for(int k=0; k<this.size(); k++)
		{
			v.add(new Double(-5));
		}
		return v;
	}
	
	public Vector<Double> getUpperBounds()
	{
		Vector<Double> v=new Vector<Double>();
		for(int k=0; k<this.size(); k++)
		{
			v.add(new Double(5));
		}
		return v;
	}
	
	public DataPoint clone()
	{
		ExampleInput pt=new ExampleInput();
		for(int k=0; k<this.size(); k++)
		{
			pt.set(k, data[k]);
		}
		return pt;
	}
}

//output must be extended from ml.lang.DataPoint
class ExampleOutput extends DataPoint
{
	private double[] data=new double[2];
	String id;
	
	public ExampleOutput(int r, int c)
	{
		data[0]=r;
		data[1]=c;
		id=""+"["+r+"]["+c+"]";
	}
	
	public int size()
	{
		return data.length;
	}
	
	public double get(int index)
	{
		return data[index];
	}
	
	public void set(int index, double value)
	{
		data[index]=value;
	}
	
	public Vector<Double> getLowerBounds()
	{
		Vector<Double> v=new Vector<Double>();
		for(int k=0; k<this.size(); k++)
		{
			v.add(new Double(0));
		}
		return v;
	}
	
	public Vector<Double> getUpperBounds()
	{
		Vector<Double> v=new Vector<Double>();
		for(int k=0; k<this.size(); k++)
		{
			v.add(new Double(1));
		}
		return v;
	}
	
	public DataPoint clone()
	{
		ExampleOutput pt=new ExampleOutput(data[0], data[1]);
		return pt;
	}
	
	public String toString()
	{
		return id;
	}
}

public class Example {
	public static void main(String[] args)
	{
		//number of neuron rows is [Rows], number of neuron cols is [Cols], input dimension is [Input Dimension]
		SOFMNet net=new SOFMNet(\param{Rows}, \param{Cols}, \param{InputDimension});
		net.setEta0(double eta0);
		net.setEpochesForSelfOrganizingPhase(1000); //SOM training consists of self-organizing phase and converging phase, this parameter specifies the number of training inputs for self-organizing phase, note that an epoch simply means a training input here
		
		//initialize weights on the SOM network
		Vector<Double> weight_lower_bounds=new Vector<Double>();
		Vector<Double> weight_upper_bounds=new Vector<Double>();
		for(int i=0; i<[Input Dimension]; i++)
		{
			weight_lower_bounds.add(new Double(\param{WeightLowerBound})); //lower bound for each input dimension is [Weight Lower Bound]
			weight_upper_bounds.add(new Double(\param{WeightUpperBound})); //upper bound for each input dimension is [Weight Upper Bound]
		}
		net.initialize(weight_lower_bounds, weight_upper_bounds);
		
		//set unique label for each neuron in SOM net
		for(int r=0; r<[Rows]; ++r)
		{
			for(int c=0; c<[Cols]; ++c)
			{				
				net.get_neuron(r, c).set_output(new ExampleOutput(r, c)); //neuron at row r and column c will have label "[r, c]"
			}
		}
		
		//the following code train the SOM net by a single training input
		ExampleInput trainingInput=new ExampleInput(new double[]{\array[continuous][\param{InputDimension}]{\param{WeightLowerBound}, \param{WeightUpperBound}}});
		net.train(trainingInput);
		// ...
		//the SOM net can be trained using a typical 3000 training inputs, repeated the above code for other training inputs
		
		//the following code using SOM net after training to predict the winning class, the out put is the label of the winning neuron for the input used
		ExampleInput testInput=new ExampleInput(new double[]{\array[continuous][\param{InputDimension}]{\param{WeightLowerBound}, \param{WeightUpperBound}}});
		SOFMNeuron winner=net.predict(testInput);
		ExampleOutput winnerLabel=(ExampleOutput)winner.get_output());	
		System.out.println("class: "+winnerLabel);
	}
}

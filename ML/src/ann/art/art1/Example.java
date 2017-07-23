package ann.art.art1;
import ann.art.art1.ARTNN;

public class Example {
	public static void main(String[] args)
	{	
		//the net is initialized to have  input array of size \param{F1NeuronCount}  and have \param{F2NeuronCount} classes
		ARTNN net=new ARTNN(\param{F1NeuronCount}, \param{F2NeuronCount});
		net.A=\param{A};
		net.B=\param{B};
		net.C=\param{C};
		net.D=\param{D};
		net.L=\param{L};
		net.rho=\param{rho};
		net.initialize();
		
		//following code is for demonstration for net with  input size [F1 neuron count]
		int[] inputSample=null;
		int classId=0;
		
		\begin{repeat}[\param{SimulationSampleCount}]
		inputSample=new int[]{\array[discrete][\param{F1NeuronCount}]{0,1}};
		classId=net.simulate(inputSample);
		System.out.println("Class: "+classId);
		
		\end{repeat}
	} 
}


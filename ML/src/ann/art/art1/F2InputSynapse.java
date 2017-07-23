package ann.art.art1;
import ann.Synapse;

public class F2InputSynapse extends Synapse<F2Neuron, F1Neuron>{
	public F2InputSynapse(F2Neuron sink, F1Neuron source)
	{
		super(sink, source);
		sink.register_input_synapse(this);
		source.register_output_synapse(this);
	}
}

package ann.art.art1;

import ann.Synapse;

public class F1InputSynapse extends Synapse<F1Neuron, F2Neuron> {
	public F1InputSynapse(F1Neuron sink, F2Neuron source)
	{
		super(sink, source);
		sink.register_input_synapse(this);
		source.register_output_synapse(this);
	}
}

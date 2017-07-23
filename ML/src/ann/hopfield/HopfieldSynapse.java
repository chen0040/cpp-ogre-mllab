package ann.hopfield;

import ann.Synapse;

public class HopfieldSynapse extends Synapse<HopfieldNeuron, HopfieldNeuron> {
	public HopfieldSynapse(HopfieldNeuron sink, HopfieldNeuron source)
	{
		super(sink, source);
		sink.register_input_synapse(this);
		source.register_output_synapse(this);
	}
}

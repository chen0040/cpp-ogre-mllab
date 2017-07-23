package ann.som.kohonen;

import ann.Synapse;

public class SOFMSynapse extends Synapse<SOFMNeuron, SOFMNeuron> {
	public SOFMSynapse(SOFMNeuron sink)
	{
		super(sink, null);
		sink.register_input_synapse(this);
	}
}

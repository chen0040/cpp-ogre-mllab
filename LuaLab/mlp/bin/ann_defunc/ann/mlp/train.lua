local trainer_db=dofile("database.lua");
trainer_db.loadSamples("[record samples]"); --trainer which acts as a database of training samples.

local ann=dofile("MLP\\MLP.lua"); --multi-layer perceptron neural network with learning rate of 0.2
ann.init(\param{LearningRate});

local err_threshold=\param{MinErrorThreshold};
local max_epoches=\param{MaxEpoches};

local sample_index=0; --the index of the training sample
local epoches=0; --number of training iterations
local totalError=0; --total amount of error over all the training samples

ann.addLayer(trainer_db.getInputCount()); --input layer
\begin{template}[HiddenLayers]
ann.addLayer(\param{LayerNeuronCount}); --hidden layer
\end{template}
ann.addLayer(trainer_db.getOutputCount()); --output layer

local logger=dofile("Util\\logger.lua");
logger.create("log.csv");
logger.println("epoches, samples, trainErr, totalErr");

while (true) do
	sample_index=sample_index+1;
	if(sample_index > trainer_db.getSampleCount()) then
		sample_index=1;
		totalError=0;
	end
	local outputs=trainer_db.getSampleOutputs(sample_index);
	local inputs=trainer_db.getSampleInputs(sample_index);
	
	ann.forwardProp(inputs);
	
	local trainErr=ann.getError(outputs);
	totalError = totalError + trainErr;
	if sample_index == trainer_db.getSampleCount() then
		logger.println(epoches .. ", " .. sample_index .. ", " .. trainErr .. ", " .. totalError);
	else
		logger.println(epoches .. ", " .. sample_index .. ", " .. trainErr);
	end
	
	epoches=epoches+1;
	if err_threshold > totalError then
		break;
	end
	if epoches > max_epoches then
		break;
	end
	
	print("epoches " .. epoches);
	
	ann.backwardProp(outputs);
end

logger.close();

BotGen=dofile("BotGen.lua");
BotGen.createNPC(ann, trainer_db.getDataInterface());


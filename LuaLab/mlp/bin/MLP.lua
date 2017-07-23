local MLP={};

function MLP.transfer(x)
	return 1/(math.exp(-x)+1);
end

function MLP.init(_learningRate)
	MLP.learningRate=_learningRate;
	MLP.layerCount=0;
end

function MLP.addLayer(_neuronCount)
	local layerIndex=MLP.layerCount+1;
	MLP[layerIndex]={};
	
	MLP[layerIndex].neuronCount=_neuronCount; 
	
	for i=1, MLP[layerIndex].neuronCount do
		MLP[layerIndex][i]={};
		MLP[layerIndex][i].bias=math.random() * 2-1;
		MLP[layerIndex][i].val=0;
		if layerIndex > 1 then
			for j=1, MLP[layerIndex-1].neuronCount do
				MLP[layerIndex][i][j]=math.random()*2-1;
			end
		end
	end
	
	MLP.layerCount=layerIndex;
end

function MLP.forwardProp(_inputs)
	local inputLayerIndex=1;
	local firstHiddenLayerIndex=inputLayerIndex+1;
	local outputLayerIndex=MLP.layerCount;
	
	for i=1, MLP[inputLayerIndex].neuronCount do
		MLP[inputLayerIndex][i].val=_inputs[i];
	end
	
	for layerIndex=firstHiddenLayerIndex, outputLayerIndex do
		for i=1, MLP[layerIndex].neuronCount do
			local sum=MLP[layerIndex][i].bias;
			for j=1, MLP[layerIndex-1].neuronCount do
				sum=sum+MLP[layerIndex-1][j].val * MLP[layerIndex][i][j];
			end
			MLP[layerIndex][i].val=MLP.transfer(sum);
		end
	end
	
	local outputs={};
	for i=1, MLP[outputLayerIndex].neuronCount do
		outputs[i]=MLP[outputLayerIndex][i].val;
	end
	
	return outputs;
end

function MLP.backwardProp(_desired_outputs)
	local outputLayerIndex=MLP.layerCount;
	local inputLayerIndex=1;
	local firstHiddenLayerIndex=inputLayerIndex+1;
	local lastHiddenLayerIndex=outputLayerIndex-1;
	
	for i=1, MLP[outputLayerIndex].neuronCount do
		local u=MLP[outputLayerIndex][i].val;
		MLP[outputLayerIndex][i].delta=(_desired_outputs[i] - u) * u * (1-u);
	end
	
	for i=lastHiddenLayerIndex, inputLayerIndex, -1 do
		for j=1, MLP[i].neuronCount do
			local weightDelta = 0;
			for k = 1, MLP[i+1].neuronCount do
				weightDelta = weightDelta + MLP[i+1][k][j]*MLP[i+1][k].delta
			end
			local u=MLP[i][j].val;
			MLP[i][j].delta = u * (1 - u) * weightDelta;
		end
	end
	
	for i = firstHiddenLayerIndex, outputLayerIndex do
		for j = 1, MLP[i].neuronCount do
			MLP[i][j].bias = MLP[i][j].bias + MLP[i][j].delta * MLP.learningRate;
			for k = 1, MLP[i-1].neuronCount do
				MLP[i][j][k] = MLP[i][j][k] + MLP[i][j].delta * MLP.learningRate * MLP[i-1][k].val;
			end
		end
	end
end

function MLP.getError(_desired_outputs)
	local outputLayerIndex=MLP.layerCount;
	local sum=0;
	for i = 1, MLP[outputLayerIndex].neuronCount do
		local err=MLP[outputLayerIndex][i].val - _desired_outputs[i];
		sum = sum + err * err;
	end
	return 0.5 * sum;
end

function MLP.getLayerCount()
	return MLP.layerCount;
end

function MLP.save(fileName)
	local logger=dofile("GameLogger.lua");
	
	logger.create(fileName);
	logger.println("local MLP={};");
	
	local inputLayerIndex=1;
	local firstHiddenLayerIndex=inputLayerIndex+1;
	local outputLayerIndex=MLP.layerCount;
	
	logger.println("MLP.layerCount=" .. MLP.layerCount .. ";");
	
	for layerIndex=inputLayerIndex, outputLayerIndex do
		logger.println("MLP[" .. layerIndex .. "]={};");
		logger.println("MLP[" .. layerIndex .. "].neuronCount=" .. MLP[layerIndex].neuronCount .. ";");
	end
	
	for layerIndex=firstHiddenLayerIndex, outputLayerIndex do
		for i=1, MLP[layerIndex].neuronCount do
			logger.println("MLP[" .. layerIndex .. "][" .. i .. "]={};");
			for j=1, MLP[layerIndex-1].neuronCount do
				logger.println("MLP[" .. layerIndex .. "][" .. i .. "][" .. j .. "]=" .. MLP[layerIndex][i][j]);
			end
		end
	end
		
	local outputs={};
	for i=1, MLP[outputLayerIndex].neuronCount do
		outputs[i]=MLP[outputLayerIndex][i].val;
	end
	
	logger.println("return MLP;");
	logger.close();
end

function MLP.load(fileName)
	local savedMLP=dofile(fileName);
	
	if MLP.layerCount ~= savedMLP.layerCount then
		print2Console("Load Failed: layerCount does not match");
		return false;
	end 
	
	local inputLayerIndex=1;
	local firstHiddenLayerIndex=inputLayerIndex+1;
	local outputLayerIndex=MLP.layerCount;
	
	for layerIndex=inputLayerIndex, outputLayerIndex do
		if MLP[layerIndex].neuronCount ~= savedMLP[layerIndex].neuronCount then
			print2Console("Load Failed: neuronCount does not match");
			return false;
		end
	end
	
	for layerIndex=firstHiddenLayerIndex, outputLayerIndex do
		for i=1, MLP[layerIndex].neuronCount do
			for j=1, MLP[layerIndex-1].neuronCount do
				MLP[layerIndex][i][j]=savedMLP[layerIndex][i][j];
			end
		end
	end
	
	return true;
end

return MLP;








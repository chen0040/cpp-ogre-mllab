local Prog={}; --game agent namespace

Prog.sampleCount=0; --number of training samples
Prog.samples={}; --training samples
Prog.dataInterface=nil; 

function Prog.loadSamples(filename)
	local samples=dofile(filename);
	for i, sample in next, samples, nil do
		local agentSheet=dofile("AgentSheet.lua");
		
		for groupId, c in next, sample, nil do
			if groupId=="User" then
				for userId, u in next, c, nil do
					player=u;
					for obs, observation in next, player, nil do
						if obs=="State" then
							agentSheet.setOutput(player.State);
						else
							agentSheet.addInput(obs, observation);
						end
					end
				end
			elseif groupId=="FriendInSight" then
				friends=c;
				agentSheet.addInput("FriendInSight.Count", friends.Count);
			elseif groupId=="EnemyInSight" then
				enemies=c;
				agentSheet.addInput("EnemyInSight.Count", enemies.Count);
			end			
		end
		
		local sampleIndex=Prog.sampleCount+1;
		Prog.samples[sampleIndex]={};
		Prog.samples[sampleIndex].inputs=agentSheet.getInputs();
		Prog.samples[sampleIndex].outputs=agentSheet.getOutputs();
		Prog.sampleCount=sampleIndex;
		
		--create a dataInterface of the input and outputs 
		if Prog.dataInterface == nil then
			Prog.dataInterface=agentSheet;
		end
	end
end

function Prog.getSampleCount()
	return Prog.sampleCount;
end	

function Prog.getSampleOutputs(index)
	return Prog.samples[index].outputs;
end

function Prog.getSampleInputs(index)
	return Prog.samples[index].inputs;
end

function Prog.getDataInterface()
	return Prog.dataInterface;
end

function Prog.getInputCount()
	return Prog.dataInterface.getInputCount();
end

function Prog.getOutputCount()
	return Prog.dataInterface.getOutputCount();
end

return Prog;



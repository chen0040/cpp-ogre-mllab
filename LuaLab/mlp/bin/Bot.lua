local Bot={};

Bot.actions={};
Bot.actions[GameAgentAction.ATTACK]=1;
Bot.actions[GameAgentAction.IDLE]=2;
Bot.actions[GameAgentAction.APPROACH]=3;
Bot.actions[GameAgentAction.WANDER]=4;
Bot.actions[GameAgentAction.ESCAPE]=5;

Bot.err_threshold=0.01;
Bot.max_epoches=1000000;

function Bot.initialize(agent)
	--agent:addEnemy("PreyBot");
	--agent:addEnemy("PredatorBot");
	agent:setWalkSpeed(40);
	agent:setSenseRange(250);
	agent:setLife(300);
	
	local agentId=agent:getAgentId();
	
	Bot[agentId]={};
	Bot[agentId].brain=Bot.createMLP(agent:getScriptClassPath());
end

function Bot.createMLP(scriptClassPath)
	local brain={};	
	
	brain=dofile(scriptClassPath .. "\\MLP.lua");
	brain.init(0.2);
	brain.addLayer(13); --input layer
	brain.addLayer(20); 
	brain.addLayer(5); --output layer	

	if fileExists(scriptClassPath .. "\\Saved.lua") then
		brain.load(scriptClassPath .. "\\Saved.lua");
	end
	
	return brain;
end

function Bot.getDataInput(record)
	local inputs={};
	
	inputs[1]=record:getSightedAttackerCount();
	inputs[2]=record:getSightedTargetCount();
	inputs[3]=record:getSightedAllyCount();
	inputs[4]=record:getLife();
	inputs[5]=record:getSenseRange();
	inputs[6]=record:getGun():getBulletCount();
	inputs[7]=record:getGun():getWeaponChargingRate();
	
	if record.currentTarget == nil then
		inputs[8]=0;
		inputs[9]=0;
		inputs[10]=0;
		inputs[11]=0;
		inputs[12]=0;
		inputs[13]=0;
	else
		inputs[8]=record:getCurrentTarget():getLife();
		inputs[9]=record:getCurrentTarget():getSenseRange();
		inputs[10]=record:getCurrentTarget():getCurrentAction();
		inputs[11]=record:getCurrentTarget():isAttacking(record);
		inputs[12]=record:getCurrentTarget():getGun():getBulletCount();
		inputs[13]=record:getCurrentTarget():getGun():getWeaponChargingRate();	
	end
	
	return inputs;
end

function Bot.getDataOutput(record)
	local outputs={};
	for index = 1, 5 do
		if Bot.actions[record:getCurrentAction()]==index then
			outputs[index]=1;
		else
			outputs[index]=0;
		end
	end
	
	return outputs;
end

function Bot.train(agent)
	local agentId=agent:getAgentId();
	local records=dofile(agent:getScriptClassPath() .. "\\data.lua");
	
	local brain=Bot[agentId].brain;
	local err=0;
	local maxIter=Bot.max_epoches / (# records);
	
	for iter = 1, maxIter do
		err=0;
		for recordIndex = 1, (# records) do
			local inputs=Bot.getDataInput(records[recordIndex]);
			local outputs=Bot.getDataOutput(records[recordIndex]);		
			
			brain.forwardProp(inputs);
			brain.backwardProp(outputs);
			err=err + brain.getError(outputs);
			
			
		end
		print2Console("error: " .. err);
	end
	
	brain.save("Saved.lua");
	
	print2Console("Training Completed with errors " .. err);
end

function Bot.getAgentInput(agent)
	local inputs={};
	
	inputs[1]=agent:getSightedAttackerCount();
	inputs[2]=agent:getSightedTargetCount();
	inputs[3]=agent:getSightedAllyCount();
	inputs[4]=agent:getLife();
	inputs[5]=agent:getSenseRange();
	inputs[6]=agent:getGun():getBulletCount();
	inputs[7]=agent:getGun():getWeaponChargingRate();
	
	local currentTarget=agent:getCurrentTarget();
	if currentTarget == nil then
		inputs[8]=0;
		inputs[9]=0;
		inputs[10]=0;
		inputs[11]=0;
		inputs[12]=0;
		inputs[13]=0;
	else
		inputs[8]=currentTarget:getLife();
		inputs[9]=currentTarget:getSenseRange();
		inputs[10]=currentTarget:getAction();
		inputs[11]=currentTarget:isAttacking(agent);
		inputs[12]=currentTarget:getGun():getBulletCount();
		inputs[13]=currentTarget:getGun():getWeaponChargingRate();	
	end
	
	return inputs;
end

function Bot.think(agent)
	local agentId=agent:getAgentId();
	local brain=Bot[agentId].brain;
	--apply inputs to the neural network
	local inputs=Bot.getAgentInput(agent);
	
	--compute outputs using neural network
	local outputs=brain.forwardProp(inputs);
	
	--convert neural network output into bot action
	local firingIndex=-1;
	local firingDegree=-1000;
	for i=1, 5 do
		if outputs[i] > firingDegree then
			firingDegree=outputs[i];
			
			firingIndex=i;
		end
	end
	
	if Bot.actions[GameAgentAction.ATTACK] == firingIndex then
		agent:attack();
	elseif Bot.actions[GameAgentAction.APPROACH] == firingIndex then
		agent:approach();
	elseif Bot.actions[GameAgentAction.ESCAPE] == firingIndex then
		agent:escape();
	elseif Bot.actions[GameAgentAction.WANDER] == firingIndex then
		agent:wander();
	elseif Bot.actions[GameAgentAction.IDLE] == firingIndex then
		agent:idle();
	end
end

return Bot;

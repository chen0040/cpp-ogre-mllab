local Bot={};

function Bot.initialize(agent)
	local agentId=agent:getAgentId();
	Bot[agentId]={};
	
	local PredatorBrainFactory=dofile(agent:getScriptClassPath() .. "\\PredatorBrain.lua");
	Bot[agentId].brain=PredatorBrainFactory.create(agent);
	--attack any type of bots
end

function Bot.think(agent)
	local agentId=agent:getAgentId();
	Bot[agentId].brain:think();
end

function Bot.train(agent)
	alert("Training not supported", "This bot does not have training algorithm embeded in it");
end

function Bot.uploadConfig(agent)
	alert("Method not implemented", "Method not implemented");
end

return Bot;


local Bot={};

function Bot.initialize(agent)
	local agentId=agent:getAgentId();
	Bot[agentId]={};
	Bot[agentId].agent=agent;
	--attack any type of bots
	
	agent:setWalkSpeed(40);
	agent:setLife(300); --a very long life so that the player can capture as many data as possible
	agent:setSenseRange(250);
end

function Bot.think(agent)
	local agentId=agent:getAgentId();
	Bot[agentId].agent:idle(); --make the agent do nothing
end

function Bot.train(agent)
	alert("Training not supported", "This bot does not have training algorithm embeded in it");
end

function Bot.uploadConfig(agent)
	alert("Method not implemented", "Method not implemented");
end

return Bot;


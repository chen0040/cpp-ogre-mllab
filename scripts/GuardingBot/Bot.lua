local Bot={};

function Bot.initialize(agent)
	--attack any type of bots
	local agentId=agent:getAgentId();
	Bot[agentId]={};
	Bot[agentId].recordedTime=getTime(); --time in milliseconds
	Bot[agentId].elapsedTime=0;
	--dofile(agent:getScriptClassPath() .. "\\Stupid.lua");
end

function Bot.think(agent)
	local agentId=agent:getAgentId();
	local currentTime=getTime();
	local timeElapsed=currentTime - Bot[agentId].recordedTime;
	Bot[agentId].elapsedTime=Bot[agentId].elapsedTime + timeElapsed;
	
	if Bot[agentId].elapsedTime >= 30000 then
		if agent:getRandomCandidateTarget() ~= nil then
			agent:targetRandom();
			agent:attack();
		else
			agent:idle();
		end
	
		Bot[agentId].elapsedTime=0;
	end
end

function Bot.train(agent)
	alert("Training not supported", "This bot does not have training algorithm embeded in it");
end

function Bot.uploadConfig(agent)
	alert("Method not implemented", "Method not implemented");
end

return Bot;


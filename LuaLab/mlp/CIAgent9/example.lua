dofile("GameUtil.lua");
dofile("GameWorld.lua");
GameAgentFactory=dofile("GameAgent.lua");

--train to obtain Saved.lua file;
local dummy=GameAgentFactory.create("dummy agent");
initializeAgent(dummy);
trainAgent(dummy);

--test accuracy of the training
local records=dofile("data.lua");

for recordIndex = 1, (# records) do
	local agent=GameAgentFactory.create(records[recordIndex]:getAgentId() .. "X");
	initializeAgent(agent);
	processAgent(agent);
	print("recorded: " .. records[recordIndex]:getCurrentAction());
	print("predict: " .. agent:getCurrentAction());
end

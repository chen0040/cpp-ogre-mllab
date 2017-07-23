local tData=dofile(".\\training.data.lua");
--tData.print();
local da={};
for i=1, tData.getActionSize() do
	da[i]=1;
end
local dr={};
dr[1]=1;
dr[2]=0;

local rewardThreshold=0.5;

local FALCONFactory=dofile(".\\FALCON.lua");
local network=FALCONFactory.create(".", tData.getStateSize(), tData.getActionSize());

local predictionAccuracy=0;
local periodicPredictionAccuracy=0;
for i=1, tData.size() do
	network:setStates(tData[i].states);
	network:setActions(da);
	network:setRewards(dr);
	
	local actions=network:predict();
	
	local J=-1;
	local Amax=0;
	for j=1, tData.getActionSize() do
		if Amax < actions[j] then
			Amax=actions[j];
			J=j;
		end
	end
	for j=1, tData.getActionSize() do
		if j==J then
			actions[j]=1;
		else
			actions[j]=0;
		end
	end
	
	local rewards={};
	if J == tData[i].action+1 then
		rewards[1]=1; --r
		print("correct prediction!");
		predictionAccuracy=predictionAccuracy+1;
		periodicPredictionAccuracy=periodicPredictionAccuracy+1;
	else
		rewards[1]=0;
	end
	rewards[2]=1-rewards[1]; --complement r
	
	if i % 10 == 0 then
		print("periodic prediction accuracy: " .. (periodicPredictionAccuracy / 10 * 100) .. "%");
		periodicPredictionAccuracy=0;
	end
	
	--penalty, reverse actions and rewards
	if rewards[1] < rewardThreshold then
		for j=1, tData.getActionSize() do
			actions[j]=1-actions[j];
		end
		rewards[1]=1-rewards[1];
		rewards[2]=1-rewards[2];
	end
	
	network:setStates(tData[i].states);
	network:setActions(actions);
	network:setRewards(rewards);
	
	network:learn();
	
	-- for j=1, tData.getActionSize() do
		-- print("simulations[" .. i .. "].actions[" .. j .. "] = " .. actions[j]);
	-- end
	--print("network.category_node_count = " .. network:getCategoryNodeCount());
end

predictionAccuracy=predictionAccuracy / tData.size() * 100;
print("prediction accuracy: " .. predictionAccuracy .. "%");
print("category node count: " .. network:getCategoryNodeCount());


local FALCON={};
FALCON.__index=FALCON;

function FALCON.create(_scriptClassPath, _sensoryFieldSize, _motorFieldSize)
	local ann = {};             -- our new object
	setmetatable(ann, FALCON);  -- make FALCON handle lookup
	
	ann.scriptClassPath=_scriptClassPath;
	ann.sensoryFieldSize=_sensoryFieldSize;
	ann.motorFieldSize=_motorFieldSize;
	ann.feedbackFieldSize=2;
	
	local sensoryFieldFactory=dofile(_scriptClassPath .. "\\SensoryField.lua");
	ann.sensoryField=sensoryFieldFactory.create(_sensoryFieldSize);
	
	local motorFieldFactory=dofile(_scriptClassPath .. "\\MotorField.lua");
	ann.motorField=motorFieldFactory.create(_motorFieldSize);
	
	local feedbackFieldFactory=dofile(_scriptClassPath .. "\\FeedbackField.lua");
	ann.feedbackField=feedbackFieldFactory.create();
	
	local categoryFieldFactory=dofile(_scriptClassPath .. "\\CategoryField.lua");
	ann.categoryField=categoryFieldFactory.create(_scriptClassPath, _sensoryFieldSize, _motorFieldSize);
	
	return ann;
end

function FALCON:loadConfig(_filename)
	local configFactory=dofile(_filename);
	local config=configFactory.create();
	
	--this method implement configuration of each of the fields' parameters
end

function FALCON:getSensoryField()
	return self.sensoryField;
end

function FALCON:getMotorField()
	return self.motorField;
end

function FALCON:getFeedbackField()
	return self.feedbackField;
end

function FALCON:getSensoryFieldSize()
	return self.sensoryFieldSize;
end

function FALCON:getMotorFieldSize()
	return self.motorFieldSize;
end

function FALCON:computeChoiceFunction(_index)
	local categoryNode=self.categoryField:getNode(_index);
	local sensoryField=self.sensoryField;
	local motorField=self.motorField;
	local feedbackField=self.feedbackField;
	
	--T is the choice function for the (_index) th node in the category field
	local T=0; 
	
	--for sensory field
	local t1=0;
	local t2=0;
	for i=1, self.sensoryFieldSize do
		t1=t1 + self:getMinimum(sensoryField:getState(i), categoryNode:getSensoryWeight(i));
		t2=t2 + categoryNode:getSensoryWeight(i);
	end
	T = T + sensoryField:getContributionParameter() * t1 / (sensoryField:getChoiceParameter() + t2);
	
	--for motor field
	t1=0;
	t2=0;
	for i=1, self.motorFieldSize do
		t1=t1 + self:getMinimum(motorField:getAction(i), categoryNode:getMotorWeight(i));
		t2=t2 + categoryNode:getMotorWeight(i);
	end
	T = T + motorField:getContributionParameter() * t1 / (motorField:getChoiceParameter() + t2);
	
	--for feedback field
	t1=0;
	t2=0;
	for i=1, 2 do
		t1=t1 + self:getMinimum(feedbackField:getReward(i), categoryNode:getFeedbackWeight(i));
		t2=t2 + categoryNode:getFeedbackWeight(i);
	end
	T = T + feedbackField:getContributionParameter() * t1 / (feedbackField:getChoiceParameter() + t2);
	
	return T;
end

function FALCON:computeMotorMatchFunction(_index)
	local categoryNode=self.categoryField:getNode(_index);
	local motorField=self.motorField;
	
	--for motor field
	local m1=0;
	local m2=0;
	for i=1, self.motorFieldSize do
		m1=m1 + self:getMinimum(motorField:getAction(i), categoryNode:getMotorWeight(i));
		m2=m2 + motorField:getAction(i);
	end
	
	return	m1 / m2;
end

function FALCON:computeFeedbackMatchFunction(_index)
	local categoryNode=self.categoryField:getNode(_index);
	local feedbackField=self.feedbackField;
	
	--for feedback field
	local m1=0;
	local m2=0;
	for i=1, 2 do
		m1=m1 + self:getMinimum(feedbackField:getReward(i), categoryNode:getFeedbackWeight(i));
		m2=m2 + feedbackField:getReward(i);
	end
	return m1 / m2;
end

function FALCON:computeSensoryMatchFunction(_index)
	local categoryNode=self.categoryField:getNode(_index);
	local sensoryField=self.sensoryField;
	
	--for sensory field
	local m1=0;
	local m2=0;
	for i=1, self.sensoryFieldSize do
		m1=m1 + self:getMinimum(sensoryField:getState(i), categoryNode:getSensoryWeight(i));
		m2=m2 + sensoryField:getState(i);
	end
	return m1 / m2;
end

function FALCON:setStates(states)
	local sensoryField=self.sensoryField;
	for i=1, self.sensoryFieldSize do
		sensoryField:setState(i, states[i]);
	end
end

function FALCON:setActions(actions)
	local motorField=self.motorField;
	for i=1, self.motorFieldSize do
		motorField:setAction(i, actions[i]);
	end
end

function FALCON:setRewards(rewards)
	local feedbackField=self.feedbackField;
	for i=1, 2 do
		feedbackField:setReward(i, rewards[i]);
	end
end

function FALCON:predict()
	local sensoryField=self.sensoryField;
	local motorField=self.motorField;
	local feedbackField=self.feedbackField;
	local categoryField=self.categoryField;
	local categoryFieldSize=categoryField:size();
	
	local Ts={};
	local TJ=1;
	local Tmax=0;
	for i=1, categoryFieldSize do
		Ts[i]=self:computeChoiceFunction(i);
		--print("Ts[" .. i .. "] = " .. Ts[i]);
		if Tmax < Ts[i] then
			TJ=i;
			Tmax=Ts[i];
		end
	end
	
	--print("TJ = " .. TJ);
	
	local winnerNode=categoryField:getNode(TJ);
	
	--for sensory field
	-- for i = 1, self.sensoryFieldSize do
		-- sensoryField:setState(i, self:getMinimum(sensoryField:getState(i), winnerNode:getSensoryWeight(i)));
	-- end
	
	local actions={};
	--for motor field
	for i = 1, self.motorFieldSize do
		actions[i]=self:getMinimum(motorField:getAction(i), winnerNode:getMotorWeight(i));
	end
	
	return actions;
	
	--for feedback field
	-- for i=1, 2 do
		-- feedbackField:setReward(i, self:getMinimum(feedbackField:getReward(i), winnerNode:getFeedbackWeight(i)));
	-- end
end

function FALCON:learn()
	local sensoryField=self.sensoryField;
	local motorField=self.motorField;
	local feedbackField=self.feedbackField;
	local categoryField=self.categoryField;
	local categoryFieldSize=categoryField:size();
	
	local Ts={};
	for i=1, categoryFieldSize do
		Ts[i]=self:computeChoiceFunction(i);
		--print("Ts[" .. i .. "] = " .. Ts[i]);
	end
	
	
	
	local J=-1;
	sensoryField:setVigilence(sensoryField:getBaselineVigilenceParameter());
	
	local reset=true;
	local perfectMismatch=false;
	while reset==true and perfectMismatch==false do
		reset=false;
		J=-1;
		local Tmax=0;
		for i=1, categoryFieldSize do
			if Tmax < Ts[i] then
				J=i;
				Tmax=Ts[i];
			end
		end
		--print("Jc = " .. J);
		
		local m1J=self:computeSensoryMatchFunction(J);
		local m2J=self:computeMotorMatchFunction(J);
		local m3J=self:computeFeedbackMatchFunction(J);
		
		
		if m1J < sensoryField:getVigilence() or m2J < motorField:getVigilence() or m3J < feedbackField:getVigilence() then
			if m1J == 1 then
				perfectMismatch=true;
			else
				Ts[J]=-1;
				reset=true;
				if sensoryField:getVigilence() < m1J then
					sensoryField:setVigilence(self:getMinimum(m1J+0.001, 1));
				end
			end
		end
	end

	local nodeJ=categoryField:getNode(J);
	if perfectMismatch then --if perfect mismatch, do overwrite
		for i=1, self.sensoryFieldSize do
			nodeJ:setSensoryWeight(i, sensoryField:getState(i));
		end
	
		for i=1, self.motorFieldSize do
			nodeJ:setMotorWeight(i, motorField:getAction(i));
		end
		
		for i=1, self.feedbackFieldSize do
			nodeJ:setFeedbackWeight(i, feedbackField:getReward(i));
		end
	else --other wise, learn		
		local newWeight=0;
		local oldWeight=0;
		local learningRate=0;
		
		learningRate=sensoryField:getLearningRate();
		for i=1, self.sensoryFieldSize do
			oldWeight=nodeJ:getSensoryWeight(i);
			newWeight=(1-learningRate) * oldWeight + learningRate * self:getMinimum(sensoryField:getState(i), oldWeight);
			--print(newWeight);
			nodeJ:setSensoryWeight(i, newWeight);
		end
		
		learningRate=motorField:getLearningRate();
		for i=1, self.motorFieldSize do
			oldWeight=nodeJ:getMotorWeight(i);
			newWeight=(1-learningRate) * oldWeight + learningRate * self:getMinimum(motorField:getAction(i), oldWeight);
			--print(newWeight);
			nodeJ:setMotorWeight(i, newWeight);
		end
		
		learningRate=feedbackField:getLearningRate();
		for i=1, self.feedbackFieldSize do
			oldWeight=nodeJ:getFeedbackWeight(i);
			newWeight=(1-learningRate) * oldWeight + learningRate * self:getMinimum(feedbackField:getReward(i), oldWeight);
			--print(newWeight);
			nodeJ:setFeedbackWeight(i, newWeight);
		end
		
		--if J node is uncommitted, then after learning, it becomes committed and a new uncommitted node is inserted into the category field
		if nodeJ:isCommitted()==false then
			nodeJ:commit();
			categoryField:createNode();
		end
	end
end

function FALCON:getCategoryNodeCount()
	return self.categoryField:size();
end

function FALCON:getMinimum(i, j)
	if i < j then
		return i;
	else
		return j;
	end
end

return FALCON;








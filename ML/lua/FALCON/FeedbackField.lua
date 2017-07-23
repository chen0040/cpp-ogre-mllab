local FeedbackField={};
FeedbackField.__index=FeedbackField;

function FeedbackField.create()
	local field = {};             -- our new object
	setmetatable(field, FeedbackField);  -- make FeedbackField handle lookup
	
	field.size=2;
	field.rewards={};
	
	field.rewards[1]=1;
	field.rewards[2]=0;

	
	field.choiceParameter=0.1;
	field.learningRate=1.0;
	field.contributionParameter=0;
	field.baselineVigilenceParameter=0.5;
	field.vigilence=field.baselineVigilenceParameter;

	return field;
end

function FeedbackField:size()
	return self.size;
end

function FeedbackField:getReward(index)
	return self.rewards[index];
end

function FeedbackField:setReward(index, value)
	self.rewards[index]=value;
end

function FeedbackField:setChoiceParameter(_parameter)
	self.choiceParameter=_parameter;
end

function FeedbackField:getChoiceParameter()
	return self.choiceParameter;
end

function FeedbackField:setContributionParameter(_parameter)
	self.contributionParameter=_parameter;
end

function FeedbackField:getContributionParameter()
	return self.contributionParameter;
end

function FeedbackField:setBaselineVigilenceParameter(_parameter)
	self.baselineVigilenceParameter=_parameter;
end

function FeedbackField:getBaselineVigilenceParameter()
	return self.baselineVigilenceParameter;
end

function FeedbackField:setVigilence(_parameter)
	self.vigilence=_parameter;
end

function FeedbackField:getVigilence()
	return self.vigilence;
end

function FeedbackField:setLearningRate(_rate)
	self.learningRate=_rate;
end

function FeedbackField:getLearningRate()
	return self.learningRate;
end

return FeedbackField;
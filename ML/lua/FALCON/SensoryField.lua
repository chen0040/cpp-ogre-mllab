local SensoryField={};
SensoryField.__index=SensoryField;

function SensoryField.create(_size)
	local field = {};             -- our new object
	setmetatable(field, SensoryField);  -- make SensoryField handle lookup
	
	field.size=_size;
	field.states={};
	for i=1, _size do
		field.states[i]=1;
	end
	
	field.choiceParameter=0.1;
	field.learningRate=1.0;
	field.contributionParameter=0.5;
	field.baselineVigilenceParameter=0.2;
	field.vigilence=field.baselineVigilenceParameter;

	return field;
end

function SensoryField:size()
	return self.size;
end

function SensoryField:setChoiceParameter(_parameter)
	self.choiceParameter=_parameter;
end

function SensoryField:getChoiceParameter()
	return self.choiceParameter;
end

function SensoryField:setContributionParameter(_parameter)
	self.contributionParameter=_parameter;
end

function SensoryField:getContributionParameter()
	return self.contributionParameter;
end

function SensoryField:setBaselineVigilenceParameter(_parameter)
	self.baselineVigilenceParameter=_parameter;
end

function SensoryField:getBaselineVigilenceParameter()
	return self.baselineVigilenceParameter;
end

function SensoryField:setVigilence(_parameter)
	self.vigilence=_parameter;
end

function SensoryField:getVigilence()
	return self.vigilence;
end

function SensoryField:setLearningRate(_rate)
	self.learningRate=_rate;
end

function SensoryField:getLearningRate()
	return self.learningRate;
end

function SensoryField:getState(index)
	return self.states[index];
end

function SensoryField:setState(index, value)
	self.states[index]=value;
end

return SensoryField;

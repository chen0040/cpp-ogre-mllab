local MotorField={};
MotorField.__index=MotorField;

function MotorField.create(_size)
	local field = {};             -- our new object
	setmetatable(field, MotorField);  -- make MotorField handle lookup
	
	field.size=_size;
	field.actions={};
	for i=1, _size do
		field.actions[i]=1;
	end
	
	field.choiceParameter=0.1;
	field.learningRate=1.0;
	field.contributionParameter=0.5;
	field.baselineVigilenceParameter=0.2;
	field.vigilence=field.baselineVigilenceParameter;

	return field;
end

function MotorField:size()
	return self.size;
end

function MotorField:getAction(index)
	return self.actions[index];
end

function MotorField:setAction(index, value)
	self.actions[index]=value;
end

function MotorField:setChoiceParameter(_parameter)
	self.choiceParameter=_parameter;
end

function MotorField:getChoiceParameter()
	return self.choiceParameter;
end

function MotorField:setContributionParameter(_parameter)
	self.contributionParameter=_parameter;
end

function MotorField:getContributionParameter()
	return self.contributionParameter;
end

function MotorField:setBaselineVigilenceParameter(_parameter)
	self.baselineVigilenceParameter=_parameter;
end

function MotorField:getBaselineVigilenceParameter()
	return self.baselineVigilenceParameter;
end

function MotorField:setVigilence(_parameter)
	self.vigilence=_parameter;
end

function MotorField:getVigilence()
	return self.vigilence;
end

function MotorField:setLearningRate(_rate)
	self.learningRate=_rate;
end

function MotorField:getLearningRate()
	return self.learningRate;
end

return MotorField;
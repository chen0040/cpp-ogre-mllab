local CategoryNode={};
CategoryNode.__index=CategoryNode;

function CategoryNode.create(_sensoryFieldSize, _motorFieldSize)
	local node = {};             
	setmetatable(node, CategoryNode);  
	
	--initialize to uncommitted node which contains all 1s
	node.sensoryFieldSize=_sensoryFieldSize;
	node.sensoryFieldWeights={};
	for i=1, _sensoryFieldSize do
		node.sensoryFieldWeights[i]=1;
	end
	
	node.motorFieldSize=_motorFieldSize;
	node.motorFieldWeights={};
	for i=1, _motorFieldSize do
		node.motorFieldWeights[i]=1;
	end
	
	node.feedbackFieldSize=2;
	node.feedbackFieldWeights={};
	for i=1, 2 do
		node.feedbackFieldWeights[i]=1;
	end
	
	node.committed=false;

	return node;
end

function CategoryNode:isCommitted()
	return self.committed;
end

function CategoryNode:commit()
	self.committed=true;
end

function CategoryNode:getMotorFieldSize()
	return self.motorFieldSize;
end

function CategoryNode:getSensoryFieldSize()
	return self.sensoryFieldSize;
end

function CategoryNode:getFeedbackFieldSize()
	return self.feedbackFieldSize;
end

function CategoryNode:getMotorWeight(_index)
	return self.motorFieldWeights[_index];
end

function CategoryNode:setMotorWeight(_index, _value)
	self.motorFieldWeights[_index]=_value;
end

function CategoryNode:getSensoryWeight(_index)
	return self.sensoryFieldWeights[_index];
end

function CategoryNode:setSensoryWeight(_index, _value)
	self.sensoryFieldWeights[_index]=_value;
end

function CategoryNode:getFeedbackWeight(_index)
	return self.feedbackFieldWeights[_index];
end

function CategoryNode:setFeedbackWeight(_index, _value)
	self.feedbackFieldWeights[_index]=_value;
end

return CategoryNode;
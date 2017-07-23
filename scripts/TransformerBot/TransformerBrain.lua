local TransformerBrain={};
TransformerBrain.__index = TransformerBrain;

function TransformerBrain.create(agent)
	local brain = {};             -- our new object
	setmetatable(brain,TransformerBrain);  -- make GameAgent handle lookup
	
	brain.owner=agent;
	brain.owner:setLife(100);
	brain.owner:setSenseRange(200);
	brain.owner:setWalkSpeed(30);
	brain.recordedTime=getTime(); --time in milliseconds
	brain.elapsedTime=0;
	
	return brain;
end

function TransformerBrain:think()
	local target=self.owner:getCurrentTarget();
	local currentTime=getTime();
	local timeElapsed=currentTime - self.recordedTime;
	self.elapsedTime=self.elapsedTime + timeElapsed;
	
	if target ~= nil then
		local distance=self.owner:getDistance(target);
		if distance > 120 or (self.owner:getCurrentAction()==GameAgentAction.APPROACH and distance > 70) then
			self.owner:approach();
		else
			self.owner:attack();
		end
		if self.elapsedTime >= 10000 then
			self.owner:changeModel("jet");
			self.elapsedTime=0;
		end
	else
		self.owner:idle();
		self.owner:changeModel("robot");
	end
end

return TransformerBrain;


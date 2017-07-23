local PredatorBrain={};
PredatorBrain.__index = PredatorBrain;

function PredatorBrain.create(agent)
	local brain = {};             -- our new object
	setmetatable(brain,PredatorBrain);  -- make GameAgent handle lookup
	
	brain.owner=agent;
	brain.owner:setLife(100);
	brain.owner:setSenseRange(200);
	brain.owner:setWalkSpeed(30);
	
	return brain;
end

function PredatorBrain:think()
	local target=self.owner:getCurrentTarget();
	
	if target ~= nil then
		local distance=self.owner:getDistance(target);
		if distance > 120 or (self.owner:getCurrentAction()==GameAgentAction.APPROACH and distance > 70) then
			self.owner:approach();
		else
			self.owner:attack();
		end
	else
		self.owner:idle();
	end
end

return PredatorBrain;


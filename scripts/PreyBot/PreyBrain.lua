local PreyBrain={};
PreyBrain.__index = PreyBrain;

function PreyBrain.create(_agent)
	local brain = {};             -- our new object
	setmetatable(brain,PreyBrain);  -- make GameAgent handle lookup

	brain.agent=_agent;
	brain.agent:setLife(1000);
	brain.agent:setWalkSpeed(15);
	
	return brain;
end

function PreyBrain:think()
	if self.agent:getCurrentTarget() ~= nil then
		if self.agent:getLife() > 100 then
			self.agent:escape();
		else
			self.agent:slump();
		end
	else
		self.agent:idle();
	end
end

return PreyBrain;

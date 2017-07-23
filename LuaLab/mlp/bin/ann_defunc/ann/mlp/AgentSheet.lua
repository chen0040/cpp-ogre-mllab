local AgentSheet={};

AgentSheet.outputs={};
AgentSheet.outputs[1]={};
AgentSheet.outputs[1].value=0;
AgentSheet.outputs[1].name="attack enemy";

AgentSheet.outputs[2]={};
AgentSheet.outputs[2].value=0;
AgentSheet.outputs[2].name="approach enemy";

AgentSheet.outputs[3]={};
AgentSheet.outputs[3].value=0;
AgentSheet.outputs[3].name="run away from enemy";

AgentSheet.outputs[4]={};
AgentSheet.outputs[4].value=0;
AgentSheet.outputs[4].name="wander";

AgentSheet.outputs[5]={};
AgentSheet.outputs[5].value=0;
AgentSheet.outputs[5].name="idle";

AgentSheet.outputs[6]={};
AgentSheet.outputs[6].value=0;
AgentSheet.outputs[6].name="dead";

AgentSheet.inputs={};
AgentSheet.inputCount=0;

function AgentSheet.setOutput(txAction)
	for i=1, 6 do
		if txAction == AgentSheet.outputs[i].name then
			AgentSheet.outputs[i].value=1;
		else
			AgentSheet.outputs[i].value=0;
		end
	end
end

function AgentSheet.addInput(inputKey, inputValue)
	local inputIndex=AgentSheet.inputCount+1;
	AgentSheet.inputs[inputIndex]={};
	AgentSheet.inputs[inputIndex].name=inputKey;
	if inputValue==true then 
		inputValue=1;
	else 
		inputValue=0; 
	end
	AgentSheet.inputs[inputIndex].value=inputValue;
	AgentSheet.inputCount=inputIndex;
end

function AgentSheet.getOutputs()
	local outputs={};
	for i=1, 6 do
		outputs[i]=AgentSheet.outputs[i].value;
	end
	return outputs;
end

function AgentSheet.getInputs()
	local inputs={};
	for i = 1, AgentSheet.inputCount do
		inputs[i]=AgentSheet.inputs[i].value;
	end
	return inputs;
end

function AgentSheet.getInputName(index)
	return AgentSheet.inputs[index].name;
end

function AgentSheet.getOutputName(index)
	return AgentSheet.outputs[index].name;
end

function AgentSheet.getInputCount()
	return AgentSheet.inputCount;
end

function AgentSheet.getOutputCount()
	return 6;
end

function AgentSheet.getOutputAPI(index)
	local outputName=AgentSheet.getOutputName(index);
	if outputName=="attack enemy" then
		return "attackEnemy()";
	elseif outputName=="approach enemy" then
		return "approachEnemy()";
	elseif outputName=="run away from enemy" then
		return "escapeEnemy()";
	elseif outputName=="wander" then
		return "wander()";
	elseif outputName=="idle" then
		return "idle()";
	elseif outputName=="dead" then
		return "doNothing()";
	end
	return "";
end

function AgentSheet.getInputAPI(index)
	local inputName=AgentSheet.getInputName(index);
	if inputName=="FriendInSight.Count" then
		return "countFriendsInSight()";
	elseif inputName=="EnemyInSight.Count" then
		return "countEnemiesInSight()";
	elseif inputName=="Dist2Enemy" then
		return "getDistanceToEnemy()";
	elseif inputName=="Armor" then
		return "getArmor()";
	elseif inputName=="Life" then
		return "getLife()";
	elseif inputName=="Score" then
		return "getScore()";
	elseif inputName=="SenseRange" then
		return "getSenseRange()";
	elseif inputName=="LockOnClosestEnemy" then
		return "isLockOnClosestEnemyEnabled()";
	elseif inputName=="WeaponImpact" then
		return "getWeaponImpact()";
	elseif inputName=="WeaponPenetration" then
		return "getWeaponPenetration()";
	elseif inputName=="WeaponSpeed" then
		return "getGun():getWeaponSpeed()";
	elseif inputName=="WeaponDelay" then
		return "getFiringDelay()";
	elseif inputName=="BulletCount" then
		return "getGun():getBulletCount()";
	elseif inputName=="WeaponChargingRate" then
		return "getGun():getWeaponChargingRate()";
	end
end

return AgentSheet;




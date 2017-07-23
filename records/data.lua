--Year: 2009 Month:10 Day: 31 Hour: 22 Minute: 40 Second: 44
local userbot={};
local recordIndex=0;
local GameAgentFactory=dofile(getDefaultScriptPath() .. "\\GameAgent.lua");

--recordIndex: 1
recordIndex=recordIndex+1;
userbot[recordIndex]=GameAgentFactory.create("UserBot");
userbot[recordIndex]:setTargetAttackable(0);
userbot[recordIndex]:setSightedAttackerCount(0);
userbot[recordIndex]:setTargetRelativeDistance(1.000000);
userbot[recordIndex]:setTargetRelativeLife(1);
userbot[recordIndex]:getGun():setBulletCount(20);
userbot[recordIndex]:setLife(1000);
userbot[recordIndex]:setScore(0.000000);
userbot[recordIndex]:setCurrentAction(2);

--recordIndex: 2
recordIndex=recordIndex+1;
userbot[recordIndex]=GameAgentFactory.create("UserBot");
userbot[recordIndex]:setTargetAttackable(1);
userbot[recordIndex]:setSightedAttackerCount(0);
userbot[recordIndex]:setTargetRelativeDistance(0.606732);
userbot[recordIndex]:setTargetRelativeLife(0);
userbot[recordIndex]:getGun():setBulletCount(16);
userbot[recordIndex]:setLife(1000);
userbot[recordIndex]:setScore(59.999908);
userbot[recordIndex]:setCurrentAction(0);

--recordIndex: 3
recordIndex=recordIndex+1;
userbot[recordIndex]=GameAgentFactory.create("UserBot");
userbot[recordIndex]:setTargetAttackable(1);
userbot[recordIndex]:setSightedAttackerCount(0);
userbot[recordIndex]:setTargetRelativeDistance(0.978025);
userbot[recordIndex]:setTargetRelativeLife(0);
userbot[recordIndex]:getGun():setBulletCount(11);
userbot[recordIndex]:setLife(1000);
userbot[recordIndex]:setScore(159.999908);
userbot[recordIndex]:setCurrentAction(4);

--recordIndex: 4
recordIndex=recordIndex+1;
userbot[recordIndex]=GameAgentFactory.create("UserBot");
userbot[recordIndex]:setTargetAttackable(0);
userbot[recordIndex]:setSightedAttackerCount(0);
userbot[recordIndex]:setTargetRelativeDistance(1.000000);
userbot[recordIndex]:setTargetRelativeLife(0);
userbot[recordIndex]:getGun():setBulletCount(12);
userbot[recordIndex]:setLife(1000);
userbot[recordIndex]:setScore(159.999908);
userbot[recordIndex]:setCurrentAction(3);

--recordIndex: 5
recordIndex=recordIndex+1;
userbot[recordIndex]=GameAgentFactory.create("UserBot");
userbot[recordIndex]:setTargetAttackable(0);
userbot[recordIndex]:setSightedAttackerCount(0);
userbot[recordIndex]:setTargetRelativeDistance(1.000000);
userbot[recordIndex]:setTargetRelativeLife(0);
userbot[recordIndex]:getGun():setBulletCount(12);
userbot[recordIndex]:setLife(1000);
userbot[recordIndex]:setScore(159.999908);
userbot[recordIndex]:setCurrentAction(0);

--recordIndex: 6
recordIndex=recordIndex+1;
userbot[recordIndex]=GameAgentFactory.create("UserBot");
userbot[recordIndex]:setTargetAttackable(0);
userbot[recordIndex]:setSightedAttackerCount(0);
userbot[recordIndex]:setTargetRelativeDistance(1.000000);
userbot[recordIndex]:setTargetRelativeLife(0);
userbot[recordIndex]:getGun():setBulletCount(12);
userbot[recordIndex]:setLife(1000);
userbot[recordIndex]:setScore(159.999908);
userbot[recordIndex]:setCurrentAction(2);

--recordIndex: 7
recordIndex=recordIndex+1;
userbot[recordIndex]=GameAgentFactory.create("UserBot");
userbot[recordIndex]:setTargetAttackable(0);
userbot[recordIndex]:setSightedAttackerCount(0);
userbot[recordIndex]:setTargetRelativeDistance(1.000000);
userbot[recordIndex]:setTargetRelativeLife(0);
userbot[recordIndex]:getGun():setBulletCount(12);
userbot[recordIndex]:setLife(1000);
userbot[recordIndex]:setScore(159.999908);
userbot[recordIndex]:setCurrentAction(4);

--recordIndex: 8
recordIndex=recordIndex+1;
userbot[recordIndex]=GameAgentFactory.create("UserBot");
userbot[recordIndex]:setTargetAttackable(0);
userbot[recordIndex]:setSightedAttackerCount(0);
userbot[recordIndex]:setTargetRelativeDistance(1.000000);
userbot[recordIndex]:setTargetRelativeLife(0);
userbot[recordIndex]:getGun():setBulletCount(12);
userbot[recordIndex]:setLife(1000);
userbot[recordIndex]:setScore(159.999908);
userbot[recordIndex]:setCurrentAction(1);

--recordIndex: 9
recordIndex=recordIndex+1;
userbot[recordIndex]=GameAgentFactory.create("UserBot");
userbot[recordIndex]:setTargetAttackable(1);
userbot[recordIndex]:setSightedAttackerCount(0);
userbot[recordIndex]:setTargetRelativeDistance(0.304993);
userbot[recordIndex]:setTargetRelativeLife(0);
userbot[recordIndex]:getGun():setBulletCount(19);
userbot[recordIndex]:setLife(1000000000);
userbot[recordIndex]:setScore(19.100000);
userbot[recordIndex]:setCurrentAction(0);

--recordIndex: 10
recordIndex=recordIndex+1;
userbot[recordIndex]=GameAgentFactory.create("UserBot");
userbot[recordIndex]:setTargetAttackable(1);
userbot[recordIndex]:setSightedAttackerCount(0);
userbot[recordIndex]:setTargetRelativeDistance(0.110840);
userbot[recordIndex]:setTargetRelativeLife(0);
userbot[recordIndex]:getGun():setBulletCount(19);
userbot[recordIndex]:setLife(1000000000);
userbot[recordIndex]:setScore(19.100000);
userbot[recordIndex]:setCurrentAction(0);

return userbot;

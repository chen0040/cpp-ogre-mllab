--Year: 2009 Month:07 Day: 23 Hour: 10 Minute: 29 Second: 03
local LuaRecords={};
local recordIndex=0;
local GameAgentFactory=dofile(getDefaultScriptPath() .. "\\GameAgent.lua");

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(0);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(1);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent1");
LuaRecords[recordIndex]:getCurrentTarget():setLife(1000);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(19);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(19);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(19);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(17);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(17);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent7");
LuaRecords[recordIndex]:getCurrentTarget():setLife(89);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(16);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(949);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(89);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(16);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(949);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent5");
LuaRecords[recordIndex]:getCurrentTarget():setLife(89);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(949);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent5");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(89);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(949);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent7");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(949);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(949);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent7");
LuaRecords[recordIndex]:getCurrentTarget():setLife(29);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(929);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(29);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(929);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent7");
LuaRecords[recordIndex]:getCurrentTarget():setLife(9);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(929);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(929);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent8");
LuaRecords[recordIndex]:getCurrentTarget():setLife(9);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(909);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent8");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(909);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent5");
LuaRecords[recordIndex]:getCurrentTarget():setLife(9);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent5");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(849);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(849);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(809);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(809);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(18);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(29);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(29);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(29);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(29);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent9");
LuaRecords[recordIndex]:getCurrentTarget():setLife(0);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(89);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(89);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(89);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(89);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(89);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(89);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(89);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(89);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(18);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(9);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(18);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(18);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(18);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(18);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(19);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(19);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(19);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(3);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(19);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(3);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(19);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(4);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(3);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(20);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(19);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(249);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(229);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(229);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(229);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(209);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(209);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(209);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(209);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(209);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(209);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(209);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(209);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(209);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(209);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(209);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(209);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(189);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(189);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(189);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(169);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(169);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(149);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(149);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(149);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(149);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(149);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(149);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(149);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(149);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(149);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(149);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(12);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(149);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(149);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(149);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(149);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(149);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(149);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(149);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(149);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(109);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(109);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(89);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(89);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(89);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(89);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(3);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(3);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent0");
LuaRecords[recordIndex]:getCurrentTarget():setLife(9);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent0");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(2);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(509);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(509);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(509);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(509);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(509);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(509);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(509);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(509);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(509);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(509);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(509);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(509);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(509);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(509);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(18);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(509);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(509);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(16);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(489);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(489);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(489);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(489);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(449);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(449);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(449);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(449);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(449);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(449);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(449);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(449);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(449);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(449);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(449);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(449);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(409);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(409);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(409);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(409);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(12);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(409);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(409);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(12);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(409);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(409);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(409);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(409);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(409);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(409);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(409);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(409);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(409);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(409);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(11);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(389);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(389);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(389);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(389);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(11);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(369);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(11);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(369);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(12);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(369);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(12);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(369);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(12);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(369);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(12);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent1");
LuaRecords[recordIndex]:getCurrentTarget():setLife(349);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(12);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent1");
LuaRecords[recordIndex]:getCurrentTarget():setLife(309);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(309);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent1");
LuaRecords[recordIndex]:getCurrentTarget():setLife(269);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(269);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent1");
LuaRecords[recordIndex]:getCurrentTarget():setLife(249);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent1");
LuaRecords[recordIndex]:getCurrentTarget():setLife(209);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(209);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent1");
LuaRecords[recordIndex]:getCurrentTarget():setLife(169);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(169);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent1");
LuaRecords[recordIndex]:getCurrentTarget():setLife(149);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(149);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent1");
LuaRecords[recordIndex]:getCurrentTarget():setLife(109);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(109);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent1");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent1");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent1");
LuaRecords[recordIndex]:getCurrentTarget():setLife(29);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(969);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(29);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(3);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(14);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent3");
LuaRecords[recordIndex]:getCurrentTarget():setLife(949);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(949);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(949);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(29);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(949);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(3);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(12);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent3");
LuaRecords[recordIndex]:getCurrentTarget():setLife(909);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(909);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(909);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(29);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(3);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(10);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent3");
LuaRecords[recordIndex]:getCurrentTarget():setLife(889);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(889);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(889);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(889);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(3);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(10);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent3");
LuaRecords[recordIndex]:getCurrentTarget():setLife(869);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(3);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(10);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent3");
LuaRecords[recordIndex]:getCurrentTarget():setLife(869);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(3);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(11);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent3");
LuaRecords[recordIndex]:getCurrentTarget():setLife(869);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(3);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(11);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent3");
LuaRecords[recordIndex]:getCurrentTarget():setLife(869);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(11);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(369);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(11);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(369);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(11);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(369);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(12);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(369);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(12);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(369);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(12);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(369);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(369);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(11);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(349);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(349);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(9);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(329);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(329);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(329);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(329);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(8);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(8);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(8);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(8);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(8);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(9);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(289);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(289);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(9);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(269);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(269);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(9);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(249);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(9);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(249);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(10);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(249);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(10);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(249);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(10);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(249);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(10);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(249);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(10);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(249);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(249);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(10);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(229);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(229);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(229);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(229);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(8);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(189);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(189);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(189);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(189);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(6);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(169);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(169);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(169);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(169);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(5);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(129);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(129);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(129);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(129);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(3);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(89);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(89);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(89);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(89);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(2);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(49);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(9);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(8);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(789);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(789);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(789);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(789);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(789);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(789);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(789);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(1);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(789);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(1);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(789);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(1);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(789);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(1);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(789);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(1);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(789);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getCurrentTarget());
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getClosestCandidateTarget());
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getStrongestCandidateTarget());
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getWeakestCandidateTarget());
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:setAttackable(LuaRecords[recordIndex]:getRandomCandidateTarget());

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(769);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(769);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(769);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(769);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(749);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(749);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(749);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(749);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(729);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(729);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(729);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(729);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(729);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(729);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(729);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(729);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(729);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(729);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(689);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(689);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(689);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(689);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(689);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent12");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setTargetChoice(4);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(0);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(689);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(689);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

return LuaRecords;

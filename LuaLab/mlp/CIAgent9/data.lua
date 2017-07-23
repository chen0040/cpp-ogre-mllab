--Year: 2009 Month:07 Day: 07 Hour: 13 Minute: 42 Second: 59
local LuaRecords={};
local recordIndex=0;

local GameAgentFactory=dofile(getDefaultScriptPath() .. "\\GameAgent.lua");


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(2);
LuaRecords[recordIndex]:setSightedTargetCount(4);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(1000);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(19);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(19);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getCurrentTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(19);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(19);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent9");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(19);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(19);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(2);
LuaRecords[recordIndex]:setSightedTargetCount(4);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(929);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(17);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(17);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getCurrentTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(17);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(17);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(17);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getWeakestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(17);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(3);
LuaRecords[recordIndex]:setSightedTargetCount(4);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(849);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(15);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent4");
LuaRecords[recordIndex]:getCurrentTarget():setLife(29);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(15);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getCurrentTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(29);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(15);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(29);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(15);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(20);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent4");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(29);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(15);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getWeakestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(15);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(3);
LuaRecords[recordIndex]:setSightedTargetCount(3);
LuaRecords[recordIndex]:setSightedAllyCount(1);
LuaRecords[recordIndex]:setLife(769);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(13);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(100);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getCurrentTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(18);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getStrongestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent1");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(3);
LuaRecords[recordIndex]:setSightedTargetCount(3);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(669);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(11);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(69);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getCurrentTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(69);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(16);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getStrongestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent3");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(869);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(16);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(3);
LuaRecords[recordIndex]:setSightedTargetCount(3);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(569);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(11);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(29);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getCurrentTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(29);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(29);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(15);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getStrongestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(29);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getWeakestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(29);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(2);
LuaRecords[recordIndex]:setSightedTargetCount(3);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(489);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(9);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent2");
LuaRecords[recordIndex]:getCurrentTarget():setLife(9);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(200);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getCurrentTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(13);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getStrongestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent2");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getWeakestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(789);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(13);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(2);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(429);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(7);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(749);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getCurrentTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(749);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(749);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getStrongestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent5");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(49);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(749);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(2);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(349);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(5);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(709);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getCurrentTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(709);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(709);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getStrongestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent5");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(200);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(6);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(709);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(2);
LuaRecords[recordIndex]:setSightedTargetCount(2);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(269);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(4);
LuaRecords[recordIndex]:getGun():setBulletCount(5);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getCurrentTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getStrongestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getWeakestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(1);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(229);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(4);
LuaRecords[recordIndex]:getGun():setBulletCount(5);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getStrongestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(7);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(1);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(209);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(4);
LuaRecords[recordIndex]:getGun():setBulletCount(5);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(8);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getStrongestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(8);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(1);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(169);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(4);
LuaRecords[recordIndex]:getGun():setBulletCount(5);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getStrongestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(5);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(1);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(129);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(4);
LuaRecords[recordIndex]:getGun():setBulletCount(5);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getStrongestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(1);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(109);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(4);
LuaRecords[recordIndex]:getGun():setBulletCount(6);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getStrongestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(4);
LuaRecords[recordIndex]:getGun():setBulletCount(6);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(4);
LuaRecords[recordIndex]:getGun():setBulletCount(6);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(9);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(4);
LuaRecords[recordIndex]:getGun():setBulletCount(6);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(1);
LuaRecords[recordIndex]:getGun():setBulletCount(6);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(1);
LuaRecords[recordIndex]:getGun():setBulletCount(7);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(1);
LuaRecords[recordIndex]:getGun():setBulletCount(7);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(10);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(1);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(1);
LuaRecords[recordIndex]:getGun():setBulletCount(7);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(1);
LuaRecords[recordIndex]:getGun():setBulletCount(7);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(1);
LuaRecords[recordIndex]:getGun():setBulletCount(8);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(1);
LuaRecords[recordIndex]:getGun():setBulletCount(8);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(1);
LuaRecords[recordIndex]:getGun():setBulletCount(8);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(11);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(1);
LuaRecords[recordIndex]:getGun():setBulletCount(8);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(1);
LuaRecords[recordIndex]:getGun():setBulletCount(8);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(1);
LuaRecords[recordIndex]:getGun():setBulletCount(9);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(9);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(9);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(12);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(9);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(13);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(13);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(9);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(13);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(13);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(0);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(10);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(13);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(13);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(1);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(89);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(2);
LuaRecords[recordIndex]:getGun():setBulletCount(10);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(13);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getStrongestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(13);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(4);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(1);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(69);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(10);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getStrongestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(3);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(1);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(49);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(10);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getClosestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createAttackerCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getAttackerCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getAttackerCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getAttackerCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getAttackerCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getStrongestCandidateTarget():setAttacking(LuaRecords[recordIndex]); 
LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(2);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:getRandomCandidateTarget():setAttacking(LuaRecords[recordIndex]); 

--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(9);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(0);
LuaRecords[recordIndex]:getGun():setBulletCount(10);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(0);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(9);
LuaRecords[recordIndex]:getGun():setBulletCount(11);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(-1);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(9);
LuaRecords[recordIndex]:getGun():setBulletCount(11);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(14);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);


--The record in archive LuaRecords
recordIndex=recordIndex+1; 
LuaRecords[recordIndex]=GameAgentFactory.create("CIAgent0");
LuaRecords[recordIndex]:setSightedAttackerCount(0);
LuaRecords[recordIndex]:setSightedTargetCount(1);
LuaRecords[recordIndex]:setSightedAllyCount(0);
LuaRecords[recordIndex]:setLife(-1);
LuaRecords[recordIndex]:setSenseRange(100);
LuaRecords[recordIndex]:setCurrentAction(9);
LuaRecords[recordIndex]:getGun():setBulletCount(11);
LuaRecords[recordIndex]:getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createCurrentTarget("CIAgent6");
LuaRecords[recordIndex]:getCurrentTarget():setLife(669);
LuaRecords[recordIndex]:getCurrentTarget():setSenseRange(100);
LuaRecords[recordIndex]:getCurrentTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setBulletCount(15);
LuaRecords[recordIndex]:getCurrentTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createClosestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getClosestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getClosestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getClosestCandidateTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getClosestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createStrongestCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getStrongestCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getStrongestCandidateTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getStrongestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createWeakestCandidateTarget("CIAgent6");
LuaRecords[recordIndex]:getWeakestCandidateTarget():setLife(669);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getWeakestCandidateTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setBulletCount(15);
LuaRecords[recordIndex]:getWeakestCandidateTarget():getGun():setWeaponChargingRate(0.2);

LuaRecords[recordIndex]:createRandomCandidateTarget("CIAgent7");
LuaRecords[recordIndex]:getRandomCandidateTarget():setLife(1000);
LuaRecords[recordIndex]:getRandomCandidateTarget():setSenseRange(100);
LuaRecords[recordIndex]:getRandomCandidateTarget():setCurrentAction(1);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setBulletCount(0);
LuaRecords[recordIndex]:getRandomCandidateTarget():getGun():setWeaponChargingRate(0.2);

return LuaRecords;

function onGameLoad(gameId)
	loadTerrain(gameId);
	loadSkyDome("Examples/CloudySky");
	setOceanHeight(150);
	setOceanSize(2000, 2000);
	loadOcean();
	dofile(getApplicationDir() .. "\\..\\games\\UAV\\forests.lua");
	setBlastImpactTextureId(5);
end

function onGameUnload(gameId)
	unloadOcean();
	unloadSkyDome("Examples/CloudySky");
	unloadForest();
	unloadTerrain();
end

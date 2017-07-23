function onGameLoad(gameId)
	loadTerrain(gameId);
	loadSkyBox("Examples/StormySkyBox");
	setOceanHeight(150);
	setOceanSize(2500, 2500);
	loadOcean();
	dofile(getApplicationDir() .. "\\..\\games\\GrassLand\\forests.lua");
	setBlastImpactTextureId(3);
end

function onGameUnload(gameId)
	unloadOcean();
	unloadSkyBox("Examples/StormySkyBox");
	unloadForest();
	unloadTerrain();
end

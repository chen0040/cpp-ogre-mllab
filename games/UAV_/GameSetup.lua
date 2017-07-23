function onGameLoad(gameId)
	loadTerrain(gameId);
	loadSkyDome("Examples/CloudySky");
	setOceanHeight(150);
	setOceanSize(2000, 2000);
	loadOcean();
end

function onGameUnload(gameId)
	unloadOcean();
	unloadSkyDome("Examples/CloudySky");
	unloadTerrain();
end

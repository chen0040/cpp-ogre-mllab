function onGameLoad(gameId)
	loadTerrain(gameId);
	loadSkyDome("Examples/CloudySky");
	setOceanHeight(150);
	setOceanSize(2500, 2500);
	loadOcean();
	setBlastImpactTextureId(5);
end

function onGameUnload(gameId)
	unloadOcean();
	unloadSkyDome("Examples/CloudySky");
	unloadTerrain();
end

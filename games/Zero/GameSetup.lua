function onGameLoad(gameId)
	loadTerrain(gameId);
	loadSkyDome("Examples/CloudySky");
	setBlastImpactTextureId(3);
end

function onGameUnload(gameId)
	unloadSkyDome("Examples/CloudySky");
	unloadTerrain();
end

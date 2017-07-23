function onGameLoad(gameId)
	loadTerrain(gameId);
	loadSkyBox("Examples/MorningSkyBox");
	setBlastImpactTextureId(4);
end

function onGameUnload(gameId)
	unloadSkyBox("Examples/MorningSkyBox");
	unloadTerrain();
end

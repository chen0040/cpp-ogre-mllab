function onGameLoad(gameId)
	loadTerrain(gameId);
	loadSkyBox("Examples/MorningSkyBox");
	loadHydrax();
	dofile(getApplicationDir() .. "\\..\\games\\GrassLand\\forests.lua");
	setBlastImpactTextureId(3);
end

function onGameUnload(gameId)
	unloadHydrax();
	unloadSkyBox("Examples/MorningSkyBox");
	unloadForest();
	unloadTerrain();
end

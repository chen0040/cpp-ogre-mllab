function onGameLoad(gameId)
	loadTerrain(gameId);
	loadHydrax();
	loadCaelum();
	setCaelumCloudSpeed(0.001, 0.001);
	setCaelumTimeScale(256);
	enableCaelumLighting();
	--caelum starts run at 2000-1-2 16:6:13
	setCaelumDateTime(2000, 1, 2, 16, 6, 13);
end

function onGameUnload(gameId)
	unloadCaelum();
	unloadHydrax();
	unloadTerrain();
end

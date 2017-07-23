function onGameLoad(gameId)
	--loadTerrain(gameId);
	loadCaelum();
	setCaelumCloudSpeed(0.001, 0.001);
	setCaelumTimeScale(256);
	enableCaelumLighting();
	--caelum starts run at 2000-1-2 13:54:48
	setCaelumDateTime(2000, 1, 2, 13, 54, 48);
	loadHydrax();
end

function onGameUnload(gameId)
	unloadHydrax();
	unloadCaelum();
	--unloadTerrain();
end

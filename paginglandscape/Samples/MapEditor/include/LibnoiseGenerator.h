#pragma once
#include <noise.h>
#include "noiseutils.h"
#include "Ogre.h"

using namespace Ogre;

class LibnoiseGenerator
{
private:
public:
				LibnoiseGenerator(void);
				~LibnoiseGenerator(void);

	void		MakeTerrainVoronoi(double* heightData, int mapWidth, int mapHeight, double x, double y, double w, double h, double frequency, double lacunarity, double octavecount, double persistance, double seed, const Real yscale);
	void		MakeTerrainPerlin(double* heightData, int mapWidth, int mapHeight, double x, double y, double w, double h, double frequency, double lacunarity, double octavecount, double persistance, double seed, const Real yscale);
	void		MakeTerrainRidgedMulti(double* heightData, int mapWidth, int mapHeight, double x, double y, double w, double h, double frequency, double lacunarity, double octavecount, double persistance, double seed, const Real yscale);
	void		MakeTerrainBillow(double* heightData, int mapWidth, int mapHeight, double x, double y, double w, double h, double frequency, double lacunarity, double octavecount, double persistance, double seed, const Real yscale);
	void		MakeTerrainCheckerboard(double* heightData, int mapWidth, int mapHeight, double x, double y, double w, double h, double frequency, double lacunarity, double octavecount, double persistance, double seed, const Real yscale);
	void		Normalise(double* const heightData, const Ogre::uint mapWidth, const Ogre::uint mapHeight, const Real yscale);
	void		Erode(double * const field, const Ogre::uint size, const float filter) const;
	void		ErodeOneDirection(double * const band, const int stride, const Ogre::uint count, const float filter) const;
};

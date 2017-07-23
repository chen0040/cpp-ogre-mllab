#include "LibnoiseGenerator.h"

LibnoiseGenerator::LibnoiseGenerator(void)
{
}
//------------------------------------------------------------------------------------------------
LibnoiseGenerator::~LibnoiseGenerator(void)
{
}
//------------------------------------------------------------------------------------------------
void LibnoiseGenerator::MakeTerrainVoronoi(double* heightData, int mapWidth, int mapHeight, double x, double y, double w, double h, double frequency, double lacunarity, double octavecount, double persistance, double seed, const Real yscale)
{
	noise::module::Voronoi myModule;
	noise::utils::NoiseMap heightMap;
	noise::utils::NoiseMapBuilderPlane heightMapBuilder;

	myModule.SetFrequency(frequency);
	myModule.SetSeed(seed);
	
	heightMapBuilder.SetSourceModule (myModule);
	heightMapBuilder.SetDestNoiseMap (heightMap);

	heightMapBuilder.SetDestSize (mapWidth, mapHeight);
	heightMapBuilder.SetBounds (x, x+w, y, y+h);
	heightMapBuilder.Build ();

	noise::utils::RendererImage renderer;
	noise::utils::Image image;
	renderer.SetSourceNoiseMap (heightMap);
	renderer.SetDestImage (image);
	renderer.Render ();

	noise::utils::Color color;

	for(int y=0; y < mapHeight; y++)
	{
		for(int x=0; x < mapWidth; x++)
		{
			short value = image.GetValue(x,y).blue;
			heightData[x + (y*mapWidth)] = value;
		}
	}

	for(int i=0; i<4; i++)
		Erode(heightData, mapWidth, 0.2f);

	Normalise(heightData, mapWidth, mapHeight, yscale);
}
void LibnoiseGenerator::MakeTerrainRidgedMulti(double* heightData, int mapWidth, int mapHeight, double x, double y, double w, double h, double frequency, double lacunarity, double octavecount, double persistance, double seed, const Real yscale)
{
	noise::module::RidgedMulti myModule;
	noise::utils::NoiseMap heightMap;
	noise::utils::NoiseMapBuilderPlane heightMapBuilder;

	myModule.SetFrequency(frequency);
	myModule.SetLacunarity(lacunarity);
	myModule.SetOctaveCount(octavecount);
	myModule.SetSeed(seed);
	
	heightMapBuilder.SetSourceModule (myModule);
	heightMapBuilder.SetDestNoiseMap (heightMap);

	heightMapBuilder.SetDestSize (mapWidth, mapHeight);
	heightMapBuilder.SetBounds (x, x+w, y, y+h);
	heightMapBuilder.Build ();

	noise::utils::RendererImage renderer;
	noise::utils::Image image;
	renderer.SetSourceNoiseMap (heightMap);
	renderer.SetDestImage (image);
	renderer.Render ();

	noise::utils::Color color;

	for(int y=0; y < mapHeight; y++)
	{
		for(int x=0; x < mapWidth; x++)
		{
			const short value = image.GetValue(x,y).blue;
			heightData[x + (y*mapWidth)] = value;
		}
	}

	for(int i=0; i<4; i++)
		Erode(heightData, mapWidth, 0.2f);

	Normalise(heightData, mapWidth, mapHeight, yscale);
}
void LibnoiseGenerator::MakeTerrainBillow(double* heightData, int mapWidth, int mapHeight, double x, double y, double w, double h, double frequency, double lacunarity, double octavecount, double persistance, double seed, const Real yscale)
{
	noise::module::Billow myModule;
	noise::utils::NoiseMap heightMap;
	noise::utils::NoiseMapBuilderPlane heightMapBuilder;

	myModule.SetFrequency(frequency);
	myModule.SetLacunarity(lacunarity);
	myModule.SetOctaveCount(octavecount);
	myModule.SetSeed(seed);
	
	heightMapBuilder.SetSourceModule (myModule);
	heightMapBuilder.SetDestNoiseMap (heightMap);

	heightMapBuilder.SetDestSize (mapWidth, mapHeight);
	heightMapBuilder.SetBounds (x, x+w, y, y+h);
	heightMapBuilder.Build ();

	noise::utils::RendererImage renderer;
	noise::utils::Image image;
	renderer.SetSourceNoiseMap (heightMap);
	renderer.SetDestImage (image);
	renderer.Render ();

	noise::utils::Color color;

	for(int y=0; y < mapHeight; y++)
	{
		for(int x=0; x < mapWidth; x++)
		{
			const short value = image.GetValue(x,y).blue;
			heightData[x + (y*mapWidth)] = value;
		}
	}

	for(int i=0; i<4; i++)
		Erode(heightData, mapWidth, 0.2f);

	Normalise(heightData, mapWidth, mapHeight, yscale);
}
void LibnoiseGenerator::MakeTerrainCheckerboard(double* heightData, int mapWidth, int mapHeight, double x, double y, double w, double h, double frequency, double lacunarity, double octavecount, double persistance, double seed, const Real yscale)
{
	noise::module::Checkerboard myModule;
	noise::utils::NoiseMap heightMap;
	noise::utils::NoiseMapBuilderPlane heightMapBuilder;
	
	heightMapBuilder.SetSourceModule (myModule);
	heightMapBuilder.SetDestNoiseMap (heightMap);

	heightMapBuilder.SetDestSize (mapWidth, mapHeight);
	heightMapBuilder.SetBounds (x, x+w, y, y+h);
	heightMapBuilder.Build ();

	noise::utils::RendererImage renderer;
	noise::utils::Image image;
	renderer.SetSourceNoiseMap (heightMap);
	renderer.SetDestImage (image);
	renderer.Render ();

	noise::utils::Color color;

	for(int y=0; y < mapHeight; y++)
	{
		for(int x=0; x < mapWidth; x++)
		{
			short value = image.GetValue(x,y).blue;
			heightData[x + (y*mapWidth)] = value;
		}
	}

	for(int i=0; i<4; i++)
		Erode(heightData, mapWidth, 0.2f);

	Normalise(heightData, mapWidth, mapHeight, yscale);
}
void LibnoiseGenerator::MakeTerrainPerlin(double* heightData, int mapWidth, int mapHeight, double x, double y, double w, double h, double frequency, double lacunarity, double octavecount, double persistance, double seed, const Real yscale)
{
	noise::module::Perlin myModule;
	noise::utils::NoiseMap heightMap;
	noise::utils::NoiseMapBuilderPlane heightMapBuilder;

	myModule.SetFrequency(frequency);
	myModule.SetLacunarity(lacunarity);
	myModule.SetOctaveCount(octavecount);
	myModule.SetSeed(seed);
	
	heightMapBuilder.SetSourceModule (myModule);
	heightMapBuilder.SetDestNoiseMap (heightMap);

	heightMapBuilder.SetDestSize (mapWidth, mapHeight);
	heightMapBuilder.SetBounds (x, x+w, y, y+h);
	heightMapBuilder.Build ();

	noise::utils::RendererImage renderer;
	noise::utils::Image image;
	renderer.SetSourceNoiseMap (heightMap);
	renderer.SetDestImage (image);
	renderer.Render ();

	noise::utils::Color color;

	for(int y=0; y < mapHeight; y++)
	{
		for(int x=0; x < mapWidth; x++)
		{
			const short value = image.GetValue(x,y).blue;
			heightData[x + (y*mapWidth)] = value;
		}
	}

	for(int i=0; i<4; i++)
		Erode(heightData, mapWidth, 0.2f);

	Normalise(heightData, mapWidth, mapHeight, yscale);
}
//------------------------------------------------------------------------------------------------
void LibnoiseGenerator::Normalise(double* const heightData, const Ogre::uint mapWidth, const Ogre::uint mapHeight, const Real yscale)
{
	/*
	Find the maximum and minimum values in the height field
	*/ 
	const Ogre::uint fieldSize = mapWidth*mapHeight;
	Real maxVal = heightData[0];
	Real minVal = heightData[0];
	Ogre::uint i;
	for (i = 1; i < fieldSize; i++)
	{
		if (heightData[i] > maxVal) 
		{
			maxVal = heightData[i];
		}
		else if (heightData[i] < minVal) 
		{
			minVal = heightData[i];
		}
	}

	/*
	Find the altitude range (dh)
	*/
    const Real minFinal = minVal;
	if (maxVal <= minFinal) 
        return;
	const Real inv_dh = yscale / (maxVal - minFinal);

	/*
	Scale all the values so they fill exactly the range 0-1
	*/
	for (i=0; i < fieldSize; i++)
	{
		heightData[i] = (heightData[i] - minFinal) * inv_dh;
        assert (heightData[i] <= yscale && heightData[i] >= 0.0f);
	}
//	fclose(file);
}
//------------------------------------------------------------------------------------------------
void LibnoiseGenerator::ErodeOneDirection(double * const band, 
                                const int stride, 
                                const Ogre::uint count, 
                                const float filter) const
{
	Ogre::uint i;
    int j = stride;
	float v = band[0];
	for (i = 0; i < count-1; i++)
	{
		band[j] = filter*v + (1-filter)*band[j];
		v = band[j];
		j += stride;
	}
}
//------------------------------------------------------------------------------------------------
void LibnoiseGenerator::Erode(double * const field, const Ogre::uint size, const float filter) const
{
	Ogre::uint i;

	/*
	Erode rows left to right
	*/
	for (i=0;i<size;i++)
	{
		ErodeOneDirection( &field[size*i], 1, size, filter);
	}
    
	/*
	Erode rows right to left
	*/
	for (i=0;i<size;i++)
	{
		ErodeOneDirection (&field[size*i+size-1], -1, size, filter);
	}

	/*
	Erode columns top to bottom
	*/
	for (i=0;i<size;i++)
	{
		ErodeOneDirection (&field[i], (int)size, size, filter);
	}

	/*
	Erode columns bottom to top
	*/
	for (i=0;i<size;i++)
	{
		ErodeOneDirection (&field[size*(size-1)+i], -((int)(size)), size, filter);
	}
}
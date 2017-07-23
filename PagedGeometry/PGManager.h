#ifndef _H_MLLAB_PG_MANAGER_H
#define _H_MLLAB_PG_MANAGER_H


#define TREE_MODEL_3D 1
#define TREE_MODEL_2D 2

#define TREE_MODEL TREE_MODEL_3D
#define PG_WIND 1

#include <Ogre.h>
#include "include/PagedGeometry.h"
#include "include/BatchPage.h"
#include "include/ImpostorPage.h"
#include "include/TreeLoader2D.h"
#if TREE_MODEL == TREE_MODEL_3D
#include "include/TreeLoader3D.h"
#endif
#ifdef PG_WIND
#include "include/WindBatchPage.h"
#endif
#include "include/GrassLoader.h"


using namespace Ogre;

//PagedGeometry's classes and functions are under the "Forests" namespace
using namespace Forests;

class PGManager
{
public:
	static PGManager* getSingletonPtr();
	static PGManager& getSingleton();

public:
	PGManager();
	virtual ~PGManager();

private:
	PGManager(const PGManager& rhs) { }
	PGManager& operator=(const PGManager& rhs) { return *this; }

public:
	void loadTree1(const Vector3& pos, const Degree& yaw, const Real& scale);
	void loadTree1(const Vector3& pos, const Real& radius, int count);
	void loadTree1();
	void unloadTree1(const Vector3& pos, const Real& radius);
	void unloadTree1();
	void loadBush(const Vector3& pos, const Real& radius, int count);
	void loadBush();
	void unloadBush();
	void unloadBush(const Vector3& pos, const Real& radius);
	void loadGrass();
	void loadGrass(const Vector3& pos, const Real& radius);
	void loadGrass(const TBounds& tb);
	void loadGrass(int left, int top, int right, int bottom);
	void unloadGrass(const Vector3& pos, const Real& radius);
	void unloadGrass();
	void update();

public:
#if TREE_MODEL == TREE_MODEL_3D
	TreeLoader3D* getTreeLoader();
#else
	TreeLoader2D* getTreeLoader();
#endif
	TreeLoader2D* getBushLoader();
	GrassLoader* getGrassLoader();

#ifdef PG_WIND
private:
	Real mWindFactorX;
	Real mWindFactorY;
public:
	void setWindFactorX(Real x) { mWindFactorX=x; }
	void setWindFactorY(Real y) { mWindFactorY=y; }
	Real getWindFactorX() const { return mWindFactorX; }
	Real getWindFactorY() const { return mWindFactorY; }
#endif

private:
	void createGrassLoader();
	void createTreeLoader();
	void createBushLoader();
	void destroyGrassLoader();
	void destroyTreeLoader();
	void destroyBushLoader();

public:
	void unloadForest();

private:
	bool mTreeLoaded;
	bool mBushLoaded;
public:
	bool isTreeLoaded() const { return mTreeLoader != NULL && mTreeLoaded; }
	bool isBushLoaded() const { return mBushLoader != NULL && mBushLoaded; }
	bool isGrassLoaded() const { return mGrassLoader !=NULL && !mGrassLoader->getLayerList().empty(); }
	bool isForestLoaded() const { return isTreeLoaded() || isBushLoaded() || isGrassLoaded(); }

protected:
	static PGManager* mSingleton;

private:
	PagedGeometry *mTrees, *mBushes, *mGrass;
#if TREE_MODEL==TREE_MODEL_3D
	TreeLoader3D * mTreeLoader;
#else
	TreeLoader2D * mTreeLoader;
#endif
	TreeLoader2D* mBushLoader;
	GrassLoader *mGrassLoader;
	Entity* mTree1;
	Entity* mFern;
	Entity* mMushroom;
	Entity* mPlant;
};
#endif
#ifndef _H_MLLAB_CAELUM_MANAGER_H
#define _H_MLLAB_CAELUM_MANAGER_H

#include <Ogre.h>
#include "../Caelum/main/include/Caelum.h"

using namespace Ogre;

class CaelumManager
{
public:
	CaelumManager();
	virtual ~CaelumManager();
	
private:
	CaelumManager(const CaelumManager& rhs) { }
	CaelumManager& operator=(const CaelumManager& rhs) { return *this; }

public:
	void loadCaelum();
	void unloadCaelum();
	bool isCaelumLoaded() const { return mActivated; }

public:
	static CaelumManager* getSingletonPtr();
	static CaelumManager& getSingleton();

public:
	void setDateTime(int year, int month, int day, int hour, int minute, int second);
	void getDateTime(int& year, int& month, int& day, int& hour, int& minute, int& second);
	void setCloudSpeed(const Vector2& cloudSpeed);
	void setTimeScale(float timescale);
	void enableLighting();
	void disableLighting();

public:
	float getTimeScale() const;
	std::string getDateTimeText();
	float getCloudSpeedX() const { return mCloudSpeed.x; }
	float getCloudSpeedY() const { return mCloudSpeed.y; }
	bool isLightingEnabled() const { return mLightingEnabled; }

private:
	Caelum::CaelumSystem* mCaelumSystem;
	bool mActivated;
	float mTimeScale;
	Vector2 mCloudSpeed;
	bool mLightingEnabled;

protected:
	static CaelumManager* mSingleton;
};

#endif
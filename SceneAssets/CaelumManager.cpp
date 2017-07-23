#include "CaelumManager.h"
#include "../GameEngine/Application.h"
#include "../OSEnvironment/OSEnvironment.h"

CaelumManager* CaelumManager::mSingleton=NULL;

CaelumManager::CaelumManager()
: mActivated(false)
, mTimeScale(1)
, mCloudSpeed(1, 1)
, mLightingEnabled(true)
, mCaelumSystem(NULL)
{
	if(mSingleton == NULL)
	{
		mSingleton=this;
	}
	else
	{
		throw Exception(42, "only single instance allowed", "CaelumManager::CaelumManager()");
	}
}

CaelumManager* CaelumManager::getSingletonPtr()
{
	return mSingleton;
}

CaelumManager& CaelumManager::getSingleton()
{
	return *mSingleton;
}

CaelumManager::~CaelumManager()
{
	 if (mCaelumSystem != NULL) 
	  {
        mCaelumSystem->shutdown (false);
        mCaelumSystem = 0;
    }
}

void CaelumManager::loadCaelum()
{
	if(!mActivated)
	{
		if(mCaelumSystem == NULL)
		{
			Application* app=Application::getSingletonPtr();

			// Initialise CaelumSystem
			Caelum::CaelumSystem::CaelumComponent componentMask=Caelum::CaelumSystem::CAELUM_COMPONENTS_DEFAULT;
			mCaelumSystem = new Caelum::CaelumSystem(Root::getSingletonPtr(), app->getSceneMgr(), componentMask);

			// Set time acceleration.
			mCaelumSystem->getUniversalClock ()->setTimeScale (mTimeScale);

			//remove the fog effect
			mCaelumSystem->setSceneFogDensityMultiplier(FOG_NONE); // or some other small value.
			mCaelumSystem->setManageSceneFog(false);

			// Set Cloud Speed;
			Caelum::CloudSystem::LayerVector& lv=mCaelumSystem->getCloudSystem()->getLayerVector();
			Caelum::CloudSystem::LayerVector::iterator lviter;
			Caelum::FlatCloudLayer* lvp;
			for(lviter=lv.begin(); lviter != lv.end(); ++lviter)
			{
				lvp=*lviter;
				lvp->setCloudSpeed(Vector2(1, 1));
			}

			mCaelumSystem->setManageAmbientLight(mLightingEnabled);
			if(!mLightingEnabled)
			{
				app->getSceneMgr()->setAmbientLight(ColourValue(1, 1, 1, 1));	
			}
			//if(mLightingEnabled)
			//{
			//	mCaelumSystem->setEnsureSingleLightSource(true); 
			//	mCaelumSystem->setEnsureSingleShadowSource(true);
			//	mCaelumSystem->getSun()->setForceDisable(false);
			//	mCaelumSystem->getMoon()->setForceDisable(false);
			//	mCaelumSystem->setManageAmbientLight(true);
			//}
			//else
			//{
			//	mCaelumSystem->setEnsureSingleLightSource(false); 
			//	mCaelumSystem->setEnsureSingleShadowSource(false);
			//	mCaelumSystem->getSun()->setForceDisable(true);
			//	mCaelumSystem->getMoon()->setForceDisable(true);
			//	mCaelumSystem->setManageAmbientLight(false);
			//}

			SYSTEMTIME st;
			::GetSystemTime(&st);
			this->setDateTime(st.wYear, st.wMonth-1, st.wDay, st.wHour, st.wMinute, st.wSecond);

			app->getWindow()->addListener(mCaelumSystem);
			Root::getSingletonPtr()->addFrameListener(mCaelumSystem);
		}
		
		mActivated=true;
	}
}

void CaelumManager::unloadCaelum()
{
	if(mActivated)
	{
		if(mCaelumSystem != NULL)
		{
			Application* app=Application::getSingletonPtr();
			app->getWindow()->removeListener(mCaelumSystem);
			Root::getSingletonPtr()->removeFrameListener(mCaelumSystem);

			mCaelumSystem->shutdown(false);
			mCaelumSystem=NULL;

			app->getSceneMgr()->setAmbientLight(ColourValue(1, 1, 1, 1));
		}

		mActivated=false;
	}
}

void CaelumManager::setTimeScale(float timeScale)
{
	mTimeScale=timeScale;
	if(mCaelumSystem != NULL)
	{
		mCaelumSystem->getUniversalClock ()->setTimeScale (mTimeScale);
	}
}

void CaelumManager::enableLighting()
{
	if(!mLightingEnabled)
	{
		mLightingEnabled=true;
		if(mActivated && mCaelumSystem != NULL)
		{
			mCaelumSystem->setManageAmbientLight(true);
		}
	/*	if(mActivated && mCaelumSystem != NULL)
		{
			mCaelumSystem->setEnsureSingleLightSource(true); 
			mCaelumSystem->setEnsureSingleShadowSource(true);
			mCaelumSystem->getSun()->setForceDisable(false);
			mCaelumSystem->getMoon()->setForceDisable(false);
			mCaelumSystem->setManageAmbientLight(true);
		}*/
	}
}

void CaelumManager::disableLighting()
{
	if(mLightingEnabled)
	{
		mLightingEnabled=false;
		if(mCaelumSystem != NULL && mActivated)
		{
			mCaelumSystem->setManageAmbientLight(false);
			Application::getSingletonPtr()->getSceneMgr()->setAmbientLight(ColourValue(1, 1, 1, 1));
		}
	/*	if(mActivated && mCaelumSystem != NULL)
		{
			mCaelumSystem->setEnsureSingleLightSource(false); 
			mCaelumSystem->setEnsureSingleShadowSource(false);
			mCaelumSystem->getSun()->setForceDisable(true);
			mCaelumSystem->getMoon()->setForceDisable(true);
			mCaelumSystem->setManageAmbientLight(false);
		}*/
	}
}

float CaelumManager::getTimeScale() const
{
	return mTimeScale;
}

void CaelumManager::setDateTime(int year, int month, int day, int hour, int minute, int second)
{
	if(mCaelumSystem != NULL)
	{
		mCaelumSystem->getUniversalClock()->setGregorianDateTime(year, month, day, hour, minute, second);	
	}
}

void CaelumManager::getDateTime(int& year, int& month, int& day, int& hour, int& minute, int& second)
{
	if(mCaelumSystem != NULL)
	{
		Caelum::LongReal calcJd=mCaelumSystem->getUniversalClock()->getJulianDay();
		Caelum::LongReal sec=0;

		Caelum::Astronomy::getGregorianDateTimeFromJulianDay (calcJd, year, month, day, hour, minute, sec);
		second=sec;
	}
	else
	{
		SYSTEMTIME st;
		::GetSystemTime(&st);
		year=st.wYear;
		month=st.wMonth;
		day=st.wDay;
		hour=st.wHour;
		minute=st.wMinute;
		second=st.wSecond;
	}
}

void CaelumManager::setCloudSpeed(const Vector2& cloudSpeed)
{
	mCloudSpeed=cloudSpeed;
	// Set Cloud Speed;
	if(mCaelumSystem != NULL)
	{
		Caelum::CloudSystem::LayerVector& lv=mCaelumSystem->getCloudSystem()->getLayerVector();
		Caelum::CloudSystem::LayerVector::iterator lviter;
		Caelum::FlatCloudLayer* lvp;
		for(lviter=lv.begin(); lviter != lv.end(); ++lviter)
		{
			lvp=*lviter;
			lvp->setCloudSpeed(cloudSpeed);
		}
	}
}

std::string CaelumManager::getDateTimeText()
{
	std::ostringstream oss;

	int year, month, day, hour, minute, second;
	getDateTime(year, month, day, hour, minute, second);

	oss << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second;
	return oss.str();
}
#include "CIAgent.h"
#include "CIAgentManager.h"
#include "../GameEngine/Application.h"
#include "../CIType/CIManager.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../Terrain/TerrainInfoManager.h"
#include "../SceneAssets/HydraxManager.h"
#include "../Widgets/MsgBox.h"
#include "../Widgets/GUIManager.h"
#include <sstream>
#include "../GameEngine/Application.h"

CIAgent::CIAgent(const Vector3& pos, const std::string& agentName)
: mRotationSpeed(30)
, mWalkSpeed(30)
, mLife(1000)
, mMaxLife(1000)
, mVisible(true)
, mActivated(false)
, mText(NULL)
, mFloatable(true)
{
	mAgentName=agentName.c_str();
	ModelManager* mm=ModelManager::getSingletonPtr();
	mModelName=mm->getDefaultModelType();
	mEntity=mm->popEntity(mModelName);

	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	mEntityNode=sm->getRootSceneNode()->createChildSceneNode(getAgentName()+"Node");
	setPosition(pos);

	mEntityNode->setScale(mm->getScale(mModelName));

	mEntityNode->yaw(Degree(180-Ogre::Math::RangeRandom(-45, 45)), Node::TS_WORLD);
	mEntityNode->attachObject(mEntity);

	std::string animationIdle=mm->getAnimationName_Idle(mModelName);
	if(animationIdle.compare("")==0)
	{
		mAnimationState=NULL;
	}
	else
	{
		mAnimationState=mEntity->getAnimationState(animationIdle.c_str());
		mAnimationState->setEnabled(true);
		mAnimationState->setLoop(true);
	}

	const Vector3& halfSize=mEntity->getBoundingBox().getHalfSize();
	const Vector3& scaleSize=mEntityNode->getScale();
	Real x=halfSize.x; // * scaleSize.x;
	Real z=halfSize.z; // * scaleSize.z;
	mHeight=halfSize.y * 2; //* scaleSize.y * 4;
	if(x > z)
	{
		mRadius=x;
	}
	else
	{
		mRadius=z;
	}
}

void CIAgent::createText(const std::string& text)
{
	if(mText == NULL)
	{
		mText = new MovableText("TXT_001", text.c_str());
		mText->setTextAlignment(MovableText::H_CENTER, MovableText::V_ABOVE); // Center horizontally and display above the node
		//mText->setAdditionalHeight( 2.0f ); //msg->setAdditionalHeight( ei.getRadius() )
		mText->setCharacterHeight(18);
		mText->showOnTop(true);
		
		mTextNode=mEntityNode->createChildSceneNode(getAgentName()+"TextNode");
		mTextNode->attachObject(mText);

		mTextNode->translate(Vector3(0, this->getHeight()+5, 0)); 
	}
}

void CIAgent::changeModel(const std::string& name)
{
	if(mModelName.compare(name)==0)
	{
		return;
	}

	mEntityNode->detachObject(mEntity->getName());

	ModelManager* mm=ModelManager::getSingletonPtr();
	mm->pushEntity(mModelName, mEntity);
	mModelName=name;
	mEntity=mm->popEntity(mModelName);

	setPosition(getPosition());

	mEntityNode->setScale(mm->getScale(mModelName));

	mEntityNode->yaw(Degree(180-Ogre::Math::RangeRandom(-45, 45)), Node::TS_WORLD);
	mEntityNode->attachObject(mEntity);

	std::string animationIdle=mm->getAnimationName_Idle(mModelName);
	if(animationIdle.compare("")==0)
	{
		mAnimationState=NULL;
	}
	else
	{
		mAnimationState=mEntity->getAnimationState(animationIdle.c_str());
		mAnimationState->setEnabled(true);
		mAnimationState->setLoop(true);
	}

	const Vector3& halfSize=mEntity->getBoundingBox().getHalfSize();
	//const Vector3& scaleSize=mEntityNode->getScale();
	Real x=halfSize.x; // * scaleSize.x;
	Real z=halfSize.z; // * scaleSize.z;
	mHeight=halfSize.y * 2; // * scaleSize.y * 4;
	if(x > z)
	{
		mRadius=x;
	}
	else
	{
		mRadius=z;
	}
}

Real CIAgent::getHeight() const
{
	return mHeight;
}

void CIAgent::activate(bool showPS)
{
	mActivated=true;
	mEntityNode->showBoundingBox(true);
}

bool CIAgent::isActive() const
{
	return mActivated;
}

void CIAgent::deactivate()
{
	mActivated=false;
	mEntityNode->showBoundingBox(false);
}

CIAgent::~CIAgent()
{
	Application* app=Application::getSingletonPtr();

	if(mText != NULL)
	{
		mEntityNode->removeAndDestroyChild(mTextNode->getName());
		delete mText;
		mText=NULL;
	}
	

	mEntityNode->detachAllObjects();
	app->getSceneMgr()->getRootSceneNode()->removeAndDestroyChild(mEntityNode->getName());
	
	ModelManager* am=ModelManager::getSingletonPtr();
	am->pushEntity(mModelName, mEntity);

	
}

void CIAgent::generateCode(const std::string& destinationFolderPath, const std::string& lang, const std::string& codeName)
{
	
}

void CIAgent::setPosition(const Ogre::Vector3 &pos)
{
	ModelManager* mm=ModelManager::getSingletonPtr();
	Vector3 offset=mm->getOffset(mModelName);
	ModelManager::EnvironmentType et=mm->getEnvironmentType(mModelName);
	if(et==ModelManager::ENVIRONMENTTYPE_AIR || et==ModelManager::ENVIRONMENTTYPE_STATIC)
	{
		Real min_height=0.0f;
		TerrainInfoManager* tm=TerrainInfoManager::getSingletonPtr();
		if(tm->isTerrainLoaded())
		{
			min_height=tm->getHeight(pos.x, pos.z) + offset.y;
		}
		else
		{
			HydraxManager* hm=HydraxManager::getSingletonPtr();
			if(hm->isHydraxLoaded())
			{
				if(mFloatable)
				{
					min_height=hm->getHeight(pos.x, pos.z)+offset.y;
				}
			}
			else
			{
				min_height=tm->getHeight(pos.x, pos.z);
			}
		}
		Real y=mEntityNode->getPosition().y;
		if(et==ModelManager::ENVIRONMENTTYPE_AIR)
		{
			y-=10.0f;
		}

		if(y < min_height)
		{
			y=min_height;
		}
		
		mEntityNode->setPosition(pos.x, y, pos.z);
	}
	else if(et==ModelManager::ENVIRONMENTTYPE_LAND)
	{
		Vector3 pos1=pos+offset;
		TerrainInfoManager* tm=TerrainInfoManager::getSingletonPtr();
		if(tm->isTerrainLoaded())
		{
			pos1.y=tm->getHeight(pos.x, pos.z) + offset.y;
		}
		else
		{
			Real groundHeight=tm->getHeight(pos.x, pos.z);
			pos1.y=groundHeight+offset.y;
			HydraxManager* hm=HydraxManager::getSingletonPtr();
			if(hm->isHydraxLoaded())
			{
				if(mFloatable)
				{
					pos1.y=hm->getHeight(pos.x, pos.z)+offset.y;
				}
			}
		}
		
		
		mEntityNode->setPosition(pos1);	
	}
}

//Vector3 CIAgent::getCenter() const
//{
//	Vector3 pos=mEntityNode->getPosition();
//	pos.y+=mEntity->getBoundingBox().getHalfSize().y; 
//	return pos;
//}

Real CIAgent::getRadius() const
{
	return  mRadius;
}

bool CIAgent::run(const std::string& cmd, Real dt)
{
	if(cmd.compare("act: idle")==0)
	{
		this->idle(dt);
	}
	else if(cmd.compare("act: shoot")==0)
	{
		this->shoot(dt);
	}
	else if(cmd.compare("act: slump")==0)
	{
		this->slump(dt);
	}
	else if(cmd.compare("act: turnLeft")==0)
	{
		this->turnLeft(dt);
	}
	else if(cmd.compare("act: turnRight")==0)
	{
		this->turnRight(dt);
	}
	else if(cmd.compare("act: walk")==0)
	{
		this->walk(dt);
	}
	else if(cmd.compare("act: die")==0)
	{
		this->die(dt);
	}
	else
	{
		return false;
	}
	return true;
}

bool CIAgent::setAnimation(const String& animationName)
{
	if(animationName.compare("")==0)
	{
		if(mAnimationState != NULL)
		{
			mAnimationState->setEnabled(false);
			mAnimationState->setLoop(false);
			mAnimationState=NULL;
			return true;
		}
	}
	else
	{
		AnimationState* as=mEntity->getAnimationState(animationName);
		if(mAnimationState != as)
		{
			if(mAnimationState != NULL)
			{
				mAnimationState->setEnabled(false);
				mAnimationState->setLoop(false);
			}
			mAnimationState=as;
			mAnimationState->setEnabled(true);
			mAnimationState->setLoop(true);
			return true;
		}
	}

	return false;
}

std::string CIAgent::toString() const
{
	return "";
}

void CIAgent::idle(Real dt)
{
	setAnimation(ModelManager::getSingletonPtr()->getAnimationName_Idle(mModelName));
	if(mAnimationState != NULL)
	{
		mAnimationState->addTime(dt);
	}
}

void CIAgent::shoot(Real dt)
{
	setAnimation(ModelManager::getSingletonPtr()->getAnimationName_Shoot(mModelName));
	if(mAnimationState != NULL)
	{
		mAnimationState->addTime(dt);
	}
}

void CIAgent::slump(Real dt)
{
	setAnimation(ModelManager::getSingletonPtr()->getAnimationName_Slump(mModelName));
	if(mAnimationState != NULL)
	{
		mAnimationState->addTime(dt);
	}
}

void CIAgent::hide()
{
	mEntityNode->setVisible(false); 
	mVisible=false;
}

void CIAgent::show()
{
	mEntityNode->setVisible(true); 
	mVisible=true;
}

void CIAgent::die(Real dt)
{
	mLife=0;
	setAnimation(ModelManager::getSingletonPtr()->getAnimationName_Die(mModelName));
	if(mAnimationState != NULL)
	{
		mAnimationState->setLoop(false);
		if(!mAnimationState->hasEnded())
		{
			mAnimationState->addTime(dt);
		}
		else
		{
			mLife=-1;
		}
	}
	else
	{
		mLife=-1;
		if(isVisible())
		{
			hide();
		}
	}
}
	
void CIAgent::walk(Real dt)
{
	ModelManager* mm=ModelManager::getSingletonPtr();
	setAnimation(mm->getAnimationName_Walk(mModelName));
	if(mAnimationState != NULL)
	{
		mAnimationState->addTime(dt);
	}	

	Vector3 direction=mEntityNode->getOrientation() * mm->getRotation(mModelName);
	direction.y=0;
	direction.normalise();
	mEntityNode->translate(direction * (dt * mWalkSpeed));
	const Vector3& pos=mEntityNode->getPosition();
	this->setPosition(pos);
}
	
void CIAgent::turnLeft(Real dt)
{
	setAnimation(ModelManager::getSingletonPtr()->getAnimationName_Idle(mModelName));
	if(mAnimationState != NULL)
	{
		mAnimationState->addTime(dt);
	}
	mEntityNode->yaw(Angle(-mRotationSpeed * dt), Node::TS_WORLD);
}

void CIAgent::turnRight(Real dt)
{
	setAnimation(ModelManager::getSingletonPtr()->getAnimationName_Idle(mModelName));
	if(mAnimationState != NULL)
	{
		mAnimationState->addTime(dt);
	}
	mEntityNode->yaw(Angle(mRotationSpeed * dt), Node::TS_WORLD);
}
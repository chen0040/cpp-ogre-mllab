#ifndef _H_MLLAB_MODEL_MANAGER_H
#define _H_MLLAB_MODEL_MANAGER_H

#include <stack>
#include <string>
#include <Ogre.h>
#include <vector>

using namespace Ogre;

class ModelManager
{
public:
	enum EnvironmentType
	{
		ENVIRONMENTTYPE_LAND,
		ENVIRONMENTTYPE_AIR,
		ENVIRONMENTTYPE_STATIC
	};

public:
	ModelManager(size_t expanded);
	virtual ~ModelManager();

protected:
	static ModelManager* mSingleton;

private:
	ModelManager(const ModelManager& rhs) { }
	ModelManager& operator=(const ModelManager& rhs) { return *this; }

public:
	static ModelManager* getSingletonPtr() { return mSingleton; }
	static ModelManager& getSingleton() { return *mSingleton; }

private:
	std::map<std::string, std::stack<Entity*> > mEntities;
	std::map<std::string, size_t> mEntityCount;
	std::map<std::string, size_t> mInitialEntityCount;
	std::map<std::string, Vector3> mScale;
	std::map<std::string, Vector3> mOffset;
	std::map<std::string, Vector3> mRotation;
	std::map<std::string, EnvironmentType> mEnvironmentType;
	std::string mDefaultModelType;
	std::map<std::string, std::string> mIdle;
	std::map<std::string, std::string> mShoot;
	std::map<std::string, std::string> mWalk;
	std::map<std::string, std::string> mSlump;
	std::map<std::string, std::string> mDie;
	std::map<std::string, std::string> mMesh;
	std::map<std::string, std::string> mWeaponName;
	std::map<std::string, Vector3> mWeaponOffset;
	std::vector<std::string> mModels;
	Vector3 mZeroVec;
	std::string mZeroText;

public:
	Entity* popEntity(const std::string& name);
	void pushEntity(const std::string& name, Entity* entity);
	size_t getEntityCount(const std::string& name) const;
	Vector3 getScale(const std::string& name) const;
	const Vector3& getOffset(const std::string& name) const;
	Vector3 getRotation(const std::string& name) const;
	EnvironmentType getEnvironmentType(const std::string& name) const;
	std::string getDefaultModelType() const { return mDefaultModelType; }
	std::string getAnimationName_Die(const std::string& name) const;
	std::string getAnimationName_Walk(const std::string& name) const;
	std::string getAnimationName_Shoot(const std::string& name) const;
	std::string getAnimationName_Slump(const std::string& name) const;
	std::string getAnimationName_Idle(const std::string& name) const;
	std::string getMesh(const std::string& name) const;
	const std::vector<std::string>& getConstModelNames() const;
	const Vector3& getWeaponOffset(const std::string& name) const;
	const std::string& getWeaponName(const std::string& name) const;
};

#endif
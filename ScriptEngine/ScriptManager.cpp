#include "ScriptManager.h"
#include <Ogre.h>
#include <sstream>
#include "../tinyxml/tinyxml.h"
#include <boost/filesystem.hpp>
#include "LuaAPI.h"
#include "../CIAgents/CIGameAgent.h"
#include <luabind/operator.hpp> //require to bind operator (which use the word "self")
#include "../OSEnvironment/OSEnvironment.h"

ScriptManager* ScriptManager::mSingleton=NULL;

ScriptManager::~ScriptManager()
{
	std::map<std::string, Scriptlet*>::iterator iter=mScriptlets.begin();
	std::map<std::string, Scriptlet*>::iterator iter_end=mScriptlets.end();
	for(; iter != iter_end; ++iter)
	{
		delete (iter->second);
	}
	mScriptlets.clear();
	lua_close(m_pLuaState);
}

void ScriptManager::saveNicknames()
{
	TiXmlDocument doc;
	doc.LinkEndChild(new TiXmlDeclaration("1.0", "", ""));

	TiXmlElement* xmlRoot=new TiXmlElement("nicknames");
	doc.LinkEndChild(xmlRoot);

	std::map<std::string, std::string>::const_iterator siter=mNicknames.begin();
	std::map<std::string, std::string>::const_iterator siter_end=mNicknames.end();

	for(; siter != siter_end; ++siter)
	{
		TiXmlElement* xmlLevel1=new TiXmlElement("nickname");
		xmlLevel1->SetAttribute("name", siter->first.c_str());
		xmlLevel1->SetAttribute("alias", siter->second.c_str());
		xmlRoot->LinkEndChild(xmlLevel1);
	}

	doc.SaveFile(OSEnvironment::getFullPath("..\\config\\nicknames.xml").c_str());
}

void ScriptManager::setNickname(const std::string& name, const std::string& alias)
{
	mNicknames[name]=alias;
	saveNicknames();
}

void ScriptManager::createNicknames()
{
	TiXmlDocument doc;
	if(!doc.LoadFile(OSEnvironment::getFullPath("..\\config\\nicknames.xml").c_str()))
	{
		throw Exception(42, "Failed to load nicknames.xml", "BotScriptWidget::createNicknames()");
	}

	TiXmlElement* xmlRoot=doc.RootElement();

	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1 = xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "nickname")==0)
		{
			std::string name=xmlLevel1->Attribute("name");
			std::string alias=xmlLevel1->Attribute("alias");
			mNicknames[name]=alias;
		}
	}
}

void ScriptManager::removeNickname(const std::string& name)
{
	std::map<std::string, std::string>::iterator fnd=mNicknames.find(name);

	if(fnd != mNicknames.end())
	{
		mNicknames.erase(fnd);
		saveNicknames();
	}
}

bool ScriptManager::hasNickname(const std::string& name) const
{
	std::map<std::string, std::string>::const_iterator fnd=mNicknames.find(name);
	if(fnd != mNicknames.end())
	{
		return true;
	}
	return false;
}

const std::string& ScriptManager::getNickname(const std::string& name) const
{
	std::map<std::string, std::string>::const_iterator fnd=mNicknames.find(name);
	if(fnd != mNicknames.end())
	{
		return fnd->second;
	}

	return name;
}

const std::vector<std::string>& ScriptManager::getScriptListings()
{
	mScriptListings.clear();
	std::map<std::string, Scriptlet*>::const_iterator iter=mScriptlets.begin();
	std::map<std::string, Scriptlet*>::const_iterator iter_end=mScriptlets.end();
	for(; iter != iter_end; ++iter)
	{
		mScriptListings.push_back(iter->first);
	}
	return mScriptListings;
}

ScriptManager::ScriptManager()
{
	if(mSingleton == NULL)
	{
		mSingleton=this;
	}
	else
	{
		throw Ogre::Exception(42, "Multiple instances not allowed!", "ScriptManager::ScriptManager()");
	}

	createNicknames();

	m_pLuaState=luaL_newstate();
	luabind::open(m_pLuaState);

	luaL_openlibs(m_pLuaState);

	/*
	luaopen_math(m_pLuaState);
	luaopen_string(m_pLuaState);
	*/
	
	/*
	luaopen_io(m_pLuaState); 
    luaopen_base(m_pLuaState);
    luaopen_table(m_pLuaState);
	luaopen_package(m_pLuaState);
	luaopen_os(m_pLuaState);
	*/

	binds();

	std::string worldScript=OSEnvironment::getFullPath("..\\script_classes\\GameWorld.lua");
	if(luaL_dofile(m_pLuaState, worldScript.c_str())!=0)
	{
		std::ostringstream oss;
		oss << "dofile(" << worldScript << ")" << std::endl;
		ScriptManager::exception("ScriptManager::binds()", oss.str().c_str());
	}

	load();
}

void ScriptManager::binds()
{
	bindVector3();
	bindGameAgent();
	bindMisc();
}

void ScriptManager::bindVector3()
{
	using namespace luabind;
	module(m_pLuaState)
	[ 
		class_<Vector3>( "Vector3")
			.def_readwrite( "x", &Vector3::x )
			.def_readwrite( "y", &Vector3::y )
			.def_readwrite( "z", &Vector3::z ) 
			.def(constructor<>())
			.def(constructor<Vector3&>()) 
			.def(constructor<Real, Real, Real>()) 
			.def("absDotProduct", &Vector3::absDotProduct) 
			.def("crossProduct", &Vector3::crossProduct ) 
			.def("directionEquals", &Vector3::directionEquals )
			.def("distance", &Vector3::distance ) 
			.def("dotProduct", &Vector3::dotProduct ) 
			.def("getRotationTo", &Vector3::getRotationTo )
			.def("isZeroLength", &Vector3::isZeroLength ) 
			.def("length", &Vector3::length ) 
			.def("makeCeil", &Vector3::makeCeil ) 
			.def("makeFloor", &Vector3::makeFloor ) 
			.def("midPoint", &Vector3::midPoint ) 
			.def("normalise", &Vector3::normalise ) 
			.def("nornaliseCopy", &Vector3::normalisedCopy )
			.def("perpendicular", &Vector3::perpendicular )
			.def("positionCloses", &Vector3::positionCloses )
			.def("positionEquals", &Vector3::positionEquals ) 
			//.def("ptr", &Vector3::ptr )
			.def("randomDeviant", &Vector3::randomDeviant )
			.def("reflect", &Vector3::reflect )
			.def("squaredDistance", &Vector3::squaredDistance )
			.def("squaredLength", &Vector3::squaredLength ) 
	        
			// Operators 
	        
			.def( self + other<Vector3>() ) 
			.def( self - other<Vector3>() ) 
			.def( self * other<Vector3>() ) 
			.def( self * Real() ) 
			.def(tostring(self))
	]; 

	LUA_CONST_START(Vector3, m_pLuaState) 
			LUA_CONST(Vector3, ZERO);
			LUA_CONST(Vector3, UNIT_X);
			LUA_CONST(Vector3, UNIT_Y);
			LUA_CONST(Vector3, UNIT_Z);
			LUA_CONST(Vector3, NEGATIVE_UNIT_X);
			LUA_CONST(Vector3, NEGATIVE_UNIT_Y);
			LUA_CONST(Vector3, NEGATIVE_UNIT_Z);
			LUA_CONST(Vector3, UNIT_SCALE);
	LUA_CONST_END;
}

void ScriptManager::bindGameAgent()
{
	using namespace luabind;

	module(m_pLuaState)
	[
		class_<Gun>("Gun")
			.def("setWeaponImpact", &Gun::setWeaponImpact)
			.def("getWeaponImpact", &Gun::getWeaponImpact)
			.def("setWeaponPenetration", &Gun::setWeaponPenetration)
			.def("getWeaponPenetration", &Gun::getWeaponPenetration)
			.def("hasBullets", &Gun::hasBullets)
			.def("getBulletCount", &Gun::getBulletCount)
			.def("setMaxBulletCount", &Gun::setMaxBulletCount)
			.def("setWeaponChargingRate", &Gun::setWeaponChargingRate)
			.def("getWeaponChargingRate", &Gun::getWeaponChargingRate)
			.def("getWeaponSpeed", &Gun::getWeaponSpeed)
	];

	module(m_pLuaState)
	[
		class_<CIGameAgent>("CIGameAgent")
			.def(constructor<const Vector3&, const std::string&, const std::string&>())
			.def("die", &CIGameAgent::registerDie)
			.def("walk", &CIGameAgent::registerWalk)
			.def("slump", &CIGameAgent::registerSlump)
			.def("shoot", &CIGameAgent::registerShoot)
			.def("idle", &CIGameAgent::registerIdle)
			.def("attack", &CIGameAgent::registerAttack)
			.def("approach", &CIGameAgent::registerApproach)
			.def("escape", &CIGameAgent::registerEscape)
			.def("wander", &CIGameAgent::registerWander)
			.def("changeModel", &CIGameAgent::changeModel)
			.def("addEnemy", &CIGameAgent::addEnemy)
			.def("setLife", &CIGameAgent::setLife)
			.def("getLife", &CIGameAgent::getLife)
			.def("setWalkSpeed", &CIGameAgent::setWalkSpeed)
			.def("setRotationSpeed", &CIGameAgent::setRotationSpeed)
			.def("getDistance", &CIGameAgent::getDistance)
			

			.def("getSightedTargetCount", &CIGameAgent::getSightedTargetCount)
			.def("getSightedAllyCount", &CIGameAgent::getSightedAllyCount)
			.def("getSightedAttackerCount", &CIGameAgent::getSightedAttackerCount)
			.def("getSightedTarget", &CIGameAgent::getSightedTarget)
			.def("getSightedAlly", &CIGameAgent::getSightedAlly)

			.def("getClosestCandidateTarget", &CIGameAgent::getCandidateTarget_Closest)
			.def("getStrongestCandidateTarget", &CIGameAgent::getCandidateTarget_Strongest)
			.def("getWeakestCandidateTarget", &CIGameAgent::getCandidateTarget_Weakest)
			.def("getRandomCandidateTarget", &CIGameAgent::getCandidateTarget_Random)
			.def("getAttackerCandidateTarget", &CIGameAgent::getCandidateTarget_Attacker)

			.def("targetClosest", &CIGameAgent::registerTargetType_Closest)
			.def("targetStrongest", &CIGameAgent::registerTargetType_Strongest)
			.def("targetWeakest", &CIGameAgent::registerTargetType_Weakest)
			.def("targetRandom", &CIGameAgent::registerTargetType_Random)
			.def("targetAttacker", &CIGameAgent::registerTargetType_Attacker)
			.def("getTargetChoice", &CIGameAgent::getRegisteredTargetChoice)
			
			.def("getCurrentAction", &CIGameAgent::getRegisteredAction)
			.def("getCurrentTarget", &CIGameAgent::getCurrentTarget)

			.def("setSenseRange", &CIGameAgent::setSenseRange)
			.def("setArmor", &CIGameAgent::setArmor)
			.def("getSenseRange", &CIGameAgent::getSenseRange)
			.def("getArmor", &CIGameAgent::getArmor)
			.def("getGun", &CIGameAgent::getGun)		
			.def("getAgentId", &CIGameAgent::getAgentName)
			.def("getScore", &CIGameAgent::getScore)
			.def("getFiringDelay", &CIGameAgent::getFiringDelay)
			.def("setFiringDelay", &CIGameAgent::setFiringDelay)
			.def("doNothing", &CIGameAgent::doNothing)
			.def("getScriptId", &CIGameAgent::getScriptId)
			.def("getScriptClassPath", &CIGameAgent::getScriptClassPath)
			
			.def("isAttacking", &CIGameAgent::isAttacking)
			.def("isAttackable", &CIGameAgent::isAttackable)
			.def("isTargetAttackable", &CIGameAgent::isTargetAttackable)
			.def("getTargetRelativeDistance", &CIGameAgent::getTargetRelativeDistance)
			.def("getTargetRelativeLife", &CIGameAgent::getTargetRelativeLife)
	];
}

void ScriptManager::bindMisc()
{
	module(m_pLuaState)
	[
		def("alert", &alert),
		def("getTime", &getTime),
		def("fileExists", &fileExists),
		def("print2Console", &print2Console),
		def("getDefaultScriptPath", &getDefaultScriptPath),
		def("print2File", &print2File),
		def("showConsole", &showConsole),
		def("repaint", &repaint),
		def("httpAddField", &httpAddField),
		def("loadTerrain", &loadTerrain),
		def("unloadTerrain", &unloadTerrain),
		def("loadSkyDome", &loadSkyDome),
		def("unloadSkyDome", &unloadSkyDome),
		def("loadSkyBox", &loadSkyBox),
		def("unloadSkyBox", &unloadSkyBox),
		def("loadSkyPlane", &loadSkyPlane),
		def("unloadSkyPlane", &unloadSkyPlane),
		def("loadCaelum", &loadCaelum),
		def("unloadCaelum", &unloadCaelum),
		def("setCaelumTimeScale", &setCaelumTimeScale),
		def("setCaelumDateTime", &setCaelumDateTime),
		def("setCaelumCloudSpeed", &setCaelumCloudSpeed),
		def("enableCaelumLighting", &enableCaelumLighting),
		def("disableCaelumLighting", &disableCaelumLighting),
		def("loadHydrax", &loadHydrax),
		def("unloadHydrax", &unloadHydrax),
		def("loadOcean", &loadOcean),
		def("unloadOcean", &unloadOcean),
		def("setOceanHeight", &setOceanHeight),
		def("setOceanSize", setOceanSize),
		def("getApplicationDir", getApplicationDir),
		def("loadTree1", loadTree1),
		def("loadBush", loadBush),
		def("loadGrass", loadGrass),
		def("unloadForest", unloadForest),
		def("getGameId", getGameId),
		def("setBlastImpactTextureId", setBlastImpactTextureId),
		def("getGameDir", getGameDir)
	];
}

void ScriptManager::load()
{
	TiXmlDocument doc;
	if(! doc.LoadFile(OSEnvironment::getFullPath("..\\config\\Scripts.xml").c_str()))
	{
		throw Ogre::Exception(42, "failed to load Scripts.xml", "ScriptManager::loadScriptSettings()");
	}

	TiXmlElement* xmlRoot=doc.RootElement();
	mScriptRootDirectory=OSEnvironment::getFullPath(xmlRoot->Attribute("folder"));

	boost::filesystem::directory_iterator end_iterator;
	boost::filesystem::path dir_path(mScriptRootDirectory);
	for(boost::filesystem::directory_iterator iter(dir_path); iter != end_iterator; ++iter)
	{
		if(boost::filesystem::is_directory(iter->status()))
		{
			std::string scriptId=iter->leaf();
			if(mScriptlets.find(scriptId)==mScriptlets.end())
			{
				mScriptlets[scriptId]=new Scriptlet(scriptId, getFullPath(scriptId));
			}
		}
	}
}

ScriptManager* ScriptManager::getSingletonPtr()
{
	return mSingleton;
}

ScriptManager& ScriptManager::getSingleton()
{
	return *mSingleton;
}

bool ScriptManager::isFuncExisted(const char* fname) const
{
	luabind::adl::object g=luabind::globals(m_pLuaState);
	luabind::adl::object func=g[fname];

	if(func)
	{
		if(luabind::type(func)==LUA_TFUNCTION)
		{
			return true;
		}
	}

	return false;
}

std::string ScriptManager::getFullPath(const std::string& path) const
{
	return mScriptRootDirectory+std::string("\\")+path;
}

int ScriptManager::compileScript(const std::string& script) const
{
	if(!OSEnvironment::exists(script))
	{
		std::ostringstream oss;
		oss << script << " does not exists!";
		throw Exception(42, oss.str().c_str(), "ScriptManager::compileScript(const std::string& script) const");
	}
	int status=luaL_dofile(m_pLuaState, script.c_str());
	if(status != 0)
	{
		ScriptManager::exception("ScriptManager::compileScript(const std::string& script) const", script.c_str());
	}

	return status;
}

void ScriptManager::removeScript(const std::string& scriptId)
{
	std::map<std::string, Scriptlet*>::iterator fnd=mScriptlets.find(scriptId);

	Scriptlet* script=fnd->second;
	std::string scriptDir=script->getScriptDirectory();

	OSEnvironment::copyFolder(scriptDir, OSEnvironment::getFullPath(OSEnvironment::append("..\\recycled_scripts\\", OSEnvironment::getFileNameUsingCurrentTime())));

	delete script;
	mScriptlets.erase(fnd);

	boost::filesystem::remove_all(scriptDir);
}

void ScriptManager::refreshScripts()
{
	load();
}

void ScriptManager::exception(const char* source, const char* extra_info)
{
	lua_State* L=ScriptManager::getSingletonPtr()->getLuaState();
	//I tried to extract the source and currentline of the lua script error, but somehow i cannot get the lua_getinfo to work correctly
	/*
	lua_Debug d;
	lua_getstack(L, 1, &d);
	lua_getinfo(L, "Sln", &d);  
	*/
	std::string error_message=lua_tostring(L, -1);
	lua_pop(L, 1);
	std::ostringstream oss;
	/*
	if(d.name != NULL)
	{
		oss << d.short_src << ":" << d.currentline << "\n";
	}
	*/
	oss << error_message << "\n";
	if(strcmp(extra_info, "")!=0)
	{
		oss << "extra_info: [" << extra_info << "]";
	}
	throw Ogre::Exception(42, oss.str().c_str(), source);
}

Scriptlet* ScriptManager::getScriptlet(const std::string& scriptId) 
{
	std::map<std::string, Scriptlet*>::iterator fnd=mScriptlets.find(scriptId);
	if(fnd == mScriptlets.end())
	{
		return NULL;
	}
	return fnd->second;
}

void ScriptManager::addScriptlet(const std::string& scriptId)
{
	mScriptlets[scriptId]=new Scriptlet(scriptId, getFullPath(scriptId));
}


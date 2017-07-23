#ifndef _H_ML_LAB_LUA_STATE_H
#define _H_ML_LAB_LUA_STATE_H

#include <string>
#include <vector>
#include <map>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
};

#include <luabind/luabind.hpp> 
#include <luabind/object.hpp>
#include <luabind/class.hpp>
#include <luabind/function.hpp>

using namespace luabind;

#include "../CIAgents/CIAgent.h"
#include "Scriptlet.h"

#define LUA_CONST_START(C, L) { luabind::adl::object g = luabind::globals(L); luabind::adl::object table = g[#C]; 
#define LUA_CONST(C, name ) table[#name] = C::name 
#define LUA_CONST_END } 

/* the above defined constants translated to following codes
{
	luabind::adl::object g=luabind::globals(L);
	luabind::adl::object table=g["C"];
	table["name"]=C::name;
}
*/

class ScriptManager
{
public:
	virtual ~ScriptManager();
	ScriptManager();

private:
	ScriptManager(const ScriptManager& rhs) { }
	ScriptManager& operator=(const ScriptManager& rhs) { return *this; }

public:
	static ScriptManager* getSingletonPtr();
	static ScriptManager& getSingleton();

private:
	void createNicknames();
	void saveNicknames();
public:
	bool hasNickname(const std::string& name) const;
	const std::string& getNickname(const std::string& name) const;
	void setNickname(const std::string& name, const std::string& alias);
	void removeNickname(const std::string& name);
private:
	std::map<std::string, std::string> mNicknames;

protected:
	void load();
	void binds();
	void bindVector3();
	void bindMisc();
	void bindGameAgent();

protected:
	static ScriptManager* mSingleton;

public:
	const std::vector<std::string>& getScriptListings();
	bool isFuncExisted(const char* fname) const;
	int compileScript(const std::string& script) const;
	Scriptlet* getScriptlet(const std::string& scriptId);
	void addScriptlet(const std::string& scriptId);
	lua_State* getLuaState() { return m_pLuaState; }
	void removeScript(const std::string& scriptId);
	void refreshScripts();
	static void exception(const char* source, const char* extra_info="");

protected:
	std::string getFullPath(const std::string& path) const;

protected:
	std::string mScriptRootDirectory;
	std::vector<std::string> mScriptListings;
	std::map<std::string, Scriptlet*> mScriptlets;
	lua_State* m_pLuaState;
};

#endif
#ifndef _H_ML_LAB_SCRIPTLET_H
#define _H_ML_LAB_SCRIPTLET_H

#include <string>
#include <vector>
#include <map>

class Scriptlet
{
public:
	Scriptlet(const std::string& scriptId, const std::string& src);
	virtual ~Scriptlet();

protected:
	void parse();

public:
	const std::string& getScriptDirectory() const { return mScriptDirectory; }
	const std::string& getScriptClassPath() const { return mLuaScriptClassPath; }
	std::string toString() const;
protected:
	std::string getFullPath(const std::string& relpath) const;
	
public:
	int getRed() const { return mRed; }
	int getBlue() const { return mBlue; }
	int getGreen() const { return mGreen; }

private:
	std::string mScriptDirectory;
	std::string mLuaScriptClassPath;
	std::string mScriptId;
	std::string mSystemType;
	int mGreen;
	int mRed;
	int mBlue;
};
#endif
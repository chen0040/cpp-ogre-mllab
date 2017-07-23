#ifndef _H_ML_LAB_CI_CODE_AGENT_H
#define _H_ML_LAB_CI_CODE_AGENT_H

#include "CIAgent.h"
#include "CodeDesign/ConfigDlg.h"
#include "../tinyxml/tinyxml.h"

class CICodeAgent : public CIAgent
{
public:
	typedef std::set<CICodeAgent*> Set;
	typedef std::set<CICodeAgent*>::iterator SetIterator;
	typedef std::set<CICodeAgent*>::const_iterator ConstSetIterator;

public:
	CICodeAgent(const Vector3& pos, const std::string& agentName, const std::string& type, const std::string& method);
	virtual ~CICodeAgent();

public:
	virtual bool run(const std::string& cmd, Ogre::Real dt=0);
	virtual void activate(bool showPS=false);
	virtual void deactivate();
	void generateCode(const std::string& destinationFolderPath, const std::string& lang, const std::string& codeName);
	std::string toString() const;
	const std::string& getCIType() const { return mCIType; }
	const std::string& getCIMethod() const { return mCIMethod; }
	virtual void setPosition(const Vector3& pos);
	void saveConfigXml(TiXmlElement* xmlConfig);
	void loadConfigXml(TiXmlElement* xmlConfig);

protected:
	void config();

protected:
	std::string mCIType;
	std::string mCIMethod;
	ConfigDlg* mConfig;
	SceneNode* mPSNode;
	ParticleSystem* mAlphaParticleSystem;
};
#endif
#include "SoundManager.h"
#include <iostream>
#include <Ogre.h>
#include <sstream>
#include "../OSEnvironment/OSEnvironment.h"
#include "../tinyxml/tinyxml.h"

SoundManager* SoundManager::mSingleton=NULL;

SoundManager::SoundManager()
: m_theme_music(NULL)
, mEnabled(true)
{
	if(!FSOUND_Init (44100, 32, FSOUND_INIT_USEDEFAULTMIDISYNTH))
	{
		throw Ogre::Exception(42, "Failed to initialize FMOD", "SoundManager::SoundManager()");
	}

	TiXmlDocument doc;
	if(!doc.LoadFile(OSEnvironment::getFullPath("..\\config\\SoundEngine.xml").c_str()))
	{
		throw Ogre::Exception(42, "Failed to load SoundEngine.xml", "SoundManager::SoundManager()");
	}

	TiXmlElement* xmlRoot=doc.RootElement();
	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "sound")==0)
		{
			std::string name=xmlLevel1->Attribute("name");
			std::string src=OSEnvironment::getFullPath(xmlLevel1->Attribute("src"));

			if(!OSEnvironment::exists(src))
			{
				std::ostringstream osse;
				osse << "Failed to load \"" << src << "\"";
				throw Ogre::Exception(42, osse.str().c_str(), "SoundManager::SoundManager()");
			}

			mSoundFiles[name]=src;
		}
		else if(strcmp(xmlLevel1->Value(), "music")==0)
		{
			std::string name=xmlLevel1->Attribute("name");
			std::string src=OSEnvironment::getFullPath(xmlLevel1->Attribute("src"));

			if(!OSEnvironment::exists(src))
			{
				std::ostringstream osse;
				osse << "Failed to load \"" << src << "\"";
				throw Ogre::Exception(42, osse.str().c_str(), "SoundManager::SoundManager()");
			}

			mSongFiles[name]=src;
		}
	}
}

SoundManager::~SoundManager()
{
	FMUSIC_StopAllSongs();
	m_theme_music=NULL;

	std::map<std::string, FSOUND_SAMPLE*>::iterator pos=m_samples.begin();
	std::map<std::string, FSOUND_SAMPLE*>::iterator pos_end=m_samples.end();
	for(; pos != pos_end; ++pos)
	{
		FSOUND_Sample_Free(pos->second);
	}
	std::map<std::string, FMUSIC_MODULE*>::iterator posm=m_songs.begin();
	std::map<std::string, FMUSIC_MODULE*>::iterator posm_end=m_songs.end();
	for(; posm != posm_end; ++posm)
	{
		FMUSIC_FreeSong(posm->second);
	}
	FSOUND_Close();
}

SoundManager* SoundManager::getSingletonPtr()
{
	if(mSingleton == NULL)
	{
		mSingleton=new SoundManager();
	}
	return mSingleton;
}

SoundManager& SoundManager::getSingleton()
{
	if(mSingleton == NULL)
	{
		mSingleton=new SoundManager();
	}
	return *mSingleton;
}

void SoundManager::play(const std::string& sound)
{
	if(mEnabled==false)
	{
		return;
	}

	std::map<std::string, std::string>::iterator fnd=mSoundFiles.find(sound);
	if(fnd==mSoundFiles.end())
	{
		std::ostringstream osse;
		osse << "Sound (key: " << sound << ") is not found";
		throw Ogre::Exception(42, osse.str().c_str(), "play(const std::string& sound)");
	}

	const std::string& sound_file=fnd->second;

	FSOUND_PlaySound(FSOUND_FREE, get_sample(sound_file));
}

FSOUND_SAMPLE* SoundManager::get_sample(const std::string& sound_file)
{
	std::map<std::string, FSOUND_SAMPLE*>::const_iterator pos=m_samples.find(sound_file);
	if(pos!=m_samples.end())
	{
		return pos->second;
	}

	FSOUND_SAMPLE* pSample=FSOUND_Sample_Load(FSOUND_UNMANAGED, sound_file.c_str(), FSOUND_NORMAL, 0, 0);  
	if(pSample==NULL)
	{
		throw Ogre::Exception(42, "pSample==NULL", "SoundManager::play(const std::string& sound_file)");
	}

	m_samples[sound_file]=pSample;

	return pSample;
}

FMUSIC_MODULE* SoundManager::get_music(const std::string& music_file)
{
	std::map<std::string, FMUSIC_MODULE*>::const_iterator pos=m_songs.find(music_file);
	if(pos!=m_songs.end())
	{
		return pos->second;
	}

	FMUSIC_MODULE* pSong=FMUSIC_LoadSong(music_file.c_str());
	m_songs[music_file]=pSong;

	return pSong;
}

void SoundManager::playThemeMusic(const std::string& song, bool looped)
{
	if(mEnabled==false)
	{
		return;
	}
	std::map<std::string, std::string>::iterator fnd=mSongFiles.find(song);
	if(fnd==mSongFiles.end())
	{
		std::ostringstream osse;
		osse << "Song (key: " << song << ") is not found";
		throw Ogre::Exception(42, osse.str().c_str(), "playSong(const std::string& song)");
	}

	const std::string& song_file=fnd->second;

	FMUSIC_MODULE* music=get_music(song_file);
	if(m_theme_music==music)
	{
		return;
	}

	if(m_theme_music != NULL)
	{
		FMUSIC_StopSong(m_theme_music);
	}

	m_theme_music=get_music(song_file);

	FMUSIC_SetLooping(m_theme_music, looped);
	FMUSIC_PlaySong(m_theme_music);
}

void SoundManager::pauseThemeMusic()
{
	if(m_theme_music != NULL)
	{
		FMUSIC_SetPaused(m_theme_music, true);
	}
}

bool SoundManager::isThemeMusic(const std::string& song)
{
	std::map<std::string, std::string>::const_iterator fnd=mSongFiles.find(song);
	if(fnd==mSongFiles.end())
	{
		std::ostringstream osse;
		osse << "Song (key: " << song << ") is not found";
		throw Ogre::Exception(42, osse.str().c_str(), "playSong(const std::string& song)");
	}

	const std::string& song_file=fnd->second;

	FMUSIC_MODULE* music=get_music(song_file);

	return m_theme_music==music;
}

void SoundManager::unpauseThemeMusic()
{
	if(m_theme_music != NULL)
	{
		FMUSIC_SetPaused(m_theme_music, false);
	}
}

void SoundManager::stopThemeMusic()
{
	if(m_theme_music != NULL)
	{
		FMUSIC_StopSong(m_theme_music);
		m_theme_music=NULL;
	}
}

#ifndef _ML_LAB_SOUNDMANAGER_H__
#define _ML_LAB_SOUNDMANAGER_H__

#include <map>
#include <string>
#include "fmod/fmod.h"

class SoundManager
{
public:
	virtual ~SoundManager();

private:
	SoundManager();
	SoundManager(const SoundManager& rhs) { }
	SoundManager& operator=(const SoundManager& rhs) { return *this; }

public:
	static SoundManager* getSingletonPtr();
	static SoundManager& getSingleton();
	virtual void play(const std::string& sound);
	virtual void playThemeMusic(const std::string& song, bool looped=true);
	virtual void stopThemeMusic();
	virtual void unpauseThemeMusic();
	virtual void pauseThemeMusic();
	virtual bool isThemeMusic(const std::string& song);

private:
	bool mEnabled;
public:
	void enable() { mEnabled=true; }
	void disable() { mEnabled=false; }

protected:
	FSOUND_SAMPLE* get_sample(const std::string& sound_file);
	FMUSIC_MODULE* get_music(const std::string& music_file);

protected:
	static SoundManager* mSingleton;

public:
	std::map<std::string, FSOUND_SAMPLE*> m_samples;
	std::map<std::string, FMUSIC_MODULE*> m_songs;
	std::map<std::string, std::string> mSoundFiles;
	std::map<std::string, std::string> mSongFiles;
	FMUSIC_MODULE* m_theme_music;
};


#endif 
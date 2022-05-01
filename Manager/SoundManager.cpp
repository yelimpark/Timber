#include "SoundManager.h"
#include <list>

void SoundManager::Init()
{
	std::list<Sound*> loaded;

	loaded.push_back(new Sound());
}

void SoundManager::PlaySound(std::string id)
{
}

void SoundManager::StopSound()
{
	Sound soundSetup;
	soundSetup.stop();
}

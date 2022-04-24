#pragma once
#include "Singleton.h"
#include <SFML/Audio.hpp>
#include <map>

using namespace sf;

class SoundManager : public Singleton<SoundManager>
{
private:
	std::map<std::string, Sound*> resouceMap;

public:
	void Init();
	//void Release();

	void PlaySound(std::string id);

};
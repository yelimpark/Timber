#include "SceneManager.h"
#include "../Scene/StageScene.h"
#include "../Scene/CharaSelectScene.h"
#include "../Scene/MenuScene.h"
#include "../Scene/SetupScene.h"
#include "../Scene/LevelScene.h"
#include "../Scene/PlayerSelectScene.h"

GameVariables& SceneManager::GetGameVariables()
{
	return gameVal;
}

SceneManager::SceneManager()
	:currScene(SceneType::MENU)
{
	memset(scenes, NULL, sizeof(scenes));
}

void SceneManager::Init()
{
	scenes[(int)SceneType::MENU] = new MenuScene(*this);
	scenes[(int)SceneType::SETUP] = new SetupScene(*this);
	scenes[(int)SceneType::LEVEL] = new LevelScene(*this);
	scenes[(int)SceneType::PLAYER] = new PlayerSelectScene(*this);
	scenes[(int)SceneType::CHARA] = new CharaSelectScene(*this);
	scenes[(int)SceneType::STAGE] = new StageScene(*this);

	scenes[0]->Start();
}

void SceneManager::ReleaseAll()
{
	for (int i = 0; i < (int)SceneType::MAX; i++) {
		if (scenes[i] != nullptr) {
			delete scenes[i];
		}
	}
}

void SceneManager::ChangeScene(SceneType newScene)
{
	scenes[(int)currScene]->End();
	currScene = newScene;
	scenes[(int)currScene]->Start();
}

void SceneManager::HanddleInput(sf::Event& event)
{
	scenes[(int)currScene]->HanddleInput(event);
}

void SceneManager::Update(float dt)
{
	scenes[(int)currScene]->Update(dt);
}

void SceneManager::Render(sf::RenderWindow& window)
{
	scenes[(int)currScene]->Render(window);
}

SceneManager::~SceneManager()
{
	ReleaseAll();
}

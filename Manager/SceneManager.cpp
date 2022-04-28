#include "SceneManager.h"
#include "../Scene/StageScene.h"
#include "../Scene/CharaSelectScene.h"

SceneManager::SceneManager()
	:currScene(SceneType::CHARA)
{
	memset(scenes, NULL, sizeof(scenes));
}

void SceneManager::Init()
{
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

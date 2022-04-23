#include "SceneManager.h"
#include "../Scene/StageScene.h"
#include "../Scene/CharaSelectScene.h"

GameVariables& SceneManager::GetGameVariables()
{
	return gameVal;
}

SceneManager::SceneManager(SceneType s_type)
	:s_type(s_type)
{
}

void SceneManager::Init()
{

	scenes[(int)SceneType::MENU] = new MenuScene(*this);
	scenes[(int)SceneType::MENU] = new SetUp(*this);
	scenes[(int)SceneType::MENU] = new LevelScene(*this);
	scenes[(int)SceneType::LEVEL] = new PlayerSelectScene(*this);
	scenes[(int)SceneType::SETUP] = new CharaSelectScene(*this);
	scenes[(int)SceneType::PLAYER] = new StageScene(*this);
	

	scenes[0]->Init();
}

void SceneManager::ReleaseAll()
{
	for (int i = 0; i < (int)SceneType::MAX; i++) {
		delete scenes[i];
	}
}

void SceneManager::ChangeScene(SceneType newScene)
{
	scenes[(int)s_type]->End();
	s_type = newScene; 
	scenes[(int)s_type]->Init();
	scenes[(int)s_type]->Start();
}

void SceneManager::HanddleInput(sf::Event& event)
{
	scenes[(int)s_type]->HanddleInput(event);
}

void SceneManager::Update(float dt)
{
	scenes[(int)s_type]->Update(dt);
}

void SceneManager::render(sf::RenderWindow* window)
{
	scenes[(int)s_type]->render(window);
}

SceneManager::~SceneManager()
{
	for (int i = 0; i < (int)SceneType::MAX; i++) {
		delete scenes[i];
	}
}

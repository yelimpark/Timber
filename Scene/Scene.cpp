#include "Scene.h"

using namespace sf;
using namespace std;

Scene::Scene(SceneType s_type, sf::RenderWindow* window)
    :s_type(s_type), window(window)
{
}

Scene::~Scene()
{  
}

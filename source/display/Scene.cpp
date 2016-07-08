#include "display/Scene.h"

Scene::Scene()
{

}

void Scene::initScene()
{

}

void Scene::addChild(Node* node)
{
	nodeManager.getRoot()->addChild( node );
}

void Scene::pause()
{
	timeService.scenePause();
}

void Scene::resume()
{
	timeService.sceneResume();
}

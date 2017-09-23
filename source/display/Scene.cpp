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

Node* Scene::findChildByName(const std::string& name)
{
	return nodeManager.getRoot()->findChildByName( name );
}

void Scene::addKeyListener(KeyListener* listener)
{
	keyDispatcher.pushListener(listener);
}

void Scene::pause()
{
	timeService.scenePause();
}

void Scene::resume()
{
	timeService.sceneResume();
}

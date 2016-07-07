#include "display/Scene.h"

Scene::Scene(): root( new Node() ) { }

void Scene::initScene()
{

}

void Scene::addChild(Node* node)
{
	root->addChild( node );
}

void Scene::pause()
{
	timeService.scenePause();
}

void Scene::resume()
{
	timeService.sceneResume();
}

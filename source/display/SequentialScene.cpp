#include "Director.h"
#include "display/Scene.h"
#include "display/SequentialScene.h"

#include <cassert>

SequentialScene::SequentialScene(): nextScene(NULL) { }

void SequentialScene::setNextScene(Scene* next)
{
	nextScene = next;
}

void SequentialScene::changeScene()
{
	assert( NULL != nextScene );
	gDirector->replaceScene( nextScene );
}

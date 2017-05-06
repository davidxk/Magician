#ifndef _SEQUENTIAL_SCENE_H_
#define _SEQUENTIAL_SCENE_H_

#include "display/Scene.h"

//description of the class here
class SequentialScene: public Scene
{
public:
	SequentialScene();
	void setNextScene(Scene* next);
	void changeScene();
protected:
	Scene* nextScene;
};
#endif

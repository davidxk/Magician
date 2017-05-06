#ifndef _LETTER_SCENE_H_
#define _LETTER_SCENE_H_

#include "Magician.h"

//description of the class here
class LetterScene: public Scene
{
public:
	virtual void initScene();
	void changeScene();

	const int goOutPoint = 5000;
};
#endif

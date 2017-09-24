#ifndef _HELLO_WORLD_H_
#define _HELLO_WORLD_H_

#include "Magician.h"
#include <vector>

//description of the class here
class HelloWorld: public Scene
{
public:
	virtual void initScene() override;
	virtual void update() override;
};
#endif

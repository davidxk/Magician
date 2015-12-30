#ifndef _HELLO_WORLD_H_
#define _HELLO_WORLD_H_

#include "Magician.h"

//description of the class here
class HelloWorld
{
public:
	HelloWorld();
	~HelloWorld();
private:
	void addSnowFlake();
	void addSnowScreen();
	const int stdDure = 4000;
};
#endif

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
	void playBGM();
	void initXmasTree();
	void initSnowMan();
	void initShack();
	void initSanta();
	void initSnow();
	void initLayerAction();
	void addSnowFlake();
	void addSnowScreen();
	const int stdDure = 4000;
	const int lookRightPoint = 9300;
	const int lookUpPoint = 18700;
	const int goOutPoint = 37000;
	Layer mainLayer;
};
#endif

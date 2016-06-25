#ifndef _HELLO_WORLD_H_
#define _HELLO_WORLD_H_

#include "Magician.h"


#include <iostream>
class Responder: public KeyListener
{
public:
	virtual void respond(Key key) { std::cout<<"\a\a\a"; }
};


//description of the class here
class HelloWorld: public Scene
{
public:
	virtual void initScene();
	~HelloWorld();
private:
	void playBGM();
	void changeScene();
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
	Responder* responder;
};
#endif

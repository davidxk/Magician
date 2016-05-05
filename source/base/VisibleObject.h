#ifndef _VISIBLE_OBJECT_H_
#define _VISIBLE_OBJECT_H_

#include "basic/ColoredChar.h"
#include "basic/ConsoleCoord.h"
#include "basic/Coord.h"
#include <vector>
#include <string>
using namespace std;

class Action;

class VisibleObject
{
public:
	Coord pos;
	Coord center;
	Size size;
	Image image;
	int zOrder;
	bool isVisible;
	bool inAction;
	//bool isColored;
	VisibleObject();
	void verify();
	void addToManager();
	void setPos(const Coord cc);
	void setCenterPos(const Coord cc);
	void updateCenter();

	void runAction(Action* action);
	void pauseActions();
	void resumeActions();
};
#endif

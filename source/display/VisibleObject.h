#ifndef _VISIBLE_OBJECT_H_
#define _VISIBLE_OBJECT_H_

#include "basic/ColoredChar.h"
#include "basic/ConsoleCoord.h"
#include "basic/Coord.h"
#include "basic/Object.h"
#include <mutex>

class Action;

//All Visible Objects in the game is a child class of VisibleObject
//VisibleObject base class is a fundamental data structure
class VisibleObject: public Object
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
	mutex mtx;

public:
	VisibleObject();
	void verify();
	void addToManager();
	void setPos(const Coord cc);
	Coord getPos() const;
	void setCenterPos(const Coord cc);
	void updateCenter();
	void setForeColor(Color foreColor);
	void setBackColor(Color backColor);
	void setColor(Color foreColor, Color backColor);

	void runAction(Action* action);
	void runActionWithObject(Object* obj);
	void pauseActions();
	void resumeActions();
};
#endif

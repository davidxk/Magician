#ifndef _VISIBLE_OBJECT_H_
#define _VISIBLE_OBJECT_H_

#include "basic/ColoredChar.h"
#include "basic/ConsoleCoord.h"
#include "basic/Coord.h"
#include "basic/Object.h"
#include <mutex>

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
	Coord getPos() const;
	void setCenterPos(const Coord cc);
	void updateCenter();
	virtual void setPos(const Coord cc);
	virtual void setForeColor(Color foreColor);
	virtual void setBackColor(Color backColor);
	virtual void setColor(Color foreColor, Color backColor);
};
#endif

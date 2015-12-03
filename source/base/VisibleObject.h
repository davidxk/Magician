#ifndef _VISIBLE_OBJECT_H_
#define _VISIBLE_OBJECT_H_

#include "basic/ConsoleCoord.h"
#include "basic/Coord.h"
#include <vector>
#include <string>
using namespace std;

class VisibleObject
{
public:
	Coord pos;
	Size size;
	vector<wstring> image;
	int zOrder;
	bool isVisible;
	//bool isColored;
	void verify();
	void setPos(const Coord& cc);
};
#endif

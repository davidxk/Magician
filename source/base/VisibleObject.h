#include "ConsoleCoord.h"
#include <vector>

class VisibleObject
{
public:
	Coord pos;
	Size size;
	vector<string> image;
	int zOrder;
	bool isVisible;
	//bool isColored;
	VisibleObject();
	void verify();
	void setPos(const Coord& cc);
};

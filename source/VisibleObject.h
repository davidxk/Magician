#include "ConsoleCoord.h"

class VisibleObject
{
public:
	Coord pos;
	Size size;
	vector<string> image;
	int zOrder;
	bool isVisible;
	//color
	void verify();
};

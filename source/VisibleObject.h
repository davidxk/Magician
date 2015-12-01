#include "ConsoleCoord.h"

class VisibleObject
{
public:
	Coord pos;
	Size size;
	vector<string> image;
	bool isVisible;
	void verify();
};

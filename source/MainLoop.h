
#include "display/DisplayCentral.h"

class MainLoop
{
public:
	void readyGo();
	void update();
	static const int TIME_UNIT;
	DisplayCentral dc;
};

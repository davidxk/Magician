#include "MainLoop.h"
#include <thread>

int main()
{
	MainLoop ml;
	std::thread refresh( &MainLoop::readyGo(), std::ref( ml ) );
	refresh.detach();

	Sprite* sp = Sprite::create("graph/moon.txt");
	vManager.addObject( sp );

	MoveTo* mt = MoveTo::create(sp, 10, Coord(23, 79), true);
	aManager->addAction( mt );

	return 0;
}

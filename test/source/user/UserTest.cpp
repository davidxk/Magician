#include "user/UserTest.h"
#include <thread>
#include "MainLoop.h"
#include "display/ActionManager.h"
#include "display/VisibleObjManager.h"
#include "user/Sprite.h"
#include "user/MoveTo.h"

void UserTest::run()
{
	MainLoop ml;

	Sprite* sp = Sprite::create("graph/moon.txt");
	vManager->addObject( sp );

	MoveTo* mt = MoveTo::create(sp, 10, Coord(23, 79), true);
	aManager->addAction( mt );

	std::thread refresh( &MainLoop::readyGo, std::ref( ml ) );
	refresh.join();
}

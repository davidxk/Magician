#include "user/UserTest.h"
#include <thread>
#include "MainLoop.h"
#include "display/ActionManager.h"
#include "display/VisibleObjManager.h"
#include "user/Sprite.h"
#include "user/MoveTo.h"
#include "user/AnimSprite.h"
#include "user/Animation.h"

void UserTest::run()
{
	MainLoop ml;

	Sprite* sp = Sprite::create("graph/moon.txt");
	vManager->addObject( sp );
	MoveTo* mt = MoveTo::create(sp, 1000, Coord(23, 79));
	aManager->addAction( mt );

	AnimSprite* asp = AnimSprite::create("batch/moon_batch.txt");
	vManager->addObject( asp );
	Animation* anim = Animation::create(asp, 1000);
	aManager->addAction( anim );

	std::thread refresh( &MainLoop::readyGo, &ml );
	refresh.join();
}

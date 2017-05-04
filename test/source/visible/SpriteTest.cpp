#include "visible/SpriteTest.h"
#include <cassert>
#include "visible/Sprite.h"

void SpriteTest::run()
{
	testCreate();
}

void SpriteTest::testCreate()
{
	Sprite* sp = Sprite::create("graph/moon.txt");
	assert( sp->getSize() == Size(2, 4) );
	assert( sp->getCenterPos() == Coord(1, 2) );
	delete sp;
}

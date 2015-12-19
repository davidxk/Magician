#include "user/ActionTest.h"
#include "user/MoveTo.h"
#include "user/Repeat.h"
#include "user/Sequence.h"
#include "basic/MagicianMacros.h"
#include <cassert>

void ActionTest::run()
{
	sp = Sprite::create("graph/moon.txt");
	testMoveTo();
	testAnimation();
	testSequence();
	testRepeat();
	delete sp;
}

void ActionTest::testMoveTo()
{
	MoveTo* mt = MoveTo::create(sp, 100, Coord(23, 79), false);
	assert( mt->cmdQueue.size() == 100/magician::TIME_UNIT+1 );
	delete mt;
}

void ActionTest::testAnimation()
{

}

void ActionTest::testSequence()
{
	MoveTo* rush = MoveTo::create(sp, 100, Coord(23, 79), false);
	MoveTo* back = MoveTo::create(sp, 400, Coord(12, 30), false);
	int cmdLen = rush->cmdQueue.size() + back->cmdQueue.size();
	Sequence* seq = Sequence::create(rush, back);

	assert( seq->duration == 500 );
	assert( seq->cmdQueue.size() == cmdLen );
	delete seq;
}

void ActionTest::testRepeat()
{
	MoveTo* rush = MoveTo::create(sp, 100, Coord(23, 79), false);
	int cmdLen = rush->cmdQueue.size() * 5;
	Repeat* repe = Repeat::create(rush, 5);
	
	assert( repe->duration == 500 );
	//assert( repe->cmdQueue.size() == cmdLen);
	delete repe;
}

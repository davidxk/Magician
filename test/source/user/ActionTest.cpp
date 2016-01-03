#include "user/ActionTest.h"
#include "user/MoveBy.h"
#include "user/MoveTo.h"
#include "user/Repeat.h"
#include "user/Sequence.h"
#include "basic/TimeService.h"
#include <cassert>

void ActionTest::run()
{
	sp = Sprite::create("graph/moon.txt");
	sp->setPos( Coord(1, 2) );
	testMoveTo();
	testMoveBy();
	testAnimation();
	testSequence();
	testRepeat();
	delete sp;
}

void ActionTest::testMoveTo()
{
	MoveTo* mt = MoveTo::create(sp, 100, Coord(21, 70), false);
	assert( mt->cmdQueue.size() == 100 / TimeService::TIME_UNIT+1 );

	MoveTo* mt_2 = MoveTo::create(100, Coord(1, 2), Coord(21, 70), false);
	mt_2->setHost( sp );
	mt_2->initWithHost( sp );
	assert( mt->cmdQueue.size() == mt_2->cmdQueue.size() );
	assert( mt->cmdQueue.back().pos == mt_2->cmdQueue.back().pos );

	assert( mt->cmdQueue.front().pos == Coord(1, 2) );
	mt->cmdQueue.pop();
	//assert( mt->cmdQueue.front().pos == Coord(11, 36) );
	mt->cmdQueue.pop();
	//assert( mt->cmdQueue.front().pos == Coord(21, 70) );
	mt->cmdQueue.pop();
	delete mt, delete mt_2;
}

void ActionTest::testMoveBy()
{
	MoveBy* mb = MoveBy::create(sp, 100, Coord(30, 2), false);
	assert( mb->cmdQueue.size() == 100 / TimeService::TIME_UNIT+1 );

	MoveBy* mb_2 = MoveBy::create(100, Coord(30, 2), false);
	mb_2->setHost( sp );
	mb_2->initWithHost( sp );
	assert( mb->cmdQueue.size() == mb_2->cmdQueue.size() );
	assert( mb->cmdQueue.back().pos == mb_2->cmdQueue.back().pos );

	assert( mb->cmdQueue.front().pos == Coord(0, 0) );
	mb->cmdQueue.pop();
	assert( mb->cmdQueue.front().pos == Coord(15, 1) );
	mb->cmdQueue.pop();
	assert( mb->cmdQueue.front().pos == Coord(15, 1) );
	mb->cmdQueue.pop();

	delete mb, delete mb_2;
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
	assert( repe->cmdQueue.size() == cmdLen);
	delete repe;
}

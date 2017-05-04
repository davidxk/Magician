#include "action/ActionTest.h"
#include <cassert>
#include "action/Action.h"
#include "action/MoveBy.h"
#include "action/MoveTo.h"
#include "action/Repeat.h"
#include "action/Sequence.h"
#include "basic/TimeService.h"
#include "display/Node.h"

void ActionTest::run()
{
	testConstructor();
	testClone();

	sp = Sprite::create("graph/moon.txt");
	sp->setPos( Coord(1, 2) );
	testMoveTo();
	testMoveBy();
	testAnimation();
	testSequence();
	testRepeat();
	delete sp;
}

void ActionTest::testConstructor()
{
	Node node;
	Action action(&node, 0, false);
	assert(action.host==&node && action.duration==0 && 
			action.isRepeat==false && action.isPause==false);
}

void ActionTest::testClone()
{
	Node node;
	Action action(&node, 0, false);
	Action* clone = action.clone();
	assert( action.host==clone->host && action.duration==clone->duration &&
			action.isRepeat==clone->isRepeat && 
			action.isPause==clone->isPause && 
			action.cmdQueue==clone->cmdQueue );
	delete clone;
}

void ActionTest::testMoveTo()
{
	//MoveTo* mt = MoveTo::create(sp, 100, Coord(21, 70), false);
	//assert( mt->cmdQueue.size() == 100 / TimeService::TIME_UNIT+1 );

	//MoveTo* mt_2 = MoveTo::create(100, Coord(1, 2), Coord(21, 70), false);
	//mt_2->setHost( sp );
	//mt_2->initWithHost( sp );
	//assert( mt->cmdQueue.size() == mt_2->cmdQueue.size() );
	//auto back1 = (MoveByCommand) mt->cmdQueue.back();
	//auto back2 = (MoveByCommand) mt_2->cmdQueue.back();
	//assert( back1.pos == back2.pos );

	//auto front = (MoveToCommand) mt->cmdQueue.front();
	//assert( front.pos == Coord(1, 2) );
	//mt->cmdQueue.pop();
	////assert( mt->cmdQueue.front().pos == Coord(11, 36) );
	//mt->cmdQueue.pop();
	////assert( mt->cmdQueue.front().pos == Coord(21, 70) );
	//mt->cmdQueue.pop();
	//delete mt, delete mt_2;
}

void ActionTest::testMoveBy()
{
	//MoveBy* mb = MoveBy::create(sp, 100, Coord(30, 2), false);
	//assert( mb->cmdQueue.size() == 100 / TimeService::TIME_UNIT+1 );

	//MoveBy* mb_2 = MoveBy::create(100, Coord(30, 2), false);
	//mb_2->setHost( sp );
	//mb_2->initWithHost( sp );
	//assert( mb->cmdQueue.size() == mb_2->cmdQueue.size() );
	//auto back1 = (MoveByCommand)mb->cmdQueue.back();
	//auto back2 = (MoveByCommand)mb_2->cmdQueue.back();
	//assert( back1.pos == back2.pos );

	//auto front = (MoveByCommand)mb->cmdQueue.front();
	//mb->cmdQueue.pop();
	//assert( front.pos == Coord(0, 0) );
	//front = (MoveByCommand)mb->cmdQueue.front();
	//mb->cmdQueue.pop();
	//assert( front.pos == Coord(15, 1) );
	//front = (MoveByCommand)mb->cmdQueue.front();
	//mb->cmdQueue.pop();
	//assert( front.pos == Coord(15, 1) );
	//mb->cmdQueue.pop();

	//delete mb, delete mb_2;
}

void ActionTest::testAnimation()
{

}

void ActionTest::testSequence()
{
	MoveTo* rush = MoveTo::create(sp, 100, Coord(23, 79));
	MoveTo* back = MoveTo::create(sp, 400, Coord(12, 30));
	int cmdLen = rush->cmdQueue.size() + back->cmdQueue.size();
	Sequence* seq = Sequence::create(rush, back);

	assert( seq->duration == 500 );
	assert( seq->cmdQueue.size() == cmdLen );
	delete seq;
}

void ActionTest::testRepeat()
{
	MoveTo* rush = MoveTo::create(sp, 100, Coord(23, 79));
	int cmdLen = rush->cmdQueue.size() * 5;
	Repeat* repe = Repeat::create(rush, 5);
	
	assert( repe->duration == 500 );
	assert( repe->cmdQueue.size() == cmdLen);
	delete repe;
}

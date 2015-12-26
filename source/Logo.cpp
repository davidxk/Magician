#include "Logo.h"

#include <chrono>
#include <functional>
#include <thread>
#include "Magician.h"

Logo::Logo(): isEnd( false )
{
	initAnim();
	scheduleTransition();
}

int Logo::getTotalTime()
{
	return N_WAVE * DURE_WAVE + DURE_JUMP;
}

void Logo::initAnim()
{
	//create wand sprite
	AnimSprite* wand = AnimSprite::create("logo/wand_batch_1.txt");
	wand->setCenterPos( Coord(6, 39) );
	//wand actions
	Animation* wave = Animation::create( wand, DURE_WAVE);
	Repeat* repe = Repeat::create( wave, N_WAVE );
	Vanish* vani = Vanish::create( wand );
	Sequence* repeVani = Sequence::create( repe, vani );
	wand->runAction(repeVani);



	//create rabbit sprite
	AnimSprite* rabbit = AnimSprite::create("logo/rabbit_batch.txt");
	rabbit->setCenterPos( Coord(11, 39) );
	//rabbit actions
	Action* wait = Sleep::create( rabbit, DURE_WAVE * N_WAVE );
	Animation* jump = Animation::create( rabbit, DURE_JUMP );
	Sequence* waitJump = Sequence::create( wait, jump );
	rabbit->runAction( waitJump );

	//add in zOrder sequence
	vManager->addObject( rabbit );
	vManager->addObject( wand );
}

void Logo::scheduleTransition()
{
	//schedule set end = true at the endding time point of this scene
	const int totalTime = getTotalTime();
	//auto func = std::bind( &Logo::setEnd, this );
	//gScheduler->schedule( func, totalTime );
	//while not end, block this thread
	std::this_thread::sleep_for( std::chrono::milliseconds(totalTime) );
}

void Logo::setEnd()
{
	isEnd = true;
}

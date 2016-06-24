#include "Logo.h"

#include <chrono>
#include <thread>

void Logo::initScene()
{
	initHat();
	auto animGo = std::bind(&Logo::initAnim, this);
	gScheduler->schedule(animGo, HAT_PAUSE);
	auto logoFly = std::bind(&Logo::logoFlyIn, this);
	gScheduler->schedule(logoFly, getAnimTime());
	//initAnim();
	scheduleTransition();
}

int Logo::getAnimTime()
{
	return HAT_PAUSE + N_WAVE * DURE_WAVE + DURE_JUMP + PAUSE_TIME;
}

int Logo::getTotalTime()
{
	return getAnimTime() + DURE_MOVEL + DURE_FLYIN + SHOW_TIME;
}

void Logo::initHat()
{
	//create rabbit sprite
	rabbit = AnimSprite::create("logo/rabbit_batch.txt");
	rabbit->setCenterPos( Coord(ConsoleCoord::MAX_LINES/2,
			   	ConsoleCoord::MAX_COLUMN/2) );
	vManager->addObject( rabbit );
}

void Logo::initAnim()
{
	//create wand sprite
	AnimSprite* wand = AnimSprite::create("logo/wand_batch_1.txt");
	wand->setCenterPos( Coord(6, ConsoleCoord::MAX_COLUMN/2) );
	vManager->addObject( wand );
	//wand actions
	Animation* wave = Animation::create( wand, DURE_WAVE);
	Repeat* repe = Repeat::create( wave, N_WAVE );
	Vanish* vani = Vanish::create( wand );
	Sequence* repeVani = Sequence::create( repe, vani );
	wand->runAction(repeVani);


	//rabbit actions
	Action* wait = Sleep::create( rabbit, DURE_WAVE * N_WAVE );
	Animation* jump = Animation::create( rabbit, DURE_JUMP );
	Sequence* waitJump = Sequence::create( wait, jump );
	rabbit->runAction(waitJump);
}

void Logo::logoFlyIn()
{
	MoveBy* moveLeft = MoveBy::create(rabbit,DURE_MOVEL,Coord::CoordXY(-20, 0));
	rabbit->runAction( moveLeft );

	Sprite* logo = Sprite::create("logo/logo_design_stick_letters.txt");
	logo->setCenterPos( Coord::CoordXY(56, 26) );
	vManager->addObject( logo );

	Action* wait = Sleep::create( logo, DURE_MOVEL );
	MoveBy* flyin = MoveBy::create(logo, DURE_FLYIN, Coord::CoordXY(0, -15));
	Sequence* waitFlyin = Sequence::create( wait, flyin );
	logo->runAction(waitFlyin);
}

void Logo::scheduleTransition()
{
	//int sleepTime = getTotalTime();
	//std::this_thread::sleep_for( std::chrono::milliseconds(sleepTime) );
	//Transition::releasePrev();
}

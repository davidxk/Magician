#include "HelloWorld.h"
#include <chrono>
#include <thread>

HelloWorld::HelloWorld()
{
	//Music here
	MciPlayer mci;
	mci.start("bgm/we_wish_you_a_merry_christmas_12.mp3");
	
	//Sprites with Animation
	AnimSprite* xmasTree = AnimSprite::create("snowy/tree_batch.txt");
	vManager->addObject( xmasTree );
	Animation* blink = Animation::create( xmasTree, 1000, true );
	aManager->addAction( blink );

	AnimSprite* snowMan = AnimSprite::create("snowy/snow_man_batch.txt");
	vManager->addObject( snowMan );
	Animation* wave = Animation::create( snowMan, 1000, true );
	aManager->addAction( wave );
	snowMan->setPos( Coord(12, 42) );

	std::this_thread::sleep_for(std::chrono::seconds( 5 ));
	//snow flakes here
	addSnowScreen();
	auto addSnowFunc = std::bind(&HelloWorld::addSnowScreen, this);
	gScheduler->scheduleAfter( addSnowFunc, stdDure );
	//gScheduler->schedule( addSnowFunc, 2*stdDure );


	VisibleObject sp = VisibleObject();
	MoveBy* move = MoveBy::create( &sp, 5000, Coord::CoordXY(-40, 0));
	Layer mainLayer;
	mainLayer.addObject( xmasTree );
	mainLayer.addObject( snowMan );
	//mainLayer.scheduleActionAfter(move, 4000);
}

void HelloWorld::addSnowScreen()
{
	const int N_SNOW_FLAKES = 20;
	for(int i=0; i<N_SNOW_FLAKES; i++)
		addSnowFlake();
}

void HelloWorld::addSnowFlake()
{
	Sprite* snowFlake = Sprite::create("snowy/snow_flake.txt");
	vManager->addObject( snowFlake );

	int xx = Random::randomPositive( ConsoleCoord::MAX_COLUMN+1 );
	int yy = Random::randomNegative( - (ConsoleCoord::MAX_LINES+1) );
	snowFlake->setPos( Coord::CoordXY(xx, yy) );

	const int num24 = ConsoleCoord::MAX_LINES + 1;
	const int distance = Random::randomRange(num24 * 2, num24 * 2.5);
	MoveBy* mb = MoveBy::create( snowFlake, stdDure/num24*distance, 
		Coord::CoordXY( 0, distance ), true);
	snowFlake->runAction( mb );
}

HelloWorld::~HelloWorld()
{

}

#include "HelloWorld.h"
#include <chrono>
#include <thread>

HelloWorld::HelloWorld()
{
	playBGM();
	
	//init Sprites with Animation
	initXmasTree();
	initSnowMan();
	initShack();
	initSanta();
	initSnow();

	initLayerAction();
}

void HelloWorld::playBGM()
{
	MciPlayer mci;
	mci.start("bgm/we_wish_you_a_merry_christmas_12.mp3");
}

void HelloWorld::initXmasTree()
{
	AnimSprite* xmasTree = AnimSprite::create("snowy/tree_batch.txt");
	vManager->addObject( xmasTree );
	mainLayer.addObject( xmasTree );
	Animation* blink = Animation::create( xmasTree, 1000, true );
	aManager->addAction( blink );
}

void HelloWorld::initSnowMan()
{
	AnimSprite* snowMan = AnimSprite::create("snowy/snow_man_batch.txt");
	vManager->addObject( snowMan );
	mainLayer.addObject( snowMan );
	Animation* wave = Animation::create( snowMan, 1000, true );
	aManager->addAction( wave );
	snowMan->setPos( Coord(12, 42) );
}

void HelloWorld::initShack()
{
	Sprite* shack = Sprite::create("snowy/larger_house.txt");
	shack->setPos( Coord(4,85 ) );
	vManager->addObject( shack );
	mainLayer.addObject( shack );

	AnimSprite* smoke = AnimSprite::create("snowy/smoke_batch.txt");
	smoke->setPos( Coord(-3,101) );
	vManager->addObject( smoke );
	mainLayer.addObject( smoke );

	Animation* sway = Animation::create( smoke, 500, true);
	aManager->addAction( sway );
}

void HelloWorld::initSanta()
{
	Layer santaLayer;

	Sprite* santa = Sprite::create("snowy/santa_sleigh.txt");
	vManager->addObject( santa );
	mainLayer.addObject( santa );

	Coord finalPos = Coord( -34,85 );
	Coord startPos = finalPos + Coord(-12,40);
	Coord santaPos = finalPos;
	//santa->setPos( startPos );
	//MoveTo* flyin = MoveTo::create(santa, 3000, finalPos);
	//aManager->scheduleAfter( flyin, lookUpPoint+2000 );
	santa->setPos( santaPos );

	AnimSprite* hat = AnimSprite::create("snowy/hat_batch.txt");
	vManager->addObject( hat );
	mainLayer.addObject( hat );
	hat->setPos( santaPos+Coord(0,22) );

	Animation* flutter = Animation::create(hat, 500, true);
	aManager->addAction( flutter );
	
	AnimSprite* eye = AnimSprite::create("snowy/eye_batch.txt");
	vManager->addObject( eye );
	mainLayer.addObject( eye );
	eye->setPos( santaPos+Coord(3,25) );

	Animation* blink = Animation::create(eye, 250);
	Repeat* rep = Repeat::create( blink, 2 );
	Sequence* seq = Sequence::create( rep, Sleep::create(eye,4000), true );
	aManager->addAction( seq );

	AnimSprite* arm = AnimSprite::create("snowy/arm_batch.txt");
	vManager->addObject( arm );
	mainLayer.addObject( arm );
	arm->setPos( santaPos+Coord(2,28) );

	Animation* wave = Animation::create(arm, 450, true);
	Repeat* re = Repeat::create( wave, 5 );
	Sequence* se_0 = Sequence::create( Appear::create(arm), re );
   	Sequence* se_1 = Sequence::create( se_0, Vanish::create( arm ) );
	Sequence* sequ = Sequence::create( se_1, Sleep::create(arm,6000),true );
	aManager->addAction( sequ );
}

void HelloWorld::initSnow()
{
	std::this_thread::sleep_for(std::chrono::seconds( 5 ));
	addSnowScreen();
	auto addSnowFunc = std::bind(&HelloWorld::addSnowScreen, this);
	gScheduler->scheduleAfter( addSnowFunc, stdDure );
	//gScheduler->schedule( addSnowFunc, 2*stdDure );
}

void HelloWorld::initLayerAction()
{
	MoveBy* moveLeft = MoveBy::create( 5000, Coord::CoordXY(-65, 0));
	mainLayer.scheduleActionAfter(moveLeft, lookRightPoint);

	MoveBy* moveUp = MoveBy::create( 5000, Coord::CoordXY(0, 37));
	mainLayer.scheduleActionAfter(moveUp, lookUpPoint);
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
	//mainLayer.addObject( snowFlake );

	int xx = Random::randomPositive( ConsoleCoord::MAX_COLUMN+1 );
	int yy = Random::randomNegative( - (ConsoleCoord::MAX_LINES+1) );
	snowFlake->setPos( Coord::CoordXY(xx, yy) );

	const int num24 = ConsoleCoord::MAX_LINES + 1;
	const int distance = Random::randomRange(num24 * 2, num24 * 2.5);
	MoveTo* mb = MoveTo::create( snowFlake, stdDure/num24*distance, 
			snowFlake->pos + Coord::CoordXY( 0, distance ), true);
	snowFlake->runAction( mb );
}

HelloWorld::~HelloWorld()
{
}

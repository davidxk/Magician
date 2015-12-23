#include "HelloWorld.h"

HelloWorld::HelloWorld()
{
	AnimSprite* xmasTree = AnimSprite::create("snowy/tree_batch.txt");
	vManager->addObject( xmasTree );
	Animation* blink = Animation::create( xmasTree, 1000, true );
	aManager->addAction( blink );

	AnimSprite* snowMan = AnimSprite::create("snowy/snow_man_batch.txt");
	vManager->addObject( snowMan );
	Animation* wave = Animation::create( snowMan, 1000, true );
	aManager->addAction( wave );
	snowMan->setPos( Coord(12, 42) );

	//snow flakes here

	//MoveBy* move = MoveTo::create( NULL, 1000, Coord(-40, 0), false)
	Layer mainLayer;
	mainLayer.addObject( xmasTree );
	mainLayer.addObject( snowMan );
	//mainLayer.schedule(move, 4000);
}

HelloWorld::~HelloWorld()
{

}

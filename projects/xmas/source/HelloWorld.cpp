#include "HelloWorld.h"

HelloWorld::HelloWorld()
{
	AnimSprite* asp = AnimSprite::create("snowy/tree_batch.txt");
	vManager->addSprite( asp );
	Animation* anim = Animation::create( asp, 1000, true );
	aManager->addAction( anim );
}

HelloWorld::~HelloWorld()
{

}

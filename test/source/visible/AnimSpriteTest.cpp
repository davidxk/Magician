#include "visible/AnimSpriteTest.h"
#include <cassert>
#include "visible/AnimSprite.h"

void AnimSpriteTest::run()
{
	testCreate();
	testSetDisplayImage();
}

void AnimSpriteTest::testCreate()
{
	AnimSprite* as = AnimSprite::create("batch/moon_batch.txt");
	assert( as->getSize() == Size(1, 4) );
	assert( as->getCenterPos() == Coord(0, 2) );
	assert( as->getImage().size() == 1 );
	assert( ImageUtil::ImageLine2str(as->getImage()[0]) == "1234" );
	delete as;
}

void AnimSpriteTest::testSetDisplayImage()
{
	AnimSprite* as = AnimSprite::create("batch/moon_batch.txt");
	as->setDisplayImage( 1 );
	assert( as->getImage().size() == 1 );
	assert( ImageUtil::ImageLine2str(as->getImage()[0]) == "4444" );
	delete as;
}

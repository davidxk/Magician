#include "HelloWorld.h"

void HelloWorld::initScene()
{
	//Cursor* cursor = Cursor::create("cursor.txt");
	Cursor* cursor = new Cursor("cursor.txt");
	addChild( cursor );
	gDirector->getKeyDispatcher()->pushListener( cursor );

	AnimCursor* coco = new AnimCursor("coco_batch.txt");
	coco->setCenterPos( Coord(20, 20) );
	addChild( coco );
	gDirector->getKeyDispatcher()->pushListener( coco );
}

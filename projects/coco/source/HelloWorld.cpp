#include "HelloWorld.h"
#include "Coco.h"

void HelloWorld::initScene()
{
	//Cursor* cursor = Cursor::create("cursor.txt");
	Cursor* cursor = new Cursor("cursor.txt");
	addChild( cursor );
	gDirector->getKeyDispatcher()->pushListener( cursor );

	Coco* coco = new Coco("coco_batch.txt");
	coco->setCenterPos( Coord(20, 20) );
	addChild( coco );
	gDirector->getKeyDispatcher()->pushListener( coco );
}

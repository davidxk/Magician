#include "HelloWorld.h"

void HelloWorld::initScene()
{
	//Cursor* cursor = Cursor::create("cursor.txt");
	Cursor* cursor = new Cursor("cursor.txt");
	cursor->addToManager();
	gMainLoop->getKeyDispatcher()->pushListener( cursor );

	AnimCursor* coco = new AnimCursor("coco_batch.txt");
	coco->setCenterPos( Coord(20, 20) );
	coco->addToManager();
	gMainLoop->getKeyDispatcher()->pushListener( coco );
}

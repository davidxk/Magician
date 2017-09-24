#include "HelloWorld.h"
#include "Coco.h"
#include "CollisionUtil.h"

void HelloWorld::initScene()
{
	//Cursor* cursor = Cursor::create("cursor.txt");
	Cursor* cursor = new Cursor("cursor.txt");
	addChild( cursor );
	gDirector->getKeyDispatcher()->pushListener( cursor );

	Coco* coco = new Coco("coco_batch.txt");
	coco->setName("Coco");
	coco->setCenterPos( Coord(20, 20) );
	addChild( coco );
	gDirector->getKeyDispatcher()->pushListener( coco );

	Sprite* arrow = Sprite::create("arrow.txt");
	arrow->setName("Arrow");
	arrow->setPos( Coord(20, 80) );
	addChild( arrow );
	Action* shoot = MoveTo::create(arrow, 3000, Coord(20, -10));
	shoot->isRepeat = true;
	arrow->runAction(shoot);
	//arrow->runAction( MoveBy::create( 3000, Coord::CoordXY(-90, 0)) );
}

void HelloWorld::update()
{
	Node* coco = findChildByName("Coco");
	Node* arrow = findChildByName("Arrow");
	if( CollisionUtil::detectCollision(coco, arrow) )
		coco->runAction(Blink::create(1000, 4));
}

#include "display/VisibleObjectTest.h"
#include <cassert>
#include "display/VisibleObject.h"

void VisibleObjectTest::run()
{
	testSetPos();
}

void VisibleObjectTest::testSetPos()
{
	VisibleObject vo;
	vo.setPos( Coord(1, 2) );
}

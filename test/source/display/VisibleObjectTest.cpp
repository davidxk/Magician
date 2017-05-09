#include "display/VisibleObjectTest.h"
#include <cassert>
#include "display/VisibleObject.h"

void VisibleObjectTest::run()
{
	testSetPos();
	testSetCenterPos();
}

void VisibleObjectTest::testSetPos()
{
	VisibleObject vo;
	const Coord coord(1, 2);
	vo.setPos( coord );
	assert( vo.getPos() == coord );
}

void VisibleObjectTest::testSetCenterPos()
{
	VisibleObject vo;
	const Coord coord(2, 4);
	vo.setPos( coord );
	vo.setCenterPos( coord );
	assert(vo.getCenterPos() == coord);

	Image img;
	img.push_back(ImageUtil::str2ImageLine("1234"));
	vo.setImage(img);
	assert(vo.getCenterPos() != coord);

	vo.setCenterPos( coord );
	assert(vo.getCenterPos() == coord);
}

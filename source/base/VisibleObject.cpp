#include "base/VisibleObject.h"

#include <cassert>

VisibleObject::VisibleObject():
	zOrder(0), isVisible(true), inAction(false) { }

void VisibleObject::verify()
{
	//A visible object should be verified before being registered 
	//Only registered objects are printed
	assert(size.line > 0);
	assert(size.column > 0);
	assert( center==( pos + size )/2 );

	assert(size.line == image.size());
	for(const auto& it: image)
		assert(size.column == it.size());
}

void VisibleObject::setPos(const Coord cc)
{
	this->pos = cc;
}

void VisibleObject::setCenterPos(const Coord cc)
{
	setPos( cc - center );
}

void VisibleObject::updateCenter()
{
	center = ( pos + size )/2;
}

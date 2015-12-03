#include "base/VisibleObject.h"

#include <cassert>

void VisibleObject::verify()
{
	//A visible object should be verified before being registered 
	//Only registered objects are printed
	assert(size.line > 0);
	assert(size.column > 0);

	int column = image[0].length();
	assert(size.line == image.size());
	assert(size.column == column);
	for(const auto& it: image)
		assert(it.length() == column);
}

void VisibleObject::setPos(const Coord cc)
{
	this->pos = cc;
}

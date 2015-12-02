#include "VisibleObject.h"

#include <cassert>

void VisibleObject::verify()
{
	//A visible object should be verified before being registered 
	//Only registered objects are printed
	int colume = image[0].length();
	assert(size.line == image.size());
	assert(size.colume == colume);
	for(const auto& it: image)
		assert(it->length() == colume);
}

void VisibleObject::setPos(const Coord& cc)
{
	this->pos = pos;
}

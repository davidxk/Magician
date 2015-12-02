#include "VisibleObject.h"

#include <cassert>

VisibleObject::VisibleObject()
{
	size = Size( image.size(), image[0].size() );
}

void VisibleObject::verify()
{
	//A visible object should be verified before being registered 
	//Only registered objects are printed
	assert(size.line > 0);
	assert(size.colume > 0);

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

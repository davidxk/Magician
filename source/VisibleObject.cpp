#include "VisibleObject.h"

#include <cassert>

void VisibleObject::verify()
{
	//A visible object should be verified before being registered 
	//Only registered objects are printed
	int colume = image[0].length();
	for(const auto& it: image)
		assert(it->length() == colume);
}

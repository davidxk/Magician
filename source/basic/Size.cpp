#include "basic/Size.h"
#include <cassert>

Size::Size(int aLine, int aColumn): OrderedPair(aLine, aColumn)
{ 
	verify();
}

void Size::verify()
{
	assert( line>=0 && column>=0 );
}

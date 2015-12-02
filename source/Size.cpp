#include "Size.h"

Size::Size(): line(0), column(0) 
{ 
	verify();
}

void Size::verify()
{
	assert( line>0 && column>0 );
}

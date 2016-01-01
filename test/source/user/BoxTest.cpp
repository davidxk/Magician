#include "user/BoxTest.h"

#include <cassert>
#include "basic/Size.h"
#include "user/DiaBox.h"

void BoxTest::run()
{
	DiaBox* dbox = DiaBox::create( Size(4, 36), 
			L"this is the first line of a box this is the second line o lala");

	assert( dbox->image.size() == 4 );
	assert( dbox->image[0] == L" ----------------------------------.");
	assert( dbox->image[1] == L"| this is the first line of a box  |");
	assert( dbox->image[2] == L"| this is the second line o lala   |");
	assert( dbox->image[3] == L"`---------------------------------- ");
}

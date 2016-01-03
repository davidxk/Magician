#include "user/BoxTest.h"

#include <cassert>
#include "basic/Size.h"
#include "user/DiaBox.h"
#include "user/TextField.h"

void BoxTest::run()
{
	testDiaBox();
	testTextField();
}

void BoxTest::testDiaBox()
{
	DiaBox* dbox = DiaBox::create( Size(4, 36), 
			L"this is the first line of a box this is the second line o lala");

	assert( dbox->image.size() == 4 );
	assert( dbox->image[0] == L" ----------------------------------.");
	assert( dbox->image[1] == L"| this is the first line of a box  |");
	assert( dbox->image[2] == L"| this is the second line o lala   |");
	assert( dbox->image[3] == L"`---------------------------------- ");
}

void BoxTest::testTextField()
{
	TextField* ttf = TextField::create( Size(4, 14), 
			L"Dear Julie,\n    Merry Christmas!\nYours,");
	TextField* ttf_2 = TextField::create( Size(3, 14), 
			L"Dear Julie,\n    Merry Christmas!\nYours,");
	TextField* ttf_3 = TextField::create( Size(5, 14), 
			L"Dear Julie,\n    Merry Christmas!\nYours,");

	assert( ttf->image.size() == 4 );
	assert( ttf->image[0] == L"Dear Julie,   ");
	assert( ttf->image[1] == L"    Merry Chri");
	assert( ttf->image[2] == L"stmas!        ");
	assert( ttf->image[3] == L"Yours,        ");
}

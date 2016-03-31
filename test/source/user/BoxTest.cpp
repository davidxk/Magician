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
			"this is the first line of a box this is the second line o lala");

	assert( dbox->image.size() == 4 );
	assert( dbox->image[0] == " ----------------------------------.");
	assert( dbox->image[1] == "| this is the first line of a box  |");
	assert( dbox->image[2] == "| this is the second line o lala   |");
	assert( dbox->image[3] == "`---------------------------------- ");
	delete dbox;
}

void BoxTest::testTextField()
{
	TextField* ttf = TextField::create( Size(4, 14), 
			"Dear Julie,\n    Merry Christmas!\nYours,");
	TextField* ttf_2 = TextField::create( Size(3, 14), 
			"Dear Julie,\n    Merry Christmas!\nYours,");
	TextField* ttf_3 = TextField::create( Size(5, 14), 
			"Dear Julie,\n    Merry Christmas!\nYours,");

	assert( ttf->image.size() == 4 );
	assert( ttf->image[0] == "Dear Julie,   ");
	assert( ttf->image[1] == "    Merry Chri");
	assert( ttf->image[2] == "stmas!        ");
	assert( ttf->image[3] == "Yours,        ");
	delete ttf, delete ttf_2, delete ttf_3;
}

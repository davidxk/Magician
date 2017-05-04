#include "visible/DiaBoxTest.h"
#include <cassert>
#include "basic/Size.h"
#include "visible/DiaBox.h"

void DiaBoxTest::run()
{
	testConstructor();
}

void DiaBoxTest::testConstructor()
{
	DiaBox* dbox = DiaBox::create( Size(4, 36), 
			"this is the first line of a box this is the second line o lala");

	assert( dbox->getImage().size() == 4 );
	assert( ImageUtil::ImageLine2str( dbox->getImage()[0] ) ==
			" ----------------------------------.");
	assert( ImageUtil::ImageLine2str( dbox->getImage()[1] ) ==
			"| this is the first line of a box  |");
	assert( ImageUtil::ImageLine2str( dbox->getImage()[2] ) == 
			"| this is the second line o lala   |");
	assert( ImageUtil::ImageLine2str( dbox->getImage()[3] ) == 
			"`---------------------------------- ");
	delete dbox;
}

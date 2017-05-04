#include "visible/BoxTest.h"
#include <cassert>
#include "basic/Size.h"
#include "visible/Box.h"

void BoxTest::run()
{
	testConstructor();
}

void BoxTest::testConstructor()
{
	//test Box shape
	Box box(Size(3, 6));
	for(const auto& line: box.getImage())
		assert(box.getImage().size()==3 && line.size()==6);
	assert(ImageUtil::ImageLine2str( box.getImage()[0] ) == " ----.");
	assert(ImageUtil::ImageLine2str( box.getImage()[1] ) == "|    |");
	assert(ImageUtil::ImageLine2str( box.getImage()[2] ) == "`---- ");
}

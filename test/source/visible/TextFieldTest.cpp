#include "visible/TextFieldTest.h"
#include <cassert>
#include "basic/Size.h"
#include "visible/TextField.h"

void TextFieldTest::run()
{
	testCreate();
}

void TextFieldTest::testCreate()
{
	TextField* ttf = TextField::create( Size(4, 14), 
			"Dear Julie,\n    Merry Christmas!\nYours," );

	assert( ttf->getImage().size() == 4 );
	assert( ImageUtil::ImageLine2str( ttf->getImage()[0] ) == "Dear Julie,   ");
	assert( ImageUtil::ImageLine2str( ttf->getImage()[1] ) == "    Merry Chri");
	assert( ImageUtil::ImageLine2str( ttf->getImage()[2] ) == "stmas!        ");
	assert( ImageUtil::ImageLine2str( ttf->getImage()[3] ) == "Yours,        ");
	delete ttf;
}

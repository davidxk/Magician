#include "visible/VisibleSuite.h"

#include "visible/AnimSpriteTest.h"
#include "visible/BoxTest.h"
#include "visible/DiaBoxTest.h"
#include "visible/ImageLoaderTest.h"
#include "visible/SpriteTest.h"
#include "visible/TextFieldTest.h"

VisibleSuite::VisibleSuite()
{
	addTestCase( new ImageLoaderTest );
	addTestCase( new SpriteTest );
	addTestCase( new AnimSpriteTest );
	addTestCase( new TextFieldTest );
	addTestCase( new BoxTest );
	addTestCase( new DiaBoxTest );
}

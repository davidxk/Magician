#include "display/DisplaySuite.h"
#include "display/DisplayCentralTest.h"
#include "display/VisibleObjectTest.h"
#include "display/VisibleObjManagerTest.h"

DisplaySuite::DisplaySuite()
{
	addTestCase(new DisplayCentralTest);
	addTestCase(new VisibleObjectTest);
	addTestCase(new VisibleObjManagerTest);
}

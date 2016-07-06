#include "display/DisplaySuite.h"
#include "display/DisplayCentralTest.h"
#include "display/NodeManagerTest.h"
#include "display/NodeTest.h"
#include "display/VisibleObjectTest.h"
#include "display/VisibleObjManagerTest.h"

DisplaySuite::DisplaySuite()
{
	addTestCase(new DisplayCentralTest);
	addTestCase(new VisibleObjectTest);
	addTestCase(new NodeTest);
	addTestCase(new NodeManagerTest);
	addTestCase(new VisibleObjManagerTest);
}

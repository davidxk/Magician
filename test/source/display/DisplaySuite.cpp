#include "display/DisplaySuite.h"
#include "display/DisplayTest.h"

DisplaySuite::DisplaySuite()
{
	addTestCase(new DisplayTest);
}

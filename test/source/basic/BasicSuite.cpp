#include "basic/BasicSuite.h"

#include "basic/BasicTest.h"

BasicSuite::BasicSuite()
{
	addTestCase(new BasicTest);
}

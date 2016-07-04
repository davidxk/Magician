#include "basic/BasicSuite.h"

#include "basic/ColoredCharTest.h"
#include "basic/ConsoleCoordTest.h"
#include "basic/CoordTest.h"
#include "basic/OrderedPairTest.h"
#include "basic/RandomTest.h"
#include "basic/SizeTest.h"

BasicSuite::BasicSuite()
{
	addTestCase(new RandomTest);
	addTestCase(new ColoredCharTest);
	addTestCase(new OrderedPairTest);
	addTestCase(new SizeTest);
	addTestCase(new CoordTest);
	addTestCase(new ConsoleCoordTest);
}

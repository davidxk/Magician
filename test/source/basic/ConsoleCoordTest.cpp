#include "basic/ConsoleCoordTest.h"
#include <cassert>
#include "basic/ConsoleCoord.h"

void ConsoleCoordTest::run()
{
	testConstructor();
}

void ConsoleCoordTest::testConstructor()
{
	ConsoleCoord cc(23, 79);
	assert( cc.line==23 && cc.column==79 );
}

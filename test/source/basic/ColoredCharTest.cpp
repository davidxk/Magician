#include "basic/ColoredCharTest.h"
#include <cassert>
#include "basic/ColoredChar.h"

void ColoredCharTest::run()
{
	testConstructor();
	testOprEqNeq();
}

void ColoredCharTest::testConstructor()
{
	ColoredChar cc('a', 7, 0);
	assert( cc.ch=='a' && cc.foreColor==7 && cc.backColor==0 );
}

void ColoredCharTest::testOprEqNeq()
{
	ColoredChar cc('a', 7, 0);
	assert( cc == ColoredChar('a', 7, 0) );

	assert( cc != ColoredChar('b', 7, 0) );
	assert( cc != ColoredChar('a', 6, 0) );
	assert( cc != ColoredChar('a', 7, 1) );
	assert( cc != ColoredChar('b', 6, 1) );
}

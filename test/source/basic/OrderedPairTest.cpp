#include "basic/OrderedPairTest.h"
#include <cassert>
#include "basic/OrderedPair.h"

void OrderedPairTest::run()
{
	testConstructor();
}

void OrderedPairTest::testConstructor()
{
	OrderedPair ord(1, 2);
	assert( ord.line==1 && ord.column==2 );
}

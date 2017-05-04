#include "basic/SizeTest.h"
#include <cassert>
#include "basic/Size.h"

void SizeTest::run()
{
	testConstructor();
	testOprEqual();
	testOprNotEqual();
}

void SizeTest::testConstructor()
{
	//create Size with validation
	//Size wrong(-1, 1);
	Size();
	Size size(1, 2);
	assert( size.line==1 && size.column==2 );

	Size(0, 2);
	Size(1, 0);
}

void SizeTest::testOprEqual()
{
	Size size(24, 35);
	assert( size == Size(24, 35) );
}

void SizeTest::testOprNotEqual()
{
	Size size(24, 35);
	assert( size != Size(24, 30) );
	assert( size != Size(20, 35) );
	assert( size != Size(20, 30) );
}

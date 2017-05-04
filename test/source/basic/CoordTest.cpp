#include "basic/CoordTest.h"
#include <cassert>
#include "basic/Coord.h"
#include "basic/Size.h"

void CoordTest::run()
{
	testConstructor();
	testCoordXY();
	testOprEqNeq();
	testOprAddSub();
	testOprMulDiv();
	testOprAddSize();
}

void CoordTest::testConstructor()
{
	Coord noarg;
	assert( noarg.line==0 && noarg.column==0 );

	Coord arged(75, -25);
	assert( arged.line==75 && arged.column==-25 );
}

void CoordTest::testCoordXY()
{
	// XY stlye initialize
	Coord coxy = Coord::CoordXY(75, -25);
	assert( coxy.line==-25 && coxy.column==75 );
}

void CoordTest::testOprEqNeq()
{
	Coord coord(75, -25);
	assert( coord == Coord(75, -25) );
	assert( coord != Coord(70, -20) );
	assert( coord != Coord(70, -25) );
	assert( coord != Coord(75, -20) );
}

void CoordTest::testOprAddSub()
{
	Coord sum = Coord() + Coord(75, -25);
	assert( sum == Coord(75, -25) );
	sum += Coord(100, 50);
	assert( sum == Coord(175, 25) );

	Coord diff = Coord(100, 50) - Coord(75, -25);
	assert( diff == Coord(25, 75) );
	diff -= Coord(100, 50);
	assert( diff == Coord(-75, 25) );
}

void CoordTest::testOprMulDiv()
{
	Coord prod = Coord(100, 50) * 5;
	assert( prod == Coord(500, 250) );
	prod *= 2;
	assert( prod == Coord(1000, 500) );

	Coord quot = Coord(100, 50) / 5;
	assert( quot == Coord(20, 10) );
	quot /= 2;
	assert( quot == Coord(10, 5) );
}

void CoordTest::testOprAddSize()
{
	// Add Size
	Coord lowerRight = Coord(75, -25) + Size(100, 50);
	assert( lowerRight == Coord(175, 25) );
}

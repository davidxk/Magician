#include "basic/BasicTest.h"

#include <cassert>
#include <iostream>
#include "basic/ConsoleCoord.h"
#include "basic/Coord.h"
#include "basic/ImageLoader.h"
#include "basic/PrintJob.h"
#include "basic/Size.h"
using namespace std;

void BasicTest::run()
{

	//ConsoleCoord(-1, 2);
	//ConsoleCoord(25, 2);
	PrintJob( ConsoleCoord(23, 50), L'a');
}

void BasicTest::testSize()
{
	//create Size with validation
	//Size wrong(-1, 1);
	Size();
	Size(1, 2);
}

void BasicTest::testCoord()
{
	//XY stlye initialize
	Coord coxy = Coord::CoordXY(75, -25);
	assert( coxy.line==-25 coxy.column==75 );

	//add Size
	Coord lowerRight = Coord(75, -25) + Size(100, 50);
	assert( lowerRight == Coord(175, 25) );



	//test operator, with == tested internally
	Coord sum = Coord() + Coord(75, -25);
	assert( sum == Coord(75, -25) );
	sum += Coord(100, 50);
	assert( sum == Coord(175, 25) );

	Coord diff = Coord(100, 50) - Coord(75, -25);
	assert( diff == Coord(25, 75) );
	diff -= Coord(100, 50);
	assert( diff == Coord(-75, 25) );

	Coord prod = Coord(100, 50) * 5;
	assert( prod == Coord(500, 250) );
	prod *= 2;
	assert( prod == Coord(1000, 500) );

	Coord diff = Coord(100, 50) / 5;
	assert( diff == Coord(20, 10) );
}

void BasicTest::testImageLoader()
{
	//load image
	vector<wstring> image = ImageLoader::load("graph/moon.txt");
	assert( image.size() == 2 );
	assert( image[0] == L"1234" && image[1] == L"4321" );

	//load animation batch
	vector<vector<wstring> > batch = ImageLoader::
		loadBatch("batch/moon_batch.txt");
	assert( batch.size() == 3 );
	assert( batch[0].size()==1 && batch[1].size()==1 && batch[2].size()==1);
	assert(batch[0][0]==L"1234"&&batch[1][0]==L"4444"&&batch[2][0]==L"4321");
}

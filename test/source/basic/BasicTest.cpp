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
	//Size wrong(-1, 1);
	Size();

	Coord coxy = Coord::CoordXY(1, -1);
	assert( coxy.line==-1 && coxy.column==1 );
	Coord right = Coord(-1, 1) + Size(1, 1);
	assert( right == Coord(0, 2) );
	Coord sum = Coord() + Coord(1, -1);
	assert( sum == Coord(1, -1) );

	//ConsoleCoord(-1, 2);
	//ConsoleCoord(25, 2);
	PrintJob( ConsoleCoord(23, 50), 'a');

	vector<wstring> image = ImageLoader::load("graph/moon.txt");
	assert( image.size() == 2 );
	assert( image[0] == L"1234" && image[1] == L"4321" );

	vector<vector<wstring> > batch = ImageLoader::
		loadBatch("batch/moon_batch.txt");
	assert( batch.size() == 3 );
	assert( batch[0].size()==1 && batch[1].size()==1 && batch[2].size()==1);
	assert(batch[0][0]==L"1234"&&batch[1][0]==L"4444"&&batch[2][0]==L"4321");
}

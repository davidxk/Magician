#include "HelloWorld.h"
#include "Maze.h"
#include "MazeGenerator.h"
#include "RPGCursorHero.h"
#include <cassert>

void HelloWorld::initScene()
{
	MazeGenerator mg;
	const int rows = 10, cols = 20;
	auto ways = mg.generate(rows, cols);
	auto mzMatrix = Maze::makeMazeMap(ways, rows, cols);
	Sprite* mz = Sprite::create( Maze::makeMazeImage(mzMatrix) );
	mz->setCenterPos( SCREEN_CENTER );
	addChild( mz );

	Image dollarImage;
	dollarImage.push_back(ImageUtil::str2ImageLine("$", 3));
	Sprite* dollar = Sprite::create(dollarImage);
	dollar->setPos( mz->getPos() + Coord(rows * 2 - 1, cols * 2 - 1) );
	addChild(dollar);

	auto line = ImageUtil::str2ImageLine("@", 5);
	Image curImg;
	curImg.push_back(line);
	RPGCursorHero* cursor = new RPGCursorHero(curImg);
	cursor->setPos( mz->getPos() - Coord::CoordXY(-1, -1) );
	cursor->setMap( mzMatrix, mz->getPos() );
	addChild(cursor);

	addKeyListener( cursor );
}

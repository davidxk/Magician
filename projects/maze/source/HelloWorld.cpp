#include "HelloWorld.h"
#include "MazeGenerator.h"
#include "RPGCursorHero.h"
#include <cassert>

void HelloWorld::initScene()
{
	MazeGenerator mg;
	auto mzMatrix = mg.generate(10, 10);
	Sprite* mz = Sprite::create( makeMazeImage(mzMatrix) );
	mz->setCenterPos( SCREEN_CENTER );
	addChild( mz );

	auto line = ImageUtil::str2ImageLine("@");
	Image curImg;
	curImg.push_back(line);
	RPGCursorHero* cursor = new RPGCursorHero(curImg);
	cursor->setPos( mz->getPos() - Coord::CoordXY(0, 1) );
	cursor->setMap( mzMatrix, mz->getPos() );
	addChild(cursor);

	addKeyListener( cursor );
}

Image HelloWorld::makeMazeImage(const vector<vector<int> >& mzMatrix)
{
	Image img; 
	for(int i = 0; i < mzMatrix.size(); i++)
	{
		img.push_back(ImageLine());
		for(int j = 0; j < mzMatrix[0].size(); j++)
			switch(mzMatrix[i][j])
			{
				case 0:
					img[i].push_back(ColoredChar('#'));
					break;
				case 1:
					img[i].push_back(ColoredChar(' '));
					break;
				default:
					assert(false && "Should never be here");
					break;
			}
	}
	return img;
}

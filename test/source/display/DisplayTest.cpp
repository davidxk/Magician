#include "display/DisplayTest.h"

#include <cassert>
#include <iostream>
#include <regex>
#include "action/ActionManager.h"
#include "action/MoveTo.h"
#include "basic/MagicianMacros.h"
#include "display/DisplayCentral.h"
#include "display/VisibleObjManager.h"
#include "visible/Sprite.h"
using namespace std;

void DisplayTest::run()
{
	testSprite();
	testVManager();
	testDisplay();
}

void DisplayTest::testSprite()
{
	Sprite* sp = Sprite::create("graph/moon.txt");
	assert( sp->image.size() == 2 );
	assert( sp->image[0].size()==4 );
	assert( sp->image[1].size()==4 );
	assert( sp->size==Size(2, 4) );

	sp->setPos( Coord(23, 79) );
	vManager->addObject( sp );
	//assert( vManager->objList.size()==1 );
	sp->isVisible = false;
}

void DisplayTest::testVManager()
{
	Sprite* sp = Sprite::create("graph/moon.txt");
	sp->setPos( Coord::CoordXY(-1, 0) );
	vManager->addObject( sp );
	MoveTo* mt = MoveTo::create(sp, 100, Coord(23, 79));
	aManager->addAction( mt );

	Image frame = vManager->getFrame();
	vector<string> vFrame;
	vFrame.push_back( ImageUtil::ImageLine2str( frame[0] ) );
	vFrame.push_back( ImageUtil::ImageLine2str( frame[1] ) );
	assert( frame.size()==24 );
	for(const auto& line: frame)
		assert( line.size()==80 );

	const regex patLine0("^234 *$");
	const regex patLine1("(321)( *)");
	assert( regex_match( vFrame[0].begin(), vFrame[0].end(), patLine0 ) );
	assert( regex_match( vFrame[1].begin(), vFrame[1].end(), patLine1 ) );

	sp->setPos( Coord::CoordXY(-1, 23) );
	Image frame_2 = vManager->getFrame();
	string sFrame_2 = ImageUtil::ImageLine2str( frame_2[23] );
	assert( regex_match( sFrame_2.begin(), sFrame_2.end(), patLine0 ) );
}

void DisplayTest::testDisplay()
{
	//test frame First init
	DisplayCentral dc;
	const regex blank(" +");
	assert( dc.frameThis.size()==24 );
	for(const auto& line: dc.frameThis)
	{
		string sLine = ImageUtil::ImageLine2str( line );
		assert(regex_match(sLine.begin(), sLine.end(), blank));
	}

	aManager->update();
	Image frameNext = vManager->getFrame();
	dc.setThisFrame( frameNext );
	//assert( dc.getDiff().size()==15 );
}

DisplayTest::~DisplayTest()
{
	sVisibleObjManager::release();
	sActionManager::release();
}

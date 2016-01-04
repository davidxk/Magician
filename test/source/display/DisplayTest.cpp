#include "display/DisplayTest.h"

#include <cassert>
#include <iostream>
#include <regex>
#include "basic/MagicianMacros.h"
#include "display/ActionManager.h"
#include "display/DisplayCentral.h"
#include "display/VisibleObjManager.h"
#include "user/Sprite.h"
#include "user/MoveTo.h"
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
	MoveTo* mt = MoveTo::create(sp, 100, Coord(23, 79), false);
	aManager->addAction( mt );

	vector<wstring> frame = vManager->getFrame();
	assert( frame.size()==24 );
	for(const auto& line: frame)
		assert( line.size()==80 );

	const wregex patLine0(L"^234 *$");
	const wregex patLine1(L"(321)( *)");
	assert( regex_match( frame[0].begin(), frame[0].end(), patLine0 ) );
	assert( regex_match( frame[1].begin(), frame[1].end(), patLine1 ) );

	sp->setPos( Coord::CoordXY(-1, 23) );
	vector<wstring> frame_2 = vManager->getFrame();
	assert( regex_match( frame_2[23].begin(), frame_2[23].end(), patLine0 ) );
}

void DisplayTest::testDisplay()
{
	//test frame First init
	DisplayCentral dc;
	const wregex blank(L" +");
	assert( dc.frameThis.size()==24 );
	for(const auto& line: dc.frameThis)
		assert(regex_match(line.begin(), line.end(), blank));

	aManager->update();
	vector<wstring> frameNext = vManager->getFrame();
	dc.setThisFrame( frameNext );
	//assert( dc.getDiff().size()==15 );
}

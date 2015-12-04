#include "display/DisplayTest.h"

#include <cassert>
#include <iostream>
#include <regex>
#include "display/ActionManager.h"
#include "display/DisplayCentral.h"
#include "display/VisibleObjManager.h"
#include "user/Sprite.h"
#include "user/MoveTo.h"
using namespace std;

void DisplayTest::run()
{
	Sprite* sp = Sprite::create("graph/moon.txt");
	assert( sp->image.size() == 2 );
	assert( sp->image[0].size()==4 );
	assert( sp->image[1].size()==4 );
	assert( sp->size==Size(2, 4) );

	sp->setPos( Coord(0, 0) );
	vManager->addObject( sp );
	assert( vManager->objList.size()==1 );

	/*
	vector<wstring> frame = vManager->getFrame();
	const wregex patLine0(L"1234 *");
	const wregex patLine1(L"4321 *");
	for(const auto& line: frame)
		assert( line.size()==80 );
	assert( frame.size()==24 );
	assert( frame[0].size()==80 );
	assert( frame[0][0]==L'1' );
	//assert( regex_match( frame[0].begin(), frame[0].end(), patLine0 ) );
	//assert( regex_match( frame[1].begin(), frame[1].end(), patLine1 ) );





	MoveTo* mt = MoveTo::create(sp, 10, Coord(23, 79), true);
	assert( mt->cmdQueue.size() == 10 );
	aManager->addAction( mt );
	assert( aManager->actionList.size()==1 );

	DisplayCentral dc;
	const wregex blank(L" +");
	assert( dc.frameThis.size()==24 );
	for(const auto& line: dc.frameThis)
		assert(regex_match(line.begin(), line.end(), blank));

	aManager->update();
	assert( !(sp->pos == Coord(0, 0)) );
	vector<wstring> frameNext = vManager->getFrame();
	//assert( frameNext[0][0] != L'1' );
	dc.setThisFrame( frameNext );
	assert( dc.getDiff().size()==15 );
	*/
}

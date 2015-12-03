#include "base/BaseTest.h"

#include <cassert>
#include <iostream>
#include "base/Action.h"
#include "base/Box.h"
#include "base/Command.h"
#include "base/VisibleObject.h"
using namespace std;

void BaseTest::run()
{
	VisibleObject vo;
	Action act(&vo, 20);

	Box box(Size(3, 6));
	for(auto& it: box.image)
		cout<<it.size()<<endl;
	assert(box.image.size()==3 && box.image[0].size()==6);
	assert(box.image[0]== L"╔─┐");
	assert(box.image[1]== L"│   │");
	assert(box.image[2]== L"╰─╯");

	Command cmd( Coord(10, 30) );
	vo.setPos( Coord(1, 2) );
	cmd.apply(&vo);
	assert( vo.pos==Coord(10, 30) );
}

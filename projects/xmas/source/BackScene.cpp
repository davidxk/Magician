#include "BackScene.h"

#include <chrono>
#include <thread>
#include "Magician.h"

BackScene::BackScene()
{
	Sprite* frame = Sprite::create("cover/merry_christmas.txt");
	frame->setPos( Coord(1, 0) );
	vManager->addObject( frame );

	const int sleepTime = 7000;
	std::this_thread::sleep_for( std::chrono::milliseconds(sleepTime) );
	Transition::releasePrev();

	//const int num39 = ConsoleCoord::MAX_COLUMN / 2;
	//const int num11 = ConsoleCoord::MAX_LINES / 2;
	//Sprite* word = Sprite::create("cover/the_end.txt");
	//word->setCenterPos( Coord(num11, num39) );
	//vManager->addObject( word );
}

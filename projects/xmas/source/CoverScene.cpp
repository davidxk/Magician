#include "CoverScene.h"

#include <chrono>
#include <thread>
#include "Magician.h"

CoverScene::CoverScene()
{
	const int num39 = ConsoleCoord::MAX_COLUMN / 2;
	const int num11 = ConsoleCoord::MAX_LINES / 2;
	Sprite* wreath = Sprite::create("cover/wreath.txt");
	wreath->setCenterPos( Coord(num11-4, num39) );
	vManager->addObject( wreath );

	Sprite* word = Sprite::create("cover/cover_word.txt");
	word->setCenterPos( Coord(num11+6, num39) );
	vManager->addObject( word );

	const sleepTime = 2500;
	std::this_thread::sleep_for( std::chrono::milliseconds(sleepTime) );
	Transition::releasePrev();
}

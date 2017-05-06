#include "CoverScene.h"

#include <cassert>
#include <chrono>
#include <thread>
#include "HelloWorld.h"

void CoverScene::initScene()
{
	const int num39 = ConsoleCoord::MAX_COLUMN / 2;
	const int num11 = ConsoleCoord::MAX_LINES / 2;
	Sprite* wreath = Sprite::create("cover/wreath.txt");
	wreath->setCenterPos( Coord(num11-2, num39) );
	vManager->addObject( wreath );

	Sprite* word = Sprite::create("cover/cover_word.txt");
	word->setCenterPos( Coord(num11+6, num39) );
	vManager->addObject( word );

	const int sleepTime = 5000;
	auto trans = std::bind(&CoverScene::changeScene, this);
	gScheduler->schedule( trans, sleepTime );
}

void CoverScene::changeScene()
{
	HelloWorld* hello = new HelloWorld();
	gMainLoop->replaceScene(hello);
}

#include "BackScene.h"

#include <chrono>
#include <thread>
#include "LetterScene.h"

void BackScene::initScene()
{
	Sprite* frame = Sprite::create("cover/merry_christmas.txt");
	frame->setPos( Coord(1, 0) );
	vManager->addObject( frame );

	const int sleepTime = 1000; //7000

	//const int num39 = ConsoleCoord::MAX_COLUMN / 2;
	//const int num11 = ConsoleCoord::MAX_LINES / 2;
	//Sprite* word = Sprite::create("cover/the_end.txt");
	//word->setCenterPos( Coord(num11, num39) );
	//vManager->addObject( word );
	auto trans = std::bind(&BackScene::changeScene, this);
	gScheduler->schedule( trans, sleepTime );
}

void BackScene::changeScene()
{
	LetterScene* letter = new LetterScene();
	gMainLoop->replaceScene( letter );
}

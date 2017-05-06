#include "LetterScene.h"
#include <fstream>
#include <string>
using namespace std;

void LetterScene::initScene()
{
	Sprite* paper = Sprite::create("cover/parchment.txt");
	vManager->addObject( paper );

	ImageLine letter;
	vector<ImageLine> list =ImageLoader::load("cover/letter.txt");
	for(auto& line: list)
	{
		line.push_back( ColoredChar('\n') );
		for(const auto& ch: line)
			letter.push_back( ch );
	}

	TextField* ttf = TextField::create( Size(18, 54), ImageUtil::
			ImageLine2str(letter) );
	ttf->setPos( Coord(2, 13) );
	vManager->addObject( ttf );

	auto trans = std::bind(&LetterScene::changeScene, this);
	gScheduler->schedule( trans, goOutPoint );
}

void LetterScene::changeScene()
{
	gDirector->popScene();
}

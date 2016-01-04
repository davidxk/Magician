#include "LetterScene.h"
#include "Magician.h"
#include <fstream>
#include <string>
using namespace std;

LetterScene::LetterScene()
{
	Sprite* paper = Sprite::create("cover/parchment.txt");
	vManager->addObject( paper );

	wstring letter;
	vector<wstring> list =ImageLoader::load("cover/letter.txt");
	for(const auto& line: list)
		letter += line + L'\n';

	TextField* ttf = TextField::create( Size(18, 54), letter );
	ttf->setPos( Coord(2, 13) );
	vManager->addObject( ttf );
}

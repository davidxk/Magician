#include "Sprite.h"

Sprite::Sprite(const string& fileName)
{
	image = ImageLoader::load(fileName);
	verify();
}

static Sprite& Sprite::create(const string& fileName)
{
	vector<VisibleObject>& list = vManager->objList;
	list.emplace_back( fileName );
	return list.back();
}

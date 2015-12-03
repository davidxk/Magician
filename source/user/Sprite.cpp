#include "Sprite.h"

Sprite::Sprite(const string& fileName)
{
	image = ImageLoader::load(fileName);
	size = Size( image.size(), image[0].size() );
	verify();
}

static Sprite& Sprite::create(const string& fileName)
{
	vector<VisibleObject>& list = vManager->objList;
	list.emplace_back( Sprite(fileName) );
	return list.back();
}

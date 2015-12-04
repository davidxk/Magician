#include "user/Sprite.h"
#include "basic/ImageLoader.h"

Sprite::Sprite(const string& fileName): VisibleObject()
{
	image = ImageLoader::load(fileName);
	size = Size( image.size(), image[0].size() );
	verify();
}

Sprite* Sprite::create(const string& fileName)
{
	//vector<VisibleObject*>& list = vManager->objList;
	//list.push_back( sp );
	Sprite* sp = new Sprite(fileName);
	return sp;
}

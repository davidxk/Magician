#include "visible/Sprite.h"
#include "visible/ImageLoader.h"

Sprite::Sprite(const string& fileName): Node()
{
	image = ImageLoader::load(fileName);
	size = Size( image.size(), image[0].size() );
	updateCenter();
	verify();
}

Sprite* Sprite::create(const string& fileName)
{
	Sprite* sp = new Sprite(fileName);
	return sp;
}

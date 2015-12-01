#include "Sprite.h"

Sprite::Sprite(const string& fileName)
{
	image = ImageLoader::load(fileName);
}

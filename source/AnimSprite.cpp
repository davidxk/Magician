#include "AnimSprite.h"
#include "ImageLoader.h"

AnimSprite::AnimSprite(string fileName)
{
	batch = ImageLoader::loadBatch(fileName);
	image = batch[ 0 ];
}

void AnimSprite::putOn(int index)
{
	image = batch[index];
}

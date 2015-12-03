#include "user/AnimSprite.h"
#include "basic/ImageLoader.h"

AnimSprite::AnimSprite(const string& fileName)
{
	batch = ImageLoader::loadBatch(fileName);
	image = batch[ 0 ];
	size = Size( image.size(), image[0].size() );
	verify();
}

AnimSprite* AnimSprite::create(const string& fileName)
{
	//vector<VisibleObject*>& list = vManager->objList;
	//list.push_back( sp );
	AnimSprite* sp = new AnimSprite(fileName);
	return sp;
}

void AnimSprite::putOn(int index)
{
	image = batch[index];
}

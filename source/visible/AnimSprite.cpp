#include "visible/AnimSprite.h"
#include <cassert>
#include "visible/ImageLoader.h"

AnimSprite::AnimSprite(const string& fileName)
{
	batch = ImageLoader::loadBatch(fileName);
	assert( batch.size() > 0 );
	image = batch[ 0 ];
	size = Size( image.size(), image[0].size() );
	updateCenter();
	verify();
}

AnimSprite* AnimSprite::create(const string& fileName)
{
	AnimSprite* sp = new AnimSprite(fileName);
	return sp;
}

void AnimSprite::setDisplayImage(int index)
{
	assert( index < batch.size() );
	image = batch[index];
}

void AnimSprite::setForeColor(Color foreColor)
{
	VisibleObject::setForeColor(foreColor);
	for(auto& image: batch)
		for(auto& line: image)
			for(auto& cchar: line)
				cchar.setForeColor( foreColor );
}

void AnimSprite::setBackColor(Color backColor)
{
	VisibleObject::setBackColor(backColor);
	for(auto& image: batch)
		for(auto& line: image)
			for(auto& cchar: line)
				cchar.setBackColor( backColor );
}

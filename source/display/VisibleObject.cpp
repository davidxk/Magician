#include "display/VisibleObject.h"
#include <cassert>

VisibleObject::VisibleObject():
	isVisible(true) { }

void VisibleObject::verify()
{
	//A visible object should be verified before being registered 
	//Only registered objects are printed
	assert(size.line > 0);
	assert(size.column > 0);
	assert( center==( pos + pos + size )/2 );

	assert(size.line == image.size());
	for(const auto& it: image)
		assert(size.column == it.size());
}

void VisibleObject::setPos(const Coord cc)
{
	//lock_guard<mutex> lock(mtx);
	this->pos = cc;
	updateCenter();
}

Coord VisibleObject::getPos() const
{
	//lock_guard<mutex> lock(mtx);
	return pos;
}

void VisibleObject::setCenterPos(const Coord cc)
{
	setPos( pos + cc - center );
}

Coord VisibleObject::getCenterPos() const
{
	return center;
}

void VisibleObject::setIsVisible(bool isVisible)
{
	this->isVisible = isVisible;
}

bool VisibleObject::getIsVisible() const
{
	return isVisible;
}

void VisibleObject::setImage(const Image image)
{
	this->image = image;
	size = Size( image.size(), image[0].size() );
	updateCenter();
	verify();
}

Image VisibleObject::getImage() const
{
	return image;
}

Size VisibleObject::getSize() const
{
	return size;
}

void VisibleObject::updateCenter()
{
	center = ( pos + pos + size )/2;
}




void VisibleObject::setForeColor(Color foreColor)
{
	for(auto& line: image)
		for(auto& cchar: line)
			cchar.setForeColor( foreColor );
}

void VisibleObject::setBackColor(Color backColor)
{
	for(auto& line: image)
		for(auto& cchar: line)
			cchar.setBackColor( backColor );
}

void VisibleObject::setColor(Color foreColor, Color backColor)
{
	for(auto& line: image)
		for(auto& cchar: line)
			cchar.setColor( foreColor, backColor );
}

void VisibleObject::highlight()
{
	for(auto& line: image)
		for(auto& cchar: line)
			cchar.setColor( 7-cchar.foreColor, 7-cchar.backColor );
}

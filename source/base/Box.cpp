#include "base/Box.h"
#include <cassert>
#include <iostream>

Box::Box(const Size& size): VisibleObject()
{
	setSize(size);
}

void Box::setSize(const Size& size)
{
	this->size = size;
	updateCenter();
	getAsciiOutline();
}

void Box::getAsciiOutline()
{
	int width  = size.column;
	int height = size.line;
	image.resize( height );
	
	//paint the outline
	for(int i=0; i<height; i++)
	{
		string& line=image[i];
		for(int j=0; j<width; j++)
			if(j == 0)
			{
				if( i==0 ) line += " ";	//upper left 
				else if( i==height-1 ) line += "`";	//lower left
				else line += "|";	//left
			}
			else if(j == width-1)
			{
				if( i==0 ) line += ".";	//upper right
				else if( i==height-1 ) line += " ";	//lower right
				else line += "|";	//right
			}
			else
			{
				if( i==0 || i==height-1 ) line += "-";	//upper and lower
				else line += " ";	//middle
			}
	} 
	assert( image.size()==size.line);
	assert( image[0].size()==size.column );
}

#include "base/Box.h"
#include <cassert>
#include <iostream>

Box::Box(const Size& size)
{
	setSize(size);
}

void Box::setSize(const Size& size)
{
	this->size = size;
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
		wstring& line=image[i];
		for(int j=0; j<width; j++)
			if(j == 0)
			{
				if( i==0 ) line += L" ";	//upper left 
				else if( i==height-1 ) line += L"`";	//lower left
				else line += L"|";	//left
			}
			else if(j == width-1)
			{
				if( i==0 ) line += L".";	//upper right
				else if( i==height-1 ) line += L" ";	//lower right
				else line += L"|";	//right
			}
			else
			{
				if( i==0 || i==height-1 ) line += L"-";	//upper and lower
				else line += L" ";	//middle
			}
	} 
	assert( image.size()==size.line);
	assert( image[0].size()==size.column );
}

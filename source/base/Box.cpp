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
	getOutline();
}

void Box::getOutline()
{
	int width  = size.column/2;
	int height = size.line;
	image.resize( height );
	
	//paint the outline
	for(int i=0; i<height; i++)
	{
		string& line=image[i];
		for(int j=0; j<width; j++)
			if(j == 0)
			{
				if( i==0 ) line += "╔";
				else if( i==height-1 ) line += "╰";
				else line += "│";
			}
			else if(j == width-1)
			{
				if( i==0 ) line += "┐";
				else if( i==height-1 ) line += "╯";
				else line += "│";
			}
			else
			{
				if( i==0 || i==height-1 ) line += "─";
				else line += "  ";
			}
	} 
	assert( image.size()==size.line);
	for(const auto& line: image)
	{
		cout<<line.size()<<endl;
	}
		//assert( line.size()==size.column/2 );
}

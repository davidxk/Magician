#include "Box.h"

void Box::setSize(Size size)
{
	this->size = size;
	int width  = size.column/2;
	int height = size.line;
	
	//paint the outline
	for(int i=0; i<height; i++)
	{
		string& line=image[i]
		for(int j=0; j<width; j++)
			switch(j)
			{
				case 0:
					if( i==0 ) line += "╔";
					else if( i==height-1 ) line += "╰";
					else line += "│";
					break;
				case width - 1:
					if( i==0 ) line += "┐";
					else if( i==height-1 ) line += "╯";
					else line += "│";
				default:
					if( i==0 || i==height-1 ) line += "─";
					else line += "  ";
			}
	} 
}

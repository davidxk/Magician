#include "visible/TextField.h"
#include <cassert>

TextField::TextField(const Size& size, const string& content): 
	VisibleObject()
{
	setSize( size );
	setContent( content );
}

TextField* TextField::create(const Size& size, const string& content)
{
	return new TextField(size, content);
}

void TextField::setSize(const Size& size)
{
	this->size = size;
	updateCenter();
}

void TextField::setContent(const string& content)
{
	assert( content.size() );
	assert( content.size() <= size.line * size.column );
	this->content = content;

	image.resize( size.line );
	for(int i=0; i<image.size(); i++)
		image[i]=ImageUtil::str2ImageLine( string( size.column, ' ' ) );

	int cnt = 0; 
	for(int i=0; i<size.line; i++)
		for(int j=0; j<size.column; j++)
			if( cnt < content.size() )
			{
				if(content[cnt] != '\n')
					image[ i ][ j ] = content[ cnt++ ];
				else
					j=size.column, cnt++;
			}
			else return;
	//assert( cnt == content.size() );
}

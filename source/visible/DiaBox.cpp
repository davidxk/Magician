#include "visible/DiaBox.h"
#include <cassert>

DiaBox::DiaBox(const Size& size, const string& content): Box( size )
{
	setContent( content );
}

DiaBox* DiaBox::create(const Size& size, const string& content)
{
	return new DiaBox(size, content);
}

void DiaBox::setContent(const string& content)
{
	this->content = content;
	assert( content.size() <= (size.line-2) * (size.column-4) );
	unsigned lineLen = size.column-4;
	for(unsigned i=0; i<content.size(); i++)
		image[ 1 + i/lineLen ][ 2 + i%lineLen ] = content[ i ];
}

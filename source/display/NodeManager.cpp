#include "display/NodeManager.h"
#include <cassert>
#include <cmath>

Image NodeManager::getFrame(const Node* node)
{
	Image frame = getEmptyFrame();
	paintTree( node, frame );

	verify( frame );
	return frame;
}

void NodeManager::paintTree(const Node* node, Image& frame)
{
	paintNode( node, frame );
	for(const auto& child: node->getChildren())
		paintTree( child, frame );
}

void NodeManager::paintNode(const VisibleObject* obj, Image& frame)
{
	if( !obj->getIsVisible() ) return;
	Coord lower = obj->getPos();
	Coord upper = obj->getPos() + obj->getSize();
	int lineLower = (int)fmax( ConsoleCoord::MIN_LINES, lower.line );
	int lineUpper = (int)fmin( ConsoleCoord::MAX_LINES+1, upper.line );
	int colLower = (int)fmax( ConsoleCoord::MIN_COLUMN, lower.column );
	int colUpper = (int)fmin( ConsoleCoord::MAX_COLUMN+1,upper.column );

	for(int i=lineLower; i<lineUpper; i++)
		for(int j=colLower; j<colUpper; j++)
			frame[i][j] = obj->getImage()[ i-lower.line ]
				[ j-lower.column ];
}

Image NodeManager::getEmptyFrame()
{
	Image frame;
	frame.resize( ConsoleCoord::MAX_LINES+1 );
	for(auto& line: frame)
		line = ImageUtil::str2ImageLine(
				string(ConsoleCoord::MAX_COLUMN + 1, ' ') );
	return frame;
}

void NodeManager::verify(Image& frame)
{
	assert( frame.size()==ConsoleCoord::MAX_LINES+1 );
	for(const auto& line: frame)
		assert( line.size()==ConsoleCoord::MAX_COLUMN+1 );
}

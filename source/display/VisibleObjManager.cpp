#include "display/VisibleObjManager.h"
#include <cassert>
#include <cmath>

void VisibleObjManager::addObject(VisibleObject* object)
{
	lock_guard<mutex> lock(mtx);
	assert( object != NULL );
	//object->verify();
	objList.push_back( object );
	/*for(auto it=objList.end(); it!=objList.begin(); it--)
		if( (*it)->zOrder == object->zOrder )
		{
			if( it==objList.end() ) 
				objList.push_back( object );
			else
				objList.insert(it+1, object);	//insert = insert_before
			break;
		}*/
}

Image VisibleObjManager::getFrame()
{
	lock_guard<mutex> lock(mtx);
	Image frame = getEmptyFrame();

	for(const auto& obj: objList)
	{
		if( !obj->isVisible ) continue;

		Coord lower = obj->pos;
		Coord upper = obj->pos + obj->size;
		int lineLower = (int)fmax( ConsoleCoord::MIN_LINES, lower.line );
		int lineUpper = (int)fmin( ConsoleCoord::MAX_LINES+1, upper.line );
		int colLower = (int)fmax( ConsoleCoord::MIN_COLUMN, lower.column );
		int colUpper = (int)fmin( ConsoleCoord::MAX_COLUMN+1,upper.column );

		for(int i=lineLower; i<lineUpper; i++)
			for(int j=colLower; j<colUpper; j++)
				frame[i][j] = obj->image[ i-lower.line ]
					[ j-lower.column ];
	}
	verify( frame );
	return frame;
}

Image VisibleObjManager::getEmptyFrame()
{
	Image frame;
	frame.resize( ConsoleCoord::MAX_LINES+1 );
	for(int i=0; i<frame.size(); i++)
		frame[i]=ImageUtil::str2ImageLine( 
				string(ConsoleCoord::MAX_COLUMN+1, ' ') );
	return frame;
}

void VisibleObjManager::verify(Image& frame)
{
	assert( frame.size()==ConsoleCoord::MAX_LINES+1 );
	for(const auto& line: frame)
		assert( line.size()==ConsoleCoord::MAX_COLUMN+1 );
}

VisibleObjManager::~VisibleObjManager()
{
	for(auto& object: objList)
		delete object;
}

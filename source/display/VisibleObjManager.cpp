#include "display/VisibleObjManager.h"
#include <cassert>
#include <cmath>

void VisibleObjManger::addObject(VisibleObject* object)
{
	assert( object != NULL );
	objList.push_back( object );
}

vector<wstring> VisibleObjManger::getFrame()
{
	vector<wstring> map;
	map.resize( ConsoleCoord::MAX_LINES+1 );
	for(int i=0; i<map.size(); i++)
		map[i]=wstring(ConsoleCoord::MAX_COLUMN+1, L' ');
	verify( map );

	for(const auto& obj: objList)
	{
		Coord lower = obj->pos;
		Coord upper = obj->pos + obj->size;
		int lineLower = (int)fmax( ConsoleCoord::MIN_LINES, lower.line );
		int lineUpper = (int)fmin( ConsoleCoord::MAX_LINES, upper.line );
		int colLower = (int)fmax( ConsoleCoord::MIN_COLUMN, lower.column );
		int colUpper = (int)fmin( ConsoleCoord::MAX_COLUMN, upper.column );

		obj->verify();
		for(int i=lineLower; i<lineUpper; i++)
			for(int j=colLower; j<colUpper; j++)
				map[i][j] = obj->image[ i-lineLower ][ j-colLower ];
	}
	verify( map );
	return map;
}

void VisibleObjManger::verify(vector<wstring>& frame)
{
	assert( frame.size()==ConsoleCoord::MAX_LINES+1 );
	for(const auto& line: frame)
		assert( line.size()==ConsoleCoord::MAX_COLUMN+1 );
}

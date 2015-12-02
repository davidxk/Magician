#include "VisibleObjManger.h"
#include <cmath>

vector<string> VisibleObjManger::getFrame()
{
	vector<string> map;
	for(int i=0; i<ConsoleCoord::MAX_LINES+1; i++)
		map[i]=string(ConsoleCoord::MAX_COLUMN+1, ' ');

	for(const auto& obj: objList)
	{
		Coord lower = objList.pos;
		Coord upper = objList.pos + objList.size;
		int lineLower = (int)fmax( ConsoleCoord::MIN_LINES, lower.line );
		int lineUpper = (int)fmin( ConsoleCoord::MAX_LINES, upper.line );
		int colLower = (int)fmax( ConsoleCoord::MIN_COLUMN, lower.column );
		int colUpper = (int)fmin( ConsoleCoord::MAX_COLUMN, upper.column );

		for(int i=lineLower; i<=lineUpper; i++)
			for(int j=colLower; j<=colUpper; j++)
				map[i][j] = obj.image[i][j];
	}
	return map;
}

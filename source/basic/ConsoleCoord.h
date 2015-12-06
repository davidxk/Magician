#ifndef _CONSOLE_COORD_H_
#define _CONSOLE_COORD_H_

#include "basic/OrderedPair.h"
#include "basic/Size.h"

//Console Coordinate is for the sole purpose of console printing
//It guarantees that the coordinate is within the screen
class ConsoleCoord: public OrderedPair
{
public:
	static const int MAX_LINES;
	static const int MAX_COLUMN;
	static const int MIN_LINES;
	static const int MIN_COLUMN;
public:
	ConsoleCoord(int line = MIN_LINES, int column = MIN_COLUMN);
	void setLine(int line);
	void setColume(int column);
	ConsoleCoord operator+(const ConsoleCoord& cc);
	ConsoleCoord operator+(const Size& cc);
};
#endif

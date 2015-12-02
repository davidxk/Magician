#ifndef _CONSOLE_COORD_H_
#define _CONSOLE_COORD_H_

//include here

//Console Coordinate is for the sole purpose of console printing
class ConsoleCoord: public OrderedPair
{
public:
	static const int MAX_LINES;
	static const int MAX_COLUMN;
	static const int MIN_LINES;
	static const int MIN_COLUMN;
public:
	Coord(int line = MIN_LINES, int column = MIN_LINES);
	void setLine(int line);
	void setColume(int column);
	ConsoleCoord operator+(const ConsoleCoord& cc);
};
#endif

#include "basic/ConsoleCoord.h"

#include <cassert>

const int ConsoleCoord::MAX_LINES = 23;
const int ConsoleCoord::MAX_COLUMN = 79;
const int ConsoleCoord::MIN_LINES = 0;
const int ConsoleCoord::MIN_COLUMN = 0;

ConsoleCoord::ConsoleCoord(int line, int column)
{
	setLine(line);
	setColume(column);
}

void ConsoleCoord::setLine(int line)
{
	assert(line>=0 && line<=MAX_LINES);
	this->line = line;
}

void ConsoleCoord::setColume(int column)
{
	assert(column>=0 && column<=MAX_COLUMN);
	this->column = column;
}

ConsoleCoord ConsoleCoord::operator+(const ConsoleCoord& cc)
{
	return ConsoleCoord(cc.line + line, cc.column + column);
}

ConsoleCoord ConsoleCoord::operator+(const Size& cc)
{
	return ConsoleCoord(cc.line + line, cc.column + column);
}

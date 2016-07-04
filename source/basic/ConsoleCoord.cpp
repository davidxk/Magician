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
	assert(line>=MIN_LINES && line<=MAX_LINES);
	this->line = line;
}

void ConsoleCoord::setColume(int column)
{
	assert(column>=MIN_COLUMN && column<=MAX_COLUMN);
	this->column = column;
}

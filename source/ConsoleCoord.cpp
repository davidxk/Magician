#include "display/ConsoleCoord.h"

#include <cassert>

const int ConsoleCoord::MAX_LINES = 80;
const int ConsoleCoord::MAX_COLUMN = 24;
const int ConsoleCoord::MIN_LINES = 0;
const int ConsoleCoord::MIN_COLUMN = 0;

ConsoleCoord::ConsoleCoord(int line, int column)
{
	setLine(line);
	setCol(column);
}

void ConsoleCoord::setLine(int line)
{
	assert(line<0 || line>=MAX_LINES);
	this->line = line;
}

void ConsoleCoord::setColume(int column)
{
	assert(column<0 || column>=MAX_COLUME);
	else this->column = column;
}

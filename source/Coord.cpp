#include "Coord.h"

Coord::Coord(): line(0), column(0) { }

Coord::Coord(int aLine, int aColumn):
        line(aLine), column(aColumn) { }

Coord Coord::operator+(const Coord& cc)
{
	return Coord(cc.line + line, cc.column + column);
}

Coord Coord::operator-(const Coord& cc)
{
	return Coord(cc.line - line, cc.column - column);
}

bool Coord::operator==(const Coord& cc)
{
	return cc.line==line && cc.column==column;
}

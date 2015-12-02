#include "Coord.h"

Coord::Coord(): line(0), column(0) { }

Coord::Coord(int aLine, int aColumn):
        line(aLine), column(aColumn) { }

Coord Coord::CoordXY(int xx, int yy)
{
	return Coord(yy, xx);
}

Coord Coord::operator+(const Size& cc)
{
	return Coord(cc.line + line, cc.column + column);
}

Coord Coord::operator+(const Coord& cc)
{
	return Coord(cc.line + line, cc.column + column);
}

Coord Coord::operator-(const Coord& cc)
{
	return Coord(cc.line - line, cc.column - column);
}

Coord Coord::operator*(int nn)
{
	return Coord(cc.line * nn, cc.column * nn);
}

Coord Coord::operator/(int nn)
{
	return Coord(cc.line / nn, cc.column / nn);
}

bool Coord::operator==(const Coord& cc)
{
	return cc.line==line && cc.column==column;
}

#include "basic/Coord.h"

Coord::Coord(): OrderedPair(0, 0) { }

Coord::Coord(int aLine, int aColumn):
        OrderedPair(aLine, aColumn) { }

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
	return Coord(line - cc.line, column - cc.column);
}

Coord Coord::operator*(int nn)
{
	return Coord(line * nn, column * nn);
}

Coord Coord::operator/(int nn)
{
	return Coord(line / nn, column / nn);
}

bool Coord::operator==(const Coord& cc)
{
	return cc.line==line && cc.column==column;
}

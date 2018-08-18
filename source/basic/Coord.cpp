#include "basic/Coord.h"
#include <cassert>

Coord::Coord(): OrderedPair(0, 0) { }

Coord::Coord(int aLine, int aColumn):
        OrderedPair(aLine, aColumn) { }

Coord Coord::CoordXY(int xx, int yy)
{
	return Coord(yy, xx);
}

Coord Coord::Cartesian(int xx, int yy)
{
	return Coord(23 - yy, xx);
}

Coord Coord::operator+(const Size& cc) const
{
	return Coord(line + cc.line, column + cc.column);
}

Coord Coord::operator+(const Coord& cc) const
{
	return Coord(line + cc.line, column + cc.column);
}

Coord Coord::operator+=(const Coord& cc)
{
	return Coord(line += cc.line, column += cc.column);
}

Coord Coord::operator-(const Coord& cc) const
{
	return Coord(line - cc.line, column - cc.column);
}

Coord Coord::operator-=(const Coord& cc)
{
	return Coord(line -= cc.line, column -= cc.column);
}





Coord Coord::operator*(int nn) const
{
	return Coord(line * nn, column * nn);
}

Coord Coord::operator*=(int nn)
{
	return Coord(line *= nn, column *= nn);
}

Coord Coord::operator/(int nn) const
{
	assert( nn != 0 );
	return Coord(line / nn, column / nn);
}

Coord Coord::operator/=(int nn)
{
	assert( nn != 0 );
	return Coord(line /= nn, column /= nn);
}

bool Coord::operator==(const Coord& cc) const
{
	return cc.line==line && cc.column==column;
}

bool Coord::operator!=(const Coord& cc) const
{
	return !(cc.line==line && cc.column==column);
}

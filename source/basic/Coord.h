#ifndef _COORD_H_
#define _COORD_H_

#include "basic/OrderedPair.h"
#include "basic/Size.h"

class Coord: public OrderedPair
{
public:
	Coord();
	Coord(int aLine, int aColumn);
	static Coord CoordXY(int xx, int yy);

	Coord operator+(const Size& cc) const;
	Coord operator+(const Coord& cc) const;
	Coord operator+=(const Coord& cc);
	Coord operator-(const Coord& cc) const;
	Coord operator-=(const Coord& cc);

	Coord operator*(int nn) const;
	Coord operator*=(int nn);
	Coord operator/(int nn) const;
	bool operator==(const Coord& cc) const;
	bool operator!=(const Coord& cc) const;
};
#endif

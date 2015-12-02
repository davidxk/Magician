
class Coord: public OrderedPair
{
public:
	Coord();
	Coord(int aLine, int aColumn);
	Coord CoordXY(int xx, int yy);
	Coord operator+(const Coord& cc);
	Coord operator-(const Coord& cc);
	Coord operator*(const Coord& cc);
	Coord operator/(const Coord& cc);
	Coord operator==(const Coord& cc);
};

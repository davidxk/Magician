
class Coord: public OrderedPair
{
public:
	Coord();
	Coord(int aLine, int aColumn);
	Coord operator+(const Coord& cc);
};

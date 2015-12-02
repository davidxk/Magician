


class MoveTo: public Action
{
public:
	//It figures out Coord from from host pointer
	MoveTo(VisibleObject* host, int duration, Coord dest);
	MoveTo(VisibleObject* host, int duration, Coord dest, bool isRepeat);
	virtual getCmdList();
private:
	Coord from;
	Coord dest;
};

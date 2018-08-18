#include "HelloWorld.h"
#include <algorithm>
#include <cctype>
#include <sstream>

Coord ReversedCursor::getNextPosition(Direction dirc)
{
	const Coord coords[]= { Coord::CoordXY(0, +1), Coord::CoordXY(0, -1),
		Coord::CoordXY(+1, 0), Coord::CoordXY(-1, 0) };

	Coord currentPosition = getPos();
	return currentPosition + coords[ dirc ]; 
}

void HelloWorld::getBounds(vector<Point> points, int& xLow, int& xHigh, int& yLow, int& yHigh)
{
	xLow = INT_MAX, xHigh = INT_MIN, yLow = INT_MAX, yHigh = INT_MIN;
	for(const Point& point: points)
	{
		if(point.x < xLow)
			xLow = point.x;
		else if(point.x > xHigh)
			xHigh = point.x;
		if(point.y < yLow)
			yLow = point.y;
		else if(point.y > yHigh)
			yHigh = point.y;
	}
}

vector<Point> HelloWorld::readPoints(const string& fileName)
{
	string path = magician::RES_PATH;
	path += fileName;
	ifstream fin(path.c_str());
	if( fin.bad() ) cerr<<"Error: File read fail! "<<endl;

	string line;
	getline(fin, line);
	auto myisspace = [](char ch) { return isspace(ch); };
	line.erase(remove_if(line.begin(), line.end(), myisspace), line.end());

	istringstream ss(line);
	vector<Point> points;
	int x, y;
	char ch;
	while(true)
	{
		ss >> ch >> x >> ch >> y >> ch;
		points.push_back(Point(x, y));
		if(!ss.eof())
			ss>>ch;
		else
			break;
	}
	return points;
}

void HelloWorld::initScene()
{
	// Read cartesian coordinates from resources/points.txt
	vector<Point> points = readPoints("points.txt");
	// Calculate bounds of the points
	int xLow, xHigh, yLow, yHigh;
	getBounds(points, xLow, xHigh, yLow, yHigh);
	// Define center of the screen and center of the points
	Point pCenter((xLow + xHigh) / 2, (yLow + yHigh) / 2);
	const Coord center(ConsoleCoord::MAX_LINES/2, ConsoleCoord::MAX_COLUMN/2);
	Coord mvToCenter = center - Coord::Cartesian(pCenter.x * 2, pCenter.y);
	// Create mapping from catesian coord to screen coord
	auto mapping = [&mvToCenter](const Point& point) {
		return Coord::Cartesian(point.x * 2, point.y) + mvToCenter;
	};
	vector<Coord> coords(points.size());
	std::transform(points.begin(), points.end(), coords.begin(), mapping);
	// Calculate parameters for the two axis
	xLow -= 2, xHigh += 2, yLow--, yHigh++;
	if(xLow > -2) xLow = -2;
	if(yLow > -2) yLow = -2;
	Coord xAxisPos = mapping(Point(xLow, 0));
	Coord yAxisPos = mapping(Point(0, yHigh));
	int xAxisLen = (xHigh - xLow) * 2, yAxisLen = yHigh - yLow;
	// Create root node for the graph
	ReversedCursor* graphRoot = new ReversedCursor(Geometry::point('+'));
	graphRoot->setPos(mapping(Point(0, 0)));
	this->addChild(graphRoot);
	this->addKeyListener(graphRoot);
	// Create X axis
	Sprite* sp;
	sp = Sprite::create(Geometry::horizontalArrow(xAxisLen, true));
	sp->setPos(xAxisPos);
	graphRoot->addChild(sp);
	// Create Y axis
	sp = Sprite::create(Geometry::verticalArrow(yAxisLen, false));
	sp->setPos(yAxisPos);
	graphRoot->addChild(sp);
	// Create origin for the coordinate system
	sp = Sprite::create(Geometry::point('+'));
	sp->setPos(mapping(Point(0, 0)));
	graphRoot->addChild(sp);
	// Add points to the graph
	for(const Coord& coord: coords)
	{
		sp = Sprite::create(Geometry::point('x'));
		sp->setCenterPos(coord);
		graphRoot->addChild(sp);
	}
}

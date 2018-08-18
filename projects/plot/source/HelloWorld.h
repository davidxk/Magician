#ifndef _HELLO_WORLD_H_
#define _HELLO_WORLD_H_

#include "Magician.h"

// A Cartesian coordinate system plotting tool

struct Point
{
    int x;
    int y;
    Point(int a = 0, int b = 0): x(a), y(b) {}
};

class ReversedCursor: public Cursor
{
public:
	ReversedCursor(const string& fileName): Cursor(fileName) { }
	ReversedCursor(const Image image): Cursor(image) { }
protected:
	virtual Coord getNextPosition(Direction dirc) override;
};

class HelloWorld: public Scene
{
public:
    virtual void initScene() override;
protected:
	void getBounds(vector<Point> points, int& xLow, int& xHigh, int& yLow, int& yHigh);
	vector<Point> readPoints(const string& fileName);
};
#endif

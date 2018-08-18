#ifndef _COORD_TEST_H_
#define _COORD_TEST_H_

#include "TestCase.h"

//description of the class here
class CoordTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Coord Test"; }
private:
	void testConstructor();
	void testCoordXY();
	void testCartesian();
	void testOprEqNeq();
	void testOprAddSub();
	void testOprMulDiv();
	void testOprAddSize();
};
#endif

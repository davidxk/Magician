#ifndef _GEOMETRY_TEST_H_
#define _GEOMETRY_TEST_H_

#include "TestCase.h"
#include "basic/ColoredChar.h"

//description of the class here
class GeometryTest: public TestCase
{
public:
	virtual void run() override;
	virtual std::string testName() override { return "Geometry Test"; }
private:
	bool isImageEqualStrings(Image image, vector<string> strs);
	void testPoint();
	void testHorizontalLine();
	void testHorizontalArrow();
	void testVerticalLine();
	void testVerticalArrow();
	void testRectangle();
};
#endif

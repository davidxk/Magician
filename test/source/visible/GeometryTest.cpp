#include "visible/GeometryTest.h"
#include <cassert>
#include "basic/ColoredChar.h"
#include "visible/Geometry.h"

void GeometryTest::run()
{
	testPoint();
	testHorizontalLine();
	testHorizontalArrow();
	testVerticalLine();
	testVerticalArrow();
	testRectangle();
}

bool GeometryTest::isImageEqualStrings(Image image, vector<string> strs)
{
	if(image.size() != strs.size())
		return false;
	for(int i = 0; i < image.size(); i++)
		if(strs[i].compare(ImageUtil::ImageLine2str(image[i])) != 0)
			return false;
	return true;
}

void GeometryTest::testPoint()
{
	Image image = Geometry::point();
	assert(isImageEqualStrings(image, vector<string>(1, "*")));
}

void GeometryTest::testHorizontalLine()
{
	Image image = Geometry::horizontalLine(5);
	assert(isImageEqualStrings(image, vector<string>(1, "-----")));
}

void GeometryTest::testHorizontalArrow()
{
	Image image = Geometry::horizontalArrow(5, true);
	assert(isImageEqualStrings(image, vector<string>(1, "---->")));
	image = Geometry::horizontalArrow(6, false);
	assert(isImageEqualStrings(image, vector<string>(1, "<-----")));
}

void GeometryTest::testVerticalLine()
{
	Image image = Geometry::verticalLine(3);
	assert(isImageEqualStrings(image, vector<string> {"|", "|", "|"}));
}

void GeometryTest::testVerticalArrow()
{
	Image image = Geometry::verticalArrow(3, true);
	assert(isImageEqualStrings(image, vector<string> {"|", "|", "v"}));
	image = Geometry::verticalArrow(3, false);
	assert(isImageEqualStrings(image, vector<string> {"^", "|", "|"}));
}

void GeometryTest::testRectangle()
{
	Image image = Geometry::rectangle(Size(4, 6));
	vector<string> strs{
		" ____ ", 
		"|    |",
		"|    |",
		"|____|",
	};
	assert(isImageEqualStrings(image, strs));
}

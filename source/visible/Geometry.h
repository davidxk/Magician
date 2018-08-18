#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include "basic/Size.h"
#include "basic/ColoredChar.h"

//Geometry class creates geometric shaped Image
class Geometry
{
public:
	static Image point(char ch = '*', Color forColor = 7, Color backColor = 0);
	static Image horizontalLine(int length, char ch = '-', Color forColor = 7, Color backColor = 0);
	static Image horizontalArrow(int length, bool isRight, Color forColor = 7, Color backColor = 0);
	static Image verticalLine(int length, char ch = '|', Color forColor = 7, Color backColor = 0);
	static Image verticalArrow(int length, bool isDown, Color forColor = 7, Color backColor = 0);
	static Image rectangle(const Size& size);
};
#endif

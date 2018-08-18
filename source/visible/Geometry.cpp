#include "visible/Geometry.h"
#include <cassert>

Image Geometry::point(char ch, Color foreColor, Color backColor)
{
	Image image = ImageUtil::char2Image(ch, foreColor, backColor);
	return image;
}

Image Geometry::horizontalLine(int length, char ch, Color foreColor, Color backColor)
{
	string line(length, ch);
	ImageLine imgLine = ImageUtil::str2ImageLine(line, foreColor, backColor);
	return Image(1, imgLine);
}

Image Geometry::horizontalArrow(int length, bool isRight, Color foreColor, Color backColor)
{
	string shaft(length - 1, '-');
	string arrow;
	if(isRight) arrow = shaft + '>';
	else arrow = '<' + shaft;
	ImageLine line = ImageUtil::str2ImageLine(arrow, foreColor, backColor);
	return Image(1, line);
}

Image Geometry::verticalLine(int length, char ch, Color foreColor, Color backColor)
{
	vector<char> line(length, ch);
	return ImageUtil::vec2Image(line, foreColor, backColor);
}

Image Geometry::verticalArrow(int length, bool isDown, Color foreColor, Color backColor)
{
	vector<char> vec(length - 1, '|');
	if(isDown) vec.push_back('v');
	else vec.insert(vec.begin(), '^');
	return ImageUtil::vec2Image(vec);
}

Image Geometry::rectangle(const Size& size)
{
	int height = size.line, width  = size.column;
	Image image;
	string line;
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
			if(i == 0 or i == height - 1)
			{
				if(j == 0 or j == width - 1)
				{
					if(i == 0)
						line += ' ';
					else
						line += '|';
				}
				else
					line += '_';
			}
			else
			{
				if(j == 0 or j == width - 1)
					line += '|';
				else
					line += ' ';
			}
		image.push_back(ImageUtil::str2ImageLine(line));
		line.clear();
	}
	return image;
}

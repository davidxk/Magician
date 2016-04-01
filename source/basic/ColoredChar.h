#ifndef _COLORED_CHAR_H_
#define _COLORED_CHAR_H_

#include <string>
#include <vector>
using namespace std;

typedef unsigned short Color;

//description of the class here
class ColoredChar
{
public:
	char ch;
	Color color;
	ColoredChar(char aCh = ' ', Color aColor = 0);
	bool operator==(const ColoredChar& cchar) const;
	bool operator!=(const ColoredChar& cchar) const;
};

typedef vector<ColoredChar> ImageLine;
typedef vector<ImageLine> Image;

class ImageUtil
{
public:
	static ImageLine str2ImageLine(const string& str, Color color = 0);
	static string ImageLine2str(const ImageLine& line);
};
#endif

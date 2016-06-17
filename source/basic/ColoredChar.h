#ifndef _COLORED_CHAR_H_
#define _COLORED_CHAR_H_

#include <string>
#include <vector>
using namespace std;

typedef unsigned short Color;

//ColoredChar adds color support to the system
class ColoredChar
{
public:
	char ch;
	Color foreColor;
	Color backColor;
	ColoredChar(char aCh = ' ', Color aForeColor= 0, Color aBackColor = 7);
	bool operator==(const ColoredChar& cchar) const;
	bool operator!=(const ColoredChar& cchar) const;
};

typedef vector<ColoredChar> ImageLine;
typedef vector<ImageLine> Image;

class ImageUtil
{
public:
	static ImageLine str2ImageLine(const string& str, Color foreColor = 0, Color backColor = 7);
	static string ImageLine2str(const ImageLine& line);
};
#endif

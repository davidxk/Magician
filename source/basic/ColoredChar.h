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
	ColoredChar(char aCh = ' ', Color aForeColor= 7, Color aBackColor = 0);
	void setForeColor(Color foreColor);
	void setBackColor(Color backColor);
	void setColor(Color foreColor, Color backColor);
	bool operator==(const ColoredChar& cchar) const;
	bool operator!=(const ColoredChar& cchar) const;
};




//ColorPair defines a foreground and background color pair for printing
class ColorPair
{
public:
	Color foreColor;
	Color backColor;
};

typedef vector<ColoredChar> ImageLine;
typedef vector<ImageLine> Image;

class ImageUtil
{
public:
	static Image char2Image(const char ch, Color foreColor = 7, Color backColor = 0);
	static Image vec2Image(const vector<char>& vec, Color foreColor = 7, Color backColor = 0);
	static ImageLine str2ImageLine(const string& str, Color foreColor = 7, Color backColor = 0);
	static string ImageLine2str(const ImageLine& line);
};
#endif

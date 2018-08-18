#include "basic/ColoredChar.h"

ColoredChar::ColoredChar(char aCh, Color aForeColor, Color aBackColor):
	ch( aCh ), foreColor(aForeColor), backColor(aBackColor) { }

void ColoredChar::setForeColor(Color foreColor)
{
	this->foreColor = foreColor;
}

void ColoredChar::setBackColor(Color backColor)
{
	this->backColor = backColor;
}

void ColoredChar::setColor(Color foreColor, Color backColor)
{
	this->foreColor = foreColor;
	this->backColor = backColor;
}

bool ColoredChar::operator==(const ColoredChar& cchar) const
{
	return ch == cchar.ch && foreColor == cchar.foreColor &&
		backColor == cchar.backColor;
}

bool ColoredChar::operator!=(const ColoredChar& cchar) const
{
	return ch != cchar.ch || foreColor != cchar.foreColor ||
	   backColor != cchar.backColor;
}





Image ImageUtil::char2Image(const char ch, Color foreColor, Color backColor)
{
	return Image(1, ImageLine(1, ColoredChar(ch, foreColor, backColor)));
}

Image ImageUtil::vec2Image(const vector<char>& vec, Color foreColor, Color backColor)
{
	Image image;
	for(const char ch: vec)
		image.push_back(ImageLine(1, ch));
	return image;
}

ImageLine ImageUtil::str2ImageLine(const string& str, Color foreColor, Color backColor)
{
	ImageLine line;
	for(const auto& ch: str)
		line.push_back( ColoredChar(ch, foreColor, backColor) );
	return line;
}

string ImageUtil::ImageLine2str(const ImageLine& line)
{
	string str;
	for(const auto& cchar: line)
		str += cchar.ch;
	return str;
}

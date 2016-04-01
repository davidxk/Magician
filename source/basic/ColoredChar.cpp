#include "basic/ColoredChar.h"

ColoredChar::ColoredChar(char aCh, Color aColor):
	ch( aCh ), color(aColor) { }

bool ColoredChar::operator==(const ColoredChar& cchar) const
{
	return ch == cchar.ch && color == cchar.color;
}

bool ColoredChar::operator!=(const ColoredChar& cchar) const
{
	return ch != cchar.ch || color != cchar.color;
}




ImageLine ImageUtil::str2ImageLine(const string& str, unsigned short color)
{
	ImageLine line;
	for(const auto& ch: str)
	{
		ColoredChar chr;
		chr.ch = ch;
		chr.color = color;
		line.push_back( chr );
	}
	return line;
}

string ImageUtil::ImageLine2str(const ImageLine& line)
{
	string str;
	for(const auto& cchar: line)
		str += cchar.ch;
	return str;
}

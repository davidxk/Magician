#include "basic/ColoredChar.h"

ColoredChar::ColoredChar(char aCh, Color aForeColor, Color aBackColor):
	ch( aCh ), foreColor(aForeColor), backColor(aBackColor) { }

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




ImageLine ImageUtil::str2ImageLine(const string& str, Color foreColor, Color backColor)
{
	ImageLine line;
	for(const auto& ch: str)
	{
		ColoredChar chr;
		chr.ch = ch;
		chr.foreColor = foreColor;
		chr.backColor = backColor;
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

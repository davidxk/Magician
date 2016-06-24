#include "display/UnixPrinter.h"
#include <curses.h>

UnixPrinter::UnixPrinter()
{
	initscr();
	curs_set(0);
	hasColor = has_colors();
	if( hasColor )
		start_color();
}

void UnixPrinter::print(PrintJob pj)
{
	int xx = pj.cCoord.column;
	int yy = pj.cCoord.line;
	char ch = pj.graph.ch;

	if( hasColor )
	{
		init_pair(1, pj.graph.foreColor, pj.graph.backColor);
		attron(COLOR_PAIR(1));
	}

	mvaddch(yy, xx, ch);
	refresh();
}

UnixPrinter::~UnixPrinter()
{
	attroff(COLOR_PAIR(1));
	endwin();
}

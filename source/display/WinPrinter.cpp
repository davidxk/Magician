#include "display/WinPrinter.h"
#include <iostream>
using namespace std;

WinPrinter::WinPrinter()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
}

void WinPrinter::print(PrintJob pj)
{
	COORD pos={ (short)pj.cCoord.column, (short)pj.cCoord.line };
	SetConsoleCursorPosition( hOut, pos );
	SetConsoleTextAttribute( hOut, (WORD)pj.graph.color );
	cout<<pj.graph.ch;
}

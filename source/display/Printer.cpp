#include "display/Printer.h"
#include <iostream>
using namespace std;

Printer::Printer()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Printer::print(PrintJob pj)
{
	COORD pos={ (short)pj.cCoord.column, (short)pj.cCoord.line };
	SetConsoleCursorPosition( hOut, pos );
	SetConsoleTextAttribute( hOut, (WORD)pj.graph.color );
	cout<<pj.graph.ch;
}

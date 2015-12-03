#include "display/Printer.h"

Printer::Printer()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Printer::print(PrintJob pj)
{
      COORD pos={ pj.cCoord.column, pj.cCoord.line };
      SetConsoleCursorPosition( hOut, pos );
	  cout<<pj.graph;
}

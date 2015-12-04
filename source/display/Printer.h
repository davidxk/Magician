#ifndef _PRINTER_H_
#define _PRINTER_H_

#include "basic/PrintJob.h"
#include <conio.h>
#include <windows.h>

//Prints char on a specified position
//If to implement on other platform, make this a base class 
class Printer
{
public:
	Printer();
	void print(PrintJob pj);
	HANDLE hOut;
};
#endif

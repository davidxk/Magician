#ifndef _WIN_PRINTER_H_
#define _WIN_PRINTER_H_

#include "display/PrintJob.h"
#include <conio.h>
#include <windows.h>

//WinPrinter is a Win32 implemention of Printer base-class
class WinPrinter
{
public:
	WinPrinter();
	virtual void print(PrintJob pj);
	virtual ~WinPrinter() { };
private:
	HANDLE hOut;
};
#endif

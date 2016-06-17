#ifndef _WIN_PRINTER_H_
#define _WIN_PRINTER_H_

#include "display/Printer.h"
#include "display/PrintJob.h"
#include <curses.h>

//UnixPrinter is a Unix implemention of Printer base-class
class UnixPrinter: public Printer
{
public:
	UnixPrinter();
	virtual void print(PrintJob pj);
	virtual ~UnixPrinter();
private:
	bool hasColor;
};
#endif


#ifndef _WIN_PRINTER_H_
#define _WIN_PRINTER_H_

#include "display/Printer.h"
#include "display/PrintJob.h"
#include <vector>

//UnixPrinter is a Unix implemention of Printer base-class
class UnixPrinter: public Printer
{
public:
	UnixPrinter();
	virtual void print(PrintJob pj);
	virtual void print(std::vector<PrintJob> jobList);
	virtual ~UnixPrinter();
private:
	void virtualPrint(PrintJob pj);
	bool hasColor;
};
#endif

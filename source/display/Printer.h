#ifndef _PRINTER_H_
#define _PRINTER_H_

#include "display/PrintJob.h"

//Printer prints chars to a specified position with specified attributes
//To implement it on multiple platforms, it is made a base class 
class Printer
{
public:
	Printer();
	virtual void print(PrintJob pj) { };
	virtual ~Printer() { };
};
#endif

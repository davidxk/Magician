#ifndef _PRINTER_H_
#define _PRINTER_H_

#include "basic/PrintJob.h"
#include <string>

//Printer prints chars to a specified position
//To implement it on another platform, make this a base class 
class Printer
{
public:
	Printer();
	void print(PrintJob pj);
};
#endif

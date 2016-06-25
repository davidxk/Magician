#include "display/Printer.h"

Printer::Printer() { }

void Printer::print(PrintJob pj) { }

void Printer::print(std::vector<PrintJob> jobList) 
{ 
	for(const auto& it: jobList)
		print( it );
}

Printer::~Printer() { }

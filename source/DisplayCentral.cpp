#include "display/DisplayCentral.h"

void DisplayCentral::update(vector<PrintJob>* jobList)
{
	for(const auto& it: jobList)
		printer.print(it);
}

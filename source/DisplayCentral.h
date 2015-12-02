#ifndef _DISPLAY_CENTRAL_H_
#define _DISPLAY_CENTRAL_H_

#include "PrintJob.h"
#include "Printer.h"
#include <vector>

//description of the class here
class DisplayCentral
{
public:
	DisplayCentral();
	void paint(const vector<PrintJob>& jobList);
	vector<PrintJob> getDiff();
	void setThisFrame(vector<string> frameThis);
public:
	Printer printer;
	vector<string> frameLast;
	vector<string> frameThis;
};
#endif

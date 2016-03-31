#ifndef _DISPLAY_CENTRAL_H_
#define _DISPLAY_CENTRAL_H_

#include "basic/PrintJob.h"
#include "display/PsudoPrinter.h"
#include <string>
#include <vector>
using namespace std;

//Display Central takes in a frame and from it calculates a print job list
//It then calls on the Printer to print it 
class DisplayCentral
{
public:
	DisplayCentral();
	void update(const vector<string>& frameThis);
	void setThisFrame(const vector<string>& frameThis);
	void verifyFrame(const vector<string>& frame);
	vector<PrintJob> getDiff();
	void print(const vector<PrintJob>& jobList);
public:
	Printer printer;
	vector<string> frameLast;
	vector<string> frameThis;
};
#endif

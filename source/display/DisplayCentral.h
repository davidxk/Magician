#ifndef _DISPLAY_CENTRAL_H_
#define _DISPLAY_CENTRAL_H_

#include "basic/PrintJob.h"
#include "display/Printer.h"
#include <string>
#include <vector>
using namespace std;

//Display Central takes in a frame and from it calculates a print job list
//It then calls on the Printer to print it 
class DisplayCentral
{
public:
	DisplayCentral();
	void update(const vector<wstring>& frameThis);
	void setThisFrame(const vector<wstring>& frameThis);
	void verifyFrame(const vector<wstring>& frame);
	vector<PrintJob> getDiff();
	void print(const vector<PrintJob>& jobList);
public:
	Printer printer;
	vector<wstring> frameLast;
	vector<wstring> frameThis;
};
#endif

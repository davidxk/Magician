#ifndef _DISPLAY_CENTRAL_H_
#define _DISPLAY_CENTRAL_H_

#include "basic/PrintJob.h"
//#include "display/Printer.h"
#include <string>
#include <vector>
using namespace std;

//description of the class here
class DisplayCentral
{
public:
	DisplayCentral();
	void update();
	void paint(const vector<PrintJob>& jobList);
	vector<PrintJob> getDiff();
	void setThisFrame(const vector<wstring>& frameThis);
	void verify(const vector<wstring>& frame);
public:
	//Printer printer;
	vector<wstring> frameLast;
	vector<wstring> frameThis;
};
#endif

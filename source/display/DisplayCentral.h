#ifndef _DISPLAY_CENTRAL_H_
#define _DISPLAY_CENTRAL_H_

#include "basic/ColoredChar.h"
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
	void update(const Image& frameThis);

	//For testability
public:
	void setThisFrame(const Image& frameThis);
	void verifyFrame(const Image& frame);
	vector<PrintJob> getDiff();
	void print(const vector<PrintJob>& jobList);

	Printer printer;
	Image frameLast;
	Image frameThis;
};
#endif

#ifndef _DISPLAY_CENTRAL_H_
#define _DISPLAY_CENTRAL_H_

//include here

//description of the class here
class DisplayCentral
{
public:
	DisplayCentral();
	void paint(const vector<PrintJob>& jobList);
	vector<PrintJob> getDiff();
	void setThisFrame(vector<string> frameThis);
};
#endif
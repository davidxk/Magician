#include "display/DisplayCentral.h"

void DisplayCentral::paint(const vector<PrintJob>& jobList)
{
	for(const auto& it: jobList)
		printer.print(it);
}

void DisplayCentral::update()
{

}

vector<PrintJob> DisplayCentral::getDiff()
{
	//get frame last and frame this
	bool newDiff = true;
	string sentence;
	vector<PrintJob> pjList;
	for(int i=0; i<frameLast.size(); i++)
		for(int j=0; j<frameLast[0].size(); j++)
			if(frameLast[i][j] != frameThis[i][j])
			{
				if(newDiff) tmp.clear();
				tmp += frameThis[i][j];
				newDiff = false;
			}
			else
			{
				pjList.push_back(PrintJob(ConsoleCoord(i,j), tmp));
				newDiff = true;
			}
	return pjList;
}

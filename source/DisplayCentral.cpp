#include "display/DisplayCentral.h"

DisplayCentral::DisplayCentral()
{
	for(int i=0; i<CONSOLE_HEIGHT; i++)
		prev[i]=string(CONSOLE_WIDTH, ' ');
}

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
	vector<PrintJob> pjList;
	for(int i=0; i<frameLast.size(); i++)
		for(int j=0; j<frameLast[0].size(); j++)
			if(frameLast[i][j] != frameThis[i][j])
				pjList.push_back(PrintJob(ConsoleCoord(i,j), frameThis[i][j]));
	return pjList;
}

vector<string> DisplayCentral::getThisFrame()
{
	// deal with static object
	// deal with actions
}

bool isInBox(ConsoleCoord upperLeft, ConsoleSize size)
{
	//pending: operator + overload
	ConsoleCoord bottomRight = upperLeft + size;
	//rectangle overlap algorithm 
}

#include "display/DisplayCentral.h"
#include "VisibleObjManger.h"

DisplayCentral::DisplayCentral()
{
	for(int i=0; i<ConsoleCoord::MAX_LINES+1; i++)
		prev[i]=string(ConsoleCoord::MAX_COLUME+1, ' ');
}

void DisplayCentral::update()
{
	setThisFrame( vManager->getFrame() );
	paint( getDiff() );
}





void DisplayCentral::setThisFrame(vector<string> frameThis)
{
	this->frameLast = this->frameThis
	this->frameThis = frameThis;
}

vector<PrintJob> DisplayCentral::getDiff()
{
	//get frame last and frame this
	vector<PrintJob> pjList;
	for(int i=0; i<frameLast.size(); i++)
		for(int j=0; j<frameLast[0].size(); j++)
			if(frameLast[i][j] != frameThis[i][j])
				pjList.push_back(PrintJob(ConsoleCoord(i,j), frameThis[i][j]));
	//else if(colorLast[i][j] != colorThis[i][j])
	return pjList;
}

void DisplayCentral::paint(const vector<PrintJob>& jobList)
{
	for(const auto& it: jobList)
		printer.print(it);
}

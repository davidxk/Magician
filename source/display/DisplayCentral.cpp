#include "display/DisplayCentral.h"
#include <cassert>
#include "display/VisibleObjManager.h"

DisplayCentral::DisplayCentral()
{
	frameThis.resize( ConsoleCoord::MAX_LINES+1 );
	for(int i=0; i<ConsoleCoord::MAX_LINES+1; i++)
		frameThis[i]=wstring(ConsoleCoord::MAX_COLUMN+1, L' ');
}

void DisplayCentral::update()
{
	setThisFrame( vManager->getFrame() );
	paint( getDiff() );
}





void DisplayCentral::setThisFrame(const vector<wstring>& frameNext)
{
	verify(frameNext);
	frameLast = frameThis;
	frameThis = frameNext;
}

vector<PrintJob> DisplayCentral::getDiff()
{
	verify(frameThis);
	//get frame last and frame this
	vector<PrintJob> pjList;
	for(int i=0; i<frameThis.size(); i++)
		for(int j=0; j<frameThis[i].size(); j++)
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

void DisplayCentral::verify(const vector<wstring>& frame)
{
	assert( frame.size()==ConsoleCoord::MAX_LINES+1 );
	for(const auto& line: frame)
		assert( line.size()==ConsoleCoord::MAX_COLUMN+1 );
}

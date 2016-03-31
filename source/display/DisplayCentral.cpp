#include "display/DisplayCentral.h"
#include <cassert>

DisplayCentral::DisplayCentral()
{
	frameThis.resize( ConsoleCoord::MAX_LINES+1 );
	for(int i=0; i<ConsoleCoord::MAX_LINES+1; i++)
		frameThis[i] = ImageUtil::str2ImageLine( string(ConsoleCoord::
					MAX_COLUMN+1, ' ') );
}

void DisplayCentral::update(const Image& frameNext)
{
	setThisFrame( frameNext );
	print( getDiff() );
}





void DisplayCentral::setThisFrame(const Image& frameNext)
{
	verifyFrame(frameNext);
	frameLast = frameThis;
	frameThis = frameNext;
}

vector<PrintJob> DisplayCentral::getDiff()
{
	verifyFrame(frameThis);
	//get frame last and frame this
	vector<PrintJob> pjList;
	for(int i=0; i<frameThis.size(); i++)
		for(int j=0; j<frameThis[i].size(); j++)
			if(frameLast[i][j] != frameThis[i][j])
				pjList.push_back(PrintJob(ConsoleCoord(i,j), frameThis[i][j]));
	//else if(colorLast[i][j] != colorThis[i][j])
	return pjList;
}

void DisplayCentral::print(const vector<PrintJob>& jobList)
{
	for(const auto& it: jobList)
		printer.print(it);
}

void DisplayCentral::verifyFrame(const Image& frame)
{
	assert( frame.size()==ConsoleCoord::MAX_LINES+1 );
	for(const auto& line: frame)
		assert( line.size()==ConsoleCoord::MAX_COLUMN+1 );
}

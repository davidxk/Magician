#include "basic/MagicianMacros.h"
#include "display/DisplayCentral.h"
#include <cassert>

#if defined(WIN)
#include "display/WinPrinter.h"
#else
#include "display/UnixPrinter.h"
#endif



DisplayCentral::DisplayCentral()
{
	// Init frameThis
	frameThis.resize( ConsoleCoord::MAX_LINES + 1 );
	for(auto& line: frameThis)
		line = ImageUtil::str2ImageLine( string(ConsoleCoord::
					MAX_COLUMN + 1, ' ') );

	// Conditional init printer according to platform
#if defined(TEST)
	printer = new Printer();
#elif defined(WIN)
	printer = new WinPrinter();
#else
	printer = new UnixPrinter();
#endif
}

void DisplayCentral::destroyPrinter()
{
	delete printer;
}

void DisplayCentral::printFrame(const Image& frameNext)
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
	for(unsigned i=0; i<frameThis.size(); i++)
		for(unsigned j=0; j<frameThis[i].size(); j++)
			if(frameLast[i][j] != frameThis[i][j])
				pjList.push_back(PrintJob(ConsoleCoord(i,j), frameThis[i][j]));
	//else if(colorLast[i][j] != colorThis[i][j])
	return pjList;
}

void DisplayCentral::print(const vector<PrintJob>& jobList)
{
	printer->print( jobList );
}

void DisplayCentral::verifyFrame(const Image& frame)
{
	assert( frame.size()==ConsoleCoord::MAX_LINES+1 );
	for(const auto& line: frame)
		assert( line.size()==ConsoleCoord::MAX_COLUMN+1 );
}

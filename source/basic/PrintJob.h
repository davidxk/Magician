#ifndef _PRINT_JOB_H_
#define _PRINT_JOB_H_

#include "basic/ConsoleCoord.h"
#include <cwchar>

//description of the class here
class PrintJob
{
public:
	ConsoleCoord cCoord;
	wchar_t graph;
	PrintJob() { }
	PrintJob(ConsoleCoord aCCoord, wchar_t aGraph);
};
#endif

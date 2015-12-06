#ifndef _PRINT_JOB_H_
#define _PRINT_JOB_H_

#include "basic/ConsoleCoord.h"
#include <cwchar>

//A Print Job specifies a character to be printed at a specific coordinate
class PrintJob
{
public:
	ConsoleCoord cCoord;
	wchar_t graph;
	PrintJob() { }
	PrintJob(ConsoleCoord aCCoord, wchar_t aGraph);
};
#endif

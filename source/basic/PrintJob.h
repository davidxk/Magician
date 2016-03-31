#ifndef _PRINT_JOB_H_
#define _PRINT_JOB_H_

#include "basic/ConsoleCoord.h"

//A Print Job specifies a character to be printed at a specific coordinate
class PrintJob
{
public:
	ConsoleCoord cCoord;
	char graph;
	PrintJob() { }
	PrintJob(ConsoleCoord aCCoord, char aGraph);
};
#endif

#ifndef _PRINT_JOB_H_
#define _PRINT_JOB_H_

#include "basic/ConsoleCoord.h"

//description of the class here
class PrintJob
{
public:
	ConsoleCoord cCoord;
	char graph;
	PrintJob() { }
	PrintJob(ConsoleCoord aCCoord, char aGraph);
};
#endif

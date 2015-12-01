#ifndef _PRINT_JOB_H_
#define _PRINT_JOB_H_

#include "display/ConsoleCoord.h"

//description of the class here
class PrintJob
{
public:
	ConsoleCoord cCoord;
	string graph;
	PrintJob() { }
	PrintJob(ConsoleCoord aCCoord, string aGraph);
};
#endif

#ifndef _PRINT_JOB_H_
#define _PRINT_JOB_H_

#include "basic/ColoredChar.h"
#include "basic/ConsoleCoord.h"

//A Print Job specifies a character to be printed at a specific coordinate
class PrintJob
{
public:
	ConsoleCoord cCoord;
	ColoredChar graph;
	PrintJob() { }
	PrintJob(ConsoleCoord aCCoord, ColoredChar aGraph);
};
#endif

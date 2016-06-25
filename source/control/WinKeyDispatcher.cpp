#include "control/WinKeyDispatcher.h"
#include <conio.h>

int WinKeyDispatcher::readkey()
{
	return getch();
}

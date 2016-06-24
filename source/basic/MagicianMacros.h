#ifndef _MAGICIAN_MACROS_H_
#define _MAGICIAN_MACROS_H_

#include <iostream>
#include <fstream>

#define MGASSERT(cond, msg) do {                              \
	if (!(cond)) {                                          \
		cout<<"Assert failed: "<<msg;             \
		assert(cond);                                      \
	} \
} while (0)

#define MGLOG( msg ) do {   \
	std::fstream logOut(magician::LOG_PATH, ios::app); \
	logOut<<msg<<std::endl; \
} while (0)

//#define TEST

namespace magician{
	const int TIME_UNIT = 50;
	const std::string RES_PATH = "../../resources/";
	const std::string LOG_PATH ="mglog.txt";
}
#endif

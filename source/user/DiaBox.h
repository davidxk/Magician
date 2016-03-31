#ifndef _DIA_BOX_H_
#define _DIA_BOX_H_

#include "base/Box.h"
#include <string>
using namespace std;

class DiaBox: public Box
{
public:
	DiaBox(const Size& size, const string& content);
	static DiaBox* create(const Size& size, const string& content);
	void setContent(const string& content);
public:
	string content;
};
#endif

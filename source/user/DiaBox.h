#ifndef _DIA_BOX_H_
#define _DIA_BOX_H_

#include "base/Box.h"
#include <string>
using namespace std;

class DiaBox: public Box
{
public:
	DiaBox(const Size& size, const wstring& content);
	static DiaBox* create(const Size& size, const wstring& content);
	void setContent(const wstring& content);
public:
	wstring content;
};
#endif

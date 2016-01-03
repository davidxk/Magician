#ifndef _TEXT_FIELD_H_
#define _TEXT_FIELD_H_

#include "base/VisibleObject.h"
#include "basic/Size.h"
#include <string>
using namespace std;

//description of the class here
class TextField: public VisibleObject
{
public:
	TextField(const Size& size, const wstring& content);
	static TextField* create(const Size& size, const wstring& content);
	void setSize(const Size& size);
	void setContent(const wstring& content);
public:
	wstring content;
};
#endif

#ifndef _TEXT_FIELD_H_
#define _TEXT_FIELD_H_

#include "base/VisibleObject.h"
#include "basic/Size.h"
#include <string>
using namespace std;

//A TextField with endline support
class TextField: public VisibleObject
{
public:
	TextField(const Size& size, const string& content);
	static TextField* create(const Size& size, const string& content);
	void setSize(const Size& size);
	void setContent(const string& content);
public:
	string content;
};
#endif

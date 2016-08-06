#ifndef _CALL_FUNC_H_
#define _CALL_FUNC_H_

#include "action/Action.h"
#include "action/Command.h"
#include "display/Node.h"
#include <functional>
using namespace std;

//description of the class here
class CallFunc: public Action
{
public:
	CallFunc(Node* host, function<void()> funcObj);
	static CallFunc* create(Node* host, function<void()> funcObj);
	void getCmdQueue();
private:
	function<void()> func;
};



class CallFuncCommand: public Command
{
public:
	CallFuncCommand(function<void()> funcObj);
	void apply(Node* node);
	virtual Command* clone() { return new CallFuncCommand(*this); }
private:
	function<void()> func;
};
#endif

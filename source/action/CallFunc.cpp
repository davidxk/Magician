#include "action/CallFunc.h"

CallFunc::CallFunc(Node* host, function<void()> funcObj):
	Action(host, 0), func( funcObj )
{
	getCmdQueue();
}

CallFunc* CallFunc::create(Node* host, function<void()> funcObj)
{
	return new CallFunc(host, funcObj);
}

void CallFunc::getCmdQueue()
{
	cmdQueue.push( new CallFuncCommand( func ) );
}




CallFuncCommand::CallFuncCommand(function<void()> funcObj): func( funcObj ) { }

void CallFuncCommand::apply(Node* node)
{
	func();
}

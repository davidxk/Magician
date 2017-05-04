#include "action/CallFuncTest.h"
#include <cassert>
#include "action/CallFunc.h"
#include "action/ActionManager.h"

void CallFuncTest::run()
{
	testWithManager();
}

void CallFuncTest::testWithManager()
{
	Node* host = new Node();
	auto funcObj = std::bind(&CallFuncTest::func, this);
	CallFunc* callFunc = CallFunc::create(host, funcObj);
	ActionManager amgr;
	amgr.addAction( callFunc );

	this->called = false;
	amgr.update();
	assert( this->called == true );
	delete host;
}

void CallFuncTest::func()
{
	this->called = true;
}

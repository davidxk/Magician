#ifndef _KEY_DISPATCHER_H_
#define _KEY_DISPATCHER_H_

#include "control/KeyListener.h"
#include <stack>

//A KeyDispatcher reads key strokes from user input in a seperate thread
//After translation, it dispatches the key stroke to the registered KeyListener
class KeyDispatcher
{
public:
	KeyDispatcher();
	virtual Key translate(int ch);
	virtual int readkey();
	void loop();
	void pushListener(KeyListener* listener);
	void popListener();
	void clearStack();
private:
	std::stack<KeyListener*> listenerStack;
};
#endif

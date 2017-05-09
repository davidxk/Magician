#ifndef _KEY_DISPATCHER_H_
#define _KEY_DISPATCHER_H_

#include "control/KeyListener.h"
#include <stack>

void loop();
Key translate(int ch);
int readkey();

//A KeyDispatcher reads key strokes from user input in a seperate thread
//After translation, it dispatches the key stroke to the registered KeyListener
class KeyDispatcher
{
friend void loop();
public:
	KeyDispatcher();
	void pushListener(KeyListener* listener);
	void popListener();
	void clearStack();
private:
	std::stack<KeyListener*> listenerStack;
};
#endif

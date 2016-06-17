#Interactive System
Apparently, the interactive system is quite a complex one which encompasses a range of subsystems. Box, Window, Menu, KeyDispatcher, etc. Let's see what they do in details. 

##KeyDispatcher
* A KeyDispatcher listens to the key strokes in a while loop on a separate thread with system specific APIs. 
* After translating the key stroke into standard code, it then dispatches the key stroke to the registered KeyListener. Use a registration stack. When one is out of use, it can be simply popped out of the stack) 
* The respond function of the KeyListener is called upon to respond to the given key stroke. A mapped function object is triggered in this very thread. (Scheduling the action on the clock thread is also considered. The implementation seems tricky) All data modification must be done with great caution of collapsing with other threads. 
(A solution to this problem is to add lock to all read and write operations on all data. ) 

##Menu
A Menu is a KeyListener. 
A Menu is inited with an array of strings as its items. Its each item relates to a certain function. 
A Menu base class defines the default action of up, down, forward and back keys. When a menu is created, it registers itself to the KeyDispatcher registration stack and popps itself out when destroyed. 

##Table
A Table is a VisibleObject. 
A Table prints its contents in a given sized matrix. 

##Box
A Box is a VisibleObject. 








#Appendix: Former Thoughts
##Intro
Menus are controllers that reads the keystroke from the keyboard and responds in accordance. The thing about Menus is that only one box can be in charge at a given point of time, so we must come up with a way to arrange for the cooperation of the Menus. Here is my solution. 

##Window Manager
###Window Stack
When a new window is created, it should be put on the top of the window stack. 

###Default Window
The default window is an optional, default, boxless window whose sole purpose is to create windows upon keystrokes. It resides at the bottom of the window stack and is never popped out. 

###Keystroke Listener
A system-specific keystroke listener that gets keystrokes and translate it into standard ascii code. 
A keystroke listener should be listening to keystroke event on a seperate thread. 

###Keystroke Dispatcher
A keystroke dispatcher always dispatches the keystroke to the window at the top of the window stack. 

##Window
A window has a pre-defined responce to every given keystroke.

When a window receives a keystroke, it should respond in the following sequence:
* Do something functional
* Display responce to keystroke

List of a few possible functions: 
* Text change in another window
* Animation on another sprite
* Saving of the game progress
* Place change of a sprite
* Entering of another scene

In a directional key based window system, a keystroke usually cause the following display effect:
* Opening of a new window
* Closing of the current window
* Highlighting of the next/previous menu item
* Text change in the current window
* Closing of stack-top windows

Based on the previous description, a window should in essence be a keystroke responder, a controller. It has the form of a visible, respondent box. It performs the tasks assigned to each button in the window, when called upon through given, specific keystrokes. 

###Window or Box?
Window is a logical widget while box is simply a visible object. For example, a dialog window knows what its lines while text box is only a means of printing a line in a box. 

class VerticalMenu: Window
{
public:
	VerticalListBox vertical;
private:
	TextBox tbox;
	vector<Ability> abilities;
	int indexItem;
public:
	void onPressUpKey()
	{
		//tbox->setText( abilities[++indexItem].description );
		//vertical->highlightNextItem();
	}
};

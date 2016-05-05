##Intro
Menus are controllers that reads the keystroke from the keyboard and responds in accordance. The thing about Menus is that only one box can be in charge at a given point of time, so we must come up with a way to arrange for the cooperation of the Menus. Here is my solution. 
A Controller should be a Controller and have a VisibleObject, usually a Box. Box is a VisibleObject in charge of the re-painting of the image while Controller is a input processor that responds to the user's input. 
For clarity, we refer to the modification of image as painting and the actual wcout output as printing. 

##CentralControl
public:
* stack<Controller*> callStack;
* unordered_map<function> msgMap;
* void addController(Controller\* ctrl);
private:
* void popBox() { callStack->front()->box->setVisible(false); pop; }
* void clearBoxes();	//for each set invisible, clear

##Controller
public:
* string respond(char keyStroke)
* Box\* box;

##DiaBox: public Box
* DiaBox(vector<wstring> aText): text(aText) { }
* vector<wstring> text;
* int index = 0;
* void paintNext();	//{ paint( text[index++] ); }
* void paint();		//{ for(1~<size.line) for(1~<size.column) [cnt++];\>\>} 

##ListBox: public Box
* vector<wstring> item;
* int index = 0;
* enum Style { FORE_COLOR, BACK_COLOR, CHAR_MARK }; 
* char marker;
* Color color;
* void paint();
* void highLightNext();	//{ 	if( index + 1 < item.size() )
				lowLight(index), highLight( item[ ++index ] ); }
* void highLightPrev();	//{ 	if( index - 1 >= 0 )
				lowLight(index), highLight( item[ --index ] ); }
* void highLight(int index, Style style = CHAR_MARK);
* void lowLight(int index, Style style = CHAR_MARK);

##HorizonBox: public ListBox
* HorizonBox(vector<wstring> item, wstring aText): ListBox(item), text(aText){}
* wstring text;
* void paint();

##DiaMenu: public Controller
// To be directly instantiated
* DiaMenu(vector<wstring> text): diabox(text) { }
* DiaBox\* diabox;
* string respond(char keyStroke) { next(); return L"";}
* void next() { diabox->paintNext; }

##ListMenu: public Controller
// To be inherited
* ListMenu(vector<wstring> item): listbox(item) { }
* ListBox\* listbox;
* string respond(char keyStroke);	//up down ok cancel

##HorizonMenu: public Controller
// To be inherited
* HorizonMenu(vector<wstring> item, wstring aText): HorizonBox(item, aText) { }
* HorizonBox horizon;
* string respond(char keyStroke);	//to be defined

##ConfirmMenu: public HorizonMenu
// To be directly instantiated
* ConfirmMenu(string aText) { Yes, No }
* string respond(char keyStroke);	//before confirm, a "CONFIRM" is sent
					// to hold the function to be executed

#Intro
Display is the core of the whole engine. It is a complex system, yet luckily, I've decided that the first version is a purely 1 space characters implementation, so there is only little more to add. 

##Printer
*Untestable on McMoonlight*

##Sprite
Sprite::Sprite(const string& fileName)
*tested interally*

static Sprite\* Sprite::create(const string& fileName)
* input: "graph/moon.txt"
* output: sp

##VisibleObjManger
void VisibleObjManger::addObject(VisibleObjManger object)
* input: sp
* output: objList.size() == 1

vector<wstring> VisibleObjManger::getFrame()
* input: 
* output: ~~ "1234 \*" "4321 \*"


##MoveTo
* input: sp (0, 0) 10 (23, 79) yes
* output: mt, cmdList.size()==9

##ActionManager
define aManager sActionManager::instance()
*tested interally*

void ActionManager::addAction(Action\* action)
* input: mt
* output: actionList.size()==1

void ActionManager::update()
* input: 
* output: frame, sp.pos==Coord(?, ?) , mt.cmdList.size()==9


##DisplayCentral
DisplayCentral::DisplayCentral()
* input: 
* output: ~~" \*"

void DisplayCentral::update()
*trusted*

void DisplayCentral::setThisFrame(vector<wstring> frameThis)
*tested interally*

vector<PrintJob> DisplayCentral::getDiff()
* input: frame
* output: pjList.size()==8

void DisplayCentral::paint(const vector<PrintJob>& jobList)
*Untestable on McMoonlight*


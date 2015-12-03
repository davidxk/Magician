#Intro
Base classes are simple classes that provide basic services. Since they have limited functions, they are easy to test. 

##VisibleObject
void VisibleObject::verify()
*test internally later*

void VisibleObject::setPos(const Coord& cc)
*trusted*

##Action
Action::Action(VisibleObject\* aHost, int aDuration, bool aIsRepeat):
*trusted*

##Box
Box::Box(const Size& size)
* input: Size(3, 6)
* output: " ----.", "|    |", "`---- "

void Box::setSize(Size size)
*test internally*

##Command
Command::Command(CmdType aType, delta aNext)
*test internally*

void apply(VisibleObject\* vo);
* input: Command(Command::CHANGE_POS, Coord(10, 30)) VisibleObject(1, 2)
* output: (10, 30)

**test later**
* input: Command(Command::CHANGE_IMG, 2), AnimSprite("batch/batch_moon.txt")
* output: "4321"

##Singleton
*trusted*

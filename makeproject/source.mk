## Const Path Variable
src_path=$(proj_path)/source 
basic_path=$(addsuffix /basic,$(src_path))
base_path=$(addsuffix /base,$(src_path))
display_path=$(addsuffix /display,$(src_path))
user_path=$(addsuffix /user,$(src_path))
audio_path=$(addsuffix /audio,$(src_path))

## Implicit Variable
VPATH+=$(src_path) $(basic_path) $(base_path) $(user_path) \
       $(display_path) $(audio_path)
CXXFLAGS+=-I $(src_path) 

## Source List
#ls -R | perl ls_r_parse.pl
#s/.*\/\([A-Z].\)$/\1 \\/
#g/\.h$/d
sources+= Logo.cpp \
MainLoop.cpp \
MciPlayer.cpp \
Action.cpp \
Box.cpp \
Command.cpp \
Singleton.cpp \
Transition.cpp \
VisibleObject.cpp \
ConsoleCoord.cpp \
Coord.cpp \
ImageLoader.cpp \
OrderedPair.cpp \
PrintJob.cpp \
Random.cpp \
Size.cpp \
TimeService.cpp \
ActionManager.cpp \
DisplayCentral.cpp \
Printer.cpp \
VisibleObjManager.cpp \
AnimSprite.cpp \
Animation.cpp \
DiaBox.cpp \
Layer.cpp \
MoveBy.cpp \
MoveTo.cpp \
Repeat.cpp \
Scheduler.cpp \
Sequence.cpp \
Sleep.cpp \
Sprite.cpp \
TextField.cpp \
Vanish.cpp \

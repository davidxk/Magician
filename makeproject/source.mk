## Const Path Variable
src_path=$(proj_path)/source 
action_path=$(addsuffix /action,$(src_path))
audio_path=$(addsuffix /audio,$(src_path))
basic_path=$(addsuffix /basic,$(src_path))
control_path=$(addsuffix /control,$(src_path))
display_path=$(addsuffix /display,$(src_path))
visible_path=$(addsuffix /visible,$(src_path))

## Implicit Variable
VPATH+=$(src_path) $(action_path) $(audio_path) $(basic_path) \
       $(control_path) $(display_path) $(visible_path)
CXXFLAGS+=-I $(src_path) 

## Source List
#ls -R | perl ls_r_parse.pl
#s/.*\/\([A-Z].\)$/\1 \\/
#g/\.h$/d
sources+= Director.cpp \
Logo.cpp \
Action.cpp \
Jump.cpp \
Box.cpp \
Command.cpp \
AnimCursor.cpp \
Cursor.cpp \
KeyDispatcher.cpp \
ColoredChar.cpp \
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
Node.cpp \
NodeManager.cpp \
Printer.cpp \
Scene.cpp \
VisibleObject.cpp \
AnimSprite.cpp \
Animation.cpp \
CallFunc.cpp \
DiaBox.cpp \
MoveBy.cpp \
MoveTo.cpp \
Repeat.cpp \
Scheduler.cpp \
Sequence.cpp \
Sleep.cpp \
Sprite.cpp \
TextField.cpp \
Vanish.cpp \

win_src=$(source) MciPlayer.cpp

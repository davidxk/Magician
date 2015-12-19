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
sources+= ConsoleCoord.cpp \
Coord.cpp \
ImageLoader.cpp \
OrderedPair.cpp \
PrintJob.cpp \
Size.cpp \
Action.cpp \
Box.cpp \
Command.cpp \
Singleton.cpp \
VisibleObject.cpp \
ActionManager.cpp \
DisplayCentral.cpp \
VisibleObjManager.cpp \
MoveTo.cpp \
Sprite.cpp \
AnimSprite.cpp \
MainLoop.cpp \
Printer.cpp \
MciPlayer.cpp \
Animation.cpp \
Sequence.cpp \
Repeat.cpp \
 \

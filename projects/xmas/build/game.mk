## Const Path Variable
xmas_src=$(proj_path)/projects/xmas/source

## Implicit Variable
#VPATH+=$(xmas_src) $(makeproj_path)
VPATH+=$(xmas_src) 
CXXFLAGS+=-I $(xmas_src) -I $(proj_path)/source

## Source List
src_list_1=HelloWorld.cpp\
	   CoverScene.cpp\
	   BackScene.cpp \
	   LetterScene.cpp \

sources+=$(src_list_1)

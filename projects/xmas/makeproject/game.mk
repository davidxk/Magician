## Const Path Variable
xmas_src=$(proj_path)/projects/xmas/source

## Implicit Variable
#VPATH+=$(xmas_src) $(makeproj_path)
VPATH+=$(xmas_src) 
CXXFLAGS+=-I $(xmas_src)	# End 

## Source List
src_list_1=HelloWorld.cpp\
	   CoverScene.cpp\
	   BackScene.cpp \

sources+=$(src_list_1)

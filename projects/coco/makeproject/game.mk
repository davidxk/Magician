## Const Path Variable
coco_src=$(proj_path)/projects/coco/source

## Implicit Variable
#VPATH+=$(coco_src) $(makeproj_path)
VPATH+=$(coco_src) 
CXXFLAGS+=-I $(coco_src) -I $(proj_path)/source

## Source List
src_list_1=HelloWorld.cpp\
		   Coco.cpp \

sources+=$(src_list_1)

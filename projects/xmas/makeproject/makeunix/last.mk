## Implicit Variable
CXX=g++
CXXFLAGS+=-std=c++11 
TARFLAGS+=-std=c++11 -lncurses

# Platform Specific
tmp_2:=$(subst MciPlayer.cpp,,$(sources))
tmp_3:=$(subst Logo.cpp,,$(tmp_2))
tmp_4:=$(subst Magician.h,,$(tmp_3))
sources:=$(tmp_4)

## .o & .d List
objects=$(subst .cpp,.o,$(sources))
mkfiles=$(subst .cpp,.d,$(sources))

## Target
$(exec): $(objects)
	$(CXX) $(objects) -o $(exec) $(TARFLAGS) 

## Includes
include ../makefile.include 

##Clean
.PHONY: clean
clean: 
	rm -f $(objects) $(mkfiles) $(exec) *.d.*

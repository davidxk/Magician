## Implicit Variable
CXX=g++
CXXFLAGS+=-std=c++11 -Wall -Wno-sign-compare -Wno-delete-non-virtual-dtor -g3
TARFLAGS+=-std=c++11 -lncurses -g3

# Platform Specific
tmp_2:=$(subst MciPlayer.cpp,,$(sources))
sources:=$(tmp_2) UnixPrinter.cpp

## .o & .d List
objects=$(subst .cpp,.o,$(sources))
mkfiles=$(subst .cpp,.d,$(sources))

## Target
$(exec): $(objects)
	$(CXX) $(objects) -o $(exec) $(TARFLAGS) 

## Includes
include makefile.include 
include $(sources:.cpp=.d)	# include the dot d files

##Clean
.PHONY: clean
clean: 
	rm -f $(objects) $(mkfiles) $(exec) *.d.*

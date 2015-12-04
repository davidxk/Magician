## Implicit Variable
CXX=g++
#CXXFLAGS+=-Wall -Wno-sign-compare -g -std=c++11 
CXXFLAGS+=-m32 -std=c++11 -I"C:\Program Files\Dev-Cpp\MinGW64\include" -I"C:\Program Files\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include" -I"C:\Program Files\Dev-Cpp\MinGW64\lib\gcc\x86_64-w64-mingw32\4.8.1\include" -I"C:\Program Files\Dev-Cpp\MinGW64\lib\gcc\x86_64-w64-mingw32\4.8.1\include\c++" -L"C:\Program Files\Dev-Cpp\MinGW64\lib32" -L"C:\Program Files\Dev-Cpp\MinGW64\x86_64-w64-mingw32\lib32" -static-libgcc -m32 -g3

## .o & .d List
objects=$(subst .cpp,.o,$(sources))
mkfiles=$(subst .cpp,.d,$(sources))

## Target
$(exec): $(objects)
	$(CXX) $(CXXFLAGS) -o $(exec) $(objects)

## Includes
include makefile.include 
#include $(sources:.cpp=.d)	# include the dot d files

##Clean
.PHONY: clean
clean: 
	rm -f $(objects) $(mkfiles) $(exec) *.d.*

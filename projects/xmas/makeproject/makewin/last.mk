## Implicit Variable
CXX=g++
CXXFLAGS+=-m32 -std=c++11 -I"C:\Program Files\Dev-Cpp\MinGW64\include" -I"C:\Program Files\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include" -I"C:\Program Files\Dev-Cpp\MinGW64\lib\gcc\x86_64-w64-mingw32\4.8.1\include" -I"C:\Program Files\Dev-Cpp\MinGW64\lib\gcc\x86_64-w64-mingw32\4.8.1\include\c++" -L"C:\Program Files\Dev-Cpp\MinGW64\lib32" -L"C:\Program Files\Dev-Cpp\MinGW64\x86_64-w64-mingw32\lib32" -static-libgcc -lwinmm -m32 #-g3 


## .o & .d List
objects=$(subst .cpp,.o,$(sources))
mkfiles=$(subst .cpp,.d,$(sources))

## Target
$(exec): $(objects)
	$(CXX) $(objects) -o $(exec) $(CXXFLAGS) 

## Includes
include ../makefile.include 

##Clean
.PHONY: clean
clean: 
	rm -f $(objects) $(mkfiles) $(exec) *.d.*

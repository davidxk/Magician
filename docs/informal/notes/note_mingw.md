##Mingw: Unix on Windows
To configure mingw on Windows is no easy task. The one you download from the official site does not work very well. The best configuration strategy, I find, is:
* Use msys from mingw official site
* Use MinGW64 from Bloodshed Dev C++ 5.6.3
* Copy all of Git directory content to MinGW64
* configure CXXFLAGS the way Dev C++ does

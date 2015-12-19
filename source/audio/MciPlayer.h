#ifndef _MCI_PLAYER_H_
#define _MCI_PLAYER_H_

#include <windows.h>
#include <digitalv.h> 
#include <mmsystem.h>  
#include <iostream>
using namespace std;
#pragma comment(lib , "winmm.lib") 

//description of the class here
class MciPlayer
{
public:
	void start(const string& fileName);
	void go(const string& fileName);
	void open(const string& fileName);
	void play();
	void close();
	void pause();
	void resume();
	void stop();
	DWORD miliLength;
private:
	MCIDEVICEID device;
	void sendGenCommand(int nCommand, DWORD_PTR param1=0, DWORD_PTR parma2=0);
	WCHAR* str2wchar(const string& str);
};
#endif

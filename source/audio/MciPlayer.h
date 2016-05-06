#ifndef _MCI_PLAYER_H_
#define _MCI_PLAYER_H_

#include <windows.h>
#include <digitalv.h> 
#include <mmsystem.h>  
#include <iostream>
using namespace std;

//A simple audio player supported only on Windows
class MciPlayer
{
public:
	void playInSeperateThread(const string& fileName);
	void play(const string& fileName);

private:
	void open(const string& fileName);
	void startPlay();
	void close();
	void pause();
	void resume();
	void stop();
	DWORD miliLength;

	MCIDEVICEID device;
	void sendGenCommand(int nCommand, DWORD_PTR param1=0, DWORD_PTR parma2=0);
	WCHAR* str2wchar(const string& str);
};
#endif

#include "audio/MciPlayer.h"
#include <digitalv.h> 
#include <mmsystem.h>  
#include <iostream>
using namespace std;
#pragma comment(lib , "winmm.lib") 

static MCIERROR s_mciError;

void MciPlayer::open(const string& fileName)
{
	if( fileName.empty() ) return;

	WCHAR* fileNameWideChar = str2wchar( fileName );
	MCI_OPEN_PARMS mciOpen = { 0 };
	mciOpen.lpstrElementName = fileNameWideChar;
	s_mciError = mciSendCommand(0, MCI_OPEN,
			MCI_OPEN_ELEMENT, (DWORD_PTR)&mciOpen);

	if( s_mciError ) cout<<"Error: BGM load fail!\n";

    //MCIDEVICEID _dev;
	device = mciOpen.wDeviceID;
	delete[] fileNameWideChar;
}

void MciPlayer::Play()
{
    MCI_PLAY_PARMS mciPlay = { 0 };
	s_mciError = mciSendCommand(device, MCI_PLAY,
			MCI_DGV_PLAY_REPEAT, (DWORD_PTR)&mciPlay);
	if( s_mciError ) cout<<"Error: BGM play fail!\n";
}

void MciPlayer::Close()
{
	Stop();
    if( device ) sendGenCommand(MCI_CLOSE);

    device = 0;
}

void MciPlayer::Pause()
{
    sendGenCommand(MCI_PAUSE);
}

void MciPlayer::Resume()
{
	sendGenCommand(MCI_RESUME);
}

void MciPlayer::Stop()
{
    sendGenCommand(MCI_STOP);
}

void MciPlayer::Rewind()
{
    if ( !device ) return;
    mciSendCommand(device, MCI_SEEK, MCI_SEEK_TO_START, 0);

    MCI_PLAY_PARMS mciPlay = { 0 };
    mciPlay.dwCallback = (DWORD_PTR)wnd;
    mciSendCommand(device, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&mciPlay);
}




void MciPlayer::sendGenCommand(int nCommand, DWORD_PTR param1, DWORD_PTR parma2)
{
    if ( !device ) return;
    mciSendCommand(device, nCommand, param1, parma2);
}

WCHAR* MultiByteToWideChar::str2wchar(const string& str)
{
	int nLen = str.size();
	const char* ss = str.c_str();
	WCHAR* strWideChar = new WCHAR[nLen + 1];

	MultiByteToWideChar(CP_ACP, 0, ss, nLen+1, strWideChar, nLen+1);
	return strWideChar;
}

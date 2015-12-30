#include "audio/MciPlayer.h"
#include <mmsystem.h>  
#include <thread>
#include "basic/MagicianMacros.h"

static MCIERROR s_mciError;

void MciPlayer::start(const string& fileName)
{
	std::thread bgm( &MciPlayer::go, this, fileName );
	bgm.detach();
}

void MciPlayer::go(const string& fileName)
{
	open(fileName);
	play();
}

void MciPlayer::open(const string& fileName)
{
	if( fileName.empty() ) return;

	string fullPath = magician::RES_PATH;
	fullPath += fileName;
	//WCHAR* fileNameWideChar = str2wchar( fullPath );

	MCI_OPEN_PARMS mciOpen = { 0 };
	mciOpen.lpstrElementName = fullPath.c_str();
	s_mciError = mciSendCommand(0, MCI_OPEN,
			MCI_OPEN_ELEMENT, (DWORD_PTR)&mciOpen);

	if( s_mciError ) 
	{
		cout<<"Error: BGM load fail!\n";
		char buf[200];
		mciGetErrorString(s_mciError, buf, sizeof(buf));
		cout<<buf<<endl;
	}

	device = mciOpen.wDeviceID;
	//delete[] fileNameWideChar;

	MCI_STATUS_PARMS mciStatus;
    mciStatus.dwItem = MCI_STATUS_LENGTH;
	mciSendCommand(device, MCI_STATUS, MCI_STATUS_ITEM, (DWORD_PTR)&mciStatus);
    miliLength = mciStatus.dwReturn; 
}

void MciPlayer::play()
{
    MCI_PLAY_PARMS mciPlay = { 0 };
	s_mciError = mciSendCommand(device, MCI_PLAY,
			MCI_DGV_PLAY_REPEAT, (DWORD_PTR)&mciPlay);

	if( s_mciError ) 
	{
		cout<<"Error: BGM play fail!\n";
		char buf[200];
		mciGetErrorString(s_mciError, buf, sizeof(buf));
		cout<<buf<<endl;
	}
}

void MciPlayer::close()
{
	stop();
    if( device ) sendGenCommand(MCI_CLOSE);

    device = 0;
}

void MciPlayer::pause()
{
    sendGenCommand(MCI_PAUSE);
}

void MciPlayer::resume()
{
	sendGenCommand(MCI_RESUME);
}

void MciPlayer::stop()
{
    sendGenCommand(MCI_STOP);
}





void MciPlayer::sendGenCommand(int nCommand, DWORD_PTR param1, DWORD_PTR parma2)
{
    if ( !device ) return;
    mciSendCommand(device, nCommand, param1, parma2);
}

WCHAR* MciPlayer::str2wchar(const string& str)
{
	int nLen = str.size();
	const char* ss = str.c_str();
	WCHAR* strWideChar = new WCHAR[nLen + 1];

	MultiByteToWideChar(CP_ACP, 0, ss, nLen+1, strWideChar, nLen+1);
	return strWideChar;
}

#ifndef _LOGO_H_
#define _LOGO_H_

//include here

//description of the class here
class Logo
{
public:
	Logo();
private:
	void initAnim();
	void scheduleTransition();
	int getTotalTime();

	//constant time
	const int DURE_WAVE = 400;
	const int N_WAVE = 3;
	const int DURE_JUMP = 500;
	const int PAUSE_TIME = 2000;
};
#endif

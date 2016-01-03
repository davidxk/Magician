#ifndef _LOGO_H_
#define _LOGO_H_

#include "Magician.h"

//description of the class here
class Logo
{
public:
	Logo();
private:
	void initHat();
	void initAnim();
	void logoFlyIn();
	void scheduleTransition();
	int getAnimTime();
	int getTotalTime();

	AnimSprite* rabbit;

	//constant time
	const int HAT_PAUSE = 1500;
	const int DURE_WAVE = 400;
	const int N_WAVE = 3;
	const int DURE_JUMP = 500;
	const int PAUSE_TIME = 1000;
	const int DURE_MOVEL = 1000;
	const int DURE_FLYIN = 2000;
	const int SHOW_TIME = 2000;
};
#endif

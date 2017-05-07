#ifndef _LOGO_H_
#define _LOGO_H_

#include "Magician.h"

// This is the Logo Scene that comes with *Magician*
class Logo: public SequentialScene
{
public:
	virtual void initScene();
	virtual void changeScene();
private:
	void initHat();
	void initAnim();
	void logoFlyIn();
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

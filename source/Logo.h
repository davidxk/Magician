#ifndef _LOGO_H_
#define _LOGO_H_



//description of the class here
class Logo
{
public:
	Logo();
private:
	void initAnim();
	void scheduleTransition();
	void setEnd();
	int getTotalTime();
	bool isEnd;

	//constant time
	const int DURE_WAVE = 400;
	const int N_WAVE = 3;
	const int DURE_JUMP = 500;
};
#endif

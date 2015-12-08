#include "audio/AudioTest.h"

#include <cassert>
#include "audio/MciPlayer.h"


void AudioTest::run()
{
	MciPlayer mp;
	mp.open("bgm/humours_of_glendart.mp3");
	mp.play();
}

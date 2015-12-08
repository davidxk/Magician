#include "audio/AudioTest.h"

#include <cassert>
#include <thread>
#include "audio/MciPlayer.h"


void AudioTest::run()
{
	std::thread bgm( &AudioTest::go, this );
	bgm.join();
}

void AudioTest::go()
{
	MciPlayer mp;
	mp.open("bgm/humours_of_glendart.mp3");
	mp.play();
	std::this_thread::sleep_for (std::chrono::milliseconds( 2*mp.miliLength ));
}

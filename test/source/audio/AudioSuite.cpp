#include "audio/AudioSuite.h"
#include "audio/AudioTest.h"

AudioSuite::AudioSuite()
{
	addTestCase( new AudioTest );
}

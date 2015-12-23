#include "Logo.h"

Logo::Logo()
{
	const int DURE_WAVE = 400;
	const int N_WAVE = 3;
	const int DURE_JUMP = 500;
	AnimSprite* wand = AnimSprite::create("logo/wand_batch_1.txt");
	wand->setCenterPos( Coord(6, 39) );
	Animation* wave = Animation::create( wand, DURE_WAVE);
	Repeat* repe = Repeat::create( wave, N_WAVE );
	Vanish* vani = Vanish::create( wand );
	Sequence* repeVani = Sequence::create( repe, vani );
	wand->runAction(repeVani);

	AnimSprite* rabbit = AnimSprite::create("logo/rabbit_batch.txt");
	rabbit->setCenterPos( Coord(11, 39) );
	Action* wait = Sleep::create( rabbit, DURE_WAVE * N_WAVE );
	Animation* jump = Animation::create( rabbit, DURE_JUMP );
	Sequence* waitJump = Sequence::create( wait, jump );
	rabbit->runAction( waitJump );

	vManager->addObject( rabbit );
	vManager->addObject( wand );

	//schedule set end = true at the endding time point of this scene
	//while( !end ) this_thread::sleep_for( chrono::milliseconds(50) );
}

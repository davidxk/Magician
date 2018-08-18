#include "Director.h"
#include "Logo.h"

//Audio
#ifdef WIN
#include "audio/MciPlayer.h"
#endif
//Basics
#include "basic/MagicianMacros.h"
#include "basic/Random.h"
//Sprites
#include "visible/AnimSprite.h"
#include "visible/DiaBox.h"
#include "visible/Geometry.h"
#include "visible/ImageLoader.h"
#include "visible/Sprite.h"
#include "visible/TextField.h"
//Actions
#include "action/Animation.h"
#include "action/Jump.h"
#include "action/MoveTo.h"
#include "action/MoveBy.h"
#include "action/Repeat.h"
#include "action/Sequence.h"
#include "action/Sleep.h"
#include "action/Vanish.h"
//UIs
#include "control/AnimCursor.h"
#include "control/Cursor.h"
#include "display/Scene.h"
#include "display/SequentialScene.h"

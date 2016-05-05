{
//The sprite is initialized in vManager's objList directly
Sprite* sp = Sprite::create("Earth.txt"); 
sp->setPosition(Coord(12, 4));
//sp->setVisibility(false);
//The action is initialized in aManager's actionList directly
//The CmdList is created by the action's constructor
Action* act = MoveTo::create(sp, 10, Coord(14, 6), true);

}

the other thread 
TimeManagement::mainLoop -n:

update()
sleep(SOMETIME);

update():
//Action Manager updates the attribute in objList in VisibleObjManger
aManager->update();
DisplayCentral->setThisFrame( vManager->getFrame() );
DisplayCentral->paint( DisplayCentral->getDiff() );


aManager::update():
for(const auto& it: actionList)
{
	it.cmdQueue.head().apply(it.host);
	it.cmdQueue.pop();
	if(it.cmdQueue.empty())
		actionList.remove(it);
}

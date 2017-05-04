#include "display/NodeManagerTest.h"
#include <cassert>
#include <regex>
#include "basic/ColoredChar.h"
#include "visible/Sprite.h"

void NodeManagerTest::run()
{
	testGetEmptyFrame();
	testPaintNode();
	testGetFrame();
	testZOrder();
}

void NodeManagerTest::testGetEmptyFrame()
{
	TestableNodeManager nmgr;
	Image frame = nmgr.getEmptyFrame();
	nmgr.verify( frame );
	const regex patBlank("^ *$");
	for(const auto& line: frame)
	{
		string strline = ImageUtil::ImageLine2str( line );
		assert( regex_match( strline.begin(), strline.end(), patBlank ) );
	}
}

void NodeManagerTest::testPaintNode()
{
	TestableNodeManager nmgr;
	Sprite* sp = Sprite::create("graph/moon.txt");
	sp->setPos( Coord::CoordXY(2, 1) );
	nmgr.getRoot()->addChild( sp );

	Image frame_A = nmgr.getEmptyFrame();
	nmgr.paintNode( sp, frame_A );
	const regex patLine1("^  1234 *$");
	const regex patLine2("^  4321 *$");
	string strline1 = ImageUtil::ImageLine2str( frame_A[1] );
	string strline2 = ImageUtil::ImageLine2str( frame_A[2] );
	assert( regex_match( strline1.begin(), strline1.end(), patLine1 ) );
	assert( regex_match( strline2.begin(), strline2.end(), patLine2 ) );

	Image frame_B = nmgr.getEmptyFrame();
	sp->setIsVisible( false );
	nmgr.paintNode( sp, frame_B );
	const regex patBlank("^ *$");
	for(const auto& line: frame_B)
	{
		string strline = ImageUtil::ImageLine2str( line );
		assert( regex_match( strline.begin(), strline.end(), patBlank ) );
	}
}

void NodeManagerTest::testGetFrame()
{
	TestableNodeManager nmgr;

	Sprite* box = Sprite::create("graph/box.txt");
	Sprite* label_1 = Sprite::create("graph/label_1.txt");
	Sprite* label_2 = Sprite::create("graph/label_2.txt");
	Sprite* label_3 = Sprite::create("graph/label_3.txt");
	label_1->setPos( Coord::CoordXY(1, 1) );
	label_2->setPos( Coord::CoordXY(1, 2) );
	label_3->setPos( Coord::CoordXY(1, 3) );
	box->addChild( label_1 );
	box->addChild( label_2 );
	box->addChild( label_3 );
	nmgr.getRoot()->addChild( box );

	Image frame = nmgr.getFrame( box );
	const regex patLine1("^\\|Nancy  *\\| *$");
	const regex patLine2("^\\|Julie  *\\| *$");
	const regex patLine3("^\\|Amanda *\\| *$");
	string strline1 = ImageUtil::ImageLine2str( frame[1] );
	string strline2 = ImageUtil::ImageLine2str( frame[2] );
	string strline3 = ImageUtil::ImageLine2str( frame[3] );
	assert( regex_match( strline1.begin(), strline1.end(), patLine1 ) );
	assert( regex_match( strline2.begin(), strline2.end(), patLine2 ) );
	assert( regex_match( strline3.begin(), strline3.end(), patLine3 ) );
}

void NodeManagerTest::testZOrder()
{
	TestableNodeManager nmgr;

	Sprite* box = Sprite::create("graph/box.txt");
	Sprite* label_1 = Sprite::create("graph/label_1.txt");
	Sprite* label_2 = Sprite::create("graph/label_2.txt");
	Sprite* label_3 = Sprite::create("graph/label_3.txt");
	label_1->setPos( Coord::CoordXY(2, 1) );
	label_2->setPos( Coord::CoordXY(1, 1) );
	label_3->setPos( Coord::CoordXY(4, 2) );
	label_1->setZOrder( 2 );
	label_2->setZOrder( 1 );
	box->addChild( label_1 );
	box->addChild( label_2 );
	box->addChild( label_3 );
	nmgr.getRoot()->addChild( box );

	Image frame = nmgr.getFrame( box );
	const regex patLine1("^\\|JNancy  *\\| *$");
	const regex patLine2("^\\|  MAmanda *$");
	string strline1 = ImageUtil::ImageLine2str( frame[1] );
	string strline2 = ImageUtil::ImageLine2str( frame[2] );
	assert( regex_match( strline1.begin(), strline1.end(), patLine1 ) );
	assert( regex_match( strline2.begin(), strline2.end(), patLine2 ) );
}

## Const Path Variable
test_src_path=$(proj_path)/test/source
test_basic_path=$(addsuffix /basic,$(test_src_path))
test_action_path=$(addsuffix /action,$(test_src_path))
test_display_path=$(addsuffix /display,$(test_src_path))
test_visible_path=$(addsuffix /visible,$(test_src_path))

## Implicit Variable
VPATH+=$(test_src_path) $(test_basic_path) $(test_action_path) \
       $(test_display_path) $(test_visible_path) 
CXXFLAGS+=-I $(test_src_path) -I $(proj_path)/source

test_suites=BasicSuite.cpp \
			ActionSuite.cpp \
			DisplaySuite.cpp \
			VisibleSuite.cpp \

test_base=TestCase.cpp \
		  TestSuite.cpp \
		  TestRoot.cpp

test_cases=ColoredCharTest.cpp \
		   ConsoleCoordTest.cpp \
		   CoordTest.cpp \
		   OrderedPairTest.cpp \
		   RandomTest.cpp \
		   SizeTest.cpp \
		   TimeServiceTest.cpp \
		   DisplayCentralTest.cpp \
		   NodeManagerTest.cpp \
		   NodeTest.cpp \
		   VisibleObjectTest.cpp \
		   AnimSpriteTest.cpp \
		   BoxTest.cpp \
		   DiaBoxTest.cpp \
		   ImageLoaderTest.cpp \
		   SpriteTest.cpp \
		   TextFieldTest.cpp \
		   ActionTest.cpp \
		   ActionManagerTest.cpp \
		   AgainTest.cpp \
		   CallFuncTest.cpp \
		   SequenceTest.cpp \
		   VanishTest.cpp \
		   WaitTest.cpp

sources:=$(test_base) $(test_suites) $(test_cases)

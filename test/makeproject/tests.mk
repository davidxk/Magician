## Const Path Variable
test_src_path=$(proj_path)/test/source
test_basic_path=$(addsuffix /basic,$(test_src_path))
test_base_path=$(addsuffix /base,$(test_src_path))
test_display_path=$(addsuffix /display,$(test_src_path))
test_user_path=$(addsuffix /user,$(test_src_path))

## Implicit Variable
VPATH+=$(test_src_path) $(test_basic_path) $(test_base_path) \
       $(test_display_path) $(test_user_path) 
CXXFLAGS+=-I $(test_src_path)

## Source List
tmp_2:=$(subst MciPlayer.cpp,,$(sources))
tmp_3:=$(subst Logo.cpp,,$(tmp_2))
tmp_4:=$(subst Magician.h,,$(tmp_3))
sources:=$(tmp_4)

test_suites=BasicSuite.cpp \
	    BaseSuite.cpp \
	    DisplaySuite.cpp \
	    UserSuite.cpp \

test_base=TestCase.cpp \
	  TestSuite.cpp \
	  TestRoot.cpp
test_cases=BasicTest.cpp \
	   BaseTest.cpp \
	   DisplayTest.cpp \
	   UserTest.cpp \
	   ActionTest.cpp \
	   BoxTest.cpp \

sources+=$(test_base) $(test_suites) $(test_cases)

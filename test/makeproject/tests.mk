## Const Path Variable
test_src_path=$(proj_path)/test/source
test_basic_path=$(addsuffix /basic,$(test_src_path))
test_comm_path=$(addsuffix /comm,$(test_src_path))
test_data_path=$(addsuffix /data,$(test_src_path))
test_ai_path=$(addsuffix /ai,$(test_src_path))

## Implicit Variable
VPATH+=$(test_src_path) $(test_basic_path) $(test_comm_path) \
       $(test_data_path) $(test_ai_path)
CXXFLAGS+=-I $(test_src_path)

## Source List
#$(subst Mailman.cpp,,$(sources))
#$(subst Controller.cpp,,$(sources))

test_suites=BasicSuite.cpp \

test_base=TestCase.cpp \
	  TestSuite.cpp \
	  TestRoot.cpp
test_cases=BasicTest.cpp \

sources+=$(test_base) $(test_suites) $(test_cases)

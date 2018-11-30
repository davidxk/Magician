# Provide project path
proj_path=..

# Set main and executable
name=magician

# Set compile options
CXX=g++
CXXFLAGS+=-Wall -std=c++11

## ------------------~~ Dividing Line ~~--------------------

# Include project source
include source.mk
# List of obj Filese
VPATH+=$(OBJECT_DIR)
objects=$(subst .cpp,.o,$(sources))
objects+= UnixPrinter.o
dir_obj=$(addprefix $(OBJECT_DIR)/,$(objects))
PICs=$(subst .cpp,.PIC,$(sources))
PICs+= UnixPrinter.PIC
dir_PIC=$(addprefix $(OBJECT_DIR)/,$(PICs))

# Target Directories
this_path=..
TARGET_DIR=$(this_path)
OBJECT_DIR=$(this_path)/build/.obj
DEPEND_DIR=$(this_path)/build/.d

# Recipe
static=lib$(name).a
PLATFORM=$(shell uname)
ifeq ($(PLATFORM), Darwin)
	DLFLAG=-dynamiclib -undefined dynamic_lookup
	dynamic=lib$(name).dylib
else
	DLFLAG=-shared
	dynamic=lib$(name).so
endif

$(dynamic): $(PICs)
	$(CXX) $(DLFLAG) -o $(TARGET_DIR)/$(dynamic) $(dir_PIC)
	mkdir -p ~/lib
	cp $(TARGET_DIR)/$(dynamic) ~/lib/

$(static): $(objects)
	ar cr $(TARGET_DIR)/$(static) $(dir_obj)


# Includes
$(shell mkdir -p $(DEPEND_DIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPEND_DIR)/$*.Td

COMPILE.cc = $(CXX) $(DEPFLAGS) $(CXXFLAGS) -c
POSTCOMPILE = mv -f $(DEPEND_DIR)/$*.Td $(DEPEND_DIR)/$*.d
OUTPUT_OPTION = -o $(OBJECT_DIR)/$@
%.o : %.cpp
%.o : %.cpp $(DEPEND_DIR)/%.d
	@if ! [ -d $(OBJECT_DIR) ]; then mkdir $(OBJECT_DIR); fi
	$(COMPILE.cc) $(OUTPUT_OPTION) $<
	@$(POSTCOMPILE)

%.PIC : %.cpp
%.PIC : %.cpp $(DEPEND_DIR)/%.d
	@if ! [ -d $(OBJECT_DIR) ]; then mkdir $(OBJECT_DIR); fi
	$(COMPILE.cc) -fPIC $(OUTPUT_OPTION) $<
	@$(POSTCOMPILE)

$(DEPEND_DIR)/%.d: ;
.PRECIOUS: $(DEPEND_DIR)/%.d

-include $(patsubst %,$(DEPEND_DIR)/%.d,$(basename $(sources)))


# Clean
.PHONY: clean
clean: 
	rm -r -f $(OBJECT_DIR)
	rm -r -f $(DEPEND_DIR)
	rm -f $(TARGET_DIR)/$(target)

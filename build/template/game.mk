# List of subsystems
subsystem=

# List of Source files
sources+=

# ------------------~~ Dividing Line ~~--------------------
src_path=$(proj_path)/source
sub_path=$(addprefix $(proj_src)/, $(subsystem))
proj_src=../source

# Implicit Variable
VPATH+=$(src_path) $(proj_src)
CXXFLAGS+=-I $(src_path) -I $(proj_src)

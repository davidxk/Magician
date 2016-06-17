## Provide project path
proj_path=$(shell pwd)/../../../..
makeproj_path=$(proj_path)/makeproject
include $(makeproj_path)/source.mk
include ../game.mk

## Add main Entrance
main=main.cpp 
sources+=$(main)
exec=game

include last.mk

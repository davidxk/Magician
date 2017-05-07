#!/bin/bash

# Usage: tools/new_game.sh proj_name

if [[ ! -f .gitignore ]]; then
	echo "Error: Please invoke this script from Magician root directory"
	exit
fi

game_name=$1
proj_path=$(pwd)

mkdir projects/$game_name
cd projects/$game_name
game_path=$(pwd)
mkdir build docs resources "source"

cd $proj_path
temp_path=build/template
cp $temp_path/root_makefile.mk $game_path/makefile
cp $temp_path/build_makefile.mk $game_path/build/makefile
cp $temp_path/game.mk $game_path/build/game.mk
cp $temp_path/main.cpp "$game_path/source/main.cpp"
cp -r $temp_path/logo $game_path/resources/

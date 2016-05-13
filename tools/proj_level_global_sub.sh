#!/bin/bash

# ./global_substitution.sh patter string [directory]
pattern=$1
string=$2
directory=$3

if [[ -n $directory ]]; then cd $directory; fi
source=$(ls)

function substitute_on_file()
{
	pattern=$1
	string=$2
	file=$3
	if [[ -n $(grep $pattern $file) ]]; then
		backup=$file.bak
		mv $file $backup
		sed s@$pattern@$string@g $backup > $file
	fi
}

for each in $source; do
	if [[ $each == *.cpp ]] || [[ $each == *.h ]]; then
		substitute_on_file $pattern $string $each
	fi
	if [[ -d $each ]]; then
		cd $each

		files=$(ls | grep "h\|cpp")
		for file in $files; do
			substitute_on_file $pattern $string $file
		done

		cd ..
	fi
done

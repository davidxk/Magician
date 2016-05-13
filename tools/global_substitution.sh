#!/bin/bash

# ./global_substitution.sh patter string [directory]
pattern=$1
string=$2
directory=$3

if [[ -n $directory ]]; then cd $directory; fi
#echo $(pwd)

source=$(ls | grep "h\|cpp")

for each in $source; do
	if [[ -n $(grep $pattern $each) ]]; then
		backup=$each.bak
		mv $each $backup;
		sed s@$pattern@$string@g $backup > $each;
	fi
done

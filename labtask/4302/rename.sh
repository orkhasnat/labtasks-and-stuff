#!/usr/bin/bash
echo "Enter the lab number (ie 1,2...)"
read lab
cp $lab/*.cpp submission

cd submission
task=1
for file in *.cpp; do
	mv $file 113_task"$task".cpp
	let "task++"
done

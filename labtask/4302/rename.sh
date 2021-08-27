#!/usr/bin/bash
echo "Please call this script from parent dir. Otherwise it would delete everything!!"
echo "Enter the lab number (ie 1,2...)"
read lab
cp $lab/*.cpp submission

cd submission
task=1
for file in *.cpp; do
	mv $file 113_task"$task".cpp
	let "task++"
done

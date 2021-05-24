#!/usr/bin/bash
echo "Enter the lab number (ie 1,2...)"
read lab
cp $lab/*.cpp submission

cd submission
task=1
for file in *.cpp; do
	mv $file 190041113_T"$task"_L"$lab"_1A.cpp
	let "task++"
done

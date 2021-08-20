#!/usr/bin/bash
echo "Please call this script from the parent folder or it will be disastarous!!"
echo "Enter the lab number (ie 1,2...)"
read lab
cp $lab/*.cpp submission

cd submission
task=1
for file in *.cpp; do
	mv $file 190041113_T"$task"_L"$lab"_1A.cpp
	let "task++"
done

#!/usr/bin/bash
echo "Files to be removed"
# why use fd ?? why not. Honestly got tired of 'find' .
for file in $(fd -Ig "*.class") #$(find . -name "*.class")
do
    echo $file
done
for file in $(fd -Ig "*.exe") #$(find . -name "*.exe")
do
    echo $file
done
for file in $(fd -t x -E "*.sh")
do
    echo $file
done
echo "Type y to delete"
read  yes

if [[ $yes == "y" || $yes == "yes" || $yes == "Y" ]]
then 
    #find . -name "*.class" -delete
    fd -Ig "*.class" -x rm {}
    fd -Ig "*.exe" -x rm {}
    fd -t x -E "*.sh" -x rm {}
    echo "Garbage removed."   
else 
    echo "Aborted."
fi

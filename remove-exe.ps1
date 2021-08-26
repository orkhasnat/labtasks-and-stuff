# get-childitem or ls works as ls (duh!)
# -recurse means recursive gets all the subfolders
# -include works like -name 
# foreach works like the python forloop
# $_ kinda means like indivial things that have been piped (not clear myself honestly)
# the .fullname is property thet kind of means the path of that item
# were saying item because its obviously get-childitem
# -whatif helps to see what can happen if i run this command 
# useful for double checking what im deleteing
# why not use write-host but read-host ? because read-host waits for an input
# thus it lets us see the console and after giving any input it exits 
#
$yes = "y"
get-childitem .\ -include "*.exe" -recurse 
$a = read-host -prompt "press y to delete "
if ($a -eq $yes){
	get-childitem .\ -include "*.exe" -recurse | foreach($_) {remove-item $_.fullname }
	read-host "successfully deleted!"
}
else {
read-host "not deleted :( "
}

#
# for using bash typeout--------
# find "path" -type f -name *.exe -delete
# path is obv the path the files i want to delete
# -type f means files not directory
#
# f*****g thing isnt an executable 
# have to run this shit in powershell
#bash is superior no doubt

# prototype in bash
# #! /bin/bash
# find /mnt/c/Users/orkha/Desktop/VScode -type f -name "*.exe"
# read -p "Press y to delete    " var
# if [ "$var" == "y" ]
# then
# find /mnt/c/Users/orkha/Desktop/VScode -type f -name "*.exe" -delete
# echo "successfuly deleted!"
# else
# echo "not deleted :( "
# fi

 

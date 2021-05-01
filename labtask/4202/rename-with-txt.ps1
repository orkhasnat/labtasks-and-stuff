#Script for creating the txt files from cpp files for submitting to lab cse 4202 
#
$yes ="y"
write-host "Do you want to delete the cpp-files-for-submission folder's cntents ?"
write-host "The following might happen"
remove-item -Path C:\Users\orkha\Desktop\VScode\root\labtask\4202\cpp-files-for-submission\*.cpp.txt -whatif
$del= read-host -prompt "press y to delete the cpp-files-for-submission folder's cntents"
if($del -eq $yes){
    remove-item -Path C:\Users\orkha\Desktop\VScode\root\labtask\4202\cpp-files-for-submission\*.cpp.txt
    write-host "successfully deleted" 
}

$dirname= read-host -prompt "Please give the directory name"

get-childitem C:\Users\orkha\Desktop\VScode\root\labtask\4202\$dirname -include "*.cpp" -recurse | foreach($_){rename-item -Path "$_" -NewName "$_.txt" -whatif }
write-host "Do you agree to such actions?"
$a=read-host -prompt "press y to act"
if ($a -eq $yes){
    copy-item -Path C:\Users\orkha\Desktop\VScode\root\labtask\4202\$dirname\*.cpp -destination C:\Users\orkha\Desktop\VScode\root\labtask\4202\cpp-files-for-submission
    get-childitem C:\Users\orkha\Desktop\VScode\root\labtask\4202\cpp-files-for-submission -include "*.cpp" -recurse | foreach($_){rename-item -Path "$_" -NewName "$_.txt"  }
    read-host "Successfull"
}
else{
    read-host "Not Successfull :("
}
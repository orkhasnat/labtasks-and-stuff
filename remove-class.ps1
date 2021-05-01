$yes = "y"
get-childitem C:\Users\orkha\Desktop\VScode\root\Java -include "*.class" -recurse 
$a = read-host -prompt "press y to delete "
if ($a -eq $yes){
	get-childitem C:\Users\orkha\Desktop\VScode\root\Java -include "*.class" -recurse | foreach($_) {remove-item $_.fullname }
	read-host "successfully deleted!"
}
else {
read-host "not deleted :( "
}
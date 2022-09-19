org 100h
       
.DATA

;array db 1,4,9,16,25,36,49,64,81
array db 1,2,3,4,5,6,7,8,9
msg db 'Enter the number','$'

.CODE

lea dx, msg
lea si, array

mov ah, 09h
int 21h

mov ah,01h
int 21h

mov cl,al
sub cl,30h
xor ax,ax

; sum in bx       
lab:
  mov al,[si]
  mul al
  add bx, ax
  inc si
  loop lab       
 
          
ret

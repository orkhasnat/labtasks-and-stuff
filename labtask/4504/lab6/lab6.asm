result MACRO string
  mov dx, offset string
  call print
ENDM


org 0100h

.data

string db 'Hello World' , '$'
good db 0dh,0ah,'Found at position ' , '$'
bad db 0dh,0ah, 'Not Found!' , '$'

.code
main proc  
MOV AX, @DATA
MOV DS, AX
  
call search 
ret 
  
main endp

search proc
  mov ah, 1
  int 21h
  mov cl, 1
  mov di ,0
  mov si, 0
  mov dh , al
  lp:
     mov bl, string[si]
     work:
     cmp al, bl
     je exit1 
     cmp dh, bl
     je exit1
     cmp bl , '$'
     je exit2
     
     cmp al , 'a'
     jge low
     
     cmp dl, 0
     jne bye 
     jmp up
     low:
        sub al, 32
        inc dl
        jmp work
     up:
        add al, 32
        inc dl
        jmp work
     bye:
      inc si
      inc cl 
      mov dl ,0
     jmp lp
  exit2:
     result bad
     jmp done
  exit1:
     result good
     mov ah, 02h
     mov dl ,cl
     add dl, 48
     int 21h 
     jmp done
  done:     
  ret
search endp

print proc
  mov ah, 09h
  int 21h
  ret
print endp

end main
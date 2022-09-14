org 0100h

main proc
  
;display prompt

mov ah, 2
mov dl, "?"
int 21h

; input a char

MOV AH, 1
INT 21H
MOV BL, AL


; go to a new line with carriage return

mov ah, 2
mov dl, 0dh
int 21h
mov dl, 0ah
int 21h


cmp bl, "a"
jge toupper
add bl, 20h
jmp end
toupper:
    sub bl, 20h
    ;jmp ending


end:
; display character
mov dl, bl
int 21h

; return to dos
mov ah, 4ch
int 21h

main endp
end main
ret
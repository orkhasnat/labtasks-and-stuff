.org 0100h

.data

;string db 'Hello', '$'
str db 6 dup('Q')
rev db 6 dup('A') 


.code   
main proc

    call input
    call reverse
    
    call newline
    
    lea dx,rev
    call print
    
    mov ah, 4ch
    mov al, 00h
    int 21h  
main endp

print proc
    mov ah, 09h
    int 21h
    ret
print endp
           

reverse proc
    mov cx, 5
    mov di, 4 
    lea si, str
    lp2:
        
        mov bl, str[si]  
        mov rev[di], bl 
        inc si
        dec di
        loop lp2
    inc si
    mov rev[si], '$'           
    ret        
reverse endp

input proc
    mov cx, 5
    mov si, 0
    lp:
       mov ah, 01h
       int 21h
       mov str[si],al
       inc si
       loop lp 
    mov str[si], '$'
    ret        
input endp

newline proc
    mov ah, 2h
    mov dl, 0dh
    int 21h
    
    mov ah, 2h
    mov dl, 0ah
    int 21h
    ret    
newline endp

end main
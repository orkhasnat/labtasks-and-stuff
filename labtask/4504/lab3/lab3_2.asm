 org 100h
    
.code

;mov ah, 1
;int 21h 

mov cl, 0

LL: 
    mov ah,1
    int 21h
    cmp al, 0dh
    jz END
    cmp al , 'a'
    jge LL
    mov dl,al
    cmp cl, 0
    jz FIRST
    
    jmp LL


FIRST:
    mov bh,dl
    inc cl
    jmp LL
        
END:
    mov bl,dl
    ; newline
    mov dl, 0ah
    mov ah,2
    int 21h
    
    ; first uppercase
    mov dl, bh
    int 21h
    
    ;newline with carriage return
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h
    
    ; last uppercase
    mov dl, bl
    int 21h
    
    ret        
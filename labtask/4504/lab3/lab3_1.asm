org 100h

.data
    input db 'We are IUT students',0dh, 0ah '$' 
    ; 0a and 0d is for newline/ carriage return both in windows and linux 

;mov cx, 5000
;
;L1:
;    mov ah, 2
;    mov dl, '*'
;    int 21h
;    
;loop L1

.code

mov ah, 2
lea dx, input
; loads the 0th addr to dx
mov bx,dx
; to derefference an addr we can only use bx,bp,si,di

mov cl, 0

LABEL:
    cmp [bx] , '$'
    jz END 
    mov dl, [bx]
    int 21h
    inc bx
    inc cl
    ; inc increments by 1
    jmp LABEL
    
END:
    mov dl, cl
    ; xor dh,dh
    ; resets the dh register
    ; int 21h
    ret    



        
        
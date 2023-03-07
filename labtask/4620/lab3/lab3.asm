CODE SEGMENT
ASSUME CS:CODE, DS:CODE, ES:CODE, SS:CODE
ORG 1000H ; The code is placed at offset 1000h

MOV AL, 10000000B ; Mode set for Control Word to control 8255 PPI
OUT 1FH, AL ; Initiate transfer of information from Source to Destination

hex:

MOV AL, 11000000B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER

MOV AL, 11111001B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER

MOV AL, 10100100B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER

MOV AL, 10110000B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER

MOV AL, 10011001B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER

MOV AL, 10010010B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER

MOV AL, 10000010B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER

MOV AL, 11111000B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER

MOV AL, 10000000B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER

MOV AL, 10011000B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER

;A
MOV AL, 00001000B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER
              
;B
MOV AL, 00000000B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER

;C
MOV AL, 01000110B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER

;D
MOV AL, 11000000B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER

;E
MOV AL, 10000110B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER

;F
MOV AL, 10001110B ; Actual data for displaying ‘3’ provided in Accumulator
OUT 19H, AL ; Data Transfer to Output Port

CALL TIMER

JMP hex
TIMER: MOV CX, 2
TIMER2: PUSH CX
MOV CX, 0
TIMER1: NOP
NOP
NOP
NOP
LOOP TIMER1
POP CX
LOOP TIMER2
RET
      
CODE ENDS
END
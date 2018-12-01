DATA SEGMENT
  BUF DB 65,72,67,43,95,76,78,86,89,68
      DB 53,67,80,90,98,87,87,89,65,83
  CNT EQU $-BUF
  G5 DB ?
  G6 DB ?
  G7 DB ?
  G8 DB ?
  G9 DB ?
DATA ENDS

CODE SEGMENT
  ASSUME DS:DATA, CS:CODE
START: MOV AX,DATA
       MOV DS,AX
      LEA BX,BUF
      MOV CX,CNT
LP:   MOV AL,[BX]
      CMP AL,60
      JL A0
      CMP AL,70
      JL A1
      CMP AL,80
      JL A2
      CMP AL,9
      JL A3
     A4:INC G9
     JMP EXIT
     A0:INC G5
     JMP EXIT
     A1:INC G6
     JMP EXIT
     A2:INC G7
     JMP EXIT
     A3:INC G8
     JMP EXIT
     EXIT:INC BX
     LOOP LP
MOV AH,4CH
INT 21H
CODE ENDS
END START

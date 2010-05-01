
Data Segment                 
 
XEqual       DB   " = $"          ; an equal sign
NewLine     DB  0AH, 0DH, "$"     ; a new line
 
Data Ends                    
 
Code Segment               
Assume CS:Code,DS:Data
 
Start: Mov  AX,Data               
           Mov  DS,AX

       Mov  CL, 0                 ; put 0 in counter register
M_Loop:                           ; start of loop
       Mov  DL, CL                ; move current count to DL
       Mov  AH, 2H                ; set AH to 2H
       Int  21H                   ; interupt 21 w/ AH = 2H prints DL to screen
 
       Add  CL, 1                 ; increment CL by one
       Cmp  CL, 00                ; compare CL to 0
       JE   Done                  ; jump to done if equal
 
       Jmp  M_Loop                ; back to top of loop
 
 
Done:  Mov  AX,4C00H              ; exit to DOS
            Int  21H
 
Code Ends
End Start

; CS272 Boston University T.Lorber
; FINAL
; Question 1

Data Segment
Data EndS

Working_Storage Segment Stack
  DW 100H DUP(?)                ; put 256 "?" into the working storage stack
Working_Storage EndS         

Code Segment
Assume DS:Data,SS:Working_Storage,CS:Code

Prog_Start: 
        Mov AX, Data
        Mov DS, AX

        Mov AX, 0B800H          ; mem. location of start of CGA
        Mov ES, AX              ; move to ES

        CLD                     ; set to read string going forward
        Mov DI, 0               ; destination index to zero
        Mov AL, 66              ; set AL to 66D
        Mov AH, 07H             ; set AH to 7H (7D) -- AX = 
        Mov CX, 2000            ; set counter to 2000D
        Rep StoSW               ; stores  a word from AX into ES:DI, 2000 times

        Mov AH, 2               
        Mov DH, 10
        Mov DL, 40
        Mov BH, 0
        Int 10H         ; BIOS INT to set cursor position @ page 0, row 10, col 40 (middle of the screen or thereabouts)
        
        Int 19H         ; bootstrap loader
Code EndS
End Prog_Start

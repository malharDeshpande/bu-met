;CS272   Boston University   T.Lorber
;FINAL                       U61244526

Data Segment

Star   DB  "*", "$"

Data Ends

Code Segment
Assume CS:Code,DS:Data

Start: Mov  AX,Data
       Mov  DS,AX
M_Loop:
       Xor  CX, CX               ; Set counter to Zeroes
       Xor  AX, AX               ;
I_Loop:
       Mov  AH, 1D              
       Int  16H                  ; Check for key stroke 
       JNE  Done                 ; Jump to done if key entered

       Add  CX, 1D               ;
       Cmp  CX, 10000D           ; 10,000 Decimal
       JL   I_Loop               ; Loop until 10,000 Loops have been done
       
       Xor  CX, CX
       Add  AX, 1D               ;
       Cmp  AX, 1000D            ; Do 1000 of above for 10-Million
       JL   I_Loop               ;

       Mov  DX, Offset Star      ; Have DOS 
       Mov  AH, 9D               ;  type "*"
       Int  21H                  ;  on the screen
       
       Jmp  M_Loop               ; Go do another 10-Million loops

;Return to DOS
Done:  Mov  AX,4C00H
       Int  21H

Code Ends
End Start


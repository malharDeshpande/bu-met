;BinDec.Asm

Data Segment
 A_Word_M   DB "Type any 2 characters (16-bits), "
            DB "program will display in Decimal "
            DB 0AH, 0DH, "$"
Data EndS

Working_Storage Segment
      DW 100  DUP ($)
Working_Storage EndS

Code Segment

    Assume CS:CODE, SS:Working_Storage, DS:DATA

Prog_S: Mov  AX, DATA    
        Mov  DS, AX

        MOV  DX, OFFSET A_Word_M
        MOV  AH,9H
        INT  21H

        MOV  AH, 1
        INT  21H
        MOV  BH, AL      ;first byte to BH

        Mov  AH, 1
        Int  21H
        Mov  BL, AL      ;second byte to BL

        Mov  AX, BX      ;Move the 16-bits to AX for Conversion
        Mov  CX, 5       ;Loop counter

DLOOP:  Mov  BL, 10      ;Divide by 10D for decimal conversion
        Xor  BH, BH
        Xor  DX, DX
        Div  BX         ;Divide AX by 10  Answer in AX, Remainder in DX

        Push DX         ;Push Remainder on Stack
        Loop DLoop

; Display the "Remainders" you placed on the stack

        Mov  CX,5        ;Display 5 Remainders

Ploop:  POP  DX
        Add  DL, 30H
        Mov  AH, 2
        Int  21H
   
        Loop Ploop       ;Print (Display) Loop 5 times

        MOV AX,4C00H
        INT 21H

CODE ENDS
END PROG_S

;Below is a complete mASM source program.....   Mini.Asm
;
;- Characters to the right of a ";" on any line are Ignored by mASM!
;
;- In DOS, you can use EDIT to create/edit the lines below to create Mini.Asm
;
;- To Assemble, Link and Run this program: [ ASM = ArrowSoftware PC Assembler]
;
;  C:> ASM Mini<CR>         <---<CR> is Carriage Return/Enter key
;                           Input  to   ASM is   Mini.Asm
;                           Output from ASM is   Mini.Obj
;
;  C:> LINK Mini<CR>        Input  to   LINK is   Mini.Obj
;      <CR><CR><CR>         Output from LINK is   Mini.Exe
;                           Carriage Return you way through all the LINK defaults
;
;  C:> Mini<CR>             This tells DOS to run Mini.Exe
;      ARe You Sure?
;  C:>
;
;
;===============================================================================
;Mini.Asm    HW1                06-Sept-2001
;CS272       Terry Lorber U61244526 01-Feb-2010

Data Segment  
Welcome_Message DB  07,"Hello, World! TGL can compute!", 0DH, 0AH, '$'
Data EndS

Code Segment
Assume CS:Code,DS:Data

Prog_Start: Mov  AX,Data                  ;make DS register point to
            Mov  DS,AX                    ;Data in this program

            Mov  DX,OffSet Welcome_Message  ;move address of Welcome_Message
            Mov  AH,9H                    ;function code 9 to AH
            Int  21H                      ;DOS Int 21H* [(33D)(041O)(00100001B)]

            Mov  AX,4C00H                 ;Return to DOS
            Int  21H                      ;via Int 21H function 4C
Code EndS
End  Prog_Start

;===============================================================================
;* - Int 21H = DOS Screen/Keyboard functions....funct.9 = Move String to screen
;              starting at current cursor position and ending when a '$' is
;              is encountered in the input string....P81 of text you don't have!
;

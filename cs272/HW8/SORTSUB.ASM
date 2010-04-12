Name SortSub

;-----------------------------------------------------------------
; This Subroutine will sort the records in Table
; Table is defined in  SortMain.Asm
;  and its' address is resolved by Link....a place for its address
;  is defined here by the Extrn statement
;-----------------------------------------------------------------

Extrn  Table: Far

;-----------------------------------------------------------------
Data Segment Public

Num_Recs            DW  0
Flip_Cntr           DW  0
Hold_Rec            DB  21D DUP ('%') 
H_Num_Recs          DW  0

M_SI                DW  0
M_DI                DW  0

Mess_Sort_Beg       DB  0DH, 0AH, "Sort beginning", 0DH, 0AH, "$"
Mess_Sort_End       DB  0DH, 0AH, "Sort finished ", 0DH, 0AH, 0AH, "$" 
Mess_Flip           DB  "*Flip*", 0DH, 0AH, "$"
Mess_Pass           DB  "**Pass Complete**", 0DH, 0AH, "$"

Data EndS
;-----------------------------------------------------------------
Code Segment

SortSub Proc Far
Public SortSub

Assume CS:Code,DS:Data                 ; We need to tell MASM about the
                                       ; the CS & DS Segment Registers, BUT
                                       ; we DO NOT give DS a value...

       Push AX                         ; Save the registers on the Stack
       Push BX                         ; ...so we can use them here...
       Push CX                         ; ..
       Push DX                         ; .
 
       Mov  Num_Recs, DX               ;Save Num Recs input (passed via DX)
 
       Mov  DX, OffSet Mess_Sort_Beg   ;Type Sort Beginning Message
       Mov  AL, 9
       Int  21H

S_Loop:
       Sub  Num_Recs, 1                ;Num_Recs - 1 = Number of Compares
       Cmp  Num_Recs, 0                ;Did we have only 1 record input?
       JLE  S_Donez                    ; yes...can't sort 1 record
       JMP  SL_0
S_Donez:
       JMP  S_Done               ;Long-Jump...20 bits...
SL_0:
       Mov  SI, offset Table           ;Address of First  record to SI
       Mov  DI, SI                     ;Address of Second record to DI
       Add  DI, 21D                    ;           which is 21D bytes away
       Mov  M_SI, SI                   ;Hold SI
       Mov  M_DI, DI                   ;Hold DI
       
       
       
       
       
       
       
       
       
       


       Mov  DX, M_SI                   ;Type 1st record
       Mov  AL, 9
       Int  21H
       
       Mov  DX, M_DI                   ;Type 2nd record
       Mov  AL, 9
       Int  21H
       
       Mov  DX, Num_Recs               ;Hold Num_recs
       Mov  H_Num_Recs, DX             ; for working with....
       Mov  Flip_Cntr, 0               ;Zero the Flip Counter
SL_1:
       Mov  SI, M_SI                   ;setup SI
       Mov  DI, M_DI                   ;setup DI
       Mov  CX, 10D                    ;String Length to CX  (10 byte compare)
       CLD                             ; go forward...
       REPZ  CMPSB                     ; Compare the string until NotEqual
       JL   Flip_em                    ;String 1st > 2nd  ...go Flip them..
SL_2:       
       Sub  H_Num_Recs, 1              ;Another compare done...
       Cmp  H_Num_Recs, 0              ;are we done comparing record pairs?
       JZ   Pass_Done                  ;yes...go do some more checking
       Add  M_SI, 21D                  ;Point to next record
       Add  M_DI, 21D                  ;Point to next record
       Jmp  SL_1                       ;go do another compare
Pass_Done:
       Mov  DX, OffSet Mess_Pass       ;Type Pass Message
       Mov  AL, 9
       Int  21H

       Cmp  Flip_Cntr, 0               ;Did we flip any record pairs this pass
       JE   S_Done                     ;NO - We are done...
       Jmp  SL_0                       ;do another pass....
Flip_em:       
       Mov  SI, M_SI                   ;1st to
       Mov  DI, Offset Hold_Rec        ;        hold
       Mov  CX, 21D                    ;
       CLD                             ;just in case
       REP  MOVSB                      ;move the string

       Mov  SI, M_DI                   ;2nd to
       Mov  DI, M_SI                   ;        1st
       Mov  CX, 21D                    ;
       CLD                             ;
       REP  MOVSB                      ;move the string

       Mov  SI, Offset Hold_Rec        ;hold to
       Mov  DI, M_DI                   ;        2nd
       Mov  CX, 21D                    ;
       CLD                             ;
       REP  MOVSB                      ;move the string
       
       Mov  DX, OffSet Mess_Flip       ;Type Flip Message
       Mov  AL, 9
       Int  21H

       Add  Flip_Cntr, 1               ;count the flip...
       Jmp  SL_2                       ;go contine compares..














S_Done:

       Mov  DX, OffSet Mess_Sort_End   ;Type Sort Ending Message
       Mov  AL, 9
       Int  21H

       Pop  DX                         ; Restore the registers from Stack
       Pop  CX                         ; ...so Sortmain.Asm does not know
       Pop  BX                         ; ..have used them....Note: Reverse
       Pop  AX                         ; .sequence of the Pop's vs Push's
       
       Ret                             ; Return....(to SortMain.Asm)

SortSub EndP
Code Ends
;-------------------------------------------------------------------------
End                       ; Note....no Start Address  (Subroutine Module)

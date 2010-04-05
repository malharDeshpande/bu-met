;----------------------------------------------------------------------------
; CS272 - ADCOCT.ASM    Add With Carry - Octal
;
; - Input two 'Max_Nibbles' digit Octal numbers from the Keyboard
;   (Validate Nibbles as Octal)
; - Add them together
; - Output the Sum to the Screen  (include carry bit in Sum)
;
;  Terry Lorber Spring '10
;
;----------------------------------------------------------------------------
Data Segment  

Max_Nibbles = 10D        ;Maximum Number of nibbles allowed

Welcome_Message DB 'Enter 10 Octal digit String   ', 0AH
CR_LF_SP        DB 0DH, 0AH, ' $'
CR_LF           DB 0DH, 0AH, '$'
CR_LF_Plus      DB 0DH, 0AH, '+$'
Bad_Octal       DB '? Bad OCTAL Nibble entered....sorry...BYE!..', '$'

Number_1        DB Max_Nibbles DUP(00H)          ;1st Octal Number
Number_2        DB Max_Nibbles DUP(00H)          ;2nd Octal Number (& Sum)
; DO NOT Place any code between the above two "Number_1/2"


My_Carry        DB 'N'                   ;Copy carry flag here!
                                         ; Y = Carry
                                         ; N = No Carry

HString         DB '1'                   ;HexString 1 or 2

Data EndS
;----------------------------------------------------------------------------
Code Segment
Assume CS:Code,DS:Data

Prog_Start: Mov  AX,Data                    ; Init 
            Mov  DS,AX                      ;   DS
            Mov  ES,AX                      ;   and ES
            
            Mov  DX,OffSet Welcome_Message  ; Welcome user...ask for
            Mov  AH,9H                      ;         first Octal string
            Int  21H                        ;            
            
            Call Get_Octal_S                  ; Get & check both octal strings

            Mov  DX,OffSet CR_LF            ; New Line
            Mov  AH,9H                      ; 
            Int  21H                        ;            
            
            Call Add_nn_Nibbles             ; Add Number_1 to Number_2 
                                            ; (Sum to Number_2)
            
            Cmp  My_Carry, "Y"            ; Check for carry on last ADC
            JE   Type_1                   ; Yes..
              
            Mov  DL, " "                  ; No...
            Jmp  Nxt_1                    ;
Type_1:     Mov  DL, "1"                  ;

Nxt_1:      Mov  AH, 2                    ; Type Sign Bit (space or 1)
            Int  21H                      ;

            Mov  BX, Offset Number_2      ; Setup BX to print Number_2
            Call Print_Octal                ; Print the Sum on screen

Done:       Mov  AX,4C00H                   ; Return to DOS
            Int  21H                        ;
;---------------------------------------------------------------------------            
; - Get characters from keyboard one at a time (end after both numbers entered)
; - Validate each character as OCTAL (0-9, A-F)
; - Place in In_Buff string
;
Get_Octal_S:
            Mov  BX, Offset Number_1        ; Make [BX] point to 1st number
            Mov  CX, 0                      ; Clear Char.Counter
Next_Byte:
            Mov  AH, 1H                     ; Get Character
            Int  21H                        ;  from keyboard

     ; Make sure Character is Octal....            
            Cmp  AL, 48D                    ; Compare it to "0"
            JB   Not_Octal                    ;  Less than "0" is Invalid
            
            Cmp  AL, 57D                    ; Compare it to "9"
            JLE  Good_Octal                   ;  Less or Equal to "9" is Octal

            Cmp  AL, "A"                    ; Compare it to "A"
            JL   Not_Octal                    ;  Less than "A" is Invalid

            Cmp  AL, "F"                    ; Compare it to "F"
            JG   Not_Octal                    ;  Greater than "F" is Invalid   
            
            Sub  AL, 7D                     ; Since it is A->F Sub 7
                                            ;  so it will be just above "9"
Good_Octal:   
            Sub  AL, 48D                    ; Now convert the byte to a
                                            ;  Octal nibble (0000 -> 1111)

            Mov  [BX], AL                   ; Store the full byte as part
                                            ;  of string...however we will 
                                            ;  only use right 4 bits (nibble) 
            
            Add  BX, 1                      ; Point to next byte
                                            
            Add  CX, 1                      ; Increment Byte counter          
            Cmp  CX, Max_Nibbles            ; Check if we have filled num
            JE   GHN_Done                   ; YES 
            Jmp  Next_Byte                  ; Go get next Char.from Terminal
Not_Octal:
            Mov  DX, OffSet Bad_Octal         ; Place Octal error message 
            Mov  AH, 9H                     ;  on screen
            Int  21H                        ;
            Jmp  Done                       ; and return to DOS            
GHN_Done:
            Cmp  HString, '1'               ;Have we entered both strings
            JNE  All_Done                   ;Yes
            Mov  HString, '2'               ;No
            Mov  CX, 0                      ;Reset Nibble Counter
            Mov  DX,OffSet CR_LF_Plus       ; New Line
            Mov  AH,9H                      ; 
            Int  21H                        ;            
            Jmp  Next_Byte                  ;Get next string
All_Done:
            Ret

;---------------------------------------------------------------------------            
Add_nn_Nibbles:
           Mov DL, 0                        ; Init Byte counter
           Mov BX, Offset Number_1          ; Left end of Number_1
           Add BX, Max_Nibbles - 1          ; Right end byte of Number_1
A32N:
           Mov AL, [BX]                     ; Byte to AL
           Add BX, Max_Nibbles              ; Point to Number_2 String
           Mov AH, [BX]                     ; Byte to AH
           Cmp My_Carry, "N"                ; Test my carry
           JE  No_Carry                     ;
           STC                              ; Set Carry Flag
           Jmp AN1                          ;
No_Carry:  
           CLC                              ; Clear Carry Flag
AN1:      
           ADC AH, AL                       ; ADC AL --> AH

           Cmp AH, 7D                      ; Check for Carry in Nibble
           JLE NCRY                         ;    None
           Sub AH, 8D                      ;    Yes, subtract 8D
           Mov My_Carry, "Y"                ; Set My_Carry to "Y"
           Jmp Carry_OK                     ;
NCRY:        
           Mov My_Carry, "N"                ; Set My_Carry to "N"
Carry_OK:
           Mov [BX], AH                     ; Place Sum in Number_2 String
           Sub BX, Max_Nibbles + 1          ; Point to previous byte in
                                            ;    Number_1....
           Add DL, 1                        ; Count another byte
           Cmp DL, Max_Nibbles              ; Are we done?
           JL  A32N                         ; No....loop
           Ret                              ; Yes...return....

;---------------------------------------------------------------------------            
Print_Octal:
           Mov  BX, Offset Number_2     ; Answer
           Mov  CH, 0                   ; Init byte counter
PHS2_Loop:
           Cmp  CH, Max_Nibbles         ; Check for all done
           JGE  PHS2_Exit               ;  Yes...get out of here!
           Mov  AX, [BX]                ; Get a byte
           Add  BX,1                    ; Have BX point to next Byte
           Add  CH,1                    ; Count them bytes

Print_One_Octal_Digit:                    ; Print right 4 bits in OCTAL
           And  AL,0FH                  ;This  (not nec.but good idea)
           Add  AL,30H                  ; makes Binary
           Cmp  AL,3AH                  ;  into  Octal
           JB   Display_It              ;            ASCII
           Add  AL,7H                   ; (Jumps between 9 -> A)
Display_It:
           Mov  DL,AL                   ;Print the
           Mov  AH,2H                   ; Octal nibble that has been
           Int  21H                     ;  converted to ASCII
           Jmp  PHS2_Loop               ;Again...
PHS2_Exit:
           Ret
;----------------------------------------------------------------------------
Code EndS
End  Prog_Start


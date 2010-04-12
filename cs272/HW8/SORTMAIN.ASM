;George Newton  CS272   Sort Input/Output   (Main Routine)  uses SortSub.Asm
; --------------------------------------------------------------------------
Data Segment Public

  Welcome_Message DB 0DH, 0AH, 'Welcome to SORT V1.0', 0DH, 0AH
                  DB      0AH, '- Enter "Records" of up to 20 Bytes Each'
                  DB 0DH, 0AH, '- End each record with <Enter> key'
                  DB 0DH, 0AH, '- Enter up to 20 records'
                  DB 0DH, 0AH, '- <Enter><Enter> = Last record from keyboard'
                  DB 0DH, 0AH, '$'

  In_Done_Msg     DB 0DH, 0AH, '!Input complete...'
                  DB 0DH, 0AH, '$'

  Table           DB 420D DUP ('*')  ;Empty 'Table' with 20 records of 21 
                                     ;bytes each...initalized to Asterisks...
                                     ;20 bytes for data, and the 21st for '$'
                                     ;which is the DOS String Terminator
                  DB '$'             ;Stop those runaway outputs!!!
  Public Table  
  

  Record_Cntr     DW 00D             ;Count records entered (Max.20)
  Done_Flag       DB 00D             ;Set to 1 when no more records
                                     ; from user {<Enter><Enter>}
  Dollar_Char     DB '$'
  Space_Char      DB ' '
  Cr_Lf           DB 0DH, 0AH, '$'
  Rej_Char        DB 07H, 08H, 020H,08H,'$' ;<Bell><BS><Space><BS><$>
  M_BX            DW 0000H           ;Store copy of BX here!
  M_CX            DW 0000H           ;16bit memory storage

Data Ends

; --------------------------------------------------------------------------

;Working_Storage Segment Stack
;  DW 100H DUP(?)
;Working_Storage Ends

; --------------------------------------------------------------------------

Code Segment
Assume DS:Data, CS:Code   ;, SS:Working_Storage...look ma, no Stack!

;===================================            
; Main Routine                     |
;===================================

Prog_Start: Mov  AX,Data            ;Establish Data Segment register  DS
            Mov  DS,AX              ;
            Mov  ES,AX              ; and the Extra Segment register  ES
            Call Init_Prog          ; Set things up
            Call Input_Recs         ; Get input from Keyboard
            Call Sort_Recs          ; Sort them
            Call Output_Recs        ; Place sorted records on Screen

            Mov  AX,4C00H           ;setup for return to DOS
            Int  21H                ;...do it!
;===================================            
; End - Main Routine               |
;===================================








; --------------------------------------------------------------------------
;===================================            
; Init Program Subroutine          |
;===================================

Init_Prog:
            Mov  DX,Offset Welcome_Message 
            Mov  AH,9               ;Greet the program user with instructions
            Int  21H
            Ret  
;===================================            
; End - Init Program Subroutine    |
;===================================
; --------------------------------------------------------------------------
;===================================            
; Input Records Subroutine         |
;===================================
            
Input_Recs:
            Mov  BX, Offset Table   ;Place address of Table in BX register
Again:
            Call Get_Record         ;Go get a record
            Cmp  Done_Flag,1        ;Check for last record
            JE   In_Done            ; All done input...(JE = JZ)
            INC  Record_Cntr        ;Count the records
            Cmp  Record_Cntr,20D    ;go get another
            Jnz  Again              ; if we don't have 20 yet...
In_Done:
            Mov  DX,Offset In_Done_Msg
            Mov  AH,9               ;Tell user input complete
            Int  21H
            Ret
;===================================            
; End - Input Records Subroutine   |
;===================================
; --------------------------------------------------------------------------
;===================================            
; Sort Records Subroutine          |
;===================================
; 
            Extrn SortSub: Far        ;SortSub is in another program
Sort_Recs:

            Mov   DX, Record_Cntr     ;Pass argument in Register
            Call  SortSub             ;Call External Subroutine....
            Ret

;===================================            
; End - Sort Records Subroutine    |
;===================================
; --------------------------------------------------------------------------




















;===================================            
; Output Records Subroutine        |
;===================================
; Write All Records in TABLE on the users Screen

Output_Recs:
            Mov  DX,OffSet Table    ;Set DX to point to Table
            Mov  AH,9               ;Set AH for DOS String Output
         Mov CX, Record_Cntr        ;Set Loop counter to #Recs input
P_Loop:              
            Int  21H                ;Write the record to the screen
            Add  DX, 21D            ;Set DX to point to next record
            
            Push DX                 ;save DX on the stack
            Mov  DX, OffSet Cr_Lf   ;set up write
            Mov  AH, 9              ;DOS write <CR><LF> to screen
            Int  21H                ;
            Pop  DX                 ;restore DX  (from the stack)

         Loop P_Loop                ;go write another one until done...
            Ret
;===================================            
; End - Output Records Subroutine  |
;===================================
; --------------------------------------------------------------------------
;===================================            
; Get-A-Record Subroutine          |
;===================================
Get_Record:                            
         Mov  M_CX, 20D             ;Move Record length to CX (loop counter)
Get_Char:
            Mov  AH,1               ;Read a single char.from keyboard
            Int  21H                ;Get char. from DOS....Int = Interrupt 
            Cmp  AL,0DH             ;Check for <Enter>
            JE   Rec_Pad            ;..Yes..go 'Pad' record
            Mov  [BX],AL            ;Move typed character to Table
            Add  BX,1               ;Increment byte pointer
            Dec  M_CX                 ;go get another character
            JZ   EOLine             ; unless you are done
            Jmp  Get_Char
EOLine:
            Mov  AH,1               ;Look for <Enter>...'Beep' until you get it
            Int  21H                ;Next Char
            Cmp  AL, 0DH            ;Is this <Enter>
            JE   Dollar_S           ;Yes - Go put $ at end of record
            Mov  AH,9               ;No  - Beep at user
            Mov  DX, OffSet Rej_Char   ;and cleanup screen
            Int  21H                ;
            Jmp  EOLine             ;      and go try again

Dollar_S:   Mov  AL,Dollar_Char     ;Dollar to AL
            Mov  [BX],AL            ;Place '$' at end of string
            Add  BX,1               ;byte pointer
            Jmp  Done          

Rec_Pad:    Cmp  M_CX, 20D          ;Check to see if this is first character
            JE   All_Done           ;YES - First Character = <Enter>
            Mov  AL, '?'            ;'?' to AL...
            Mov  [BX],AL            ;put in Pad...
            Add  BX,1               ;byte pointer
            Dec  M_CX               ; and again...{Note: Same Loop counter}
            Jnz  Rec_Pad            ; unless you are at the end..then '$'
            Jmp  Dollar_S           ;go end with '$' and return to caller








All_Done:   Mov  Done_Flag, 1       ;Set all done input flag to 'Yes' = 1
Done:       Mov  DX, OffSet Cr_Lf   ;set up write
            Mov  AH, 9              ;DOS write <CR><LF> to screen
            Int  21H                ;
            Ret                     ;Return to caller....
;===================================
; End - Get-A-Record Subroutine    |
;===================================

Code Ends
End Prog_Start

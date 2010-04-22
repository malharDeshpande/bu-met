;KbdTSR5.Asm   [ NEW HomeWork - Apr.2005]    CS272   G.Newton             

;Homework #9 2010-04-22 Terry Lorber

Data Segment  

IntNo   Equ  9H   ;Interupt Number we are modifying  (KeyBoard Press)

OldVector    DD 00000000   ;Save Old Vector Address here (32 bits - 4 bytes)

ScrChar      DB "$"        ;smiley face
Color        DB 00         ;character attribute

Data EndS

Code Segment
Assume CS:Code,DS:Data

Prog_Start: Mov  AX, Data
            Mov  DS, AX
            Jmp  ChgVector

;******************************************************************************
My_Int_TSR:            
            Push DS

; - Begin Call Old Vector Routine - Have DOS/BIOS process the Keystroke
;                                   as they normally would...

            Push DX                    ; Save DX
            Mov  DX, Data              ; TSR code needs DS set
            Mov  DS, DX                ;  for accessing  OldVect...
            Pop  DX                    ; Now restore it....
           PushF             ;Call the    NOTE: FLAGS get place on STACK for Int
            Call  OldVector            ; Old Interrupt Routine

; - End Call Old Vector Routine - Now we do out "Stuff"            

            Push SI 
            Push ES
            Push AX                    ;Save the Registers
            Push DI                    ;that may be needed
            Mov AX, 0B800H             ;Top-Left Corner of Screen
            Mov ES, AX
            Mov AX, 00
                       ;go to 12x40 (2 pos./Char.)
            Mov DI, AX
            Mov AL, ScrChar       ;Your Character
            STOSB                 ;Place AL Char. in top-right corner screen
            Mov AL, Color         ;Now CHANGE the Color
            STOSB                 ; now second char...(attribute byte)
	       Add Color, 1          ;Change your Color for next KeyStroke

Done:       Pop  DI
	       Pop  AX
	       Pop  ES
	       Pop  SI     
            Pop  DS               ; Restore DS

            IRET                       ;*Return to the program you were running
                                       ; when the Interrupt occured.....
;******************************************************************************            

; Set the Keyboard Interrupt Vector Segment & Offset Addresses to
; our own routine...

ChgVector:  Mov  AL, IntNo             ; Interrupt
            Mov  AH, 35H               ; DOS Int21H function to get Vector
            Int  21H

            Mov  Word PTR  OldVector, BX    ; and Save OldVector Address Here
            Mov  Word PTR  OldVector+2, ES  ; for use on keystroke interrupts

            Mov  AX, 0                 ;Set ES to Memory Segment 0
            Mov  ES, AX                ;  0000H
            Mov  DS, AX
            CLD                        ;Go forward

            Mov  DI, IntNo*4           ;Set DI offset to the 0Hth Interrupt

            CLI                        ;Disable Interrupts

            Mov  AX, OffSet  My_Int_TSR
            STOSW                      ; Place our Keyboard interrupt offset

            Mov  AX, CS                ;       and CS Segment Address 
            STOSW                      ;       in the INT 9 Vector Table slot

            STI                        ;Enable Interrupts

; Now EXIT from this program, leaving 20H Paragraphs of it in memory....

            Mov  DX, 50H               ;*Tell TSR to keep 50H Paragraphs of
                                       ;  16 bytes each in memory
            
            Mov  AH, 31H               ;*Terminate process, Stay Resident in
                                       ;  memory    TSR
            Int  21H                   ;*DOS Int .... Exit Prog, Prog.stays
                                       ;              in memory

;Return to DOS

Code EndS
End  Prog_Start

;CS272 - Hearts.ASM - The Feb.14th Program....
;
;        The Dos CGA screen information is stored starting at Memory Location B8000 Hex
;        This program places characters and character attributes in this area, and
;         the "video card" extracts it to the screen via Direct Memory Access (DMA).
; 
;  NOTE: If this program leaves your Screen so
;        you can't see characters, then you
;        need to reset it to the "default"
;        black background with white
;        characters. To do that, at the DOS
;        prompt, (which you will not be able
;        to see) type:   CLS<Enter>                 
;                                           
;        Your homework is to modify the SC
;        character...curently set to Smiley
;        Faces...to another of your choice..
;        then (see below)..
;        Change the Add inside the LOOP to a
;        power-of-two...2,4,8,16 etc.
;                                                                       
;        Create, Print, and turn in Hearts.LST
;        listings!   
;                                  
;  Good luck....George                                                  



Data Segment

SChar      DB 03   ; Fill the screen with this
                   ; character (02 = "")
                   ; [Note: 04 = "", 01 = ""
                   ;        & 03 = ""]

SA         DB 00   ;Screen Character Attribute
                   ; [See: Thorne P.565]
                   ;  00 = Black Character
                   ;       on Black Background
Data Ends

Code Segment
Assume DS:Data, CS:Code

ProgSt: Mov  AX,Data   ;
        Mov  DS,AX     ;

A1:     Mov  AX,0B800H ;<- memory address
        Mov  ES,AX     ;   of CGA Screen
                       ;   (top left corner)
                       ;to Extra Segment ES
                       ;   Register...
                             
        CLD            ;Set STRING MOVE
                       ;   direction   Forward

        Mov  DI, 0     ;Set DI offset to ES
                       ;DI = Destination Index
                       ;ES = Extra Segment

        Mov  AL, SChar ;Set Screen Character
                       ;to ""   00000010B

        Mov  AH, SA    ;Set Screen Attribute
                       ;to  Black Char.
                       ;    Black Backgrnd
                       ;     00000000B

                       ;The CGA Screen uses
                       ; 2000 Words of memory
                       ; 80 Char. X 25 Lines
                       ; = 2000 Words

        Mov  CX,2000D  ;each Word =
                       ;    1 Char.Byte
                       ;  & 1 Attribute Byte
      
AA:     StoSW          ;Modify all 25 Lines
                       ;        of 80 bytes
                       ; [ in this AA: Loop! ]
                       ;
        Add AH,1       ;Note:  By changing the
                       ;=====      Add AH, 1
                       ;       to  Add AH, 2
                       ;
                       ; you will change the
                       ; pattern on the screen
                       ; Also try 4, 8, 16,
                       ;          32, 64 etc.
                       ; and try and predict
                       ; the results!

        Loop AA        ;Note: Loop instruction
                       ;===== uses CX as
                       ; count-down counter...
                       ; and when CX = Zero,
                       ; the instruction does
                       ; loop back to AA:, it
                       ; FALLS-Through to the
                       ; Next Sequentional
                       ; Instruction !!!

        Mov  AH,1      ;Hit AnyKey to Continue
        Int  21H       ;
                       ;Note: This leaves the
                       ; entire screen full of
                       ; Hearts...by typing
                       ; anything, top line of
                       ; Hearts screen is
                       ;"scrolled off the top"
                       ; to make room for the
                       ; Dos prompt on bottom!

        Mov  AX,4C00H  ;Return to
        Int  21H       ;       DOS

Code Ends
End ProgSt

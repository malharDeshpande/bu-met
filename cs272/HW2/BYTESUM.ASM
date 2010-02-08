;George Newton  CS272   HW2 F03 

;Your homework, due next week, is to modify the program below to
;             handle BOTH UPPER-Case and lower-Case Alphabetic Characters.

;             Please create, print and turn in BtyeSum.Lst

;Program: Input a group of characters (a word) from the terminal.
;         - The program converts each character to a binary nunber, 
;            (where A=1, B=2, C=3....Z=26)
;         - The binary number is then added to an accumulator.  
;         - When the Accumulator = 100, you WIN!! 
;            (the 'Bell' rings and the program exits to DOS)  
;         - When the Accumulator goes over 100, you are prompted to try again.


Data Segment
Welcome_Message DB 0DH, 0AH, 'Terry Lorber C272 - Spring 2010', 0DH, 0AH, 0AH 
                DB 'Welcome to "Add-the-Bytes"', 0DH, 0AH, 0AH, '$'  

Intro_Message   DB 0DH, 0AH, 'Enter a string of digits that sum 100'
                DB 0DH, 0AH, '0=0, 1=1, 2=2...9=9' 
                DB 0DH, 0AH, 0AH, '$'    ;Note: Message on 3 lines

Error_Message   DB 007, ' <--- ?Error...Sum Exceeds 100, try again!...'
                DB 0DH, 0AH, 0AH, '$'    ;Error-Message

Error_Message2  DB 0DH, 0AH, 007, '  ^--- ?Error...Sum is Below 100, try again!'
                DB 0DH, 0AH, 0AH, '$'    ;Error-Message

Bad_Character   DB 007, ' <--- ?Char.Entered NOT 0<>9 ?', 0DH, 0AH, '$'

Plus_String     DB 0DH, 0AH, '+ $'

Exit_Message    DB 007, ' <--- "A WINNER!" {Sum 100 = Exit to Dos}', 007 
                DB 0DH, 0AH, 007, '$'   ;Note: 007 = Bell

Bye_Message DB 0DH, 0AH, 'Thanks for using "Add-the-Bytes"...have a nice day!'
            DB 0DH, 0AH, '$'
Data EndS
;------------------------------
Working_Storage Segment Stack
  DW 100H    DUP (?)
Working_Storage EndS
;------------------------------
Code Segment
     Assume CS:Code, DS:Data, SS:Working_Storage

Prog_Start: Mov AX,Data             ;Init
            Mov DS,AX               ;Data Segment Pointer

            Mov  DX, Offset Welcome_Message
            Mov  AH,9               ;String write to DOS
            Int  21H                ;Write it

P_Loop:     Mov  AH,9               ;String write to DOS
            Mov  DX, OffSet Intro_Message
            Int  21H                ;Write it
            Mov  CH, 0              ;Clear CH..our Byte Sum Accumulator

Get_Chr:    MOV DX,OFFSET PLUS_STRING
            MOV AH,9
            INT 21H
            Mov  AH,1               ;Read a single char.from keyboard
            Int  21H                ;Get char. from DOS....Int = Interrupt 
            
   ;Make sure character is =>0 & =<9
            Cmp  AL,"0"             ;Check it against '0'
            JB   NG                 ; Less than (Below) '0', Jump to NG:
            Cmp  AL,"9"             ;Check it against '9'
            JA   NG                 ; Greater than (Above) '9', Jump to NG:

   ;Ok, the character entered is between 0<->9
OK:         Sub  AL, 48             ; 48 == "0"' 
            Add  CH,AL              ;Add binary result to CH
            CMP  CH, 100            ;Check interim result against 100
            JZ   Winner             ; Yes, word = 100
            JA   Oops               ; No...and you went over 100!
            Jmp  Get_Chr            ;go get another character...

Oops:       Mov  DX, OffSet Error_Message
            Mov  AH,9               ;Sorry...Sum > 100
            Int  21H
            Jmp  P_Loop             ;go try another word....

Winner:     Mov  DX, OffSet Exit_Message
            Mov  AH,9
            Int  33                 ; 33Decimal = 21Hex
            Mov  DX, OffSet Bye_Message
            Int  33
            Mov  AX,4C00H           ;setup for return to DOS
            Int  21H                ;...do it!
;You have gone back to DOS with the above Interrupt!

            
NG:         JMP SNG
            Cmp  AL, 'a'
            JL   SNG
            Cmp  AL, 'z'
            JA   SNG
            Sub  AL, 32
            Jmp  OK
SNG:        Cmp  AL, 0DH            ;See if char.entered is <CR = 0D Hex = 0000 1101 Binary>
            JE   Word_End           ;Yes...go tell them error...

            Mov  DX, OffSet Bad_Character
            Mov  AH,9
            Int  33                 ;type out error message [ 33 Decimal = 21 Hex ]
            Jmp  P_Loop             ;Go try another word!

Word_End:   Mov  DX, OffSet Error_Message2
            Mov  AH,9
            Int  33                 ;Tell user sum is too low
            Jmp  P_Loop             ;Go try another word!
Code EndS
End Prog_Start


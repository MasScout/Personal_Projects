@ Filename: GIBarrow.s
@ Author:   Mason Barrow
@ Term:		CS309-01 2020-21
@ Purpose:  Show CS309 and CS413 students how to read user inputs from
@           the keyboard. Students are expected to learn ARM assembly in
@           these courses not obscure details about C printf and scanf.
@           In most cases it should be assumed the user provided a valid
@           input. 
@ 
@ History: 
@    Date       Purpose of change
@    ----       ----------------- 
@   4-Jul-2019  Changed this code from using the stack pointer to a 
@               locally declared variable. 
@  15-Sep-2019  Moved some code around to make it clearer on how to 
@               get the input value into a register. 
@   1-Oct-2019  Added code to check for user input errors from the 
@               scanf call.   
@  21-Feb-2019  Added comments about "%c" vs " %c" related to scanf.
@
@  14-Mar-2021	Modified for ARM3 HW Submission


@ ***********************************************************************
@ The = (equal sign) is used in the ARM Assembler to get the address of a
@ label declared in the .data section. This takes the place of the ADR
@ instruction used in the textbook. 
@ ***********************************************************************

.equ READERROR, 0 @Used to check for scanf read error. 

.global main @ Have to use main because of C library uses. 

main:

@*******************
prompt:
@*******************

@ Ask the user to enter a number.
 
   ldr r0, =strInputPrompt @ Put the address of my string into the first parameter
   bl  printf              @ Call the C printf to display input prompt. 

@*******************
get_input:
@*******************

@ For Reading and printing an Integer
	ldr r0, =numInputPattern	@ Setup to read in one number.
	ldr r1, =intInput       	@ load r1 with the address of where the
								@ input value will be stored. 
	bl  scanf               	@ scan the keyboard.
	cmp r0, #READERROR      	@ Check for a read error.
	beq readerror           	@ If there was a read error go handle it. 
	ldr r1, =intInput       	@ Have to reload r1 because it gets wiped out. 
	ldr r1, [r1]            	@ Read the contents of intInput and store in r1 so that
								@ it can be printed.
	subs r2, r1, #100			@ Subtract 100 from the input
	bpl	IntThen					@ If positive
	ldr r0, =strOutputNumLess	@ If negative
	b 	Exit					@ Exit If statement
IntThen: ldr r0, =strOutputNumMore	@ Save output less string to r0
IntExit: b1 printf					@ Print whichever string is saved to r0
	

@ Ask the user to enter a character.
 
	ldr r0, =strInputCharPrompt 	@ Put the address of my string into the first parameter
	bl  printf              		@ Call the C printf to display input prompt. 

@ For Reading and printing a Character
	ldr r0, =charInputPattern	@ Setup to read in one number.
	ldr r1, =charInput       	@ load r1 with the address of where the
								@ input value will be stored. 
	bl  scanf                	@ scan the keyboard.
	cmp r0, #READERROR       	@ Check for a read error.
	beq readerror            	@ If there was a read error go handle it. 
	ldr r1, =charInput       	@ Have to reload r1 because it gets wiped out. 
	ldr r1, [r1]             	@ Read the contents of charInput and store in r1 so that
								@ it can be printed.
	

@ Print the input out as a character.
@ r1 contains the value input to keyboard. 

	ldr r0, =strOutputChar
	bl  printf
   
	b   myexit @ leave the code. 

@***********
readerror:
@***********

	ldr r0, =strInputPattern
	ldr r1, =strInputError   @ Put address into r1 for read.
	bl scanf                 @ scan the keyboard.

	b prompt

@*******************
myexit:
@*******************
@ End of my code. Force the exit and return control to OS

	mov r7, #0x01 @ SVC call to exit
	svc 0         @ Make the system call. 

.data

@ Declare the strings and data needed

.balign 4
strInputPrompt: .asciz "Input the number: \n"

.balign 4
strOutputNumLess: .asciz "The input number is less than 100. \n"

.balign 4
strOutputNumMore: .asciz "The input number is greater than or equal to 100. \n"

.balign 4
strInputCharPrompt: .asciz "Input the character: \n"

.balign 4
strOutputChar: .asciz "Upper case letter entered. \n"

.balign 4
strOutputCharLower: .asciz "Lower case letter entered. \n"

.balign 4
strOutputCharSpecial: .asciz "Special character entered. \n"

@ Format pattern for scanf call.
.balign 4
numInputPattern: .asciz "%d"  @ integer format for read.

.balign 4
charInputPattern: .asciz "%s"	@ character format for read.

.balign 4
strInputPattern: .asciz "%[^\n]" @ Used to clear the input buffer for invalid input. 

.balign 4
strInputError: .skip 100*4  @ User to clear the input buffer for invalid input. 

.balign 4
intInput: .word 0   @ Location used to store the user int input. 

.balign 4
charInput: .word 0   @ Location used to store the user char input. 



.global printf

.global scanf

@ End of code and end of file. Leave a blank line after this.

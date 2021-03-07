@ File:    helloworld.s
@ Author:  Mason Barrow
@ Email:   mab0086@uah.edu
@ Term:	   CS309-1 2020-21
@ Purpose: Provide enough assembly to allow students to complete an assignment. 
@ History: 
@    04-Mar-2019 Added comments to help with printf and svc calls.
@    15-Sep-2019 Added comments on which registers are changed
@           when there is a call to printf or SVC.
@	 28-Feb-2021 Modified for ARM1 HW Submission



.global main 
main:        @Must use this label where to start executing the code. 

	@ Print using system call
    MOV   r7, #0x04    @ A 4 is a write command and has to be in r7.
    MOV   r0, #0x01    @ 01 is the STD (standard) output device. 
    MOV   r2, #0x26    @ Length of string to print (in Hex).
    LDR   r1, =string1 @ Put address of the start of the string in r1
    SVC   0            @ Do the system call

	@ Print using C function printf
    LDR  r0, =string2 @ Put address of string in r0
    BL   printf       @ Make the call to printf

	@ Print using system call
    MOV   r2, #0x39    @ Length of string to print (in Hex).
    LDR   r1, =string3 @ Put address of the start of the string in r1
    SVC   0            @ Do the system call
	
	@ Force the exit of this program and return command to OS.
    MOV  r7, #0X01
    SVC  0

@ Declare the stings
.data       @ Lets the OS know it is OK to write to this area of memory. 
.balign 4   @ Force a word boundry.
string1: .asciz "My full name is Mason Alexander Barrow"  @Length 0x26

.balign 4   @ Force a word boundry
string2: .asciz "My UAH email address is mab0086@uah" @Length 0x23

.balign 4   @ Force a word boundry
string3: .asciz "This is my first ARM assembly program for CS309-1 2020-21" @Length 0x39

.global printf 

@end of code and end of file. Leave a blank line after this. 

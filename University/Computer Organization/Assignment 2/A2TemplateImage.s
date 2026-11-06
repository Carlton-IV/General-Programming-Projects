@ File: A2TemplateImage.s
@ Student,
@ Template in ARM for the program based on a subset of
@ the C program written for Assignment 1
@ The original program in C reads a 2D image from an input file, applies
@ to it some image processing transformation upon request and
@ prints the output both to the screen and to a file.
@ The 2D image is stored and handled as a 2D array of characters. */

@@@@@@ REVISED PSEUDO CODE FOR THE ARM PROGRAM  *******
@Initialization:
@	Open the input file
@		if problems, print message and exit program
@	Print a header message to screen
@Obtain the input data:
@	Read row size (Rsize1) and column size (Csize1) of image from the input file
@	Read exactly (Rsize1)x(Csize1) integers as elements for an image,
@		convert to characters, and store as 2D char array
@	Print image as characters with headings to screen
@Processing the image:
@	Construct the Horizontal Mirror of the image into a second image
@		and print the resulting image with headings to screen
@	Construct the Vertical Mirror of the image into a second image
@		and print the resulting image with headings to screen
@BONUS: 	Construct the Diagonal Right of the image into a second image
@		and print the resulting image with headings (note that this
@		is the equivalent of constructing the transpose of a matrix)
@Closure:
@	Print a final message to screen
@	Close the input file
@	Exit the program */

@ Code for File I/O taken from IO_Example2a.s

	.equ	MAXROW, 10 @ Maximum of 10 rows
	.equ	MAXCOL, 10 @ Maximum of 10 columns
@ We use nicer labels for the hex SWI codes:
	.equ	SWI_Open,  	0x66	@ open a file
	.equ	SWI_Close, 	0x68	@ close a file
	.equ	FileInputMode,  0	@ Input mode for file
	.equ	SWI_RdInt,	0x6c	@ Read an Integer from a file
	.equ	SWI_PrChr,	0x00  	@ Write a byte as an ASCII char to Output View
	.equ	SWI_PrStr, 	0x69  	@ Write a null-ending string
	.equ	SWI_PrInt,	0x6b	@ Write an Integer
	.equ	Stdout,		1	@ Set output mode to be Output View
	.equ	SWI_Exit, 	0x11  	@ Stop execution

	.equ	AMP_CHAR,  0x26
	.equ	PLUS_CHAR, 0x2B
	.global _start
	.text
_start:

@@@ Refer to IO Primer in ARMSim# and to Lab 5: IO_Example2a.s and to QUIZ 3
@@@ Refer also to the C code from Assignment 1 (answer from instructor posted)
@ ===============================================================
@	Open the input file for reading
@		if problems, print message to screen and exit
	ldr	r0,=InputFileName		@ set Name for input file
	mov	r1,#0			    	@ mode is input
	swi	SWI_Open		    	@ open file for input
	bcs	InFileError 	    	@ Check Carry-Bit (C): if= 1 then ERROR
	ldr	r1,=InputFileHandle	    @ if OK, load input file handle
	str	r0,[r1]			    	@ save the file handle

@ ===============================================================
@ 	Print a header message with your name and student number
@@@@@ EDIT THE MESSAGE HERE
	mov	r0, #Stdout
	ldr	r1, =HelloMsg
	swi	SWI_PrStr 	@ R0:target, R1:msg

@ =================================================
@ 	Read row size and column size of image from the input file
@@@@@ This is given to you as a further example of how to read
@@@@@ integers from a file. Use it as a guide to read the
@@@@@ image elements below
	ldr	r1, =InputFileHandle	@get file name
	ldr	r1, [r1]
	mov	r0, r1		@ R0 has file handle
	swi	SWI_RdInt 	@ Read and result in R0
	mov	r2, r0    	@ R2=rows
	mov	r0, r1		@ R0 has file handle
	swi	SWI_RdInt 	@ Read and result in R0
	mov	r3, r0    	@ R3=cols

	ldr	r1, =Rsize1
	str	r2, [r1]    	@ store rows
	ldr	r1, =Csize1
	str	r3, [r1]    	@ store cols

@ =================================================
@	Read exactly (Rsize1)x(Csize1) integers as elements for an image,
@	convert each correctly to characters, and store as 2D char array
@@@@@ YOUR CODE HERE: Read exactly (Rsize1)x(Csize1) integers
    mul r4, r2, r3              @r4 has ros * cols
    ldr r7, =IM1                @r7 has the address of the current IM1 array slot
    ldr r1, =InputFileHandle
    ldr r1, [r1]
readloop:
    mov r0, r1
    swi SWI_RdInt
    str r0, [r7], #4
    subs r4, r4, #1
    bgt readloop



@@@@@ as elements for an image,convert to characters, and store as 2D char array

@ =================================================
@	Print original image as characters with headings

@ Print heading message for the original image
@@@@@ YOUR CODE HERE

    mov r0, #Stdout
    ldr r1, =OrIm
    swi SWI_PrStr


@ Set up the imput parameters to call PrImage to print the image
	ldr	r7,=IM1		@ R7 = address of IM1
	ldr	r2,=Rsize1
	ldr	r2,[r2]		@ R2 = Rsize1
	ldr	r3,=Csize1
	ldr	r3,[r3]		@ R3 = Csize1
@@@@@ choose the correct routine according to your storage choices
	BL	PrImage		@ PrImage(&Im2:R7,Rsize1:R2,Csize1:R3)

@ =================================================
@ Horizontal Mirror

	ldr	r1, =IM1	@ R1 = address of IM1
	ldr	r2, =IM2	@ R2 = address of IM2

@@@@@ YOUR CODE HERE to produce the horizontal mirror
@ 	of IM1 in IM2

    ldr r3, =Rsize1
    ldr r3, [r3]
    ldr r4, =Csize1
    ldr r4, [r4]                  @r4 stores a constant of size col

    ldr r5, [r2, -r4, lsl #2]!   @Sets to IM2[i = -cols]
    sub r2, r2, #4
hrRowLoop:
    ldr r5, [r2, r4, lsl #3]!   @Sets to IM2[i += 2cols]
    mov r5, r4                  @r5 stores a counter of size col
hrColLoop:
    ldr r6, [r1], #4
    str r6, [r2], #-4
    ldr r7, [r2, #4]
    subs r5, r5, #1
    bgt hrColLoop
    subs r3, r3, #1
    bgt hrRowLoop




@ =================================================
@ Print IM2 as characters with headings

@ Print heading message for the original image
@@@@@ YOUR CODE HERE
    mov r0,#Stdout
    ldr r1,=HrIm
    swi SWI_PrStr

@ set up to call routine to print the image
	ldr	r7,=IM2		@ R7 = address of IM2
	ldr	r2,=Rsize1
	ldr	r2,[r2]		@ R2 = Rsize1
	ldr	r3,=Csize1
	ldr	r3,[r3]		@ R3 = Csize1
@@@@@ choose the correct routine according to your storage choices
	BL	PrImage		@ PriImage(&Im2:R7,Rsize1:R2,Csize1:R3)
@ =================================================
@ Vertical Mirror

	ldr	r1, =IM1	@ R1 = address of IM1
	ldr	r2, =IM2	@ R2 = address of IM2

@@@@@ YOUR CODE HERE to produce the vertical mirror
@ 	of IM1 in IM2

    ldr r3, =Rsize1
    ldr r3, [r3]
    ldr r4, =Csize1
    ldr r4, [r4]                    @r4 stores a constant of size col
    mul r8, r3, r4

    ldr r5, [r2, r8, lsl #2]!       @Sets to IM2[i = col*row]
    ldr r5, [r2, r4, lsl #2]!
    vrRowLoop:
    ldr r5, [r2, -r4, lsl #3]!      @Sets to IM2[i += 2cols]
    mov r5, r4                      @r5 stores a counter of size col
    vrColLoop:
    ldr r6, [r1], #4
    str r6, [r2], #4
    ldr r7, [r2, #4]
    subs r5, r5, #1
    bgt vrColLoop
    subs r3, r3, #1
    bgt vrRowLoop

@ =================================================
@ Print IM2 as characters with headings

@ Print heading message for the original image
@@@@@ YOUR CODE HERE
    mov r0,#Stdout
    ldr r1,=VrIm
    swi SWI_PrStr

@ set up to call routine to print the image
	ldr	r7,=IM2		@ R7 = address of IM2
	ldr	r2,=Rsize1
	ldr	r2,[r2]		@ R2 = Rsize1
	ldr	r3,=Csize1
	ldr	r3,[r3]		@ R3 = Csize1
@@@@@ choose the correct routine according to your storage choices
	BL	PrImage		@ PriImage(&Im2:R7,Rsize1:R2,Csize1:R3)

@ =================================================
@ Print a final message to screen
@@@@@ YOUR CODE HERE

@ =================================================
@ Close the input file
	ldr	R0, =InputFileHandle  @ get address of file handle
	ldr	R0, [R0]              @ get value at address
	swi	SWI_Close

Exit:
	swi	SWI_Exit

InFileError:
	mov	R0,#Stdout		@ to screen
	ldr	R1, =FileOpenInpErrMsg
	swi	SWI_PrStr  		@ display error message
	bal	Exit            @ give up, exit

@ =================================================
@ PriImage(&ImageChar:R7,RowSize:R2,ColSize:R3)
@ Print a 2D array of char row by row
@ R7 = address of 2D array, R2 = # rows, R3 = # columns
@ Assumptions: elements are stored consecutively
PrImage:
	STMFD	sp!,{r0-r5,lr}	;save registers
	mov	r4,r7		@ R4 is pointer to array elements
ROWLOOP:
	mov	r5,r3		@ set column counter
COLLOOP:
    mov r0, #Stdout
    ldr r1,[r4],#4		@ get char to be printed
	swi	SWI_PrInt		@ print it
	subs	r5,r5,#1		@ next element, same row?
	bne	COLLOOP
	mov	R0,#Stdout		@ mode is Output view
	ldr	r1, =EOL		@ end of line
	swi	SWI_PrStr
	subs	r2,r2,#1		@ next row?
	bne	ROWLOOP

DonePrImage:
	LDMFD	sp!,{r0-r5,pc}	;load registers and return

	.data
Rsize1:	.word	0
Csize1:	.word	0
InputFileHandle:	.skip	4
IM1:	.skip	MAXROW*MAXCOL*4
IM2:	.skip	MAXROW*MAXCOL*4
InputFileName:  	.asciz	"A1inF.txt"
FileOpenInpErrMsg: 	.asciz	"Failed to open input file \n"
OrIm: 	.asciz	"The original image contains: \n"
VrIm: 	.asciz	"The vertical mirror image contains: \n"
HrIm: 	.asciz	"The horizontal mirror image contains: \n"
EOL:	.asciz	"\n"
HelloMsg:
	.ascii	"\n Carlton Champion - Student Number 240955 \n"
	.ascii	"\n File = A2templateImage.s - November 2026 \n"
	.ascii	"\n 62:367, Assignment 2 \n\n"
	.asciz	"Starting: \n"
	.end

/* File: TEMPLATE2.c */
/* GIVEN TO STUDENTS AS INITIAL TEMPLATE*/
/* does not compile or execute */

/* This program reads a 2D image from an input file, applies
to it some image processing transformation upon request and
prints the output both to the screen and to a file.
The 2D image is stored and handled as a 2D array of characters. */

/****** PSEUDO CODE: ******
	*Initialization:
		Open the input file
			if problems, print message and exit
		Open the output file
				if problems, print message and exit
		Print a header message to screen and to file

		*Obtain the input data:
		Read row size and column size of image
		Read elements of image as integers, convert to characters, and store as 2D char array
		Print image as characters with headings to screen and to file

		*Processing the image:
		Repeat until the end of file is reached:
			Read an integer k from the input file specifying a task for the image
				Case k of:
					If 1 then call Vertical Mirror Image routine
					If 2 then call Horizontal Mirror Image routine
					If 3 then call Diagonal Right Image routine
					If 4 then call Diagonal Left Image routine
					If 5 then call Rotate Right Image routine (BONUS)
				Print the new image generated with headings to screen and to file

		*Closure:
		When End of File is reached
			Print a final message to screen and to file
			Close input and output files
		Exit the program*/

/* Code for File I/O to be taken from FileIntegersArray2.c */

#include <stdio.h>	/* include needed libraries */
#define MAXROW 50	/*set maximum sizes for image 2D array */
#define MAXCOL 50
#define	AP	'&'		/*char symbols used in array */
#define	PL	'+'

/* global variables*/
FILE *fpin1,*fpout1;	/*pointers to files*/

/*************************************************************/
/****** void PrImage(Image, Nrows,Ncols) ******/
/* This procedure prints a 2D char array row by row
	both to the screen and to an output file (global) */
void PrImage( char Image[MAXROW][MAXCOL], int Nrows, int Ncols)
{

	/* YOUR CODE HERE */

}/*End of PrImage*/
/*************************************************************/
/****** void CopyCol(Mat1,Mat2,Nrows,Coli,Colj) ******/
/* Copy Coli of Mat1 to Colj of Mat2 of the same dimensions */
void CopyCol( char Mat1[MAXROW][MAXCOL], char Mat2[MAXROW][MAXCOL],
	int Nrows, int Coli, int Colj)
{

			/* YOUR CODE HERE */
			/* THIS ROUTINE IS NOT REQUIRED */


}/*End of CopyCol*/
/*************************************************************/
/****** void CopyRow(Mat1,Mat2,Ncols,Rowi,Rowj) ******/
/* Copy row i of Mat1 to row j of Mat2 of the same dimensions */
void CopyRow( char Mat1[MAXROW][MAXCOL], char Mat2[MAXROW][MAXCOL],
	int Ncols, int Rowi, int Rowj)
{

			/* YOUR CODE HERE */
			/* THIS ROUTINE IS NOT REQUIRED */

}/*End of CopyRow*/
/*************************************************************/
/****** void CopyColRow(Mat1,Mat2,Nrows,Coli,Rowj) ******/
/* Copy col i of Mat1 to row j of Mat2 */
void CopyColRow( char Mat1[MAXROW][MAXCOL], char Mat2[MAXROW][MAXCOL],
	int Nrows, int Ncols, int Coli, int Rowj)
{
		/* YOUR CODE HERE */
		/* THIS ROUTINE IS NOT REQUIRED */

}/*End of CopyColRow*/
/*************************************************************/
/****** void CopyColrevRow(Mat1,Mat2,Nrows,Ncols,Coli,Rowj) ******/
/* Copy col i from (Nrows to 0) of Mat1 to row j of Mat2 from 0 to Ncols */
/* that is, copy the column, from bottom to top element,to the row */
/* 	copy column (Ncols-1) from (Nrows-1 element) to row (0) from (0) element
	copy column (Ncols-2) from (Nrows-1 element) to row (1) from (0) element
	copy column (0) from (Nrows-1 element) to row (Ncols-1) from (0) element*/
void CopyColrevRow( char Mat1[MAXROW][MAXCOL], char Mat2[MAXROW][MAXCOL],
	int Nrows, int Ncols, int Coli, int Rowj)
{

		/* YOUR CODE HERE */
		/* THIS ROUTINE IS NOT REQUIRED */

}/*End of CopyrevColRow*/
/*************************************************************/
/****** void VMirror(Image1, Image2, Nrows, Ncols) ******/
/* Given the 2D char array of Image1 and its dimensions,
	construct the vertical mirror image in Image 2 as in:
	copy columns (0,1,...,Ncols-1) of Image1 to
	columns (Ncols-1, Ncols-2, ..., 1, 0) respectively of Image2 */
void VMirror( char Image1[MAXROW][MAXCOL], char Image2[MAXROW][MAXCOL],
	int Nrows, int Ncols)
{

		/* YOUR CODE HERE */

}/*End of VMirror*/
/*************************************************************/
/****** void HMirror(Image1, Image2, Nrows, Ncols) ******/
/* Given the 2D char array of Image1 and its dimensions,
	construct the horizontal mirror image in Image 2 as in:
		copy rows (0,1,...,Nrows-1) of Image1
		to rows (Nrows-1,Nrows-2,...,1,0) respectively of Image2 */
void HMirror( char Image1[MAXROW][MAXCOL], char Image2[MAXROW][MAXCOL],
	int Nrows, int Ncols)
{

		/* YOUR CODE HERE */

}/*End of HMirror*/
/*************************************************************/
/****** void DiagR(Image1, Image2, Nrows, Ncols) ******/
/*Given the 2D char array of Image1 and its dimensions,
	construct the flipped image in Image2 along the top
	left to bottom right diagonal as in:
		 copy col 0 of Image1 -> row 0 of Image2
		 copy col 1 of Image1 -> row 1 of Image2
		......................................
		 copy col (Ncols-1) of Image1 to row (Ncols-1) of Image2
		 NOTE: sizes of Image2 are inverted from Image1 */
void DiagR( char Image1[MAXROW][MAXCOL], char Image2[MAXROW][MAXCOL],
	int Nrows, int Ncols)
{

		/* YOUR CODE HERE */


}/*End of DiagR*/
/*************************************************************/
/****** void DiagL(Image1, Image2, Nrows, Ncols) ******/
/*Given the 2D char array of Image1 and its dimensions,
	construct the flipped image in Image2 along the top
	right to bottom left diagonal as in:
		copy col (Ncols-1) of Image1 -> row 0 of Image2
		copy col (Ncols-2) of Image1 -> row 1 of Image2
		......................................
		copy col 0 of Image1 -> row (Ncols-1) of Image2
		NOTE: sizes of Image2 are inverted from Image1 */
void DiagL( char Image1[MAXROW][MAXCOL], char Image2[MAXROW][MAXCOL],
	int Nrows, int Ncols)
{

		/* YOUR CODE HERE */


}/*End of DiagL*/
/*************************************************************/
/****** void RotR(Image1, Image2, Nrows, Ncols) ******/
/*Given the 2D char array of Image1 and its dimensions,
	construct the rotated by 90 degree image in Image2 */
void RotR( char Image1[MAXROW][MAXCOL], char Image2[MAXROW][MAXCOL],
	int Nrows, int Ncols)
{
	fprintf(stdout, "\n Optional task 5 - not implemented \n");
	fprintf(fpout1, "\n Optional task 5 - not implemented \n");

		/* YOUR CODE HERE - bonus only */


}/*End of RotR*/
/*************************************************************/
/****** void RdSize(*Nrows,*Ncols) ******/
/*Read from an input file two integers for the number of rows and
	number of columns of the image to be processed*/
void RdSize(int *Nrows, int *Ncols)
{

		/* YOUR CODE HERE */

}/*End of RdSize*/
/*************************************************************/
/****** void RdImage(Image,Nrows,Ncols) ******/
/*Read from an input file the integers describing the image to
	be processed and store the corresponding character in the 2D array*/
void RdImage(char Image1[MAXROW][MAXCOL],int Nrows, int Ncols)
{

		/* YOUR CODE HERE */

}/*End of RdImage*/
/*************************************************************/
/****** void RdDoTask(Image1,Image2,Nrows,Ncols)***/
/*Read integers from an opened input file until EOF, and call
the appropriate stub routine for each task represented*/
int RdDoTask(char Image1[MAXROW][MAXCOL],
			char Image2[MAXROW][MAXCOL],int Nrows, int Ncols)
{

		/* YOUR CODE HERE */

} /*End RdDoTask*/


/*************************************************************/
/*************************************************************/
int main() {

    int	eof;

    /* Initialize a 4x3 char image for testing*/
	int Rsize1 = 4;
	int Csize1 = 3;
	char IM1[MAXROW][MAXCOL] = {{'+', '+', '&'},{'+', '&', '&'},
		{'+', '&', '&'},{'+', '&', '+'}};

	/* these are probably the real declarations you will need */
    int Rsize1, Csize1,	/*image sizes*/
	char IMchr1[MAXROW][MAXCOL]; /*original image*/
	char IMchr2[MAXROW][MAXCOL]; /*resulting image after processing*/

	fprintf(stdout, "Hello:\n");		/*start of program*/

	/*open all input and output files*/
	fpin1 = fopen("A1In.txt", "r");  /* open the file for reading */
	if (fpin1 == NULL) {
		fprintf(stdout, "Cannot open input file - Bye\n");
		return(0); /*if problem, exit program*/
	}

	fpout1 = fopen("A1Out.txt", "w");  /* open the file for writing */
	if (fpout1 == NULL) {
		fprintf(stdout, "Cannot open output file - Bye\n");
	return(0); /*if problem, exit program*/
	}

	/*hello message to screen and output file*/
	fprintf(stdout, "\n Captain Picard - Student Number V00123456 \n");
	fprintf(stdout, "\n File = A1csc230.c	- Fall 2011 \n");
	fprintf(stdout, "\n Welcome to CSC 230, Assignment 1 \n\n");
	fprintf(fpout1, "\n Captain Picard - Student Number V00123456 \n");
	fprintf(fpout1, "\n File = A1csc230.c	- Fall 2011 \n");
	fprintf(fpout1, "\n Welcome to CSC 230, Assignment 1 \n\n");

	fprintf(stdout,"Starting: \n");
	fprintf(fpout1,"Starting: \n");

	/*Read in the sizes for the image*/
	/* call RdSize */
	/*Read in the image*/
	/* call RdImage */

	/*Print the initial image*/
	fprintf(stdout, " Initial IMchr1 contains: \n");
	fprintf(fpout1, " Initial IMchr1 contains: \n");
	/* call PrImage */

	/* read all integers from file until EOF - for each call the
	required stub routine for the image processing task*/
	/* call RdDoTask */

	/* Closure */
	fprintf(stdout, "\n The program is all done - Bye! \n");
	fprintf(fpout1, "\n The program is all done - Bye! \n");

	fclose(fpin1);  /* close the files */
	fclose(fpout1);

	return (0);
}/*End of Main*/

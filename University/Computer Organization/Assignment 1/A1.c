#include <stdio.h>	/* include needed libraries */
#include <stdlib.h>
#include <string.h>
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
    fprintf(stdout, "\n");
    fprintf(fpout1, "\n");
    for(int i = 0; i < Nrows; i++) {
        for(int j = 0; j < Ncols; j++) {
            if(Image[i][j] == '0') {
               	fprintf(stdout, "+ ");
                fprintf(fpout1, "+ ");
            }
            else {
               	fprintf(stdout, "& ");
                fprintf(fpout1, "& ");
            }
        }
       	fprintf(stdout, "\n");
        fprintf(fpout1, "\n");
    }
}/*End of PrImage*/
/*************************************************************/
/****** void VMirror(Image1, Image2, Nrows, Ncols) ******/
/* Given the 2D char array of Image1 and its dimensions,
	construct the vertical mirror image in Image 2 as in:
	copy columns (0,1,...,Ncols-1) of Image1 to
	columns (Ncols-1, Ncols-2, ..., 1, 0) respectively of Image2 */
void VMirror( char Image1[MAXROW][MAXCOL], char Image2[MAXROW][MAXCOL],
	int Nrows, int Ncols)
{
    fprintf(stdout, "TASK 1 = Vertical Mirroring\nIMchr2 contains:\n");
    fprintf(fpout1, "TASK 1 = Vertical Mirroring\nIMchr2 contains:\n");
    for(int i = 0; i < Nrows; i++) {
        for(int j = 0; j < Ncols; j++) {
            Image2[i][Ncols-j-1] = Image1[i][j];
        }
    }

    PrImage(Image2, Nrows, Ncols);
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
    fprintf(stdout, "TASK 2 = Horizontal Mirroring\nIMchr2 contains:\n");
    fprintf(fpout1, "TASK 2 = Horizontal Mirroring\nIMchr2 contains:\n");
    for(int i = 0; i < Nrows; i++) {
        for(int j = 0; j < Ncols; j++) {
            Image2[Nrows-i-1][j] = Image1[i][j];
        }
    }

    PrImage(Image2, Nrows, Ncols);
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
    fprintf(stdout, "TASK 3 = Diagonal Right\nIMchr2 contains:\n");
    fprintf(fpout1, "TASK 3 = Diagonal Right\nIMchr2 contains:\n");
    for(int i = 0; i < Nrows; i++) {
        for(int j = 0; j < Ncols; j++) {
            Image2[j][i] = Image1[i][j];
        }
    }

    PrImage(Image2, Ncols, Nrows);
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
    fprintf(stdout, "TASK 4 = Diagonal Left\nIMchr2 contains:\n");
    fprintf(fpout1, "TASK 4 = Diagonal Left\nIMchr2 contains:\n");
    for(int i = 0; i < Nrows; i++) {
        for(int j = 0; j < Ncols; j++) {
            Image2[Ncols-j-1][Nrows-i-1] = Image1[i][j];
        }
    }

    PrImage(Image2, Ncols, Nrows);
}/*End of DiagL*/
/*************************************************************/
/****** void RotR(Image1, Image2, Nrows, Ncols) ******/
/*Given the 2D char array of Image1 and its dimensions,
	construct the rotated by 90 degree image in Image2 */
void RotR( char Image1[MAXROW][MAXCOL], char Image2[MAXROW][MAXCOL],
	int Nrows, int Ncols)
{
    fprintf(stdout, "TASK 5 = Rotation Right\nIMchr2 contains:\n");
    fprintf(fpout1, "TASK 5 = Rotation Right\nIMchr2 contains:\n");
    for(int i = 0; i < Nrows; i++) {
        for(int j = 0; j < Ncols; j++) {
            Image2[j][Nrows-i-1] = Image1[i][j];
        }
    }

    PrImage(Image2, Ncols, Nrows);
}/*End of RotR*/
/*************************************************************/
/****** void RdSize(*Nrows,*Ncols) ******/
/*Read from an input file two integers for the number of rows and
	number of columns of the image to be processed*/
void RdSize(int *Nrows, int *Ncols)
{
    //Created with set length 1 over so \0 char gets added automatically so array doesnt overflow
    char rows[3] = {getc(fpin1), getc(fpin1)};
    *Nrows = atoi(rows);

    //Created with set length 1 over so \0 char gets added automatically so array doesnt overflow
    char cols[4] = {getc(fpin1)}, ch = getc(fpin1);
    //can sometimes end up with character 'control return', so to prevent that it will skip any character of value 13
    if(ch != '\n' && ch != 13) cols[1] = ch;
    if( (ch = getc(fpin1)) != '\n' && ch != 13) cols[2] = ch;
    *Ncols = atoi(cols);

}/*End of RdSize*/
/*************************************************************/
/****** void RdImage(Image,Nrows,Ncols) ******/
/*Read from an input file the integers describing the image to
	be processed and store the corresponding character in the 2D array*/
void RdImage(char Image1[MAXROW][MAXCOL],int Nrows, int Ncols)
{
    char ch;
    //Goes through each row after every colomn on prev row has been visited
    for(int i = 0; i < Nrows; i++) {
        for(int j = 0; j < Ncols; j++) {
            do
                ch = getc(fpin1);
            //skips any spaces or newline characters so that it doesn't clog up the image data
            while(ch != '1' && ch != '0');
            //if the file's end is reached, stop reading
            if(ch == EOF) break;

            Image1[i][j] = ch;

            ch = getc(fpin1);
        }
        if(ch == EOF) break;
    }
}/*End of RdImage*/
/*************************************************************/
/****** void RdDoTask(Image1,Image2,Nrows,Ncols)***/
/*Read integers from an opened input file until EOF, and call
the appropriate stub routine for each task represented*/
int RdDoTask(char Image1[MAXROW][MAXCOL],
			char Image2[MAXROW][MAXCOL],int Nrows, int Ncols)
{
    char ch;

    do
    {
        do
            ch = getc(fpin1);
        while(ch == ' ' || ch == '\n');
        switch (ch) {
            case '1':
                VMirror(Image1, Image2, Nrows, Ncols);
                break;
            case '2':
                HMirror(Image1, Image2, Nrows, Ncols);
                break;
            case '3':
                DiagR(Image1, Image2, Nrows, Ncols);
                break;
            case '4':
                DiagL(Image1, Image2, Nrows, Ncols);
                break;
            case '5':
                RotR(Image1, Image2, Nrows, Ncols);
                break;
        }
    }
    while(ch != EOF);
    return(0);
} /*End RdDoTask*/


/*************************************************************/
/*************************************************************/
int main() {

    int	eof;

	/* these are probably the real declarations you will need */
    int Rsize1, Csize1;	/*image sizes*/
	char IMchr1[MAXROW][MAXCOL]; /*original image*/
	char IMchr2[MAXROW][MAXCOL]; /*resulting image after processing*/

	fprintf(stdout, "Hello:\n");		/*start of program*/

	char fileName[50];

	fprintf(stdout, "\nWhat is the name of the file you'd like to edit? (Assuming .txt): ");

	scanf("%s", fileName);
	strcat(fileName, ".txt");

	fprintf(stdout, "\n\n\n\n");

	/*open all input and output files*/
	fpin1 = fopen(fileName, "r");  /* open the file for reading */
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
	fprintf(stdout, "Carlton Champion - Student Number 240955 \n");
	fprintf(stdout, "\n File = %s - Fall 2026 \n", fileName);
	fprintf(stdout, "\n Welcome to 62:367, Assignment 1 \n\n");
	fprintf(fpout1, "Carlton Champion - Student Number 240955 \n");
	fprintf(fpout1, "\n File = %s - Fall 2026 \n", fileName);
	fprintf(fpout1, "\n Welcome to 62:367, Assignment 1 \n\n");

	fprintf(stdout,"Starting: \n");
	fprintf(fpout1,"Starting: \n");

	/*Read in the sizes for the image*/
	/* call RdSize */
	RdSize(&Rsize1, &Csize1);
	/*Read in the image*/
	/* call RdImage */
	RdImage(IMchr1, Rsize1, Csize1);

	/*Print the initial image*/
	fprintf(stdout, " Initial IMchr1 contains: \n");
	fprintf(fpout1, " Initial IMchr1 contains: \n");
	/* call PrImage */
	PrImage(IMchr1, Rsize1, Csize1);

	/* read all integers from file until EOF - for each call the
	required stub routine for the image processing task*/
	/* call RdDoTask */
	RdDoTask(IMchr1, IMchr2, Rsize1, Csize1);

	/* Closure */
	fprintf(stdout, "\n The program is all done - Bye! \n");
	fprintf(fpout1, "\n The program is all done - Bye! \n");

	fclose(fpin1);  /* close the files */
	fclose(fpout1);

	return (0);
}/*End of Main*/

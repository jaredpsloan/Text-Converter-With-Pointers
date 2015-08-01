/* -----------------------------------------------------------------------------

Program file:   pointer_example_js.c
Author:         Jared Sloan
Email:          jaredpsloan@gmail.com
Date:           March 12th, 2015 
Objective:     	This program stores a line of text up to 50 characters. Then using
				pointer notation it	converts and displays these characters in three
				separate lines. First in all caps, then in all lower case, and 
				finally in proper sentence grammar rules.
----------------------------------------------------------------------------- */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Prototype for safer_gets */
/*--------------------------*/

void safer_gets (char array[ ], int max_chars);


/* Main Functions */
/*----------------*/

int main(void)
{

    /* Declare variables */
    /* ----------------- */

	char	text[51];
 	char	*text_ptr;
	int 	up;

    /* Prompt user for line of text */
    /* -----------------------------*/

	printf ("\nEnter a line of text (up to 50 characters):\n");
	safer_gets(text,51);
	fflush(stdin);
 

    /* Convert and display the text in uppercase characters. */
    /*------------------------------------------------------*/

    printf ("\nThe line of text in uppercase is:\n");

   	text_ptr = text;
    while (*text_ptr != '\0')  
	{     
		putchar( toupper(*text_ptr++) );
	}
         
    /* Convert and display the text in uppercase characters. */
    /* ---------------------------------------------------- */

    printf ("\n\nThe line of text in lowercase is:\n");

  	text_ptr = text;
    while ( *text_ptr != '\0' )
    {
		putchar( tolower(*text_ptr++) );
    }
    
    /* Convert and display the text in uppercase characters. */
    /* ---------------------------------------------------- */
    
    
  	printf ("\n\nThe line of text in sentence case is:\n");
  	
   	text_ptr = text;
   	/* Up = 1 means that upper case is true based on sentence grammar rules */
	/*----------------------------------------------------------------------*/
   	
  	up = 1;
	while ( *text_ptr!='\0' )     
	{
        
		/* Decision statements to change case based on sentence grammar rules */
        /*--------------------------------------------------------------------*/
        
		if (!up)
        	if (*text_ptr - 1 == ' ' && toupper(*text_ptr) == 'I' &&  *text_ptr + 1 == ' ')
        	up = 1;   
        
        
		if (up)
        	if (*text_ptr != ' ')
        	{
        		putchar(toupper(*text_ptr++));
        		up = 0;
        	}/* end if */
        	
        	else
          	putchar(tolower(*text_ptr++));
 	
        else
        {
			putchar(tolower(*text_ptr));
			if (*text_ptr == '?' || *text_ptr == '.' || *text_ptr == '!')
        	up = 1;
        	*text_ptr++;
        } /* end else*/
    } /* end while*/
    
	putchar('\n');
    
    getchar(); /* To pause output */


} /* End main */


/* Function safer_gets pointer version*/
/*------------------------------------*/

void safer_gets (char array[], int max_chars)
/* Pointer version */

{
	int i;
	char *ptr;
	
	/* Read name from input buffer, character by character, */
	/* up up to the maximum number of characters in the array.*/
	/* */
	
	ptr = array;
	for (i = 0; i < max_chars; i++)
	{
		if((*ptr = getchar()) == '\n') break;
		ptr++;
	}
	
	*ptr = '\0'; /* sets the last position to null */
	fflush(stdin);
	
} /* End function safer_gets */

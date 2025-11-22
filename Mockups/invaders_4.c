/* Ruler 1         2         3         4         5         6         7        */

/* invaders_4.c ***************************************************************/
/*                                                                            */
/*   +----+ +----+                          SPACE INVADERS                    */
/*   ++  ++ ++******                                                          */
/*    |  |   |**  **                                                          */
/*    |  |   | *  *       This code demonstrates the setting methods used     */
/*    |  |   | *  *       to specify attributes in different instances.       */
/*    |******| *  *                                                           */
/*    |**  **| *  *                                                           */
/*    ++*  ** **  *       DEVELOPED BY: Ing. Juan C. Giraldo, Ph.D.           */
/*     +**  ***  **                     jcgiraldo@javeriana.edu.co            */
/*      +**     **                                                            */
/*        *******         Bogota, D.C., October 31st, 2021.                   */
/*                                                                            */
/*          Copyright (C) Department de Electronics                           */
/*                        School of Engineering                               */
/*                        Pontificia Universidad Javeriana                    */
/*                        Bogota - Colombia - South America                   */
/*                                                                            */
/******************************************************************************/

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>

/* ------------------------ Inclusion of Own Headers ------------------------ */

#include "drawings_unicode.h"
#include "conio.h"
#include "alien.h"



/**************************** Symbolic  Constants *****************************/

#define MAX_ALIENS 55



/************************** Definition of Data Types **************************/



/******************************* Main Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Draw instances of aliens.
*
*   Plan:    Part 1: Create instances of aliens in array
*            Part 2: Set attributes according to locations in console
*            Part 3: Draw aliens in consola
*            Part 4: Free all the instances
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 31/2021  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int main()
{
clrscr();
ALIEN_T *alien_vec[MAX_ALIENS];

/* Part 1: Create instances of aliens in array */

for( int i = 0; i < MAX_ALIENS; i++ )
	alien_vec[i] = New_Alien();

/* Part 2: Set attributes according to locations in console */

for( int i = 0; i < 5; i++ )

	for( int j = 0; j < 11; j++ ) {

		if( i == 0 ) {
			Set_Alien_Aspect( alien_vec[i*11 + j], &squid );
			Set_Alien_Color( alien_vec[i*11 + j], RED );
		} else if ( i == 1 || i == 2 ) {
			Set_Alien_Aspect( alien_vec[i*11 + j], &crab );
			Set_Alien_Color( alien_vec[i*11 + j], GREEN );
		} else if ( i == 3 || i == 4 )  {
			Set_Alien_Aspect( alien_vec[i*11 + j], &octopus );
			Set_Alien_Color( alien_vec[i*11 + j], CYAN );
		}

		Set_Alien_Location( alien_vec[i*11 + j], j*9 + 1, i*5 + 1 );

	} /* for j */

/* Part 3: Draw aliens in consola */

for( int i = 0; i < MAX_ALIENS; i++ )
	Draw_Alien( alien_vec[i] );

/* Part 4: Free all the instances */

for( int i = 0; i < MAX_ALIENS; i++ )
	Free_Alien( alien_vec[i] );

return 0;

} /* main */

/* Ruler 1         2         3         4         5         6         7        */

/* invaders_2.c ***************************************************************/
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

#include "drawings_asciiart.h"
#include "conio.h"
#include "alien.h"



/**************************** Symbolic  Constants *****************************/

#define MAX_ALIENS 3



/************************** Definition of Data Types **************************/



/******************************* Main Function ********************************/

/*FN****************************************************************************
*
*   Purpose: This code demonstrates the setting methods used to specify
*            attributes in different instances.
*
*   Plan:    Simple function that does not need a plan description
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
ALIEN_T *alien[MAX_ALIENS];

for( int i = 0; i < MAX_ALIENS; i++ )
	alien[i] = New_Alien();

for( int i = 0; i < MAX_ALIENS; i++ ) {
	Set_Alien_Aspect( alien[i], &crab );
	Set_Alien_Color( alien[i], RED );
	Set_Alien_Location( alien[i], 1, i*7 + 1 );
	Draw_Alien( alien[i] );
}

for( int i = 0; i < MAX_ALIENS; i++ )
	Free_Alien( alien[i] );

return 0;

} /* main */

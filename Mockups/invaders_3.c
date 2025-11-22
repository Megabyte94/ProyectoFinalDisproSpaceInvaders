/* Ruler 1         2         3         4         5         6         7        */

/* invaders_3.c ***************************************************************/
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



/************************** Definition of Data Types **************************/

enum { DAD, MOM, CHILD, MAX_ALIENS };



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

for( int member = 0; member < MAX_ALIENS; member++ )
	alien[member] = New_Alien();

Set_Alien_Aspect( alien[DAD], &squid );
Set_Alien_Color( alien[DAD], RED );
Set_Alien_Location( alien[DAD], 1, 1 );
Draw_Alien( alien[DAD] );

Set_Alien_Aspect( alien[MOM], &crab );
Set_Alien_Color( alien[MOM], GREEN );
Set_Alien_Location( alien[MOM], 21, 1 );
Draw_Alien( alien[MOM] );

Set_Alien_Aspect( alien[CHILD], &octopus );
Set_Alien_Color( alien[CHILD], CYAN );
Set_Alien_Location( alien[CHILD], 41, 1 );
Draw_Alien( alien[CHILD] );

for( int member = 0; member < MAX_ALIENS; member++ )
	Free_Alien( alien[member] );

return 0;

} /* main */

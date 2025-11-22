/* Ruler 1         2         3         4         5         6         7        */

/* invaders_1.c ***************************************************************/
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
ALIEN_T *alien_dad   = New_Alien();
ALIEN_T *alien_mom   = New_Alien();
ALIEN_T *alien_child = New_Alien();

Set_Alien_Aspect( alien_dad, &squid );
Set_Alien_Color( alien_dad, RED );
Set_Alien_Location( alien_dad, 1, 1 );
Draw_Alien( alien_dad );

Set_Alien_Aspect( alien_mom, &crab );
Set_Alien_Color( alien_mom, GREEN );
Set_Alien_Location( alien_mom, 21, 1 );
Draw_Alien( alien_mom );

Set_Alien_Aspect( alien_child, &octopus );
Set_Alien_Color( alien_child, CYAN );
Set_Alien_Location( alien_child, 41, 1 );
Draw_Alien( alien_child );

printf( "\nThree different instances of aliens!\n" );

Free_Alien( alien_dad );
Free_Alien( alien_mom );
Free_Alien( alien_child );

return 0;

} /* main */

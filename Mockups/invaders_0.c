/* Ruler 1         2         3         4         5         6         7        */

/* invaders_0.c ***************************************************************/
/*                                                                            */
/*   +----+ +----+                          SPACE INVADERS                    */
/*   ++  ++ ++******                                                          */
/*    |  |   |**  **                                                          */
/*    |  |   | *  *       This code demonstrates the setting methods used     */
/*    |  |   | *  *       to specify and change attribute to one instance.    */
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



/******************************* Main Function ********************************/

/*FN****************************************************************************
*
*   Purpose: This code demonstrates the setting methods used to specify and
*            change attribute to one instance.
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
ALIEN_T *alien = New_Alien();

Set_Alien_Aspect( alien, &alien1 );
Set_Alien_Color( alien, RED );
Set_Alien_Location( alien, 1, 1 );
Draw_Alien( alien );

Set_Alien_Aspect( alien, &alien2 );
Set_Alien_Color( alien, GREEN );
Set_Alien_Location( alien, 21, 1 );
Draw_Alien( alien );

Set_Alien_Aspect( alien, &alien3 );
Set_Alien_Color( alien, CYAN );
Set_Alien_Location( alien, 41, 1 );
Draw_Alien( alien );

printf( "\nSame alien changing appearance, color and location!\n" );

Free_Alien( alien );

return 0;

} /* main */

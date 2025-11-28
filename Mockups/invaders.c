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

// Draw "SCORE<1>" text at top left
ALIEN_T *score1_S = New_Alien();
Set_Alien_Aspect(score1_S, &S);
Set_Alien_Color(score1_S, CYAN);
Set_Alien_Location(score1_S, 1, 1);
Draw_Alien(score1_S);

ALIEN_T *score1_C = New_Alien();
Set_Alien_Aspect(score1_C, &C);
Set_Alien_Color(score1_C, CYAN);
Set_Alien_Location(score1_C, 5, 1);
Draw_Alien(score1_C);

ALIEN_T *score1_O = New_Alien();
Set_Alien_Aspect(score1_O, &O);
Set_Alien_Color(score1_O, CYAN);
Set_Alien_Location(score1_O, 10, 1);
Draw_Alien(score1_O);

ALIEN_T *score1_R = New_Alien();
Set_Alien_Aspect(score1_R, &R);
Set_Alien_Color(score1_R, CYAN);
Set_Alien_Location(score1_R, 15, 1);
Draw_Alien(score1_R);

ALIEN_T *score1_E = New_Alien();
Set_Alien_Aspect(score1_E, &E);
Set_Alien_Color(score1_E, CYAN);
Set_Alien_Location(score1_E, 20, 1);
Draw_Alien(score1_E);

// Draw numbers "0000" for SCORE<1>
for(int i = 0; i < 4; i++) {
		ALIEN_T *digit = New_Alien();
		Set_Alien_Aspect(digit, &_0);
		Set_Alien_Color(digit, WHITE);
		Set_Alien_Location(digit, 1 + i*5, 7);
		Draw_Alien(digit);
		Free_Alien(digit);
}

// Draw lives counter at top right
ALIEN_T *lives_heart1 = New_Alien();
Set_Alien_Aspect(lives_heart1, &cocoro);
Set_Alien_Color(lives_heart1, RED);
Set_Alien_Location(lives_heart1, 70, 1);
Draw_Alien(lives_heart1);

ALIEN_T *lives_heart2 = New_Alien();
Set_Alien_Aspect(lives_heart2, &cocoro);
Set_Alien_Color(lives_heart2, RED);
Set_Alien_Location(lives_heart2, 76, 1);
Draw_Alien(lives_heart2);

ALIEN_T *lives_heart3 = New_Alien();
Set_Alien_Aspect(lives_heart3, &cocoro);
Set_Alien_Color(lives_heart3, RED);
Set_Alien_Location(lives_heart3, 82, 1);
Draw_Alien(lives_heart3);

// Draw UFO at top
ALIEN_T *ufo_alien = New_Alien();
Set_Alien_Aspect( ufo_alien, &ufo ); 
Set_Alien_Color( ufo_alien, YELLOW );
Set_Alien_Location( ufo_alien, 43, 5 );
Draw_Alien( ufo_alien );

/* Part 2: Set alien matrix attributes */

for( int i = 0; i < 5; i++ )

	for( int j = 0; j < 20; j++ ) {

		if( i == 0 ) {
			Set_Alien_Aspect( alien_vec[i*11 + j], &alien1 );
			Set_Alien_Color( alien_vec[i*11 + j], RED );
		} else if ( i == 1) {
			Set_Alien_Aspect( alien_vec[i*11 + j], &alien2 );
			Set_Alien_Color( alien_vec[i*11 + j], GREEN );
		} else if ( i == 2) {
			Set_Alien_Aspect( alien_vec[i*11 + j], &alien3 );
			Set_Alien_Color( alien_vec[i*11 + j], CYAN );
		} else if ( i == 3) {
			Set_Alien_Aspect( alien_vec[i*11 + j], &alien4 );
			Set_Alien_Color( alien_vec[i*11 + j], BLUE );
		} else if ( i == 4) {
			Set_Alien_Aspect( alien_vec[i*11 + j], &alien5 );
			Set_Alien_Color( alien_vec[i*11 + j], PURPLE );
		}

		Set_Alien_Location( alien_vec[i*11 + j], j*7 + 1, i*7 + 13 );

	} /* for j */

/* Part 3: Draw aliens in consola */

for( int i = 0; i < MAX_ALIENS; i++ )
	Draw_Alien( alien_vec[i] );

/* Part 4: Free all the instances */

Free_Alien(score1_S);
Free_Alien(score1_C);
Free_Alien(score1_O);
Free_Alien(score1_R);
Free_Alien(score1_E);

Free_Alien(lives_heart1);
Free_Alien(lives_heart2);
Free_Alien(lives_heart3);

Free_Alien(ufo_alien); // Corrected to free ufo_alien

return 0;

} /* main */
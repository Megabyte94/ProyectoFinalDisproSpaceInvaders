/* Ruler 1         2         3         4         5         6         7        */

/* game_over.c ****************************************************************/
/*                                                                            */
/*   +----+ +----+                     SPACE INVADERS GAME OVER SCREEN        */
/*   ++  ++ ++******                                                          */
/*    |  |   |**  **                                                          */
/*    |  |   | *  *       This code displays the game over screen for         */
/*    |  |   | *  *       Space Invaders game with options to play again      */
/*    |******| *  *       or quit.                                            */
/*    |**  **| *  *                                                           */
/*    ++*  ** **  *       DEVELOPED BY: Ing. Juan C. Giraldo, Ph.D.           */
/*     +**  ***  **                     jcgiraldo@javeriana.edu.co            */
/*      +**     **                                                            */
/*        *******         Modified: November 22nd, 2025.                      */
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



/******************************* Main Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Display the game over screen for Space Invaders game
*
*   Plan:    Part 1: Display "GAME OVER" title in red
*            Part 2: Display "PRESS ENTER TO PLAY" message
*            Part 3: Display "OR" 
*            Part 4: Display "PRESS ANY TO QUIT" message
*            Part 5: Free all the instances
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 31/2021  J.C.Giraldo  Initial implementation
*   Nov 22/2025  Modified     Game over screen implementation
*
*******************************************************************************/

int main()
{
clrscr();

/* Part 1: Display "GAME OVER" title in red */

int title_row = 8;
int title_col = 25;

// GAME - First line
// G
ALIEN_T *title_G = New_Alien();
Set_Alien_Aspect(title_G, &G);
Set_Alien_Color(title_G, RED);
Set_Alien_Location(title_G, title_col, title_row);
Draw_Alien(title_G);

// A
ALIEN_T *title_A = New_Alien();
Set_Alien_Aspect(title_A, &A);
Set_Alien_Color(title_A, RED);
Set_Alien_Location(title_A, title_col + 5, title_row);
Draw_Alien(title_A);

// M
ALIEN_T *title_M = New_Alien();
Set_Alien_Aspect(title_M, &M);
Set_Alien_Color(title_M, RED);
Set_Alien_Location(title_M, title_col + 10, title_row);
Draw_Alien(title_M);

// E
ALIEN_T *title_E = New_Alien();
Set_Alien_Aspect(title_E, &E);
Set_Alien_Color(title_E, RED);
Set_Alien_Location(title_E, title_col + 15, title_row);
Draw_Alien(title_E);

// OVER - Second line
int title_row2 = title_row + 7;

// O
ALIEN_T *title_O = New_Alien();
Set_Alien_Aspect(title_O, &O);
Set_Alien_Color(title_O, RED);
Set_Alien_Location(title_O, title_col + 5, title_row2);
Draw_Alien(title_O);

// V
ALIEN_T *title_V = New_Alien();
Set_Alien_Aspect(title_V, &V);
Set_Alien_Color(title_V, RED);
Set_Alien_Location(title_V, title_col + 10, title_row2);
Draw_Alien(title_V);

// E
ALIEN_T *title_E2 = New_Alien();
Set_Alien_Aspect(title_E2, &E);
Set_Alien_Color(title_E2, RED);
Set_Alien_Location(title_E2, title_col + 15, title_row2);
Draw_Alien(title_E2);

// R
ALIEN_T *title_R = New_Alien();
Set_Alien_Aspect(title_R, &R);
Set_Alien_Color(title_R, RED);
Set_Alien_Location(title_R, title_col + 20, title_row2);
Draw_Alien(title_R);

/* Part 2: Display "PRESS ENTER TO PLAY" message in white */

int msg_row = title_row2 + 12;
int msg_col = 25;

// PRESS
// P
ALIEN_T *msg_P = New_Alien();
Set_Alien_Aspect(msg_P, &P);
Set_Alien_Color(msg_P, WHITE);
Set_Alien_Location(msg_P, msg_col, msg_row);
Draw_Alien(msg_P);

// R
ALIEN_T *msg_R = New_Alien();
Set_Alien_Aspect(msg_R, &R);
Set_Alien_Color(msg_R, WHITE);
Set_Alien_Location(msg_R, msg_col + 5, msg_row);
Draw_Alien(msg_R);

// E
ALIEN_T *msg_E1 = New_Alien();
Set_Alien_Aspect(msg_E1, &E);
Set_Alien_Color(msg_E1, WHITE);
Set_Alien_Location(msg_E1, msg_col + 10, msg_row);
Draw_Alien(msg_E1);

// S
ALIEN_T *msg_S1 = New_Alien();
Set_Alien_Aspect(msg_S1, &S);
Set_Alien_Color(msg_S1, WHITE);
Set_Alien_Location(msg_S1, msg_col + 15, msg_row);
Draw_Alien(msg_S1);

// S
ALIEN_T *msg_S2 = New_Alien();
Set_Alien_Aspect(msg_S2, &S);
Set_Alien_Color(msg_S2, WHITE);
Set_Alien_Location(msg_S2, msg_col + 20, msg_row);
Draw_Alien(msg_S2);

// ENTER
int msg_row2 = msg_row + 7;

// E
ALIEN_T *msg_E2 = New_Alien();
Set_Alien_Aspect(msg_E2, &E);
Set_Alien_Color(msg_E2, WHITE);
Set_Alien_Location(msg_E2, msg_col, msg_row2);
Draw_Alien(msg_E2);

// N
ALIEN_T *msg_N = New_Alien();
Set_Alien_Aspect(msg_N, &N);
Set_Alien_Color(msg_N, WHITE);
Set_Alien_Location(msg_N, msg_col + 5, msg_row2);
Draw_Alien(msg_N);

// T
ALIEN_T *msg_T = New_Alien();
Set_Alien_Aspect(msg_T, &T);
Set_Alien_Color(msg_T, WHITE);
Set_Alien_Location(msg_T, msg_col + 10, msg_row2);
Draw_Alien(msg_T);

// E
ALIEN_T *msg_E3 = New_Alien();
Set_Alien_Aspect(msg_E3, &E);
Set_Alien_Color(msg_E3, WHITE);
Set_Alien_Location(msg_E3, msg_col + 15, msg_row2);
Draw_Alien(msg_E3);

// R
ALIEN_T *msg_R2 = New_Alien();
Set_Alien_Aspect(msg_R2, &R);
Set_Alien_Color(msg_R2, WHITE);
Set_Alien_Location(msg_R2, msg_col + 20, msg_row2);
Draw_Alien(msg_R2);

// TO
int msg_row3 = msg_row2 + 7;

// T
ALIEN_T *msg_T2 = New_Alien();
Set_Alien_Aspect(msg_T2, &T);
Set_Alien_Color(msg_T2, WHITE);
Set_Alien_Location(msg_T2, msg_col, msg_row3);
Draw_Alien(msg_T2);

// O
ALIEN_T *msg_O = New_Alien();
Set_Alien_Aspect(msg_O, &O);
Set_Alien_Color(msg_O, WHITE);
Set_Alien_Location(msg_O, msg_col + 5, msg_row3);
Draw_Alien(msg_O);

// PLAY
int msg_row4 = msg_row3 + 7;

// P
ALIEN_T *msg_P2 = New_Alien();
Set_Alien_Aspect(msg_P2, &P);
Set_Alien_Color(msg_P2, WHITE);
Set_Alien_Location(msg_P2, msg_col, msg_row4);
Draw_Alien(msg_P2);

// I (usando I como L)
ALIEN_T *msg_L = New_Alien();
Set_Alien_Aspect(msg_L, &I);
Set_Alien_Color(msg_L, WHITE);
Set_Alien_Location(msg_L, msg_col + 5, msg_row4);
Draw_Alien(msg_L);

// A
ALIEN_T *msg_A = New_Alien();
Set_Alien_Aspect(msg_A, &A);
Set_Alien_Color(msg_A, WHITE);
Set_Alien_Location(msg_A, msg_col + 10, msg_row4);
Draw_Alien(msg_A);

// Y (usando z como Y)
ALIEN_T *msg_Y = New_Alien();
Set_Alien_Aspect(msg_Y, &z);
Set_Alien_Color(msg_Y, WHITE);
Set_Alien_Location(msg_Y, msg_col + 15, msg_row4);
Draw_Alien(msg_Y);

/* Part 3: Display "OR" */

int or_row = msg_row4 + 7;

// O
ALIEN_T *or_O = New_Alien();
Set_Alien_Aspect(or_O, &O);
Set_Alien_Color(or_O, WHITE);
Set_Alien_Location(or_O, 38, or_row);
Draw_Alien(or_O);

// R (using K as approximation since no lowercase available)
ALIEN_T *or_R = New_Alien();
Set_Alien_Aspect(or_R, &R);
Set_Alien_Color(or_R, WHITE);
Set_Alien_Location(or_R, 43, or_row);
Draw_Alien(or_R);

/* Part 4: Display "PRESS ANY TO QUIT" message */

int quit_row = or_row + 7;
int quit_col = 25;

// PRESS
// P
ALIEN_T *quit_P = New_Alien();
Set_Alien_Aspect(quit_P, &P);
Set_Alien_Color(quit_P, WHITE);
Set_Alien_Location(quit_P, quit_col, quit_row);
Draw_Alien(quit_P);

// R
ALIEN_T *quit_R = New_Alien();
Set_Alien_Aspect(quit_R, &R);
Set_Alien_Color(quit_R, WHITE);
Set_Alien_Location(quit_R, quit_col + 5, quit_row);
Draw_Alien(quit_R);

// E
ALIEN_T *quit_E1 = New_Alien();
Set_Alien_Aspect(quit_E1, &E);
Set_Alien_Color(quit_E1, WHITE);
Set_Alien_Location(quit_E1, quit_col + 10, quit_row);
Draw_Alien(quit_E1);

// S
ALIEN_T *quit_S1 = New_Alien();
Set_Alien_Aspect(quit_S1, &S);
Set_Alien_Color(quit_S1, WHITE);
Set_Alien_Location(quit_S1, quit_col + 15, quit_row);
Draw_Alien(quit_S1);

// S
ALIEN_T *quit_S2 = New_Alien();
Set_Alien_Aspect(quit_S2, &S);
Set_Alien_Color(quit_S2, WHITE);
Set_Alien_Location(quit_S2, quit_col + 20, quit_row);
Draw_Alien(quit_S2);

// ANY
int quit_row2 = quit_row + 7;

// A
ALIEN_T *quit_A = New_Alien();
Set_Alien_Aspect(quit_A, &A);
Set_Alien_Color(quit_A, WHITE);
Set_Alien_Location(quit_A, quit_col, quit_row2);
Draw_Alien(quit_A);

// N
ALIEN_T *quit_N = New_Alien();
Set_Alien_Aspect(quit_N, &N);
Set_Alien_Color(quit_N, WHITE);
Set_Alien_Location(quit_N, quit_col + 5, quit_row2);
Draw_Alien(quit_N);

// Y (usando z como Y)
ALIEN_T *quit_Y = New_Alien();
Set_Alien_Aspect(quit_Y, &z);
Set_Alien_Color(quit_Y, WHITE);
Set_Alien_Location(quit_Y, quit_col + 10, quit_row2);
Draw_Alien(quit_Y);

// TO
int quit_row3 = quit_row2 + 7;

// T
ALIEN_T *quit_T = New_Alien();
Set_Alien_Aspect(quit_T, &T);
Set_Alien_Color(quit_T, WHITE);
Set_Alien_Location(quit_T, quit_col, quit_row3);
Draw_Alien(quit_T);

// O
ALIEN_T *quit_O = New_Alien();
Set_Alien_Aspect(quit_O, &O);
Set_Alien_Color(quit_O, WHITE);
Set_Alien_Location(quit_O, quit_col + 5, quit_row3);
Draw_Alien(quit_O);

// QUIT
int quit_row4 = quit_row3 + 7;

// Q
ALIEN_T *quit_Q = New_Alien();
Set_Alien_Aspect(quit_Q, &Q);
Set_Alien_Color(quit_Q, WHITE);
Set_Alien_Location(quit_Q, quit_col, quit_row4);
Draw_Alien(quit_Q);

// U
ALIEN_T *quit_U = New_Alien();
Set_Alien_Aspect(quit_U, &U);
Set_Alien_Color(quit_U, WHITE);
Set_Alien_Location(quit_U, quit_col + 5, quit_row4);
Draw_Alien(quit_U);

// I
ALIEN_T *quit_I = New_Alien();
Set_Alien_Aspect(quit_I, &I);
Set_Alien_Color(quit_I, WHITE);
Set_Alien_Location(quit_I, quit_col + 10, quit_row4);
Draw_Alien(quit_I);

// T
ALIEN_T *quit_T2 = New_Alien();
Set_Alien_Aspect(quit_T2, &T);
Set_Alien_Color(quit_T2, WHITE);
Set_Alien_Location(quit_T2, quit_col + 15, quit_row4);
Draw_Alien(quit_T2);

/* Part 5: Free all instances */

// Free title
Free_Alien(title_G);
Free_Alien(title_A);
Free_Alien(title_M);
Free_Alien(title_E);
Free_Alien(title_O);
Free_Alien(title_V);
Free_Alien(title_E2);
Free_Alien(title_R);

// Free "PRESS ENTER TO PLAY" message
Free_Alien(msg_P);
Free_Alien(msg_R);
Free_Alien(msg_E1);
Free_Alien(msg_S1);
Free_Alien(msg_S2);
Free_Alien(msg_E2);
Free_Alien(msg_N);
Free_Alien(msg_T);
Free_Alien(msg_E3);
Free_Alien(msg_R2);
Free_Alien(msg_T2);
Free_Alien(msg_O);
Free_Alien(msg_P2);
Free_Alien(msg_L);
Free_Alien(msg_A);
Free_Alien(msg_Y);

// Free OR
Free_Alien(or_O);
Free_Alien(or_R);

// Free "PRESS ANY TO QUIT" message
Free_Alien(quit_P);
Free_Alien(quit_R);
Free_Alien(quit_E1);
Free_Alien(quit_S1);
Free_Alien(quit_S2);
Free_Alien(quit_A);
Free_Alien(quit_N);
Free_Alien(quit_Y);
Free_Alien(quit_T);
Free_Alien(quit_O);
Free_Alien(quit_Q);
Free_Alien(quit_U);
Free_Alien(quit_I);
Free_Alien(quit_T2);

return 0;

} /* main */
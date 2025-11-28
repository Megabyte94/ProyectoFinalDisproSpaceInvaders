/* Ruler 1         2         3         4         5         6         7        */

/* start.c ********************************************************************/
/*                                                                            */
/*   +----+ +----+                     SPACE INVADERS START SCREEN            */
/*   ++  ++ ++******                                                          */
/*    |  |   |**  **                                                          */
/*    |  |   | *  *       This code displays the start screen for the         */
/*    |  |   | *  *       Space Invaders game with title, instructions        */
/*    |******| *  *       and score advance table.                            */
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
*   Purpose: Display the start screen for Space Invaders game
*
*   Plan:    Part 1: Display "SPACE INVADERS" title
*            Part 2: Display "PRESS ENTER TO PLAY" message
*            Part 3: Display score advance table with aliens and points
*            Part 4: Free all the instances
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 31/2021  J.C.Giraldo  Initial implementation
*   Nov 22/2025  Modified     Start screen implementation
*
*******************************************************************************/

int main()
{
clrscr();

/* Part 1: Display "SPACE INVADERS" title in green */

// Row positions for centering the title (approximately at column 15)
int title_row = 3;
int title_col = 15;

// S
ALIEN_T *title_S = New_Alien();
Set_Alien_Aspect(title_S, &S);
Set_Alien_Color(title_S, GREEN);
Set_Alien_Location(title_S, title_col, title_row);
Draw_Alien(title_S);

// P
ALIEN_T *title_P = New_Alien();
Set_Alien_Aspect(title_P, &P);
Set_Alien_Color(title_P, GREEN);
Set_Alien_Location(title_P, title_col + 5, title_row);
Draw_Alien(title_P);

// A
ALIEN_T *title_A1 = New_Alien();
Set_Alien_Aspect(title_A1, &A);
Set_Alien_Color(title_A1, GREEN);
Set_Alien_Location(title_A1, title_col + 10, title_row);
Draw_Alien(title_A1);

// C
ALIEN_T *title_C = New_Alien();
Set_Alien_Aspect(title_C, &C);
Set_Alien_Color(title_C, GREEN);
Set_Alien_Location(title_C, title_col + 15, title_row);
Draw_Alien(title_C);

// E
ALIEN_T *title_E1 = New_Alien();
Set_Alien_Aspect(title_E1, &E);
Set_Alien_Color(title_E1, GREEN);
Set_Alien_Location(title_E1, title_col + 20, title_row);
Draw_Alien(title_E1);

// Second row: INVADERS
int title_row2 = title_row + 7;

// I
ALIEN_T *title_I = New_Alien();
Set_Alien_Aspect(title_I, &I);
Set_Alien_Color(title_I, GREEN);
Set_Alien_Location(title_I, title_col, title_row2);
Draw_Alien(title_I);

// N
ALIEN_T *title_N = New_Alien();
Set_Alien_Aspect(title_N, &N);
Set_Alien_Color(title_N, GREEN);
Set_Alien_Location(title_N, title_col + 5, title_row2);
Draw_Alien(title_N);

// V
ALIEN_T *title_V = New_Alien();
Set_Alien_Aspect(title_V, &V);
Set_Alien_Color(title_V, GREEN);
Set_Alien_Location(title_V, title_col + 10, title_row2);
Draw_Alien(title_V);

// A
ALIEN_T *title_A2 = New_Alien();
Set_Alien_Aspect(title_A2, &A);
Set_Alien_Color(title_A2, GREEN);
Set_Alien_Location(title_A2, title_col + 15, title_row2);
Draw_Alien(title_A2);

// D
ALIEN_T *title_D = New_Alien();
Set_Alien_Aspect(title_D, &D);
Set_Alien_Color(title_D, GREEN);
Set_Alien_Location(title_D, title_col + 20, title_row2);
Draw_Alien(title_D);

// E
ALIEN_T *title_E2 = New_Alien();
Set_Alien_Aspect(title_E2, &E);
Set_Alien_Color(title_E2, GREEN);
Set_Alien_Location(title_E2, title_col + 25, title_row2);
Draw_Alien(title_E2);

// R
ALIEN_T *title_R = New_Alien();
Set_Alien_Aspect(title_R, &R);
Set_Alien_Color(title_R, GREEN);
Set_Alien_Location(title_R, title_col + 30, title_row2);
Draw_Alien(title_R);

// S
ALIEN_T *title_S2 = New_Alien();
Set_Alien_Aspect(title_S2, &S);
Set_Alien_Color(title_S2, GREEN);
Set_Alien_Location(title_S2, title_col + 35, title_row2);
Draw_Alien(title_S2);
Set_Alien_Location(title_S2, title_col + 35, title_row2);
Draw_Alien(title_S2);

/* Part 2: Display "PRESS ENTER TO PLAY" message in white */

int msg_row = title_row2 + 9;
int msg_col = 30;

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

/* Part 3: Display score advance table */

int table_row = msg_row4 + 10;
int table_col = 18;

// Display decorative stars
ALIEN_T *star1 = New_Alien();
Set_Alien_Aspect(star1, &piupiu);
Set_Alien_Color(star1, WHITE);
Set_Alien_Location(star1, table_col, table_row);
Draw_Alien(star1);

// SCORE
// S
ALIEN_T *table_S = New_Alien();
Set_Alien_Aspect(table_S, &S);
Set_Alien_Color(table_S, WHITE);
Set_Alien_Location(table_S, table_col + 7, table_row);
Draw_Alien(table_S);

// C
ALIEN_T *table_C = New_Alien();
Set_Alien_Aspect(table_C, &C);
Set_Alien_Color(table_C, WHITE);
Set_Alien_Location(table_C, table_col + 12, table_row);
Draw_Alien(table_C);

// O
ALIEN_T *table_O = New_Alien();
Set_Alien_Aspect(table_O, &O);
Set_Alien_Color(table_O, WHITE);
Set_Alien_Location(table_O, table_col + 17, table_row);
Draw_Alien(table_O);

// R
ALIEN_T *table_R = New_Alien();
Set_Alien_Aspect(table_R, &R);
Set_Alien_Color(table_R, WHITE);
Set_Alien_Location(table_R, table_col + 22, table_row);
Draw_Alien(table_R);

// E
ALIEN_T *table_E = New_Alien();
Set_Alien_Aspect(table_E, &E);
Set_Alien_Color(table_E, WHITE);
Set_Alien_Location(table_E, table_col + 27, table_row);
Draw_Alien(table_E);

// ADVANCE
int table_row2 = table_row + 7;

// A
ALIEN_T *adv_A = New_Alien();
Set_Alien_Aspect(adv_A, &A);
Set_Alien_Color(adv_A, WHITE);
Set_Alien_Location(adv_A, table_col + 7, table_row2);
Draw_Alien(adv_A);

// D
ALIEN_T *adv_D = New_Alien();
Set_Alien_Aspect(adv_D, &D);
Set_Alien_Color(adv_D, WHITE);
Set_Alien_Location(adv_D, table_col + 12, table_row2);
Draw_Alien(adv_D);

// V
ALIEN_T *adv_V = New_Alien();
Set_Alien_Aspect(adv_V, &V);
Set_Alien_Color(adv_V, WHITE);
Set_Alien_Location(adv_V, table_col + 17, table_row2);
Draw_Alien(adv_V);

// A
ALIEN_T *adv_A2 = New_Alien();
Set_Alien_Aspect(adv_A2, &A);
Set_Alien_Color(adv_A2, WHITE);
Set_Alien_Location(adv_A2, table_col + 22, table_row2);
Draw_Alien(adv_A2);

// N
ALIEN_T *adv_N = New_Alien();
Set_Alien_Aspect(adv_N, &N);
Set_Alien_Color(adv_N, WHITE);
Set_Alien_Location(adv_N, table_col + 27, table_row2);
Draw_Alien(adv_N);

// C
ALIEN_T *adv_C = New_Alien();
Set_Alien_Aspect(adv_C, &C);
Set_Alien_Color(adv_C, WHITE);
Set_Alien_Location(adv_C, table_col + 32, table_row2);
Draw_Alien(adv_C);

// E
ALIEN_T *adv_E = New_Alien();
Set_Alien_Aspect(adv_E, &E);
Set_Alien_Color(adv_E, WHITE);
Set_Alien_Location(adv_E, table_col + 37, table_row2);
Draw_Alien(adv_E);

// TABLE
int table_row3 = table_row2 + 7;

// T
ALIEN_T *tbl_T = New_Alien();
Set_Alien_Aspect(tbl_T, &T);
Set_Alien_Color(tbl_T, WHITE);
Set_Alien_Location(tbl_T, table_col + 12, table_row3);
Draw_Alien(tbl_T);

// A
ALIEN_T *tbl_A = New_Alien();
Set_Alien_Aspect(tbl_A, &A);
Set_Alien_Color(tbl_A, WHITE);
Set_Alien_Location(tbl_A, table_col + 17, table_row3);
Draw_Alien(tbl_A);

// B
ALIEN_T *tbl_B = New_Alien();
Set_Alien_Aspect(tbl_B, &B);
Set_Alien_Color(tbl_B, WHITE);
Set_Alien_Location(tbl_B, table_col + 22, table_row3);
Draw_Alien(tbl_B);

// I (using I as placeholder for L)
ALIEN_T *tbl_I = New_Alien();
Set_Alien_Aspect(tbl_I, &I);
Set_Alien_Color(tbl_I, WHITE);
Set_Alien_Location(tbl_I, table_col + 27, table_row3);
Draw_Alien(tbl_I);

// E
ALIEN_T *tbl_E = New_Alien();
Set_Alien_Aspect(tbl_E, &E);
Set_Alien_Color(tbl_E, WHITE);
Set_Alien_Location(tbl_E, table_col + 32, table_row3);
Draw_Alien(tbl_E);

// Star
ALIEN_T *star2 = New_Alien();
Set_Alien_Aspect(star2, &piupiu);
Set_Alien_Color(star2, WHITE);
Set_Alien_Location(star2, table_col + 42, table_row);
Draw_Alien(star2);

/* Display aliens with their point values */

int aliens_row = table_row3 + 8;

// UFO = ? MISTERY
ALIEN_T *ufo_display = New_Alien();
Set_Alien_Aspect(ufo_display, &ufo);
Set_Alien_Color(ufo_display, RED);
Set_Alien_Location(ufo_display, 35, aliens_row);
Draw_Alien(ufo_display);

// "= ? MISTERY"
ALIEN_T *eq1 = New_Alien();
Set_Alien_Aspect(eq1, &_exclamationMark);
Set_Alien_Color(eq1, WHITE);
Set_Alien_Location(eq1, 42, aliens_row + 2);
Draw_Alien(eq1);

// M
ALIEN_T *mist_M = New_Alien();
Set_Alien_Aspect(mist_M, &M);
Set_Alien_Color(mist_M, WHITE);
Set_Alien_Location(mist_M, 48, aliens_row + 1);
Draw_Alien(mist_M);

// I
ALIEN_T *mist_I = New_Alien();
Set_Alien_Aspect(mist_I, &I);
Set_Alien_Color(mist_I, WHITE);
Set_Alien_Location(mist_I, 53, aliens_row + 1);
Draw_Alien(mist_I);

// S
ALIEN_T *mist_S = New_Alien();
Set_Alien_Aspect(mist_S, &S);
Set_Alien_Color(mist_S, WHITE);
Set_Alien_Location(mist_S, 58, aliens_row + 1);
Draw_Alien(mist_S);

// T
ALIEN_T *mist_T = New_Alien();
Set_Alien_Aspect(mist_T, &T);
Set_Alien_Color(mist_T, WHITE);
Set_Alien_Location(mist_T, 63, aliens_row + 1);
Draw_Alien(mist_T);

// E
ALIEN_T *mist_E = New_Alien();
Set_Alien_Aspect(mist_E, &E);
Set_Alien_Color(mist_E, WHITE);
Set_Alien_Location(mist_E, 68, aliens_row + 1);
Draw_Alien(mist_E);

// R
ALIEN_T *mist_R = New_Alien();
Set_Alien_Aspect(mist_R, &R);
Set_Alien_Color(mist_R, WHITE);
Set_Alien_Location(mist_R, 73, aliens_row + 1);
Draw_Alien(mist_R);

// Alien5 = 30 POINTS
aliens_row += 7;

ALIEN_T *alien5_display = New_Alien();
Set_Alien_Aspect(alien5_display, &alien5);
Set_Alien_Color(alien5_display, GREEN);
Set_Alien_Location(alien5_display, 35, aliens_row);
Draw_Alien(alien5_display);

// "=30 POINTS"
ALIEN_T *eq2 = New_Alien();
Set_Alien_Aspect(eq2, &_exclamationMark);
Set_Alien_Color(eq2, WHITE);
Set_Alien_Location(eq2, 42, aliens_row + 2);
Draw_Alien(eq2);

ALIEN_T *pts30_3 = New_Alien();
Set_Alien_Aspect(pts30_3, &_3);
Set_Alien_Color(pts30_3, WHITE);
Set_Alien_Location(pts30_3, 45, aliens_row + 1);
Draw_Alien(pts30_3);

ALIEN_T *pts30_0 = New_Alien();
Set_Alien_Aspect(pts30_0, &_0);
Set_Alien_Color(pts30_0, WHITE);
Set_Alien_Location(pts30_0, 50, aliens_row + 1);
Draw_Alien(pts30_0);

// P
ALIEN_T *pts30_P = New_Alien();
Set_Alien_Aspect(pts30_P, &P);
Set_Alien_Color(pts30_P, WHITE);
Set_Alien_Location(pts30_P, 56, aliens_row + 1);
Draw_Alien(pts30_P);

// O
ALIEN_T *pts30_O = New_Alien();
Set_Alien_Aspect(pts30_O, &O);
Set_Alien_Color(pts30_O, WHITE);
Set_Alien_Location(pts30_O, 61, aliens_row + 1);
Draw_Alien(pts30_O);

// I
ALIEN_T *pts30_I = New_Alien();
Set_Alien_Aspect(pts30_I, &I);
Set_Alien_Color(pts30_I, WHITE);
Set_Alien_Location(pts30_I, 66, aliens_row + 1);
Draw_Alien(pts30_I);

// N
ALIEN_T *pts30_N = New_Alien();
Set_Alien_Aspect(pts30_N, &N);
Set_Alien_Color(pts30_N, WHITE);
Set_Alien_Location(pts30_N, 71, aliens_row + 1);
Draw_Alien(pts30_N);

// T
ALIEN_T *pts30_T = New_Alien();
Set_Alien_Aspect(pts30_T, &T);
Set_Alien_Color(pts30_T, WHITE);
Set_Alien_Location(pts30_T, 76, aliens_row + 1);
Draw_Alien(pts30_T);

// S
ALIEN_T *pts30_S = New_Alien();
Set_Alien_Aspect(pts30_S, &S);
Set_Alien_Color(pts30_S, WHITE);
Set_Alien_Location(pts30_S, 81, aliens_row + 1);
Draw_Alien(pts30_S);

// Alien3 = 20 POINTS
aliens_row += 7;

ALIEN_T *alien3_display = New_Alien();
Set_Alien_Aspect(alien3_display, &alien3);
Set_Alien_Color(alien3_display, CYAN);
Set_Alien_Location(alien3_display, 35, aliens_row);
Draw_Alien(alien3_display);

// "=20 POINTS"
ALIEN_T *eq3 = New_Alien();
Set_Alien_Aspect(eq3, &_exclamationMark);
Set_Alien_Color(eq3, WHITE);
Set_Alien_Location(eq3, 42, aliens_row + 2);
Draw_Alien(eq3);

ALIEN_T *pts20_2 = New_Alien();
Set_Alien_Aspect(pts20_2, &_2);
Set_Alien_Color(pts20_2, WHITE);
Set_Alien_Location(pts20_2, 45, aliens_row + 1);
Draw_Alien(pts20_2);

ALIEN_T *pts20_0 = New_Alien();
Set_Alien_Aspect(pts20_0, &_0);
Set_Alien_Color(pts20_0, WHITE);
Set_Alien_Location(pts20_0, 50, aliens_row + 1);
Draw_Alien(pts20_0);

// P
ALIEN_T *pts20_P = New_Alien();
Set_Alien_Aspect(pts20_P, &P);
Set_Alien_Color(pts20_P, WHITE);
Set_Alien_Location(pts20_P, 56, aliens_row + 1);
Draw_Alien(pts20_P);

// O
ALIEN_T *pts20_O = New_Alien();
Set_Alien_Aspect(pts20_O, &O);
Set_Alien_Color(pts20_O, WHITE);
Set_Alien_Location(pts20_O, 61, aliens_row + 1);
Draw_Alien(pts20_O);

// I
ALIEN_T *pts20_I = New_Alien();
Set_Alien_Aspect(pts20_I, &I);
Set_Alien_Color(pts20_I, WHITE);
Set_Alien_Location(pts20_I, 66, aliens_row + 1);
Draw_Alien(pts20_I);

// N
ALIEN_T *pts20_N = New_Alien();
Set_Alien_Aspect(pts20_N, &N);
Set_Alien_Color(pts20_N, WHITE);
Set_Alien_Location(pts20_N, 71, aliens_row + 1);
Draw_Alien(pts20_N);

// T
ALIEN_T *pts20_T = New_Alien();
Set_Alien_Aspect(pts20_T, &T);
Set_Alien_Color(pts20_T, WHITE);
Set_Alien_Location(pts20_T, 76, aliens_row + 1);
Draw_Alien(pts20_T);

// S
ALIEN_T *pts20_S = New_Alien();
Set_Alien_Aspect(pts20_S, &S);
Set_Alien_Color(pts20_S, WHITE);
Set_Alien_Location(pts20_S, 81, aliens_row + 1);
Draw_Alien(pts20_S);

// Alien1 = 10 POINTS
aliens_row += 7;

ALIEN_T *alien1_display = New_Alien();
Set_Alien_Aspect(alien1_display, &alien1);
Set_Alien_Color(alien1_display, PURPLE);
Set_Alien_Location(alien1_display, 35, aliens_row);
Draw_Alien(alien1_display);

// "=10 POINTS"
ALIEN_T *eq4 = New_Alien();
Set_Alien_Aspect(eq4, &_exclamationMark);
Set_Alien_Color(eq4, WHITE);
Set_Alien_Location(eq4, 42, aliens_row + 2);
Draw_Alien(eq4);

ALIEN_T *pts10_1 = New_Alien();
Set_Alien_Aspect(pts10_1, &_1);
Set_Alien_Color(pts10_1, WHITE);
Set_Alien_Location(pts10_1, 45, aliens_row + 1);
Draw_Alien(pts10_1);

ALIEN_T *pts10_0 = New_Alien();
Set_Alien_Aspect(pts10_0, &_0);
Set_Alien_Color(pts10_0, WHITE);
Set_Alien_Location(pts10_0, 50, aliens_row + 1);
Draw_Alien(pts10_0);

// P
ALIEN_T *pts10_P = New_Alien();
Set_Alien_Aspect(pts10_P, &P);
Set_Alien_Color(pts10_P, WHITE);
Set_Alien_Location(pts10_P, 56, aliens_row + 1);
Draw_Alien(pts10_P);

// O
ALIEN_T *pts10_O = New_Alien();
Set_Alien_Aspect(pts10_O, &O);
Set_Alien_Color(pts10_O, WHITE);
Set_Alien_Location(pts10_O, 61, aliens_row + 1);
Draw_Alien(pts10_O);

// I
ALIEN_T *pts10_I = New_Alien();
Set_Alien_Aspect(pts10_I, &I);
Set_Alien_Color(pts10_I, WHITE);
Set_Alien_Location(pts10_I, 66, aliens_row + 1);
Draw_Alien(pts10_I);

// N
ALIEN_T *pts10_N = New_Alien();
Set_Alien_Aspect(pts10_N, &N);
Set_Alien_Color(pts10_N, WHITE);
Set_Alien_Location(pts10_N, 71, aliens_row + 1);
Draw_Alien(pts10_N);

// T
ALIEN_T *pts10_T = New_Alien();
Set_Alien_Aspect(pts10_T, &T);
Set_Alien_Color(pts10_T, WHITE);
Set_Alien_Location(pts10_T, 76, aliens_row + 1);
Draw_Alien(pts10_T);

// S
ALIEN_T *pts10_S = New_Alien();
Set_Alien_Aspect(pts10_S, &S);
Set_Alien_Color(pts10_S, WHITE);
Set_Alien_Location(pts10_S, 81, aliens_row + 1);
Draw_Alien(pts10_S);

/* Part 4: Free all instances */

// Free title
Free_Alien(title_S);
Free_Alien(title_P);
Free_Alien(title_A1);
Free_Alien(title_C);
Free_Alien(title_E1);
Free_Alien(title_I);
Free_Alien(title_N);
Free_Alien(title_V);
Free_Alien(title_A2);
Free_Alien(title_D);
Free_Alien(title_E2);
Free_Alien(title_R);
Free_Alien(title_S2);

// Free message
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

// Free table text
Free_Alien(star1);
Free_Alien(table_S);
Free_Alien(table_C);
Free_Alien(table_O);
Free_Alien(table_R);
Free_Alien(table_E);
Free_Alien(adv_A);
Free_Alien(adv_D);
Free_Alien(adv_V);
Free_Alien(adv_A2);
Free_Alien(adv_N);
Free_Alien(adv_C);
Free_Alien(adv_E);
Free_Alien(tbl_T);
Free_Alien(tbl_A);
Free_Alien(tbl_B);
Free_Alien(tbl_I);
Free_Alien(tbl_E);
Free_Alien(star2);

// Free aliens and points
Free_Alien(ufo_display);
Free_Alien(eq1);
Free_Alien(mist_M);
Free_Alien(mist_I);
Free_Alien(mist_S);
Free_Alien(mist_T);
Free_Alien(mist_E);
Free_Alien(mist_R);

Free_Alien(alien5_display);
Free_Alien(eq2);
Free_Alien(pts30_3);
Free_Alien(pts30_0);
Free_Alien(pts30_P);
Free_Alien(pts30_O);
Free_Alien(pts30_I);
Free_Alien(pts30_N);
Free_Alien(pts30_T);
Free_Alien(pts30_S);

Free_Alien(alien3_display);
Free_Alien(eq3);
Free_Alien(pts20_2);
Free_Alien(pts20_0);
Free_Alien(pts20_P);
Free_Alien(pts20_O);
Free_Alien(pts20_I);
Free_Alien(pts20_N);
Free_Alien(pts20_T);
Free_Alien(pts20_S);

Free_Alien(alien1_display);
Free_Alien(eq4);
Free_Alien(pts10_1);
Free_Alien(pts10_0);
Free_Alien(pts10_P);
Free_Alien(pts10_O);
Free_Alien(pts10_I);
Free_Alien(pts10_N);
Free_Alien(pts10_T);
Free_Alien(pts10_S);

return 0;

} /* main */
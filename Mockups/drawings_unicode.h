/* Ruler 1         2         3         4         5         6         7        */

#define UNICODE

/************************* Definition of Global Data **************************/

/* ---------------------- Global Data in main program ----------------------- */

/******************************************************************************/
/*                                                                            */
/*  IMPORTANT DIRECTIONS TO TAKE INTO ACCOUNT WHEN DEFINING A VISUAL OBJECT:  */
/*                                                                            */
/*  1. The number of unicode codes per string MUST be exactly the same        */
/*  2. A null string MUST be used to indicate the end of the object's aspect  */
/*  3. When using strlen(), a single unicode code will return 3 chars length  */
/*                                                                            */
/******************************************************************************/

/* -------------------------------- Aliens ---------------------------------- */

char *squid[] = {
"\u2800\u259F\u2599\u2800", /*  ▟▙  */
"\u259F\u259C\u259B\u2599", /* ▟▜▛▙ */
"\u259C\u259C\u259B\u259B", /* ▜▜▛▛ */
"\u259A\u2800\u2800\u259E", /* ▚  ▞ */
""
};

char *crab[] = {
"\u2800\u259A\u2800\u2800\u259E\u2800", /*  ▚  ▞  */
"\u2597\u259B\u2588\u2588\u259C\u2596", /* ▗▛██▜▖ */
"\u259B\u2588\u2588\u2588\u2588\u259C", /* ▛████▜ */
"\u2598\u259A\u2596\u2597\u259E\u259D", /* ▘▚▖▗▞▝ */
""
};

char *octopus[] = {
"\u2597\u2584\u2588\u2588\u2584\u2596", /* ▗▄██▄▖ */
"\u2588\u259B\u259C\u259B\u259C\u2588", /* █▛▜▛▜█ */
"\u2580\u259C\u259B\u259C\u259B\u2580", /* ▀▜▛▜▛▀ */
"\u2584\u2580\u259D\u2598\u2580\u2584", /* ▄▀▝▘▀▄ */
""
};

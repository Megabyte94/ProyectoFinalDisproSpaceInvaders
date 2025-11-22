/* Ruler 1         2         3         4         5         6         7        */

#ifndef	ALIEN_H
#define ALIEN_H

/******************** Declaration of Class with Attributes ********************/

typedef struct ALIEN_T ALIEN_T;



/************************ Prototypes of Public Methods ************************/

/* ------------------------ Constructor & Destructor ------------------------ */

ALIEN_T * New_Alien();
int       Free_Alien( ALIEN_T * );

/* ------------------------ Setting Alien Attributes ------------------------ */

ALIEN_T *   Set_Alien_Aspect( ALIEN_T *, char *(*)[] );
ALIEN_T *    Set_Alien_Color( ALIEN_T *, int );
ALIEN_T * Set_Alien_Location( ALIEN_T *, unsigned char, unsigned char );

/* ------------------------ Performing Alien Actions ------------------------ */

void Draw_Alien( ALIEN_T * );

#endif /* ALIEN_H */

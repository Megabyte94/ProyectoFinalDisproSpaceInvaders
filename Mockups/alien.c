/* Ruler 1         2         3         4         5         6         7        */

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>  // Due to printf()
#include <stdlib.h> // Due to malloc()
#include <string.h> // Due to strlen()

/* ------------------------ Inclusion of Own Headers ------------------------ */

#include "alien.h"
#include "conio.h"



/************************** Declarations of New Types *************************/

/* Attributes to show how the alien looks like: */
struct ALIEN_T {
	unsigned char x, y;          /* Public position */
	int           color;         /* Public color    */
	char       *(*aspect)[];     /* Public aspect   */
	unsigned char width, height; /* Private size    */
};



/************************ Definition of Public Methods ************************/

/* ------------------------ Constructor & Destructor ------------------------ */

/*FN****************************************************************************
*
*   ALIEN_T *New_Alien();
*
*   Purpose: This constructor returns a pointer to a new instance of the
*            ALIEN_T class or it returns NULL if it fails
*
*   Plan:    Simple function that does not need a plan description
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 31/2020  J.C.Giraldo  Documentation
*
*******************************************************************************/

ALIEN_T *New_Alien()
{
return (ALIEN_T *)malloc( sizeof( ALIEN_T ) );

} /* New_Alien */



/*FN****************************************************************************
*
*   int Free_Alien( ALIEN_T *this );
*
*   Purpose: This method destroys instance of alien pointed by parameter "this"
*
*   Plan:    Simple function that does not need a plan description
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 31/2020  J.C.Giraldo  Documentation
*
*******************************************************************************/

int Free_Alien( ALIEN_T *this )
{
free( this );

return 1;

} /* Free_Alien */



/* ------------------------ Setting Alien Attributes ------------------------ */

/*FN****************************************************************************
*
*   ALIEN_T *Set_Alien_Aspect( ALIEN_T *this, char **(*aspect)[] );
*
*   Purpose: This method sets the aspect for an instance of ALIEN_T class
*
*   Plan:    Part 1: Point to the address of the array that defines alien
*            Part 2: Calculate width and height of the object in console
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 31/2020  J.C.Giraldo  Documentation
*
*******************************************************************************/

ALIEN_T *Set_Alien_Aspect( ALIEN_T *this, char *(*aspect)[] )
{
/* Part 1: Point to the address of the array that defines alien */

this->aspect = aspect;

/* Part 2: Calculate width and height of the object in console */

#ifdef UNICODE
this->width  = strlen( (*this->aspect)[0] )/3;
#else
this->width  = strlen( (*this->aspect)[0] );
#endif

this->height = 0;
while( *(*this->aspect)[this->height] != '\0' ) this->height++;

return this;

} /* Set_Alien_Aspect */



/*FN****************************************************************************
*
*   ALIEN_T *Set_Alien_Color( ALIEN_T *this, void (*color)() );
*
*   Purpose: This method sets a color for an instance of ALIEN_T class
*
*   Plan:    Simple function that does not need a plan description
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 31/2020  J.C.Giraldo  Documentation
*
*******************************************************************************/

ALIEN_T *Set_Alien_Color( ALIEN_T *this, int color )
{
this->color = color;

return this;

} /* Set_Alien_Color */



/*FN****************************************************************************
*
*   ALIEN_T *Set_Alien_Location( ALIEN_T *this,
*                                unsigned char x, unsigned char y );
*
*   Purpose: This method sets a new location for an instance of ALIEN_T class
*
*   Plan:    Simple function that does not need a plan description
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 31/2020  J.C.Giraldo  Documentation
*
*******************************************************************************/

ALIEN_T *Set_Alien_Location( ALIEN_T *this, unsigned char x, unsigned char y )
{
this->x = x;
this->y = y;

return this;

} /* Set_Alien_Location */



/* ------------------------ Performing Alien Actions ------------------------ */

/*FN****************************************************************************
*
*   void Draw_Alien( ALIEN_T *this );
*
*   Purpose: This method draws an instance of the ALIEN_T class at a location
*
*   Plan:    Simple function that does not need a plan description
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 31/2020  J.C.Giraldo  Documentation
*
*******************************************************************************/

void Draw_Alien( ALIEN_T *this )
{
textcolor( this->color);
for( int i = 0; *(*this->aspect)[i] != '\0'; i++ ) {
	gotoxy( this->x, this->y+i );
	printf( "%s\n", (*this->aspect)[i] );
}
textcolor( RESET );

} /* Draw_Alien */


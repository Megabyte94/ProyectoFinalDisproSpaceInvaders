/* Ruler 1         2         3         4         5         6         7        */

/********************************** Headers ***********************************/

#include <stdio.h>   // Due to kbhit()
#include <termios.h> // Due to kbhit()
#include <unistd.h>  // Due to kbhit()
#include <fcntl.h>   // Due to kbhit()

#include <stdlib.h>  // Due to system()
#include <stdint.h>  // Due to uint8_t in gotoxy()
#include <string.h>  // Due to strlen()

/**************************** Symbolic  Constants *****************************/

#define MIN_X 1
#define MAX_X 75   // Ajusta dependiendo del tamaño de tu terminal

#define CANNON_WIDTH 5  // ANCHO REAL del cañón

/************************** Definition of Data Types **************************/

typedef enum { OFF, ON } STATUS_T;

/************************** Prototypes of Functions ***************************/

int kbhit( void );
void draw_at( uint8_t x, uint8_t y, char *object[] );
void clear_at( uint8_t x, uint8_t y, char *object[] );
void gotoxy( uint8_t x, uint8_t y );
void cursor( STATUS_T status );

/************************* Definition of Global Data **************************/

char *cannon[] = {
"\u2800\u2800\u2588\u2800\u2800",   /*   █   */
"\u2590\u2597\u2588\u2596\u258C",   /* ▐▗█▖▌ */
"\u259F\u2588\u2588\u2588\u2599",   /* ▟███▙ */
"\u259C\u2588\u2588\u2588\u259B",   /* ▜███▛ */
"\u259D\u259D\u2588\u2598\u2598",   /* ▝▝█▘▘ */
""
};

/******************************* Main Function ********************************/

int main( void )
{

do {

  draw_at( x, y, cannon );

  while( !kbhit() ) ;  // Espera sin bloquear

  clear_at( x, y, cannon );

  c = getchar();

  if( c == 'q' )
    break;

  /* SOLO MOVIMIENTO LATERAL */
  if( c == 'j' )  // mover izquierda
  {
    if( x > MIN_X )
        x -= 2;
  }

  else if( c == 'l' )  // mover derecha
  {
    if( x + CANNON_WIDTH < MAX_X )
        x += 2;
  }

} while( 1 );

return 0;

} /* main */


/********************** Definition of Public Functions ************************/

return 0;
}

void draw_at( uint8_t x, uint8_t y, char *object[] )
{
for( int i = 0; *object[i] != '\0'; i++ ) {
  gotoxy( x, y+i );
  printf( "%s\n", object[i] );
}
}

void clear_at( uint8_t x, uint8_t y, char *object[] )
{
for( int i = 0; *object[i] != '\0'; i++ ) {
  gotoxy( x, y+i );
  for( int j = 0; j < strlen( object[i] )/3; j++ )
    printf( " " );
}
}


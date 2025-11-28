/* Ruler 1         2         3         4         5         6         7        */

// COMPILE WITH:         gcc emoji.c conio.c -o emoji

/* emoji.c ********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "connio.h"

/**************************** Definition of Emojis ****************************/

char *alien1[] = {
"\u2800\u2580\u2584\u2580\u2800",   /*⠀▀▄▀⠀*/    
"\u258C\u259F\u2588\u2599\u2590",   /*▌▟█▙▐*/  
"\u2588\u258C\u2588\u2590\u2588",   /*█▌█▐█*/  
"\u259D\u2588\u2588\u2588\u2598",   /*▝███▘*/  
"\u2597\u259E\u2800\u259A\u2596",   /*▗▞⠀▚▖*/
""
};

/******************* Prototype of Functions in Current File *******************/

void drawElement ( char *[], unsigned char, unsigned char );
void clearElement( char *[], unsigned char, unsigned char );
void Frame( unsigned char, unsigned char, unsigned char, unsigned char );
void Delay_Seconds( float );

/****************************  ADICIÓN META 1  ********************************/
/* Estructura para manejar varios marcianos */

typedef struct {
    int x;
    int y;
} Alien;

/******************************* Main Function ********************************/

int main()
{
    /* Part 1: GENERAL SETUP */

    unsigned char positionX = 2;
    unsigned char positionY = 2;

    unsigned char width  = 5;   // ancho del emoji
    unsigned char height = 5;   // alto del emoji

    signed char direction = 1;  // 1 = derecha, -1 = izquierda

    unsigned char screenWidth;
    unsigned char screenHeight;

    Get_Console_Size( &screenWidth, &screenHeight );
    screenWidth = ( screenWidth % 2 ? screenWidth - 1 : screenWidth );
    Clear_Screen();

    Frame( 1, 1, screenWidth, screenHeight );
    Cursor( 0 );

    /****************************  ADICIÓN META 1  ****************************/
    #define NUM_ALIENS 14
    Alien aliens[NUM_ALIENS];

    int spacing = 2;  // separación para que no se sobrepongan

    for(int i = 0; i < NUM_ALIENS; i++) {
        aliens[i].x = positionX + i * (width + spacing);
        aliens[i].y = positionY;
    }

    /* Part 2: RUN PROGRAM */

    while( 1 ) {

        /* Limpiar elementos anteriores */
        /**************** ADICIÓN META 1 ****************/
        for(int i = 0; i < NUM_ALIENS; i++)
            clearElement( alien1, aliens[i].x, aliens[i].y );
        /************************************************/

        /* Movimiento horizontal estilo Space Invaders */

        /**************** ADICIÓN META 1 ****************/
        int leftmost  = aliens[0].x;
        int rightmost = aliens[0].x;

        for(int i = 1; i < NUM_ALIENS; i++) {
            if (aliens[i].x < leftmost) leftmost = aliens[i].x;
            if (aliens[i].x > rightmost) rightmost = aliens[i].x;
        }

        if (leftmost <= 2) {
            direction = 1;
            for(int i = 0; i < NUM_ALIENS; i++)
                aliens[i].y++;
        }
        else if (rightmost >= screenWidth - width) {
            direction = -1;
            for(int i = 0; i < NUM_ALIENS; i++)
                aliens[i].y++;
        }

        for(int i = 0; i < NUM_ALIENS; i++)
            aliens[i].x += direction;
        /************************************************/

        /* Dibujar aliens */
        /**************** ADICIÓN META 1 ****************/
        for(int i = 0; i < NUM_ALIENS; i++)
            drawElement( alien1, aliens[i].x, aliens[i].y );
        /************************************************/

        /* Pequeño delay */
        Delay_Seconds( 0.15 );
    }

    return 0;

} /* main */

/******************* Definition of Functions in Current File ******************/

void drawElement( char *element[], unsigned char x, unsigned char y )
{
    for( int i = 0, j = 0; element[i][0] != '\0'; i++, j++ ) {
        gotoxy( x, y + j );
        printf( "%s\n", element[i] );
    }
}

void clearElement(  char *element[], unsigned char x, unsigned char y )
{
    for( int i = 0, j = 0; element[i][0] != '\0'; i++, j++ ) {
        gotoxy( x, y + j );
        int width = strlen( element[0] ) / 3;
        for( int spaces = 0; spaces < width; spaces++ )
            printf( " " );
    }
}

void Frame( unsigned char x, unsigned char y, unsigned char dx, unsigned char dy )
{
    gotoxy( x, y );
    printf( "\u256D" );

    gotoxy( x+1, y );
    for( int i=x+1; i<x+dx-1; i++ )
        printf( "\u2500" );

    gotoxy( x+dx-1, y );
    printf( "\u256E" );

    for( int j=y+1; j<y+dy-1; j++ ) {
        gotoxy( x, j );
        printf( "\u2502" );
    }

    for( int j=y+1; j<y+dy-1; j++ ) {
        gotoxy( x+dx-1, j );
        printf( "\u2502" );
    }

    gotoxy( x, y+dy-1 );
    printf( "\u2570" );

    gotoxy( x+1, y+dy-1 );
    for( int i=x+1; i<x+dx-1; i++ )
        printf( "\u2500" );

    gotoxy( x+dx-1, y+dy-1 );
    printf( "\u256F" );
}

void Delay_Seconds( float delay )
{
    float previous = (float)clock() / CLOCKS_PER_SEC;
    while( (float)clock() / CLOCKS_PER_SEC - previous < delay )
        ;
}

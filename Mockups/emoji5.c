/* Ruler 1         2         3         4         5         6         7        */

// COMPILE WITH:         gcc emoji.c conio.c -o emoji

/* emoji.c ********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "connio.h"

/**************************** Definition of Emojis ****************************/
/*  
    IMPORTANTE:
    Reemplaza cada uno de estos arrays con tus propios emojis (frames A/B).
    Debes conservar la forma: cada array termina con "" .
*/

/************* ALIENS (tus arrays ya puestos) **********/

char *alien1A[] = {
"\u2800\u2580\u2584\u2580\u2800",   /*⠀▀▄▀⠀*/    
"\u258C\u259F\u2588\u2599\u2590",   /*▌▟█▙▐*/  
"\u2588\u258C\u2588\u2590\u2588",   /*█▌█▐█*/  
"\u259D\u2588\u2588\u2588\u2598",   /*▝███▘*/  
"\u2597\u259E\u2800\u259A\u2596",   /*▗▞⠀▚▖*/
""
};
char *alien1B[] = {
"\u2800\u2580\u2584\u2580\u2800",   /*⠀▀▄▀⠀*/    
"\u258C\u259F\u2588\u2599\u2590",   /*▌▟█▙▐*/  
"\u2588\u258C\u2588\u2590\u2588",   /*█▌█▐█*/  
"\u259D\u2588\u2588\u2588\u2598",   /*▝███▘*/  
"\u2800\u2590\u2584\u258C\u2800",   /*⠀▐▄▌⠀*/
""
};

char *alien2A[] = {
"\u2590\u2597\u2800\u2596\u258C",   /*▐▗⠀▖▌*/
"\u259D\u2588\u2588\u2588\u2598",   /*▝███▘*/
"\u259F\u258C\u2588\u2590\u2599",   /*▟▌█▐▙*/
"\u259F\u2580\u2580\u2580\u2599",   /*▟▀▀▀▙*/
"\u2599\u2800\u2800\u2800\u259F",   /*▙⠀⠀⠀▟*/
""
};
char *alien2B[] = {
"\u2590\u2597\u2800\u2596\u258C",   /*▐▗⠀▖▌*/
"\u259D\u2588\u2588\u2588\u2598",   /*▝███▘*/
"\u259F\u258C\u2588\u2590\u2599",   /*▟▌█▐▙*/
"\u259F\u2580\u2580\u2580\u2599",   /*▟▀▀▀▙*/
"\u259F\u2800\u2800\u2800\u2599",   /*▟⠀⠀⠀▙*/
""
};

char *alien3A[] = {
"\u2800\u2597\u2588\u2596\u2800",   /*⠀▗█▖⠀*/
"\u2597\u2588\u2584\u2588\u2596",   /*▗█▄█▖*/
"\u259C\u259F\u2584\u2599\u259B",   /*▜▟▄▙▛*/
"\u2597\u259C\u2580\u259B\u2596",   /*▗▜▀▛▖*/
"\u259F\u2590\u2800\u258C\u2599",   /*▟▐⠀▌▙*/
""
};
char *alien3B[] = {
"\u2800\u2597\u2588\u2596\u2800",   /*⠀▗█▖⠀*/
"\u2597\u2588\u2584\u2588\u2596",   /*▗█▄█▖*/
"\u259C\u259F\u2584\u2599\u259B",   /*▜▟▄▙▛*/
"\u2597\u2580\u2588\u2580\u2596",   /*▗▀█▀▖*/
"\u2590\u2596\u2588\u2597\u258C",   /*▐▖█▗▌*/
""
};

char *alien4A[] = {
"\u2800\u259F\u2588\u2599\u2800",   /*⠀▟█▙⠀*/
"\u259F\u2580\u2588\u2580\u2599",   /*▟▀█▀▙*/
"\u2580\u259C\u2588\u259B\u2580",   /*▀▜██▛▀*/
"\u2800\u259E\u2800\u259A\u2800",   /*⠀▞⠀▚⠀*/
"\u259E\u2800\u2800\u2800\u259A",   /*▞⠀⠀⠀▚*/
""
};
char *alien4B[] = {
"\u2800\u259F\u2588\u2599\u2800",   /*⠀▟█▙⠀*/
"\u259F\u2580\u2588\u2580\u2599",   /*▟▀█▀▙*/
"\u2580\u259C\u2588\u259B\u2580",   /*▀▜██▛▀*/
"\u2800\u2590\u2800\u258C\u2800",   /*⠀▐⠀▌⠀*/
"\u2800\u2590\u2800\u258C\u2800",   /*⠀▐⠀▌⠀*/
""
};

char *alien5A[] = {
"\u2597\u259F\u2588\u2599\u2596",   /*▗▟█▙▖*/
"\u2588\u2588\u2588\u2588\u2588",   /*█████*/
"\u2588\u2584\u2588\u2584\u2588",   /*█▄█▄█*/
"\u2800\u2580\u2584\u2580\u2800",   /*⠀▀▄▀⠀*/
"\u2584\u2580\u2800\u2580\u2584",   /*▄▀⠀▀▄*/
""
};
char *alien5B[] = {
"\u2597\u259F\u2588\u2599\u2596",   /*▗▟█▙▖*/
"\u2588\u2588\u2588\u2588\u2588",   /*█████*/
"\u2588\u2584\u2588\u2584\u2588",   /*█▄█▄█*/
"\u2800\u2580\u2584\u2580\u2800",   /*⠀▀▄▀⠀*/
"\u2800\u2800\u2580\u2800\u2800",   /*⠀⠀▀⠀⠀*/
""
};

/******************** ARREGLO DE TIPOS DE ALIEN CON 2 FRAMES ******************/

char **AlienTypesA[] = { alien1A, alien2A, alien3A, alien4A, alien5A };
char **AlienTypesB[] = { alien1B, alien2B, alien3B, alien4B, alien5B };

/******************* Prototype of Functions in Current File *******************/

void drawElement ( char *[], unsigned char, unsigned char );
void clearElement( char *[], unsigned char, unsigned char );
void Frame( unsigned char, unsigned char, unsigned char, unsigned char );
void Delay_Seconds( float );

/******************************* Alien Struct *********************************/

typedef struct {
    int x;
    int y;
    int type;           // 0–4 → 5 tipos de alien
} Alien;

/*************************** Alien bullets structs ****************************/

#define MAX_ALIEN_BULLETS 12

typedef struct {
    int x;
    int y;
    int active;     // 0 = inactivo, 1 = activo
    int ownerCol;   // columna desde la que fue lanzada
} AlienBullet;

char *alienShotSprite[] = {
"\u2800\u2800\u2584\u2800\u2800", 
"\u2800\u2590\u2588\u258C\u2800",  
"\u258C\u259F\u2588\u2599\u2590",   
"\u2590\u2588\u2588\u2588\u258C",   
"\u2800\u259C\u2588\u259B\u2800", 
 ""
};


/* Buffer de balas */
AlienBullet alienBullets[MAX_ALIEN_BULLETS];

/*************************** Prototipos nuevas funciones ************************/

int bottomAlienIndexInColumn(Alien aliens[], int col, int rows, int cols, int totalAliens);
int createAlienBullet(int x, int y, int ownerCol);
void tryAlienShoot(Alien aliens[], int rows, int cols, int totalAliens, int width, int height);
void updateAlienBullets(int screenHeight, int width);

/******************************* Main Function ********************************/

int main()
{
    srand((unsigned int)time(NULL));

    /* Part 1: GENERAL SETUP */

    unsigned char screenWidth;
    unsigned char screenHeight;

    Get_Console_Size( &screenWidth, &screenHeight );
    screenWidth = ( screenWidth % 2 ? screenWidth - 1 : screenWidth );
    Clear_Screen();

    Frame( 1, 1, screenWidth, screenHeight );
    Cursor( 0 );

    /* Configuración básica */
    int width = 5;       // reemplazar si tu alien mide distinto
    int height = 5;      // igual
    int direction = 1;

    /* Configuración de filas */
    #define ROWS   5
    #define ALIENS_PER_ROW 14
    #define TOTAL_ALIENS (ROWS * ALIENS_PER_ROW)

    Alien aliens[TOTAL_ALIENS];

    int spacing = 2;
    int startX = 4;
    int startY = 6;

    /* Inicializar aliens en filas */
    int index = 0;
    for(int r = 0; r < ROWS; r++) {
        for(int i = 0; i < ALIENS_PER_ROW; i++) {

            aliens[index].x = startX + i * (width + spacing);
            aliens[index].y = startY + r * (height + 1);

            aliens[index].type = r;    // fila 0 = tipo 0, fila 1 = tipo 1, etc.

            index++;
        }
    }

    /* Inicializar buffer de balas */
    for (int i = 0; i < MAX_ALIEN_BULLETS; i++) alienBullets[i].active = 0;

    /* Control de animación A/B */
    int frameToggle = 0;   // 0 usa frame A, 1 usa frame B

    /* Part 2: RUN PROGRAM */

    while( 1 ) {

        /* Borrar todos los aliens */
        for(int i = 0; i < TOTAL_ALIENS; i++) {
            char **sprite = frameToggle ? AlienTypesB[ aliens[i].type ]
                                        : AlienTypesA[ aliens[i].type ];
            clearElement( sprite, aliens[i].x, aliens[i].y );
        }

        /* Detectar límites */
        int leftmost  = aliens[0].x;
        int rightmost = aliens[0].x;

        for(int i = 1; i < TOTAL_ALIENS; i++) {
            if (aliens[i].x < leftmost) leftmost = aliens[i].x;
            if (aliens[i].x > rightmost) rightmost = aliens[i].x;
        }

        if (leftmost <= 2) {
            direction = 1;
            for(int i = 0; i < TOTAL_ALIENS; i++)
                aliens[i].y++;
        }
        else if (rightmost >= screenWidth - width - 1) {
            direction = -1;
            for(int i = 0; i < TOTAL_ALIENS; i++)
                aliens[i].y++;
        }

        /* Mover aliens */
        for(int i = 0; i < TOTAL_ALIENS; i++)
            aliens[i].x += direction;

        /* Cambiar animación */
        frameToggle = !frameToggle;

        /* Dibujar aliens */
        for(int i = 0; i < TOTAL_ALIENS; i++) {

            char **sprite = frameToggle ? AlienTypesB[ aliens[i].type ]
                                        : AlienTypesA[ aliens[i].type ];

            drawElement( sprite, aliens[i].x, aliens[i].y );
        }

        /* Intento de disparo de alien (1/N probabilidad por frame) */
        if ( rand() % 22 == 0 ) {   /* ajusta 22 para cambiar frecuencia */
            tryAlienShoot(aliens, ROWS, ALIENS_PER_ROW, TOTAL_ALIENS, width, height);
        }

        /* Actualizar balas de alien (mover y dibujar) */
        updateAlienBullets(screenHeight, width);

        Delay_Seconds(0.6);
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

/************************* Nuevas funciones: disparos alien *************************/

/* Devuelve el índice en aliens[] del alien más bajo (mayor y) en la columna `col`.
   Si no hay ninguno (p.ej. murieron y se pusieron x < 0), devuelve -1. */
int bottomAlienIndexInColumn(Alien aliens[], int col, int rows, int cols, int totalAliens)
{
    int bestIndex = -1;
    for (int r = 0; r < rows; r++) {
        int idx = r * cols + col;
        if (idx < 0 || idx >= totalAliens) continue;
        if (aliens[idx].x < 0) continue; // alien "muerto" o fuera
        if (bestIndex == -1 || aliens[idx].y > aliens[bestIndex].y)
            bestIndex = idx;
    }
    return bestIndex;
}

/* Crea una bala en (x,y) con ownerCol (para evitar duplicados por columna si quieres)
   Retorna 1 si se creó, 0 si no hay hueco. */
int createAlienBullet(int x, int y, int ownerCol)
{
    for (int i = 0; i < MAX_ALIEN_BULLETS; i++) {
        if (!alienBullets[i].active) {
            alienBullets[i].active = 1;
            alienBullets[i].x = x;
            alienBullets[i].y = y;
            alienBullets[i].ownerCol = ownerCol;
            return 1;
        }
    }
    return 0;
}

/* Intenta que un alien dispare: elige una columna que tenga un alien abajo y que
   no tenga ya una bala activa para esa columna (evita solapamiento). */
void tryAlienShoot(Alien aliens[], int rows, int cols, int totalAliens, int width, int height)
{
    int colsIdx[ALIENS_PER_ROW];
    int colsCount = 0;

    for (int c = 0; c < cols; c++) {
        int ai = bottomAlienIndexInColumn(aliens, c, rows, cols, totalAliens);
        if (ai != -1) {
            int columnHasBullet = 0;
            for (int b = 0; b < MAX_ALIEN_BULLETS; b++) {
                if (alienBullets[b].active && alienBullets[b].ownerCol == c) {
                    columnHasBullet = 1;
                    break;
                }
            }
            if (!columnHasBullet) {
                colsIdx[colsCount++] = ai;
            }
        }
    }

    if (colsCount == 0) return;

    int pickIdx = colsIdx[ rand() % colsCount ];
    int ownerCol = pickIdx % cols;

    /* Crear bala justo debajo del sprite (centro aproximado) */
    int bx = aliens[pickIdx].x + (width / 2);
    int by = aliens[pickIdx].y + height;

    createAlienBullet(bx, by, ownerCol);
}

/* Mueve todas las balas de alien hacia abajo, detecta salida de pantalla y dibuja.
   Aquí también podrías agregar detección de colisión con la nave del jugador. */


void updateAlienBullets(int screenHeight, int width)
{
    for (int i = 0; i < MAX_ALIEN_BULLETS; i++) {

        if (!alienBullets[i].active) continue;

        /* Borrar el sprite anterior (5 líneas) */
        for (int l = 0; l < 5; l++) {
            gotoxy(alienBullets[i].x, alienBullets[i].y + l);
            printf("     ");   // 5 espacios, porque tu bala tiene 5 columnas
        }

        /* Mover hacia abajo */
        alienBullets[i].y += 1;

        /* Si sale de la pantalla */
        if (alienBullets[i].y >= screenHeight - 5) {
            alienBullets[i].active = 0;
            continue;
        }

        /* Dibujar bala en nueva posición */
        drawElement(alienShotSprite, alienBullets[i].x, alienBullets[i].y);
    }
}



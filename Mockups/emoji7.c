/* Ruler 1         2         3         4         5         6         7        */

// COMPILE WITH:         gcc emoji.c connio.c -o emoji

/* emoji.c ********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "connio.h"

#include <termios.h> // Due to kbhit()
#include <unistd.h>  // Due to kbhit()
#include <fcntl.h>   // Due to kbhit()

/**************************** Definition of Emojis ****************************/
/*  
    IMPORTANTE:
    Reemplaza cada uno de estos arrays con tus propios emojis (frames A/B).
    Debes conservar la forma: cada array termina con "" .
*/

/************* ALIENS (tus arrays ya puestos) **********/

char *alien1A[] = {
"\u2800\u2580\u2584\u2580\u2800",
"\u258C\u259F\u2588\u2599\u2590",
"\u2588\u258C\u2588\u2590\u2588",
"\u259D\u2588\u2588\u2588\u2598",
"\u2597\u259E\u2800\u259A\u2596",
""
};
char *alien1B[] = {
"\u2800\u2580\u2584\u2580\u2800",
"\u258C\u259F\u2588\u2599\u2590",
"\u2588\u258C\u2588\u2590\u2588",
"\u259D\u2588\u2588\u2588\u2598",
"\u2800\u2590\u2584\u258C\u2800",
""
};

char *alien2A[] = {
"\u2590\u2597\u2800\u2596\u258C",
"\u259D\u2588\u2588\u2588\u2598",
"\u259F\u258C\u2588\u2590\u2599",
"\u259F\u2580\u2580\u2580\u2599",
"\u2599\u2800\u2800\u2800\u259F",
""
};
char *alien2B[] = {
"\u2590\u2597\u2800\u2596\u258C",
"\u259D\u2588\u2588\u2588\u2598",
"\u259F\u258C\u2588\u2590\u2599",
"\u259F\u2580\u2580\u2580\u2599",
"\u259F\u2800\u2800\u2800\u2599",
""
};

char *alien3A[] = {
"\u2800\u2597\u2588\u2596\u2800",
"\u2597\u2588\u2584\u2588\u2596",
"\u259C\u259F\u2584\u2599\u259B",
"\u2597\u259C\u2580\u259B\u2596",
"\u259F\u2590\u2800\u258C\u2599",
""
};
char *alien3B[] = {
"\u2800\u2597\u2588\u2596\u2800",
"\u2597\u2588\u2584\u2588\u2596",
"\u259C\u259F\u2584\u2599\u259B",
"\u2597\u2580\u2588\u2580\u2596",
"\u2590\u2596\u2588\u2597\u258C",
""
};

char *alien4A[] = {
"\u2800\u259F\u2588\u2599\u2800",
"\u259F\u2580\u2588\u2580\u2599",
"\u2580\u259C\u2588\u259B\u2580",
"\u2800\u259E\u2800\u259A\u2800",
"\u259E\u2800\u2800\u2800\u259A",
""
};
char *alien4B[] = {
"\u2800\u259F\u2588\u2599\u2800",
"\u259F\u2580\u2588\u2580\u2599",
"\u2580\u259C\u2588\u259B\u2580",
"\u2800\u2590\u2800\u258C\u2800",
"\u2800\u2590\u2800\u258C\u2800",
""
};

char *alien5A[] = {
"\u2597\u259F\u2588\u2599\u2596",
"\u2588\u2588\u2588\u2588\u2588",
"\u2588\u2584\u2588\u2584\u2588",
"\u2800\u2580\u2584\u2580\u2800",
"\u2584\u2580\u2800\u2580\u2584",
""
};
char *alien5B[] = {
"\u2597\u259F\u2588\u2599\u2596",
"\u2588\u2588\u2588\u2588\u2588",
"\u2588\u2584\u2588\u2584\u2588",
"\u2800\u2580\u2584\u2580\u2800",
"\u2800\u2800\u2580\u2800\u2800",
""
};

/******************** ARREGLO DE TIPOS DE ALIEN *******************************/

char **AlienTypesA[] = { alien1A, alien2A, alien3A, alien4A, alien5A };
char **AlienTypesB[] = { alien1B, alien2B, alien3B, alien4B, alien5B };

/******************* Prototipos ************************************************/

void drawElement ( char *[], unsigned char, unsigned char );
void clearElement( char *[], unsigned char, unsigned char );
void Frame( unsigned char, unsigned char, unsigned char, unsigned char );
void Delay_Seconds( float );

/******************************* Alien Struct *********************************/

typedef struct {
    int x;
    int y;
    int type;
} Alien;

/*************************** Alien bullets structs ****************************/

#define MAX_ALIEN_BULLETS 12

typedef struct {
    int x;
    int y;
    int active;
    int ownerCol;
} AlienBullet;

char *alienShotSprite[] = {
"\u2800\u2800\u2584\u2800\u2800", 
"\u2800\u2590\u2588\u258C\u2800",
"\u258C\u259F\u2588\u2599\u2590",
"\u2590\u2588\u2588\u2588\u258C",
"\u2800\u259C\u2588\u259B\u2800",
""
};

AlienBullet alienBullets[MAX_ALIEN_BULLETS];

#define MAX_PLAYER_BULLETS 20

typedef struct {
    int x;
    int y;
    int active;
} PlayerBullet;

PlayerBullet playerBullets[MAX_PLAYER_BULLETS];

char *playerShotSprite[] =  {
"\u2800\u2597\u2584\u2596\u2800", 
"\u2597\u2588\u2588\u2588\u2596",  
"\u259E\u2588\u2588\u2588\u259A",   
"\u2598\u2590\u2588\u258C\u259D",   
"\u2800\u259D\u2588\u2598\u2800", 
""
};

int createPlayerBullet(int x, int y);
void updatePlayerBullets(void);

/*************************** Prototipos nuevos ********************************/

int bottomAlienIndexInColumn(Alien[], int, int, int, int);
int createAlienBullet(int, int, int);
void tryAlienShoot(Alien[], int, int, int, int, int);
void updateAlienBullets(int, int);

/******************************* PLAYER (CAÑÓN) ********************************/

/* Tu sprite real reemplázalo por tu array 5x5. Aquí hay un placeholder 5x5. */
#define PLAYER_WIDTH  5
#define PLAYER_HEIGHT 5

char *playerSprite[] = {
  "\u2800\u2800\u2588\u2800\u2800",   /*   █   */
  "\u2590\u2597\u2588\u2596\u258C",   /* ▐▗█▖▌ */
  "\u259F\u2588\u2588\u2588\u2599",   /* ▟███▙ */
  "\u259C\u2588\u2588\u2588\u259B",   /* ▜███▛ */
  "\u259D\u259D\u2588\u2598\u2598",   /* ▝▝█▘▘ */
  ""
};

typedef struct {
    int x;
    int y;
} Player;

/* Prototipo */
void handlePlayerMovement(Player *p, int screenWidth);
int kbhit(void);


/******************************* Main Function ********************************/

int main() {

    srand((unsigned int)time(NULL));

    unsigned char screenWidth;
    unsigned char screenHeight;

    Get_Console_Size( &screenWidth, &screenHeight );
    screenWidth = ( screenWidth % 2 ? screenWidth - 1 : screenWidth );
    Clear_Screen();

    Frame( 1, 1, screenWidth, screenHeight );
    Cursor( 0 );

    /* Tus aliens son 5x5 siempre */
    int width  = 5;
    int height = 5;

    int direction = 1;

    #define ROWS   3
    #define ALIENS_PER_ROW 14
    #define TOTAL_ALIENS (ROWS * ALIENS_PER_ROW)

    Alien aliens[TOTAL_ALIENS];

    int spacing = 2;
    int startX = 4;
    int startY = 6;

    int index = 0;
    for(int r = 0; r < ROWS; r++) {
        for(int i = 0; i < ALIENS_PER_ROW; i++) {

            aliens[index].x = startX + i * (width + spacing);
            aliens[index].y = startY + r * (height + 1);

            aliens[index].type = r;

            index++;
        }
    }

    for (int i = 0; i < MAX_ALIEN_BULLETS; i++) alienBullets[i].active = 0;

    int frameToggle = 0;

    /* ------------------ Inicializar jugador ------------------ */
    Player player;
    player.x = (screenWidth / 2) - (PLAYER_WIDTH / 2);
    player.y = screenHeight - PLAYER_HEIGHT - 2; /* dejar margen inferior */
    /* Dibujar jugador inicialmente */
    drawElement(playerSprite, player.x, player.y);

    int fps = 0 ;

    while( 1 ) {

        if (fps >= 60000) {

            /* Borrar aliens */
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
    
            for(int i = 0; i < TOTAL_ALIENS; i++)
                aliens[i].x += direction;
    
            frameToggle = !frameToggle;
    
            for(int i = 0; i < TOTAL_ALIENS; i++) {
    
                char **sprite = frameToggle ? AlienTypesB[ aliens[i].type ]
                                            : AlienTypesA[ aliens[i].type ];
    
                drawElement( sprite, aliens[i].x, aliens[i].y );
            }
    
            if ( rand() % 22 == 0 )
                tryAlienShoot(aliens, ROWS, ALIENS_PER_ROW, TOTAL_ALIENS, width, height);
    
            updateAlienBullets(screenHeight, width);
            updatePlayerBullets();

            fps = 0;

        }
    
        /* ------------------ Manejo de movimiento del jugador ------------------ */
        
        handlePlayerMovement(&player, screenWidth);
       

        fps++;

    }

    return 0;

} /* main */

/******************* Functions *************************************************/

void drawElement( char *element[], unsigned char x, unsigned char y )
{
    for( int i = 0, j = 0; element[i][0] != '\0'; i++, j++ ) {
        gotoxy( x, y + j );
        printf( "%s\n", element[i] );
    }
}

void clearElement( char *element[], unsigned char x, unsigned char y )
{
    for( int i = 0, j = 0; element[i][0] != '\0'; i++, j++ ) {
        gotoxy( x, y + j );
        printf("     ");   /* exactamente 5 espacios */
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

/************************* Disparos ********************************************/

int bottomAlienIndexInColumn(Alien aliens[], int col, int rows, int cols, int totalAliens)
{
    int bestIndex = -1;
    for (int r = 0; r < rows; r++) {
        int idx = r * cols + col;
        if (idx < 0 || idx >= totalAliens) continue;
        if (aliens[idx].x < 0) continue;
        if (bestIndex == -1 || aliens[idx].y > aliens[bestIndex].y)
            bestIndex = idx;
    }
    return bestIndex;
}

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

    /* bala centrada para sprite 5×5 */
    int bx = aliens[pickIdx].x + 2;
    int by = aliens[pickIdx].y + height;

    createAlienBullet(bx, by, ownerCol);
}

void updateAlienBullets(int screenHeight, int width)
{
    for (int i = 0; i < MAX_ALIEN_BULLETS; i++) {

        if (!alienBullets[i].active) continue;

        /* Borrar sprite anterior (5 líneas de 5 espacios) */
        for (int l = 0; l < 5; l++) {
            gotoxy(alienBullets[i].x, alienBullets[i].y + l);
            printf("     ");
        }

        /* Mover hacia abajo */
        alienBullets[i].y += 1;

        if (alienBullets[i].y >= screenHeight - 5) {
            alienBullets[i].active = 0;
            continue;
        }

        drawElement(alienShotSprite, alienBullets[i].x, alienBullets[i].y);
    }
}

/********************* Manejo jugador *****************************************/

int kbhit( void ){
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    oldf = fcntl( STDIN_FILENO, F_GETFL, 0 );
    fcntl( STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK );

    ch = getchar();

    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    fcntl( STDIN_FILENO, F_SETFL, oldf );

    if( ch != EOF ) {
        ungetc( ch, stdin );
        return 1;
    }

return 0;
}


void handlePlayerMovement(Player *p, int screenWidth)
{
    if (!kbhit()) return;

    int ch = getchar();

    /* Flechas */
    if (ch == 0 || ch == 224) {
        int ch2 = getchar();
        if (ch2 == 75) { 
            clearElement(playerSprite, p->x, p->y);
            if (p->x > 2) p->x--;
            drawElement(playerSprite, p->x, p->y);
        }
        else if (ch2 == 77) { 
            clearElement(playerSprite, p->x, p->y);
            if (p->x < screenWidth - PLAYER_WIDTH - 2) p->x++;
            drawElement(playerSprite, p->x, p->y);
        }
    } else {
        clearElement(playerSprite, p->x, p->y);
        if (ch == 'a' || ch == 'A') { if (p->x > 2) p->x--; }
        else if (ch == 'd' || ch == 'D') { if (p->x < screenWidth - PLAYER_WIDTH - 2) p->x++; }
        else if (ch == ' ' || ch == 'w' || ch == 'W') {
            /* Disparo del jugador */
            createPlayerBullet(p->x + PLAYER_WIDTH/2, p->y - 1);
        }
        drawElement(playerSprite, p->x, p->y);
    }
}

int createPlayerBullet(int x, int y)
{
    for(int i = 0; i < MAX_PLAYER_BULLETS; i++) {
        if(!playerBullets[i].active) {
            playerBullets[i].active = 1;
            playerBullets[i].x = x - 2; // centrar sprite 5x5
            playerBullets[i].y = y - 4; // colocar arriba del jugador
            return 1;
        }
    }
    return 0;
}

void updatePlayerBullets(void)
{
    for(int i = 0; i < MAX_PLAYER_BULLETS; i++) {
        if(!playerBullets[i].active) continue;

        /* Borrar posición anterior */
        for(int l = 0; l < 5; l++) {
            gotoxy(playerBullets[i].x, playerBullets[i].y + l);
            printf("     ");
        }

        /* Mover hacia arriba */
        playerBullets[i].y -= 1;

        /* Desactivar si se va de pantalla */
        if(playerBullets[i].y < 1) {
            playerBullets[i].active = 0;
            continue;
        }

        /* Dibujar nueva posición */
        drawElement(playerShotSprite, playerBullets[i].x, playerBullets[i].y);
    }
}






















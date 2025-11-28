/* Ruler 1         2         3         4         5         6         7        */

/* 
 * COMPILACIÓN:  gcc emoji10.c connio.c -o emoji10
 * 
 * Space Invaders.
 * 
 * FUENTES CONSULTADAS: Natalia Ospina, Juan Sebastián Arcila, monitorías dispro, ChatGPT, Claude
 * 
 */

/* emoji10.c ******************************************************************/

/* Inclusión de librerías estándar necesarias para el funcionamiento del juego */
#include <stdio.h>      /* Funciones de entrada/salida estándar */
#include <stdlib.h>     /* Funciones generales: rand, srand */
#include <string.h>     /* Operaciones con cadenas */
#include <time.h>       /* Manejo de tiempo para delays y semilla aleatoria */
#include <termios.h>    /* Configuración de terminal (kbhit) */
#include <unistd.h>     /* Funciones POSIX estándar */
#include <fcntl.h>      /* Control de archivos y descriptores */

#include "connio.h"     /* Biblioteca personalizada para control de consola */


/* Definición de colores ANSI para facilitar el uso en el código */
#define COLOR_BRIGHT_YELLOW "\x1b[93m"
#define COLOR_BRIGHT_RED    "\x1b[91m"
#define COLOR_RESET         "\x1b[0m"


/**************************** Definición de Sprites ***************************/
/* 
 * Esta sección contiene todos los sprites del juego representados mediante
 * caracteres Unicode de bloques (U+2580 - U+259F). Cada sprite está definido
 * como un array de strings, donde cada string representa una línea del dibujo.
 * Los sprites terminan siempre con una cadena vacía "" para marcar el final.
 * 
 * Los aliens tienen dos frames (A y B) para crear efecto de animación.
 */

/* Sprites de los aliens - Frame A y Frame B para animación (3x3) */

char *alien1A[] = {
"\u2580\u2584\u2580",
"\u259F\u2588\u2599",
"\u259E\u2800\u259A",
""
};
char *alien1B[] = {
"\u2580\u2584\u2580",
"\u259F\u2588\u2599",
"\u2590\u2584\u258C",
""
};
char *alien2A[] = {
"\u2597\u2800\u2596",
"\u2588\u2588\u2588",
"\u2599\u2800\u259F",
""
};
char *alien2B[] = {
"\u2597\u2800\u2596",
"\u2588\u2588\u2588",
"\u259F\u2800\u2599",
""
};
char *alien3A[] = {
"\u2597\u2588\u2596",
"\u259F\u2584\u2599",
"\u2590\u2800\u258C",
""
};
char *alien3B[] = {
"\u2597\u2588\u2596",
"\u259F\u2584\u2599",
"\u2596\u2588\u2597",
""
};
char *alien4A[] = {
"\u259F\u2588\u2599",
"\u259C\u2588\u259B",
"\u259E\u2800\u259A",
""
};
char *alien4B[] = {
"\u259F\u2588\u2599",
"\u259C\u2588\u259B",
"\u2590\u2800\u258C",
""
};
char *alien5A[] = {
"\u259F\u2588\u2599",
"\u2588\u2588\u2588",
"\u2580\u2800\u2580",
""
};
char *alien5B[] = {
"\u259F\u2588\u2599",
"\u2588\u2588\u2588",
"\u2800\u2580\u2800",
""
};
char *kaboom[] = {
"\u259A\u2800\u259E", 
"\u2800\u2800\u2800",  
"\u259E\u2800\u259A",
""
};
char *H[] = {
"\u2588\u2800\u2800\u2588",
"\u2588\u2800\u2800\u2588",
"\u2588\u2588\u2588\u2588",
"\u2588\u2800\u2800\u2588",
"\u2588\u2800\u2800\u2588",
""
};
char *I[] = {
"\u2588\u2588\u2588\u2588", 
"\u2800\u2590\u258C\u2800",  
"\u2800\u2590\u258C\u2800",   
"\u2800\u2590\u258C\u2800",   
"\u2588\u2588\u2588\u2588",  
"" 
};
char *G[] = {
    "\u2588\u2588\u2588\u2588",
    "\u2588\u2800\u2800\u2800",
    "\u2588\u2800\u2588\u2588",
    "\u2588\u2800\u2800\u2588",
    "\u2588\u2588\u2588\u2588",
    ""
};
char *S[] = {
"\u259F\u2588\u2588\u2588",  
"\u2588\u2800\u2800\u2800",  
"\u259C\u2588\u2588\u2599",   
"\u2800\u2800\u2800\u2588",   
"\u2588\u2588\u2588\u259B",
""
};
char *C[] = {
    "\u2588\u2588\u2588\u2588",
    "\u2588\u2800\u2800\u2800",
    "\u2588\u2800\u2800\u2800",
    "\u2588\u2800\u2800\u2800",
    "\u2588\u2588\u2588\u2588",
    ""
};
char *O[] = {
"\u259F\u2588\u2588\u2599", 
"\u2588\u2800\u2800\u2588",  
"\u2588\u2800\u2800\u2588",   
"\u2588\u2800\u2800\u2588",   
"\u259C\u2588\u2588\u259B", 
""  
};
char *R[] = {
"\u2588\u2588\u2588\u2599",  
"\u2588\u2800\u2800\u2588",  
"\u2588\u2588\u2588\u259B",   
"\u2588\u2800\u259D\u2588",   
"\u2588\u2800\u2800\u2588", 
""
};
char *E[] = {
    "\u2588\u2588\u2588\u2588",
    "\u2588\u2800\u2800\u2800",
    "\u2588\u2588\u2588\u2588",
    "\u2588\u2800\u2800\u2800",
    "\u2588\u2588\u2588\u2588",
    ""
};
char *ZERO[] = {
    "\u259F\u2588\u2588\u2599", 
    "\u2588\u2800\u2800\u2588",  
    "\u2588\u2800\u2800\u2588",   
    "\u2588\u2800\u2800\u2588",   
    "\u259C\u2588\u2588\u259B",
    ""
};
char *ONE[] = {
  "\u2800\u2800\u2800\u2588",
  "\u2800\u2800\u2800\u2588",
  "\u2800\u2800\u2800\u2588",
  "\u2800\u2800\u2800\u2588",
  "\u2800\u2800\u2800\u2588",
  ""
};

char *TWO[] = {
  "\u2588\u2588\u2588\u2599",
  "\u2800\u2800\u2800\u2588",
  "\u259F\u2588\u2588\u259B",
  "\u2588\u2800\u2800\u2800",
  "\u2588\u2588\u2588\u2588",
  ""
};

char *THREE[] = {
  "\u2588\u2588\u2588\u2599",
  "\u2800\u2800\u2800\u2588",
  "\u2590\u2588\u2588\u2588",
  "\u2800\u2800\u2800\u2588",
  "\u2588\u2588\u2588\u259B",
  ""
};

char *FOUR[] = {
  "\u2588\u2800\u2800\u2588",
  "\u2588\u2800\u2800\u2588",
  "\u259C\u2588\u2588\u2588",
  "\u2800\u2800\u2800\u2588",
  "\u2800\u2800\u2800\u2588",
  ""
};

char *FIVE[] = {
"\u2588\u2588\u2588\u2588",
"\u2588\u2800\u2800\u2800",
"\u259C\u2588\u2588\u2599",
"\u2800\u2800\u2800\u2588",
"\u2588\u2588\u2588\u259B",
  ""
};

char *SIX[] = {
"\u259F\u2588\u2588\u2588",
"\u2588\u2800\u2800\u2599",
"\u2588\u2588\u2588\u2599",
"\u2588\u2800\u2800\u2588",
"\u259C\u2588\u2588\u259B",
  ""
};

char *SEVEN[] = {
  "\u2588\u2588\u2588\u2599",
  "\u2800\u2800\u2800\u2588",
  "\u2590\u2588\u2588\u2588",
  "\u2800\u2800\u2800\u2588",
  "\u2800\u2800\u2800\u2588",
  ""
};

char *EIGHT[] = {
    "\u259F\u2588\u2588\u2599",
    "\u2588\u2800\u2800\u2588",
    "\u2588\u2588\u2588\u2588",
    "\u2588\u2800\u2800\u2588",
    "\u259C\u2588\u2588\u259B",
    ""
};

char *NINE[] = {
    "\u259F\u2588\u2588\u2599",
    "\u2588\u2800\u2800\u2588",
    "\u259C\u2588\u2588\u2588",
    "\u2800\u2800\u2800\u2588",
    "\u2800\u2800\u2800\u2588",
    ""
};
char *D[] = {
"\u2588\u2588\u2588\u2596",
"\u2588\u2800\u259D\u2588",
"\u2588\u2800\u2800\u2588",
"\u2588\u2800\u2597\u2588",
"\u2588\u2588\u2588\u2598",
""
};
char *P[] = {
"\u2588\u2588\u2588\u2599", 
"\u2588\u2800\u2800\u2588",  
"\u2588\u2588\u2588\u2580",   
"\u2588\u2800\u2800\u2800",   
"\u2588\u2800\u2800\u2800", 
""
};
char *N[] = {
"\u2588\u2800\u2800\u2588", 
"\u2588\u2599\u2800\u2588",  
"\u2588\u259C\u2599\u2588",   
"\u2588\u2800\u259C\u2588",   
"\u2588\u2800\u2800\u2588", 
""
};
char *SPC[] = { "  ", "  ", "  ", "  ", "  ", "" };
char *T[] = {
"\u2588\u2588\u2588\u2588",  
"\u2800\u2590\u258C\u2800",  
"\u2800\u2590\u258C\u2800",   
"\u2800\u2590\u258C\u2800",   
"\u2800\u2590\u258C\u2800",
"" 
};
char *Y[] = {
"\u2588\u2800\u2800\u2588",  
"\u2588\u2800\u2800\u2588",  
"\u259C\u2599\u259F\u259B",   
"\u2800\u259C\u259B\u2800",   
"\u2800\u2590\u258C\u2800",
""
};
char *A[] = {
"\u2588\u2588\u2588\u2588",
"\u2588\u2800\u2800\u2588",
"\u2588\u2588\u2588\u2588",
"\u2588\u2800\u2800\u2588",
"\u2588\u2800\u2800\u2588",
    ""
};
char *B[] = {
    "\u2588\u2588\u2588\u2800",
    "\u2588\u2800\u2800\u2588",
    "\u2588\u2588\u2588\u2800",
    "\u2588\u2800\u2800\u2588",
    "\u2588\u2588\u2588\u2800",
    ""
};
char *U[] = {
"\u2588\u2800\u2800\u2588",  
"\u2588\u2800\u2800\u2588",  
"\u2588\u2800\u2800\u2588",   
"\u2588\u2800\u2800\u2588",   
"\u2588\u2588\u2588\u2588",
""
};
char *K[] = {
"\u2588\u2800\u2597\u2588", 
"\u2588\u2584\u2588\u2598",  
"\u2588\u2588\u258C\u2800",   
"\u2588\u2580\u2588\u2596",   
"\u2588\u2800\u259D\u2588", 
"" 
};
char *L[] = {
"\u2588\u2800\u2800\u2800",  
"\u2588\u2800\u2800\u2800",  
"\u2588\u2800\u2800\u2800",   
"\u2588\u2800\u2800\u2800",   
"\u2588\u2588\u2588\u2800",
""
};


/* Arrays de punteros para formar palabras completas en pantalla */
char **highScore[] = { H, I, G, H, SPC, S, C, O, R, E, SPC, ZERO, ZERO, ZERO, ZERO };
char **Score[] = { S, C, O, R, E };  /* Solo la palabra SCORE, sin dígitos */
char **dispro[]    = { D, I, S, P, R, O };
char **badLuck[]   = { B, A, D, SPC, L, U, C, K };
char **tryAgain[]  = { T, R, Y, SPC, A, G, A, I, N};

/* Arrays que contienen los tipos de aliens disponibles para cada frame de animación */
char **AlienTypesA[] = { alien1A, alien2A, alien3A, alien4A, alien5A };
char **AlienTypesB[] = { alien1B, alien2B, alien3B, alien4B, alien5B };

/************************** Prototipos de Funciones ***************************/

/* Funciones de dibujo y limpieza de elementos en pantalla */
void drawElement ( char *[], unsigned char, unsigned char );   /* Dibuja sprite en posición */
void clearElement( char *[], unsigned char, unsigned char );   /* Borra sprite de pantalla */
void Frame( unsigned char, unsigned char, unsigned char, unsigned char );  /* Dibuja marco */
void Delay_Seconds( float );                                   /* Pausa programada */
void drawBigWord(int x, int y, char **letters[], int totalLetters);  /* Texto grande */

/******************************* Estructuras **********************************/

/* Variable global para almacenar puntuación del jugador */
int playerScore = 0;

/* Estructura que representa cada alien enemigo en el juego */
typedef struct {
    int x;       /* Posición horizontal en la consola */
    int y;       /* Posición vertical en la consola */
    int type;    /* Tipo de alien (0-4), determina sprite a usar */
} Alien;

/* Sistema de proyectiles de los aliens */
#define MAX_ALIEN_BULLETS 12  /* Máximo de balas simultáneas de aliens */

/* Estructura para manejar las balas disparadas por los aliens */
typedef struct {
    int x;         /* Posición X de la bala */
    int y;         /* Posición Y de la bala */
    int active;    /* Estado: 1=activa, 0=inactiva */
    int ownerCol;  /* Columna del alien que disparó (para control de disparo) */
} AlienBullet;

char *alienShotSprite[] = {
"\u2800\u2800\u2584\u2800\u2800", 
"\u2800\u2590\u2588\u258C\u2800",
"\u258C\u259F\u2588\u2599\u2590",
"\u2590\u2588\u2588\u2588\u258C",
"\u2800\u259C\u2588\u259B\u2800",
""
};

/* Array global que almacena todas las balas de los aliens */
AlienBullet alienBullets[MAX_ALIEN_BULLETS];

/* Sistema de proyectiles del jugador */
#define MAX_PLAYER_BULLETS 20  /* Máximo de balas simultáneas del jugador */

/* Estructura para manejar las balas disparadas por el jugador */
typedef struct {
    int x;       /* Posición X de la bala */
    int y;       /* Posición Y de la bala */
    int active;  /* Estado: 1=activa, 0=inactiva */
} PlayerBullet;

/* Array global que almacena todas las balas del jugador */
PlayerBullet playerBullets[MAX_PLAYER_BULLETS];

char *playerShotSprite[] =  {
"\u2800\u2597\u2584\u2596\u2800", 
"\u2597\u2588\u2588\u2588\u2596",  
"\u259E\u2588\u2588\u2588\u259A",   
"\u2598\u2590\u2588\u258C\u259D",   
"\u2800\u259D\u2588\u2598\u2800", 
""
};

/* Prototipos de funciones del sistema de proyectiles del jugador */
int createPlayerBullet(int x, int y);  /* Crea nueva bala del jugador */
void updatePlayerBullets(void);        /* Actualiza posición de todas las balas */

/* Prototipos de funciones de detección de colisiones */
int checkCollision(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh);
void detectPlayerBulletHits(Alien aliens[], int totalAliens, int width, int height, int frameToggle, int scoreX, int scoreY);
void detectBulletCollisions();  /* Detecta colisión entre balas del jugador y aliens */
void updateScoreDisplay(int x, int y);  /* Actualiza el marcador de puntuación en pantalla */

/* Prototipos adicionales para sistema de disparos de aliens */
int bottomAlienIndexInColumn(Alien[], int, int, int, int);  /* Encuentra alien inferior en columna */
int createAlienBullet(int, int, int);                       /* Crea nueva bala alien */
void tryAlienShoot(Alien[], int, int, int, int, int);       /* Intenta disparar desde alien */
void updateAlienBullets(int, int);                          /* Actualiza balas de aliens */

/************************** Configuración del Jugador **************************/

/* Dimensiones del sprite del cañón del jugador (5x5 caracteres) */
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

char *cocoro[] = {
    "\u259F\u2599\u2597\u2588\u2596", 
    "\u2588\u2588\u2588\u2588\u258C",  
    "\u2588\u2588\u2588\u2588\u258C",   
    "\u259D\u2588\u2588\u259B\u2800",   
    "\u2800\u259D\u259B\u2800\u2800",
    ""
};

/* Funciones de dibujo de vidas del jugador */
void drawPlayerLives(int screenWidth);  /* Dibuja corazones en pantalla */

/* Configuración del sistema de vidas */
#define MAX_HEARTS 3           /* Número máximo de vidas */
int playerLives = MAX_HEARTS;  /* Vidas actuales del jugador */
int heartSpacing = 2;          /* Separación en caracteres entre corazones */

/* Estructura que representa al jugador */
typedef struct {
    int x;  /* Posición horizontal del cañón */
    int y;  /* Posición vertical del cañón */
} Player;

/* Prototipos de funciones relacionadas con el jugador */
void handlePlayerMovement(Player *p, int screenWidth);  /* Maneja controles del jugador */
int kbhit(void);  /* Detecta si se presionó una tecla sin bloquear programa */
void detectAlienBulletHitsPlayer(Player *player, int screenWidth);  /* Detecta impactos */
void playerHit(int lives, int screenWidth);  /* Maneja animación cuando jugador es golpeado */
void destroyPlayerBulletsAtTop();  /* Destruye balas que llegan al borde superior */

/* Variables para control de cadencia de disparo */
clock_t lastPlayerShot = 0;           /* Tiempo del último disparo realizado */
#define PLAYER_SHOT_COOLDOWN 1.5      /* Tiempo mínimo entre disparos (segundos) */

/* Prototipo de pantalla de fin de juego */
int showGameOverScreen(int screenWidth, int screenHeight);  /* Muestra pantalla final */



/******************************* Función Principal ****************************/

/* 
 * Función main: Punto de entrada del programa
 * 
 * Inicializa el juego, configura la pantalla, crea los aliens en formación,
 * y ejecuta el bucle principal que maneja toda la lógica del juego.
 */
int main() {

    /* Inicializar generador de números aleatorios con semilla basada en tiempo actual */
    srand((unsigned int)time(NULL));

    /* Desactivar buffering de stdout para control manual del output */
    setvbuf(stdout, NULL, _IOFBF, 8192);

    /* Variables para almacenar dimensiones de la consola */
    unsigned char screenWidth;
    unsigned char screenHeight;

    /* Obtener tamaño actual de la consola */
    Get_Console_Size( &screenWidth, &screenHeight );
    /* Ajustar ancho a número par para evitar problemas de alineación */
    screenWidth = ( screenWidth % 2 ? screenWidth - 1 : screenWidth );
    /* Limpiar pantalla antes de comenzar */
    Clear_Screen();

    /* Dibujar marco exterior del juego */
    Frame( 1, 1, screenWidth, screenHeight );
    /* Ocultar cursor para mejor estética */
    Cursor( 0 );
    
    /* Calcular dimensiones y posición para texto "SCORE" */
    int totalScore = sizeof(Score) / sizeof(Score[0]);
    int estWidth  = totalScore * 6;  /* Cada letra ocupa ~6 caracteres */
    int startXX    = 2;
    int startYY    = 2;

    /* Dibujar "SCORE" en amarillo brillante */
    printf(COLOR_BRIGHT_YELLOW);
    drawBigWord(startXX, startYY, Score, totalScore);
    printf(COLOR_RESET);

    /* Guardar posición del score para actualizaciones */
    int scoreX = startXX;
    int scoreY = startYY;

    /* Dibujar texto "DISPRO" (nombre del juego o empresa) */
    /* Mover más a la derecha: SCORE (5 letras × 6) + espacio + 4 dígitos (4 × 5) + margen */
    int totalDis = sizeof(dispro) / sizeof(dispro[0]);
    int disproX = startXX + (5 * 6) + 2 + (4 * 5) + 4;  /* Posición después del score y dígitos */
    drawBigWord(disproX, startYY, dispro, totalDis);

    /* Dimensiones de los sprites de aliens (todos son 3x3) */
    int width  = 3;
    int height = 3;

    /* Dirección de movimiento: 1=derecha, -1=izquierda */
    int direction = 1;

    /* Configuración de la formación de aliens */
    #define ROWS   3                /* Número de filas de aliens */
    #define ALIENS_PER_ROW 9        /* Aliens por cada fila */
    #define TOTAL_ALIENS (ROWS * ALIENS_PER_ROW)  /* Total de aliens en pantalla */

    /* Array que contiene todos los aliens del juego */
    Alien aliens[TOTAL_ALIENS];

    /* Parámetros de distribución espacial */
    int spacing = 2;  /* Espacio horizontal entre aliens */
    int startX = 4;   /* Posición X inicial de la formación */
    int startY = 8;   /* Posición Y inicial de la formación */

    /* Crear formación de aliens en matriz */
    int index = 0;
    for(int r = 0; r < ROWS; r++) {           /* Iterar por cada fila */
        for(int i = 0; i < ALIENS_PER_ROW; i++) {  /* Iterar por cada columna */

            /* Calcular posición X con espaciado */
            aliens[index].x = startX + i * (width + spacing);
            /* Calcular posición Y con separación entre filas */
            aliens[index].y = startY + r * (height + 1);

            /* Asignar tipo según fila (cada fila tiene un tipo diferente) */
            aliens[index].type = r;

            index++;
        }
    }

    /* Inicializar sistema de balas de aliens (todas inactivas al inicio) */
    for (int i = 0; i < MAX_ALIEN_BULLETS; i++) alienBullets[i].active = 0;

    /* Variable para alternar entre frames de animación (0=Frame A, 1=Frame B) */
    int frameToggle = 0;

    /* Inicializar puntuación del jugador */
    playerScore = 0;

    /* Inicializar jugador (cañón) */
    Player player;
    /* Centrar jugador horizontalmente en la pantalla */
    player.x = (screenWidth / 2) - (PLAYER_WIDTH / 2);
    /* Colocar jugador cerca del borde inferior, dejando margen */
    player.y = screenHeight - PLAYER_HEIGHT - 2;
    
    /* Dibujar sprite del jugador en color morado oscuro */
    printf("\x1b[38;5;55m");
    drawElement(playerSprite, player.x, player.y);
    printf("\x1b[0m");

    /* Inicializar vidas del jugador */
    playerLives = MAX_HEARTS;
    
    /* Dibujar indicador de vidas (corazones) en rojo brillante */
    printf("\x1b[91m");
    drawPlayerLives(screenWidth);
    printf("\x1b[0m");

    /* Contador de frames para controlar velocidad del juego */
    int fps = 0;

    /* Bucle principal del juego - continúa mientras el jugador tenga vidas */
    while( playerLives > 0 ) {

        /* Actualizar lógica del juego cada 60000 frames (controla velocidad) */
        if (fps >= 60000) {

            /* Detectar límites de pantalla para cambiar dirección */

            /* Encontrar posiciones extremas de la formación de aliens */
            int leftmost  = aliens[0].x;  /* Alien más a la izquierda */
            int rightmost = aliens[0].x;  /* Alien más a la derecha */
            int shouldMoveDown = 0;       /* Flag para bajar la formación */

            /* Buscar posiciones extremas entre todos los aliens vivos */
            for(int i = 1; i < TOTAL_ALIENS; i++) {
                if (aliens[i].x >= 0) {  /* Solo considerar aliens vivos */
                    if (aliens[i].x < leftmost) leftmost = aliens[i].x;
                    if (aliens[i].x > rightmost) rightmost = aliens[i].x;
                }
            }

            /* Si la formación toca el borde izquierdo */
            if (leftmost <= 2) {
                direction = 1;  /* Cambiar dirección a la derecha */
                shouldMoveDown = 1;
            }
            /* Si la formación toca el borde derecho */
            else if (rightmost >= screenWidth - width - 1) {
                direction = -1;  /* Cambiar dirección a la izquierda */
                shouldMoveDown = 1;
            }

            /* Alternar frame de animación para efecto de movimiento */
            frameToggle = !frameToggle;

            /* PASO 1: Borrar solo el borde que quedará expuesto de cada alien */
            for(int i = 0; i < TOTAL_ALIENS; i++) {
                if (aliens[i].x >= 0) {
                    /* Solo limpiar la columna que quedará vacía al moverse */
                    int clearX = (direction > 0) ? aliens[i].x : aliens[i].x + width - 1;
                    for(int row = 0; row < height; row++) {
                        gotoxy(clearX, aliens[i].y + row);
                        printf(" ");
                    }
                    /* Si baja, limpiar la fila superior */
                    if (shouldMoveDown) {
                        gotoxy(aliens[i].x, aliens[i].y);
                        printf("   "); /* 3 espacios = ancho del alien */
                    }
                }
            }

            /* PASO 2: Mover todos los aliens */
            for(int i = 0; i < TOTAL_ALIENS; i++) {
                if (aliens[i].x >= 0) {
                    aliens[i].x += direction;
                    if (shouldMoveDown) {
                        aliens[i].y++;
                    }
                }
            }

            /* PASO 3: Redibujar todos los aliens de una vez */
            for(int i = 0; i < TOTAL_ALIENS; i++) {
                if (aliens[i].x >= 0) {
                    char **newSprite = frameToggle ? AlienTypesB[ aliens[i].type ]
                                                   : AlienTypesA[ aliens[i].type ];
                    
                    /* Seleccionar color según tipo de alien (fila) */
                    switch(aliens[i].type) {
                        case 0: printf("\x1b[91m"); break;
                        case 1: printf("\x1b[92m"); break;
                        case 2: printf("\x1b[93m"); break;
                        default: printf("\x1b[94m"); break;
                    }
                    
                    drawElement( newSprite, aliens[i].x, aliens[i].y );
                }
            }
            printf("\x1b[0m");
            fflush(stdout); /* Enviar todo el buffer de una vez */

            /* Verificar si algún alien llegó a la altura del jugador (Game Over) */
            for(int i = 0; i < TOTAL_ALIENS; i++) {
                if (aliens[i].y + height >= player.y) {
                    /* Limpiar pantalla completamente */
                    Clear_Screen();

                    /* Mostrar pantalla de Game Over */
                    showGameOverScreen( screenWidth, screenHeight);

                    /* Terminar el bucle y salir del programa */
                    return 0;
                }
            }

            /* Probabilidad aleatoria de que los aliens disparen (1/22) */
            if ( rand() % 22 == 0 )
                tryAlienShoot(aliens, ROWS, ALIENS_PER_ROW, TOTAL_ALIENS, width, height);

            /* Actualizar posiciones y estados de todos los proyectiles */
            updateAlienBullets(screenHeight, width);
            updatePlayerBullets();
            
            /* Detectar todas las colisiones posibles */
            detectPlayerBulletHits(aliens, TOTAL_ALIENS, width, height, frameToggle, scoreX, scoreY);
            detectBulletCollisions();
            detectAlienBulletHitsPlayer(&player, screenWidth);
            destroyPlayerBulletsAtTop();

            /* Forzar envío de todo el buffer al terminal */
            fflush(stdout);

            /* Reiniciar contador de frames */
            fps = 0;

        }

        /* Procesar entrada del jugador (movimiento y disparo) */
        handlePlayerMovement(&player, screenWidth);

        /* Incrementar contador de frames */
        fps++;

    }

    /* Si se acaban las vidas, mostrar pantalla de Game Over */
    if (playerLives <= 0) {
        int option = showGameOverScreen(screenWidth, screenHeight);
        if (option == 1) {
             main();  /* Reiniciar juego si el jugador elige jugar de nuevo */
        }
    }

    return 0;

} /* main */

/************************* Implementación de Funciones ************************/

/*
 * drawElement: Dibuja un sprite en la pantalla
 * 
 * Recibe un array de strings (elemento) y lo dibuja línea por línea
 * en la posición especificada (x, y).
 */
void drawElement( char *element[], unsigned char x, unsigned char y )
{
    /* Iterar por cada línea del sprite hasta encontrar el terminador "" */
    for( int i = 0, j = 0; element[i][0] != '\0'; i++, j++ ) {
        gotoxy( x, y + j );  /* Posicionar cursor */
        printf( "%s\n", element[i] );  /* Imprimir línea */
    }
}

/*
 * drawBigWord: Dibuja una palabra grande usando sprites de letras
 * 
 * Parámetros:
 *   x, y: posición inicial
 *   letters: array de punteros a sprites de letras
 *   totalLetters: cantidad de letras a dibujar
 */
void drawBigWord(int x, int y, char **letters[], int totalLetters) {
    /* Dibujar cada fila del texto (las letras tienen 5 filas) */
    for (int row = 0; row < 5; row++) {
        gotoxy(x, y + row);
        /* Imprimir fila correspondiente de cada letra */
        for (int l = 0; l < totalLetters; l++) {
            printf("%s ", letters[l][row]);
        }
    }
}

/*
 * clearElement: Borra un sprite de la pantalla
 * 
 * Reemplaza el sprite con espacios en blanco para "borrarlo".
 * Calcula dinámicamente el ancho basándose en la longitud de cada línea.
 */
void clearElement( char *element[], unsigned char x, unsigned char y ) {
    /* Iterar por cada línea del sprite */
    for( int i = 0, j = 0; element[i][0] != '\0'; i++, j++ ) {
        gotoxy( x, y + j );
        /* Calcular el ancho de esta línea del sprite */
        int len = 0;
        for(int k = 0; element[i][k] != '\0'; ) {
            /* Contar caracteres Unicode (pueden ser multi-byte) */
            unsigned char c = element[i][k];
            if ((c & 0x80) == 0) k += 1;
            else if ((c & 0xE0) == 0xC0) k += 2;
            else if ((c & 0xF0) == 0xE0) k += 3;
            else if ((c & 0xF8) == 0xF0) k += 4;
            else k += 1;
            len++;
        }
        /* Imprimir espacios para borrar */
        for(int s = 0; s < len; s++) printf(" ");
    }
}

/*
 * Frame: Dibuja un marco decorativo usando caracteres Unicode
 * 
 * Parámetros:
 *   x, y: posición de la esquina superior izquierda
 *   dx, dy: ancho y alto del marco
 * 
 * Usa caracteres de línea redondeada Unicode para crear el borde.
 */
void Frame( unsigned char x, unsigned char y, unsigned char dx, unsigned char dy ) {
    /* Esquina superior izquierda */
    gotoxy( x, y );
    printf( "\u256D" );

    /* Línea superior horizontal */
    gotoxy( x+1, y );
    for( int i=x+1; i<x+dx-1; i++ )
        printf( "\u2500" );

    /* Esquina superior derecha */
    gotoxy( x+dx-1, y );
    printf( "\u256E" );

    /* Línea vertical izquierda */
    for( int j=y+1; j<y+dy-1; j++ ) {
        gotoxy( x, j );
        printf( "\u2502" );
    }

    /* Línea vertical derecha */
    for( int j=y+1; j<y+dy-1; j++ ) {
        gotoxy( x+dx-1, j );
        printf( "\u2502" );
    }

    /* Esquina inferior izquierda */
    gotoxy( x, y+dy-1 );
    printf( "\u2570" );

    /* Línea inferior horizontal */
    gotoxy( x+1, y+dy-1 );
    for( int i=x+1; i<x+dx-1; i++ )
        printf( "\u2500" );

    /* Esquina inferior derecha */
    gotoxy( x+dx-1, y+dy-1 );
    printf( "\u256F" );
}

/*
 * Delay_Seconds: Implementa una pausa sin bloquear
 * 
 * Parámetros:
 *   delay: tiempo en segundos a esperar
 * 
 * Usa clock() para crear una pausa activa (busy-wait).
 */
void Delay_Seconds( float delay ) {
    float previous = (float)clock() / CLOCKS_PER_SEC;
    /* Esperar hasta que transcurra el tiempo deseado */
    while( (float)clock() / CLOCKS_PER_SEC - previous < delay )
        ;
}

/******************** Sistema de Disparos de Aliens **************************/

/*
 * bottomAlienIndexInColumn: Encuentra el alien más bajo de una columna
 * 
 * Busca el alien vivo que esté más abajo en una columna específica.
 * Esto es necesario para que solo dispare el alien más cercano al jugador.
 * 
 * Parámetros:
 *   aliens: array con todos los aliens
 *   col: número de columna a revisar
 *   rows, cols: dimensiones de la matriz de aliens
 *   totalAliens: total de aliens en el juego
 * 
 * Retorna: índice del alien más bajo, o -1 si no hay aliens vivos en esa columna
 */
int bottomAlienIndexInColumn(Alien aliens[], int col, int rows, int cols, int totalAliens)
{
    int bestIndex = -1;
    /* Recorrer todas las filas de la columna especificada */
    for (int r = 0; r < rows; r++) {
        int idx = r * cols + col;  /* Calcular índice en el array */
        /* Validaciones de seguridad */
        if (idx < 0 || idx >= totalAliens) continue;
        if (aliens[idx].x < 0) continue;  /* Saltar aliens muertos */
        /* Actualizar si es el más bajo encontrado hasta ahora */
        if (bestIndex == -1 || aliens[idx].y > aliens[bestIndex].y)
            bestIndex = idx;
    }
    return bestIndex;
}

/*
 * createAlienBullet: Crea una nueva bala de alien
 * 
 * Busca un slot disponible en el array de balas de aliens y lo activa
 * con la posición especificada.
 * 
 * Parámetros:
 *   x, y: posición inicial de la bala
 *   ownerCol: columna del alien que disparó (para evitar múltiples disparos)
 * 
 * Retorna: 1 si se creó exitosamente, 0 si no hay slots disponibles
 */
int createAlienBullet(int x, int y, int ownerCol)
{
    /* Buscar slot inactivo en el array de balas */
    for (int i = 0; i < MAX_ALIEN_BULLETS; i++) {
        if (!alienBullets[i].active) {
            /* Inicializar la nueva bala */
            alienBullets[i].active = 1;
            alienBullets[i].x = x;
            alienBullets[i].y = y;
            alienBullets[i].ownerCol = ownerCol;
            return 1;  /* Éxito */
        }
    }
    return 0;  /* No hay espacio disponible */
}

/*
 * tryAlienShoot: Intenta hacer que un alien dispare
 * 
 * Selecciona aleatoriamente una columna que no tenga balas activas
 * y hace que el alien más bajo de esa columna dispare.
 * 
 * Parámetros:
 *   aliens: array con todos los aliens
 *   rows, cols: dimensiones de la matriz
 *   totalAliens: total de aliens
 *   width, height: dimensiones de los sprites
 */
void tryAlienShoot(Alien aliens[], int rows, int cols, int totalAliens, int width, int height)
{
    /* Array temporal para almacenar columnas candidatas */
    int colsIdx[ALIENS_PER_ROW];
    int colsCount = 0;

    /* Identificar columnas que pueden disparar */
    for (int c = 0; c < cols; c++) {
        /* Buscar alien más bajo en esta columna */
        int ai = bottomAlienIndexInColumn(aliens, c, rows, cols, totalAliens);
        if (ai != -1) {
            /* Verificar si ya hay una bala activa de esta columna */
            int columnHasBullet = 0;
            for (int b = 0; b < MAX_ALIEN_BULLETS; b++) {
                if (alienBullets[b].active && alienBullets[b].ownerCol == c) {
                    columnHasBullet = 1;
                    break;
                }
            }
            /* Solo agregar si no tiene balas activas */
            if (!columnHasBullet) {
                colsIdx[colsCount++] = ai;
            }
        }
    }

    /* Si no hay columnas disponibles, salir */
    if (colsCount == 0) return;

    /* Seleccionar aleatoriamente una columna de las disponibles */
    int pickIdx = colsIdx[ rand() % colsCount ];
    int ownerCol = pickIdx % cols;

    /* Calcular posición inicial de la bala (centrada en el alien) */
    int bx = aliens[pickIdx].x + 2;  /* Centrar horizontalmente (sprite 5x5) */
    int by = aliens[pickIdx].y + height;  /* Debajo del alien */

    /* Crear la bala */
    createAlienBullet(bx, by, ownerCol);
}

/*
 * updateAlienBullets: Actualiza todas las balas de aliens
 * 
 * Borra, mueve y redibuja todas las balas activas de los aliens.
 * Desactiva balas que salen de la pantalla.
 * 
 * Parámetros:
 *   screenHeight: altura de la pantalla para detectar límite
 *   width: ancho de los sprites (no usado actualmente)
 */
void updateAlienBullets(int screenHeight, int width)
{
    /* Procesar cada bala en el array */
    for (int i = 0; i < MAX_ALIEN_BULLETS; i++) {

        if (!alienBullets[i].active) continue;  /* Saltar balas inactivas */

        /* Borrar sprite anterior (5 líneas de 5 espacios) */
        for (int l = 0; l < 5; l++) {
            gotoxy(alienBullets[i].x, alienBullets[i].y + l);
            printf("     ");
        }

        /* Mover bala hacia abajo */
        alienBullets[i].y += 1;

        /* Desactivar si sale de la pantalla */
        if (alienBullets[i].y >= screenHeight - 5) {
            alienBullets[i].active = 0;
            continue;
        }
        
        /* Redibujar bala en nueva posición con color amarillo brillante */
        printf("\x1b[93m");
        drawElement(alienShotSprite, alienBullets[i].x, alienBullets[i].y);
        printf("\x1b[0m");
    }
}

/******************** Control y Manejo del Jugador ***************************/

/*
 * kbhit: Detecta si se presionó una tecla sin bloquear
 * 
 * Implementa detección no bloqueante de teclas usando termios.
 * Esta función permite al juego continuar ejecutándose mientras
 * espera input del usuario.
 * 
 * Retorna: 1 si hay una tecla disponible, 0 si no
 */
int kbhit( void ){
    struct termios oldt, newt;
    int ch;
    int oldf;

    /* Obtener configuración actual del terminal */
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    /* Deshabilitar modo canónico y echo */
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    /* Configurar lectura no bloqueante */
    oldf = fcntl( STDIN_FILENO, F_GETFL, 0 );
    fcntl( STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK );

    /* Intentar leer un carácter */
    ch = getchar();

    /* Restaurar configuración original del terminal */
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    fcntl( STDIN_FILENO, F_SETFL, oldf );

    /* Si se leyó algo, devolverlo al buffer */
    if( ch != EOF ) {
        ungetc( ch, stdin );
        return 1;
    }

return 0;
}

/*
 * handlePlayerMovement: Procesa entrada del usuario para mover y disparar
 * 
 * Detecta teclas presionadas y actualiza posición del jugador o dispara.
 * Soporta flechas y teclas A/D para movimiento, W/Espacio para disparar.
 * Implementa cooldown para evitar disparo continuo.
 * 
 * Parámetros:
 *   p: puntero a estructura del jugador
 *   screenWidth: ancho de pantalla para límites de movimiento
 */
void handlePlayerMovement(Player *p, int screenWidth){
    if (!kbhit()) return;  /* Salir si no hay tecla presionada */

    int ch = getchar();  /* Leer carácter */

    /* Detectar secuencias de escape (flechas) */
    if (ch == 0 || ch == 224) {
        int ch2 = getchar();  /* Leer segundo byte */
        if (ch2 == 75) {  /* Flecha izquierda */
            clearElement(playerSprite, p->x, p->y);
            if (p->x > 2) p->x--;  /* Mover si no está en el borde */
            printf("\x1b[38;5;55m");
            drawElement(playerSprite, p->x, p->y);
            printf("\x1b[0m");
        }
        else if (ch2 == 77) {  /* Flecha derecha */
            clearElement(playerSprite, p->x, p->y);
            if (p->x < screenWidth - PLAYER_WIDTH - 2) p->x++;  /* Mover si no está en el borde */
            printf("\x1b[38;5;55m");
            drawElement(playerSprite, p->x, p->y);
            printf("\x1b[0m");
        }
    } else {
        /* Procesar teclas normales */
        clearElement(playerSprite, p->x, p->y);
        
        if (ch == 'a' || ch == 'A') { 
            if (p->x > 2) p->x--;  /* Mover izquierda */
        }
        else if (ch == 'd' || ch == 'D') { 
            if (p->x < screenWidth - PLAYER_WIDTH - 2) p->x++;  /* Mover derecha */
        }
        else if (ch == ' ' || ch == 'w' || ch == 'W') {
            /* Manejar disparo con cooldown */
            clock_t now = clock();
            float secondsSinceLastShot = (float)(now - lastPlayerShot) / CLOCKS_PER_SEC;

            /* Solo disparar si pasó suficiente tiempo desde el último disparo */
            if (secondsSinceLastShot >= PLAYER_SHOT_COOLDOWN) {
                /* Crear bala centrada en el jugador */
                createPlayerBullet(p->x + PLAYER_WIDTH/2, p->y - 1);
                lastPlayerShot = now;  /* Actualizar tiempo del último disparo */
            }
        }
        
        /* Redibujar jugador en nueva posición */
        printf("\x1b[38;5;55m");
        drawElement(playerSprite, p->x, p->y);
        printf("\x1b[0m");
    }
}

/*
 * createPlayerBullet: Crea una nueva bala del jugador
 * 
 * Busca un slot disponible en el array de balas y lo inicializa.
 * 
 * Parámetros:
 *   x, y: posición inicial de la bala
 * 
 * Retorna: 1 si se creó exitosamente, 0 si no hay espacio
 */
int createPlayerBullet(int x, int y){
    /* Buscar slot inactivo */
    for(int i = 0; i < MAX_PLAYER_BULLETS; i++) {
        if(!playerBullets[i].active) {
            playerBullets[i].active = 1;
            playerBullets[i].x = x - 2;  /* Centrar sprite 5x5 */
            playerBullets[i].y = y - 4;  /* Colocar arriba del jugador */
            return 1;
        }
    }
    return 0;  /* No hay espacio disponible */
}

/*
 * updatePlayerBullets: Actualiza todas las balas del jugador
 * 
 * Borra, mueve y redibuja todas las balas activas del jugador.
 * Las balas se mueven hacia arriba y se desactivan al salir de pantalla.
 */
void updatePlayerBullets(void){
    /* Procesar cada bala */
    for(int i = 0; i < MAX_PLAYER_BULLETS; i++) {
        if(!playerBullets[i].active) continue;  /* Saltar inactivas */

        /* Borrar posición anterior (sprite 5x5) */
        for(int l = 0; l < 5; l++) {
            gotoxy(playerBullets[i].x, playerBullets[i].y + l);
            printf("     ");
        }

        /* Mover hacia arriba */
        playerBullets[i].y -= 1;

        /* Desactivar si sale de la pantalla */
        if(playerBullets[i].y < 1) {
            playerBullets[i].active = 0;
            continue;
        }

        /* Dibujar en nueva posición con color verde neón */
        printf("\x1b[38;5;46m");
        drawElement(playerShotSprite, playerBullets[i].x, playerBullets[i].y);
        printf("\x1b[0m");

    }
}

/******************* Sistema de Detección de Colisiones ***********************/

/*
 * updateScoreDisplay: Actualiza el marcador de puntuación en pantalla
 * 
 * Convierte la puntuación actual a dígitos y los dibuja usando sprites
 * grandes en la posición del marcador.
 * 
 * Parámetros:
 *   x, y: posición base del texto "SCORE"
 */
void updateScoreDisplay(int x, int y) {
    /* Array con punteros a sprites de dígitos */
    char **digitSprites[] = {
        ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE
    };
    
    /* Convertir puntuación a string de 4 dígitos con ceros a la izquierda */
    char scoreStr[5];
    snprintf(scoreStr, 5, "%04d", playerScore);
    
    /* Calcular posición inicial de los dígitos (después de "SCORE") */
    int digitStartX = x + (5 * 6) + 2; /* 5 letras en "SCORE" × 6 caracteres + espacio */
    
    /* Dibujar cada dígito usando su sprite grande */
    printf(COLOR_BRIGHT_YELLOW);
    for (int i = 0; i < 4; i++) {
        int digit = scoreStr[i] - '0';  /* Convertir carácter a número */
        char **sprite = digitSprites[digit];
        
        /* Dibujar cada línea del sprite del dígito */
        for (int row = 0; row < 5; row++) {
            gotoxy(digitStartX + (i * 5), y + row);  /* 5 caracteres de ancho por dígito */
            printf("%s", sprite[row]);
        }
    }
    printf(COLOR_RESET);
}

/*
 * checkCollision: Detecta colisión entre dos rectángulos
 * 
 * Usa algoritmo de detección de colisión AABB (Axis-Aligned Bounding Box).
 * Dos rectángulos colisionan si se superponen en ambos ejes.
 * 
 * Parámetros:
 *   ax, ay: posición del primer rectángulo (esquina superior izquierda)
 *   aw, ah: ancho y alto del primer rectángulo
 *   bx, by: posición del segundo rectángulo
 *   bw, bh: ancho y alto del segundo rectángulo
 * 
 * Retorna: 1 si hay colisión, 0 si no
 */
int checkCollision(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh) {
    /* Verificar que NO haya separación en ningún eje */
    return !(ax + aw - 1 < bx ||   /* A completamente a la izquierda de B */
             ax > bx + bw - 1 ||   /* A completamente a la derecha de B */
             ay + ah - 1 < by ||   /* A completamente arriba de B */
             ay > by + bh - 1);    /* A completamente abajo de B */
}

/*
 * detectPlayerBulletHits: Detecta impactos de balas del jugador en aliens
 * 
 * Verifica colisión entre cada bala activa del jugador y cada alien vivo.
 * Al detectar impacto, muestra animación de explosión, desactiva ambos y
 * actualiza la puntuación según el tipo de alien destruido.
 * 
 * Parámetros:
 *   aliens: array de aliens
 *   totalAliens: cantidad total de aliens
 *   width, height: dimensiones de los sprites de aliens
 *   frameToggle: frame actual de animación (para borrar sprite correcto)
 *   scoreX, scoreY: posición del marcador de puntuación
 */
void detectPlayerBulletHits(Alien aliens[], int totalAliens, int width, int height, int frameToggle, int scoreX, int scoreY) {
    /* Puntos por tipo de alien (fila 0 = más puntos, fila 2 = menos puntos) */
    int pointsPerAlien[] = { 30, 20, 10, 40, 50 };
    /* Revisar cada bala activa */
    for(int b = 0; b < MAX_PLAYER_BULLETS; b++) {
        if(!playerBullets[b].active) continue;

        /* Revisar colisión con cada alien vivo */
        for(int a = 0; a < totalAliens; a++) {
            if(aliens[a].x < 0) continue;  /* Saltar aliens ya destruidos */

            /* Verificar colisión usando hitboxes */
            if(checkCollision(
                aliens[a].x, aliens[a].y, width, height,
                playerBullets[b].x, playerBullets[b].y, 5, 3
            )) {
                /* Colisión detectada - procesar impacto */

                /* Borrar la bala de la pantalla */
                for(int l = 0; l < 5; l++) {
                    gotoxy(playerBullets[b].x, playerBullets[b].y + l);
                    printf("     ");
                }

                /* Desactivar la bala */
                playerBullets[b].active = 0;

                /* Borrar sprite del alien */
                clearElement(frameToggle ? AlienTypesB[ aliens[a].type ] : AlienTypesA[ aliens[a].type ],
                            aliens[a].x, aliens[a].y);
                
                /* Mostrar animación de explosión */
                printf("\x1b[31m");  /* Color rojo */
                drawElement(kaboom, aliens[a].x, aliens[a].y);
                printf("\x1b[0m");

                Delay_Seconds(0.5);  /* Duración de la explosión */
                clearElement( kaboom, aliens[a].x, aliens[a].y );

                /* Actualizar puntuación según tipo de alien */
                playerScore += pointsPerAlien[aliens[a].type];
                updateScoreDisplay(scoreX, scoreY);

                /* Marcar alien como destruido (moverlo fuera de pantalla) */
                aliens[a].x = -100;
                aliens[a].y = -100;
                break;  /* Una bala solo puede destruir un alien */
                }
            }
        }
    }

/*
 * detectBulletCollisions: Detecta colisiones entre balas del jugador y aliens
 * 
 * Verifica si alguna bala del jugador impacta con una bala de alien.
 * Al colisionar, ambas balas se destruyen con animación de explosión.
 */
void detectBulletCollisions() {
    /* Revisar cada bala del jugador */
    for(int i = 0; i < MAX_PLAYER_BULLETS; i++) {
        if(!playerBullets[i].active) continue;

        /* Revisar contra cada bala de alien */
        for(int j = 0; j < MAX_ALIEN_BULLETS; j++) {
            if(!alienBullets[j].active) continue;

            /* Verificar colisión entre las balas */
            if(checkCollision(
                playerBullets[i].x, playerBullets[i].y, 5, 5,   /* Bala jugador */
                alienBullets[j].x, alienBullets[j].y, 5, 5      /* Bala alien */
            )) {
                /* Borrar ambas balas de la pantalla */
                for(int l = 0; l < 5; l++) {
                    gotoxy(playerBullets[i].x, playerBullets[i].y + l);
                    printf("     ");
                    gotoxy(alienBullets[j].x, alienBullets[j].y + l);
                    printf("     ");
                }
                
                /* Mostrar explosiones en ambas posiciones */
                printf("\x1b[31m");
                drawElement(kaboom, playerBullets[i].x, playerBullets[i].y);
                drawElement(kaboom, alienBullets[j].x, alienBullets[j].y);
                printf("\x1b[0m");

                Delay_Seconds(0.5);  /* Duración de las explosiones */
                
                /* Limpiar explosiones */
                clearElement( kaboom, playerBullets[i].x, playerBullets[i].y );
                clearElement( kaboom, alienBullets[j].x, alienBullets[j].y );

                /* Marcar ambas balas como inactivas */
                playerBullets[i].active = 0;
                alienBullets[j].active = 0;
            }
        }
    }
}

/*
 * detectAlienBulletHitsPlayer: Detecta si alguna bala alien impactó al jugador
 * 
 * Revisa colisión entre balas de aliens y el sprite del jugador.
 * Al detectar impacto, reduce vidas, muestra animación y actualiza HUD.
 * 
 * Parámetros:
 *   player: puntero a estructura del jugador
 *   screenWidth: ancho de pantalla para actualizar indicador de vidas
 */
void detectAlienBulletHitsPlayer(Player *player, int screenWidth) {
    /* Revisar cada bala de alien activa */
    for(int i = 0; i < MAX_ALIEN_BULLETS; i++) {
        if(!alienBullets[i].active) continue;

        /* Verificar colisión con hitbox del jugador */
        if(checkCollision(
            alienBullets[i].x, alienBullets[i].y, 5, 5,      /* Bala alien */
            player->x, player->y, PLAYER_WIDTH, PLAYER_HEIGHT /* Jugador */
        )) {
            /* Borrar bala de la pantalla */
            for(int l = 0; l < 5; l++) {
                gotoxy(alienBullets[i].x, alienBullets[i].y + l);
                printf("     ");
            }
            
            /* Mostrar explosión en posición de la bala */
            printf("\x1b[31m");
            drawElement(kaboom, alienBullets[i].x, alienBullets[i].y);
            printf("\x1b[0m");

            Delay_Seconds(0.5);  /* Duración de explosión */
            clearElement( kaboom, alienBullets[i].x, alienBullets[i].y );

            /* Desactivar bala */
            alienBullets[i].active = 0;
            
            /* Reducir vidas del jugador */
            if(playerLives > 0) {
                playerLives--;
            }
            
            /* Actualizar indicador de vidas en pantalla */
            printf("\x1b[31m");
            drawPlayerLives(screenWidth);
            printf("\x1b[0m");

            /* Ejecutar animación de impacto */
            playerHit(playerLives, screenWidth);

            break;  /* Solo procesar un impacto por iteración */
        }
    }
}

/*
 * drawPlayerLives: Dibuja el indicador de vidas (corazones) en pantalla
 * 
 * Muestra los corazones restantes en la esquina superior derecha.
 * Primero limpia la zona completa y luego dibuja solo los corazones activos.
 * 
 * Parámetros:
 *   screenWidth: ancho de pantalla para calcular posición de los corazones
 */
void drawPlayerLives(int screenWidth) {
    /* Limpiar zona de vidas completa (para los 3 corazones posibles) */
    for(int i = 0; i < MAX_HEARTS; i++) {
        for(int y = 0; y < 6; y++) {  /* Altura del sprite del corazón */
            /* Posicionar en esquina superior derecha */
            gotoxy(screenWidth - (i+1)*(6 + heartSpacing), 2 + y);
            printf("      ");  /* Limpiar espacio */
        }
    }

    /* Dibujar los corazones restantes */
    for(int i = 0; i < playerLives; i++) {
        /* Dibujar cada línea del sprite del corazón */
        for(int y = 0; cocoro[y][0] != '\0'; y++) {
            gotoxy(screenWidth - (i+1)*(6 + heartSpacing), 2 + y);
            printf("%s", cocoro[y]);
        }
    }
}

/*
 * playerHit: Animación cuando el jugador pierde una vida
 * 
 * Muestra una explosión sobre el corazón que se acaba de perder.
 * Proporciona feedback visual del impacto recibido.
 * 
 * Parámetros:
 *   lives: vidas restantes (para calcular qué corazón animar)
 *   screenWidth: ancho de pantalla para posicionar animación
 */
void playerHit(int lives, int screenWidth) {

    /* Calcular posición del corazón perdido */
    int heartX = screenWidth - (lives+1)*(6 + heartSpacing);
    int heartY = 2;

    /* Mostrar explosión sobre el corazón perdido */
    printf("\x1b[91m");  /* Rojo brillante */
    drawElement(kaboom, heartX, heartY);
    printf("\x1b[0m");

    Delay_Seconds(0.5);  /* Duración de la animación */
    clearElement(kaboom, heartX, heartY);
}

/*
 * destroyPlayerBulletsAtTop: Destruye balas que llegan al límite superior
 * 
 * Evita que las balas del jugador se acumulen indefinidamente en el
 * borde superior. Las desactiva con animación al alcanzar cierta altura.
 */
void destroyPlayerBulletsAtTop() {
    /* Revisar cada bala activa del jugador */
    for (int b = 0; b < MAX_PLAYER_BULLETS; b++) {
        if (!playerBullets[b].active) continue;

        /* Si la bala llegó al límite superior */
        if (playerBullets[b].y <= 6) {
            /* Mostrar explosión en la posición de la bala */
            drawElement(kaboom, playerBullets[b].x, playerBullets[b].y);
            Delay_Seconds(0.3);
            clearElement(kaboom, playerBullets[b].x, playerBullets[b].y);

            /* Desactivar bala */
            playerBullets[b].active = 0;
        }
    }
}

/*
 * showGameOverScreen: Muestra la pantalla de Game Over
 * 
 * Presenta al jugador opciones para jugar de nuevo o salir.
 * Muestra mensajes de fin de juego, puntuación y récord.
 * 
 * Parámetros:
 *   screenWidth, screenHeight: dimensiones de la pantalla
 * 
 * Retorna: 1 si el jugador quiere jugar otra vez, 0 si quiere salir
 */
int showGameOverScreen(int screenWidth, int screenHeight) {
    Clear_Screen();  /* Limpiar pantalla completamente */

    /* Calcular centro de la pantalla */
    int centerX = screenWidth / 2;
    int startY = screenHeight / 2 - 5;

    /* Dibujar mensaje "BAD LUCK" */
    drawBigWord(centerX - 15, startY - 15, badLuck, sizeof(badLuck) / sizeof(badLuck[0]));

    /* Dibujar mensaje "TRY AGAIN" */
    drawBigWord(centerX - 15, startY -3, tryAgain, sizeof(tryAgain) / sizeof(tryAgain [0]));

    /* Mostrar puntuación actual */
    drawBigWord(centerX - 15, startY + 13, Score, sizeof(Score) / sizeof(Score [0]));

    /* Mostrar récord histórico */
    drawBigWord(centerX - 20, startY + 20, highScore, sizeof(highScore) / sizeof(highScore [0]));

    /* Mostrar instrucciones al jugador */
    gotoxy(centerX - 13, startY + 8);
    printf("Press ENTER to play again or ESC to exit");

    /* Esperar decisión del jugador */
    while (1) {
        if (kbhit()) {
            int ch = getchar();
            if (ch == 13) {      /* ENTER - reiniciar */
                return 1;
            } else if (ch == 27) { /* ESC - salir */
                return 0;
            }
        }
    }
}


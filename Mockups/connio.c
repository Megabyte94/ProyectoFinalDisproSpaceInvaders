/* Ruler 1         2         3         4         5         6         7        */

/*
 * connio.c - Implementación de funciones de control de consola
 * 
 * Este archivo contiene la implementación de todas las funciones declaradas
 * en connio.h. Utiliza secuencias de escape ANSI estándar para manipular
 * la apariencia y comportamiento de la terminal.
 * 
 * Las secuencias ANSI son códigos especiales que las terminales modernas
 * interpretan para realizar acciones como cambiar colores o mover el cursor.
 */

/* Inclusión de bibliotecas del sistema necesarias */
#include <stdio.h>      /* Funciones de entrada/salida (printf) */
#include <stdint.h>     /* Tipos de datos de tamaño fijo */
#include <sys/ioctl.h>  /* Control de dispositivos de E/S (para obtener tamaño de consola) */

/* Inclusión de bibliotecas del sistema necesarias */
#include <stdio.h>      /* Funciones de entrada/salida (printf) */
#include <stdint.h>     /* Tipos de datos de tamaño fijo */
#include <sys/ioctl.h>  /* Control de dispositivos de E/S (para obtener tamaño de consola) */

/********************* Implementación de Funciones Públicas *******************/

/* 
 * Funciones de configuración de color de texto
 * 
 * Todas estas funciones utilizan la secuencia ANSI: \033[<código>m
 * donde <código> determina el estilo y color a aplicar.
 * 
 * Códigos ANSI utilizados:
 * - 0m: Reset (valores predeterminados)
 * - 0;3Xm: Colores Light (X = 0-7 para negro a blanco)
 * - 1;3Xm: Colores Dark (mayor intensidad)
 * - 0;9Xm: Colores Thin (brillantes)
 * - 1;9Xm: Colores Bold (negrita brillante)
 * - 4Xm: Colores de fondo (X = 0-7)
 * 
 * Autor: J.C.Giraldo
 * Fecha: 31 de Octubre, 2021
 */

void Reset()       { printf("\033[0m"); }  /* Restablecer formato predeterminado */

/* Paleta Light - Colores estándar */

void Reset()       { printf("\033[0m"); }  /* Restablecer formato predeterminado */

/* Paleta Light - Colores estándar */
void Light_Black() { printf("\033[0;30m"); }
void Light_Red()   { printf("\033[0;31m"); }
void Light_Green() { printf("\033[0;32m"); }
void Light_Yellow(){ printf("\033[0;33m"); }
void Light_Blue()  { printf("\033[0;34m"); }
void Light_Purple(){ printf("\033[0;35m"); }
void Light_Cyan()  { printf("\033[0;36m"); }
void Light_White() { printf("\033[0;37m"); }

/* Paleta Dark - Mayor intensidad */
void Dark_Black()  { printf("\033[1;30m"); }
void Dark_Red()    { printf("\033[1;31m"); }
void Dark_Green()  { printf("\033[1;32m"); }
void Dark_Yellow() { printf("\033[1;33m"); }
void Dark_Blue()   { printf("\033[1;34m"); }
void Dark_Purple() { printf("\033[1;35m"); }
void Dark_Cyan()   { printf("\033[1;36m"); }
void Dark_White()  { printf("\033[1;37m"); }

/* Paleta Thin - Colores brillantes de baja intensidad */
void Thin_Black()  { printf("\033[0;90m"); }
void Thin_Red()    { printf("\033[0;91m"); }
void Thin_Green()  { printf("\033[0;92m"); }
void Thin_Yellow() { printf("\033[0;93m"); }
void Thin_Blue()   { printf("\033[0;94m"); }
void Thin_Purple() { printf("\033[0;95m"); }
void Thin_Cyan()   { printf("\033[0;96m"); }
void Thin_White()  { printf("\033[0;97m"); }

/* Paleta Bold - Colores en negrita brillante */
void Bold_Black()  { printf("\033[1;90m"); }
void Bold_Red()    { printf("\033[1;91m"); }
void Bold_Green()  { printf("\033[1;92m"); }
void Bold_Yellow() { printf("\033[1;93m"); }
void Bold_Blue()   { printf("\033[1;94m"); }
void Bold_Purple() { printf("\033[1;95m"); }
void Bold_Cyan()   { printf("\033[1;96m"); }
void Bold_White()  { printf("\033[1;97m"); }

/* Colores de fondo */
void Back_Black()  { printf("\033[40m"); }
void Back_Red()    { printf("\033[41m"); }
void Back_Green()  { printf("\033[42m"); }
void Back_Yellow() { printf("\033[43m"); }
void Back_Blue()   { printf("\033[44m"); }
void Back_Purple() { printf("\033[45m"); }
void Back_Cyan()   { printf("\033[46m"); }
void Back_White()  { printf("\033[47m"); }

void Back_White()  { printf("\033[47m"); }

/* 
 * Servicios de manipulación de consola 
 */

/*
 * Clear_Screen: Limpia la pantalla de la terminal
 * 
 * Utiliza la secuencia ANSI:
 * - \033[H: Mueve el cursor a posición (1,1)
 * - \033[J: Borra desde el cursor hasta el final de la pantalla
 * 
 * Juntas, estas secuencias limpian toda la pantalla eficientemente.
 * 
 * Autor: J.C.Giraldo
 * Fecha: 31 de Octubre, 2020
 */
void Clear_Screen()
{
printf("\033[H\033[J");

} /* Clear_Screen */


/*
 * gotoxy: Posiciona el cursor en coordenadas específicas
 * 
 * Mueve el cursor a la posición (x, y) en la terminal usando
 * la secuencia ANSI \033[<y>;<x>f
 * 
 * Parámetros:
 *   x: columna (posición horizontal)
 *   y: fila (posición vertical)
 * 
 * Nota: Las coordenadas empiezan en (1,1) en la esquina superior izquierda
 * 
 * Autor: J.C.Giraldo
 * Fecha: 31 de Octubre, 2020
 */
void gotoxy( uint8_t x, uint8_t y )
{
printf( "\033[%d;%df", y, x );

} /* gotoxy */


/*
 * Cursor: Controla la visibilidad del cursor
 * 
 * Muestra u oculta el cursor de la terminal usando secuencias ANSI:
 * - \x1B[?25h: Mostrar cursor
 * - \x1B[?25l: Ocultar cursor
 * 
 * Parámetros:
 *   status: 1 para mostrar, 0 para ocultar
 * 
 * Útil para crear interfaces limpias donde el cursor parpadeante
 * puede resultar distractor.
 * 
 * Autor: J.C.Giraldo
 * Fecha: 15 de Junio, 2021
 */
void Cursor( int status )
{
status ? printf( "\x1B[?25h" ) : printf( "\x1B[?25l" );

} /* Cursor */


/*
 * Set_Console_Size: Establece el tamaño de la ventana de consola
 * 
 * Intenta redimensionar la ventana de terminal usando la secuencia
 * ANSI \033[8;<y>;<x>t
 * 
 * Parámetros:
 *   x: número de columnas
 *   y: número de filas
 * 
 * Nota: No todas las terminales soportan esta funcionalidad por
 * motivos de seguridad. Funciona mejor en terminales como xterm.
 * 
 * Autor: J.C.Giraldo
 * Fecha: 31 de Octubre, 2020
 */
void Set_Console_Size( uint8_t x, uint8_t y )
{
printf( "\033[8;%d;%dt", y, x );

} /* Set_Console_Size */


/*
 * Get_Console_Size: Obtiene las dimensiones actuales de la consola
 * 
 * Usa ioctl() con TIOCGWINSZ para consultar el tamaño de la ventana
 * de terminal al sistema operativo. Esta es la forma más confiable
 * de obtener dimensiones en sistemas Unix/Linux.
 * 
 * Parámetros:
 *   x: puntero donde se guardará el número de columnas
 *   y: puntero donde se guardará el número de filas
 * 
 * Estructura winsize contiene:
 *   ws_col: número de columnas
 *   ws_row: número de filas
 * 
 * Autor: J.C.Giraldo
 * Fecha: 31 de Octubre, 2020
 */
void Get_Console_Size( unsigned char *x, unsigned char *y )
{
struct winsize w;
ioctl( 0, TIOCGWINSZ, &w );  /* Consultar tamaño al sistema */
*x = w.ws_col;  /* Asignar número de columnas */
*y = w.ws_row;  /* Asignar número de filas */

} /* Get_Console_Size */


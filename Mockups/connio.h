/* Ruler 1         2         3         4         5         6         7        */

/*
 * connio.h - Biblioteca de control de consola
 * 
 * Proporciona funciones para manipular la consola en sistemas Unix/Linux
 * mediante secuencias de escape ANSI. Permite control de colores, posición
 * del cursor, y configuración de la terminal.
 * 
 * Esta biblioteca es esencial para crear interfaces de usuario en modo texto
 * con colores y posicionamiento preciso de elementos.
 */

#ifndef	CONIO_H
#define CONIO_H

/* Inclusión de cabeceras estándar necesarias */
#include <stdint.h>  /* Para tipos de datos de tamaño fijo (uint8_t) */

/* Inclusión de cabeceras estándar necesarias */
#include <stdint.h>  /* Para tipos de datos de tamaño fijo (uint8_t) */

/*********************** Prototipos de Funciones Públicas *********************/

/* 
 * Funciones de configuración de colores de texto
 * 
 * Estas funciones utilizan códigos ANSI para cambiar el color del texto
 * en la terminal. Se dividen en cuatro categorías:
 * 
 * - Light: Colores estándar claros
 * - Dark: Colores con mayor intensidad
 * - Thin: Colores con menor intensidad  
 * - Bold: Colores en negrita/brillantes
 * - Back: Colores de fondo
 */

void Reset();  /* Restablece formato predeterminado de la terminal */

/* Paleta de colores Light (intensidad estándar) */
void Light_Black();
void Light_Red();
void Light_Green();
void Light_Yellow();
void Light_Blue();
void Light_Purple();
void Light_Cyan();
void Light_White();

/* Paleta de colores Dark (alta intensidad) */
void Dark_Black();
void Dark_Red();
void Dark_Green();
void Dark_Yellow();
void Dark_Blue();
void Dark_Purple();
void Dark_Cyan();
void Dark_White();

/* Paleta de colores Thin (baja intensidad) */
void Thin_Black();
void Thin_Red();
void Thin_Green();
void Thin_Yellow();
void Thin_Blue();
void Thin_Purple();
void Thin_Cyan();
void Thin_White();

/* Paleta de colores Bold (negrita/brillante) */
void Bold_Black();
void Bold_Red();
void Bold_Green();
void Bold_Yellow();
void Bold_Blue();
void Bold_Purple();
void Bold_Cyan();
void Bold_White();

/* Configuración de colores de fondo */
void Back_Black();
void Back_Red();
void Back_Green();
void Back_Yellow();
void Back_Blue();
void Back_Purple();
void Back_Cyan();
void Back_White();

void Back_White();

/* 
 * Servicios de manipulación de consola
 * 
 * Funciones para controlar el comportamiento y apariencia de la terminal.
 */

/* Clear_Screen: Limpia completamente la pantalla de la terminal */
void Clear_Screen();

/* gotoxy: Posiciona el cursor en coordenadas específicas (x, y) */
void gotoxy( uint8_t, uint8_t );

/* Cursor: Muestra (1) u oculta (0) el cursor de la terminal */
void Cursor( int );

/* Set_Console_Size: Establece las dimensiones de la ventana de consola */
void Set_Console_Size( uint8_t, uint8_t );

/* Get_Console_Size: Obtiene las dimensiones actuales de la consola
 * Los valores se retornan por referencia en los punteros x (columnas) e y (filas) */
void Get_Console_Size( uint8_t *, uint8_t * );

#endif 

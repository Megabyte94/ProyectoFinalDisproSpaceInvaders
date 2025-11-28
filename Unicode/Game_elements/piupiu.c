#define UNICODE
#include <stdio.h>
#include <locale.h>


char *piupiu[] = {
"\u2800\u2597\u2584\u2596\u2800", 
"\u2597\u2588\u2588\u2588\u2596",  
"\u259E\u2588\u2588\u2588\u259A",   
"\u2598\u2590\u2588\u258C\u259D",   
"\u2800\u259D\u2588\u2598\u2800", 
 ""
};


// u2800 para nada 
// u2588 para uno entero


int main(void) {
    printf("Obstacle 1:\n");

    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; piupiu[i][0] != '\0'; ++i) {
        puts(piupiu[i]);
    }
    return 0;
}


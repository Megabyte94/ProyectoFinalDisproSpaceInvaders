#define UNICODE
#include <stdio.h>
#include <locale.h>


char *kaboom[] = {
"\u2596\u259A\u2800\u259E\u2597", 
"\u259D\u2596\u2800\u2597\u2598",  
"\u259A\u2800\u2800\u2800\u259E",   
"\u2597\u2598\u2800\u259D\u2596",   
"\u2598\u259E\u2800\u259A\u259D",
""
};


// u2800 para nada 
// u2588 para uno entero


int main(void) {
    printf("Obstacle 1:\n");

    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; kaboom[i][0] != '\0'; ++i) {
        puts(kaboom[i]);
    }
    return 0;
}


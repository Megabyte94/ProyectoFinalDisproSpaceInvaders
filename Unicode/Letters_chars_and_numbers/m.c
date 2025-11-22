#define UNICODE
// O = \u2588
// P = \u2800
// L = \u2599
// J = \u259F


char *M[] = {
"\u2588\u2800\u2800\u2588", 
"\u2588\u2599\u259F\u2588",  
"\u2588\u259C\u259B\u2588",   
"\u2588\u259D\u2598\u2588",   
"\u2588\u2800\u2800\u2588",   
""
};

#include <stdio.h>
#include <locale.h>

int main(void) {
    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; M[i][0] != '\0'; ++i) {
        puts(M[i]);
    }
    return 0;
}
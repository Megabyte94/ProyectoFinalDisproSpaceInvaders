#define UNICODE
// O = \u2588
// P = \u2800
// L = \u2599
// J = \u259F


char *K[] = {
"\u2588\u2800\u2597\u2588", 
"\u2588\u2584\u2588\u2598",  
"\u2588\u2588\u258C\u2800",   
"\u2588\u2580\u5888\u2596",   
"\u2588\u2800\u259D\u2588",
"" 
};

#include <stdio.h>
#include <locale.h>

int main(void) {
    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; K[i][0] != '\0'; ++i) {
        puts(K[i]);
    }
    return 0;
}
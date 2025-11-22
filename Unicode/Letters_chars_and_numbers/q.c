#define UNICODE
// O = \u2588
// P = \u2800
// L = \u2599
// J = \u259F


char *Q[] = {
"\u2590\u2588\u2588\u258C",  
"\u2588\u2800\u2800\u2588",  
"\u2588\u2800\u2800\u2588",   
"\u2588\u2800\u2588\u2588",   
"\u2590\u2588\u2588\u2588",
""
};

#include <stdio.h>
#include <locale.h>

int main(void) {
    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; Q[i][0] != '\0'; ++i) {
        puts(Q[i]);
    }
    return 0;
}
#define UNICODE
// O = \u2588
// P = \u2800
// L = \u2599
// J = \u259F


char *J[] = {
"\u2800\u2800\u2800\u2588", 
"\u2800\u2800\u2800\u2588",  
"\u2584\u2800\u2800\u2588",   
"\u2588\u2800\u2800\u2588",   
"\u2580\u2588\u2588\u2580",
"" 
};

#include <stdio.h>
#include <locale.h>

int main(void) {
    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; J[i][0] != '\0'; ++i) {
        puts(J[i]);
    }
    return 0;
}
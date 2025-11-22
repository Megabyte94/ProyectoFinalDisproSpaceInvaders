#define UNICODE
#include <stdio.h>
#include <locale.h>


char *alien2[] = {
"\u2590\u2597\u2800\u2596\u258C",   /*▐▗⠀▖▌*/
"\u259D\u2588\u2588\u2588\u2598",   /*▝███▘*/
"\u259F\u258C\u2588\u2590\u2599",   /*▟▌█▐▙*/
"\u259F\u2580\u2580\u2580\u2599",   /*▟▀▀▀▙*/
"\u2599\u2800\u2800\u2800\u259F",   /*▙⠀⠀⠀▟*/
""
};


// u2800 para nada 
// u2588 para uno entero


int main(void) {
    printf("Alien 2:\n");

    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; alien2[i][0] != '\0'; ++i) {
        puts(alien2[i]);
    }
    return 0;
}


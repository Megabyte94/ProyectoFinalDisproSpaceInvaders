#define UNICODE
#include <stdio.h>
#include <locale.h>


char *cannon[] = {
"\u2800\u2800\u2588\u2800\u2800",   /*   █   */
"\u2590\u2597\u2588\u2596\u258C",   /* ▐▗█▖▌ */
"\u259F\u2588\u2588\u2588\u2599",   /* ▟███▙ */
"\u259C\u2588\u2588\u2588\u259B",   /* ▜███▛ */
"\u259D\u259D\u2588\u2598\u2598",   /* ▝▝█▘▘ */
""
};


// u2800 para nada 
// u2588 para uno entero


int main(void) {
    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; cannon[i][0] != '\0'; ++i) {
        puts(cannon[i]);
    }
    return 0;
}


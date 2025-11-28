#define UNICODE
#define O  "\u2588"
#define P  "\u2800"
#define L  "\u2599"
#define J  "\u259F"


char *G[] = {
    "\u2588\u2588\u2588\u2588",
    "\u2588\u2800\u2800\u2800",
    "\u2588\u2800\u2588\u2588",
    "\u2588\u2800\u2800\u2588",
    "\u2588\u2588\u2588\u2588"
    ""
};


// u2800 para nada 
// u2588 para uno entero



#include <stdio.h>
#include <locale.h>

int main(void) {
    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; G[i][0] != '\0'; ++i) {
        puts(G[i]);
    }
    return 0;
}
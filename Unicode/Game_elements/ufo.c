#define UNICODE
#include <stdio.h>
#include <locale.h>


char *ufo[] = {
    "\u2800\u2800\u2584\u2800\u2800",
    "\u2800\u259F\u2588\u2599\u2800",
    "\u259F\u2588\u2588\u2588\u2599",
    "\u259C\u2588\u2588\u2588\u259B",
    "\u2800\u2580\u2580\u2580\u2800", 
    ""
};


// u2800 para nada 
// u2588 para uno entero


int main(void) {
    printf("UFO:\n");

    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; ufo[i][0] != '\0'; ++i) {
        puts(ufo[i]);
    }
    return 0;
}


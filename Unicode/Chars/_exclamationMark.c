#define UNICODE

char *exclamationMark[] = {
    "\u2588\u2800\u2800\u2800",
    "\u2588\u2800\u2800\u2800",
    "\u2588\u2800\u2800\u2800",
    "\u2800\u2800\u2800\u2800",
    "\u2588\u2800\u2800\u2800",
    ""
};


// u2800 para nada 
// u2588 para uno entero



#include <stdio.h>
#include <locale.h>

int main(void) {
    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; exclamationMark[i][0] != '\0'; ++i) {
        puts(exclamationMark[i]);
    }
    return 0;
}
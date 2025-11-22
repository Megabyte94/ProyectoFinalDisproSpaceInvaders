#define UNICODE
#include <stdio.h>
#include <locale.h>


char *obstacle1[] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
};


// u2800 para nada 
// u2588 para uno entero


int main(void) {
    printf("Obstacle 1:\n");

    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; obstacle1[i][0] != '\0'; ++i) {
        puts(obstacle1[i]);
    }
    return 0;
}


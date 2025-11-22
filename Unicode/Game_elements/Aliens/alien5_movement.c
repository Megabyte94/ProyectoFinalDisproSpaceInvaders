#define UNICODE
#include <stdio.h>
#include <locale.h>


char *alien5_movement[] = {
"\u2597\u259F\u2588\u2599\u2596",   /*▗▟█▙▖*/
"\u2588\u2588\u2588\u2588\u2588",   /*█████*/
"\u2588\u2584\u2588\u2584\u2588",   /*█▄█▄█*/
"\u2800\u2580\u2584\u2580\u2800",   /*⠀▀▄▀⠀*/
"\u2800\u2800\u2580\u2800\u2800",   /*⠀⠀▀⠀⠀*/
""
};


// u2800 para nada 
// u2588 para uno entero


int main(void) {
    printf("Alien 5 (movement):\n");

    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; alien5_movement[i][0] != '\0'; ++i) {
        puts(alien5_movement[i]);
    }
    return 0;
}


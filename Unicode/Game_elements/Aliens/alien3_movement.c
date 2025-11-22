#define UNICODE
#include <stdio.h>
#include <locale.h>


char *alien3_movement[] = {
"\u2800\u2597\u2588\u2596\u2800",   /*⠀▗█▖⠀*/
"\u2597\u2588\u2584\u2588\u2596",   /*▗█▄█▖*/
"\u259C\u259F\u2584\u2599\u259B",   /*▜▟▄▙▛*/
"\u2597\u2580\u2588\u2580\u2596",   /*▗▀█▀▖*/
"\u2590\u2596\u2588\u2597\u258C",   /*▐▖█▗▌*/
""
};


// u2800 para nada 
// u2588 para uno entero


int main(void) {
    printf("Alien 3 (movement):\n");

    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; alien3_movement[i][0] != '\0'; ++i) {
        puts(alien3_movement[i]);
    }
    return 0;
}


#define UNICODE
#include <stdio.h>
#include <locale.h>


char *alien3[] = {
"\u2800\u2597\u2588\u2596\u2800",   /*⠀▗█▖⠀*/
"\u2597\u2588\u2584\u2588\u2596",   /*▗█▄█▖*/
"\u259C\u259F\u2584\u2599\u259B",   /*▜▟▄▙▛*/
"\u2597\u259C\u2580\u259B\u2596",   /*▗▜▀▛▖*/
"\u259F\u2590\u2800\u258C\u2599",   /*▟▐⠀▌▙*/
""
};


// u2800 para nada 
// u2588 para uno entero


int main(void) {
    printf("Alien 3:\n");

    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; alien3[i][0] != '\0'; ++i) {
        puts(alien3[i]);
    }
    return 0;
}


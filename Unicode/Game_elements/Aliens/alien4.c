#define UNICODE
#include <stdio.h>
#include <locale.h>


char *alien4[] = {
"\u2800\u259F\u2588\u2599\u2800",   /*⠀▟█▙⠀*/
"\u259F\u2580\u2588\u2580\u2599",   /*▟▀█▀▙*/
"\u2580\u259C\u2588\u259B\u2580",   /*▀▜██▛▀*/
"\u2800\u259E\u2800\u259A\u2800",   /*⠀▞⠀▚⠀*/
"\u259E\u2800\u2800\u2800\u259A",   /*▞⠀⠀⠀▚*/
""
};


// u2800 para nada 
// u2588 para uno entero


int main(void) {
    printf("Alien 4:\n");

    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; alien4[i][0] != '\0'; ++i) {
        puts(alien4[i]);
    }
    return 0;
}


#define UNICODE
#include <stdio.h>
#include <locale.h>


char *alien1_movement[] = {
"\u2800\u2580\u2584\u2580\u2800",   /*⠀▀▄▀⠀*/    
"\u258C\u259F\u2588\u2599\u2590",   /*▌▟█▙▐*/  
"\u2588\u258C\u2588\u2590\u2588",   /*█▌█▐█*/  
"\u259D\u2588\u2588\u2588\u2598",   /*▝███▘*/  
"\u2800\u2590\u2584\u258C\u2800",   /*⠀▐▄▌⠀*/
""
};


// u2800 para nada 
// u2588 para uno entero


int main(void) {
    printf("Alien 1 (movement):\n");

    /* Asegura que la salida use la codificación local (normalmente UTF-8 en macOS) */
    setlocale(LC_ALL, "");

    for (size_t i = 0; alien1_movement[i][0] != '\0'; ++i) {
        puts(alien1_movement[i]);
    }
    return 0;
}


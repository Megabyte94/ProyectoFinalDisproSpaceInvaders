#include <stdio.h>
#include <stdint.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#include "connio.h"

/* ---------------------------------- OBJETOS -------------------------------- */

char *alien1[] = {
    "\u2800\u2580\u2584\u2580\u2800",
    "\u258C\u259F\u2588\u2599\u2590",
    "\u2588\u258C\u2588\u2590\u2588",
    "\u259D\u2588\u2588\u2588\u2598",
    "\u2597\u259E\u2800\u259A\u2596",
    ""
};

char *cannon[] = {
    "\u2800\u2800\u2588\u2800\u2800",
    "\u2590\u2597\u2588\u2596\u258C",
    "\u259F\u2588\u2588\u2588\u2599",
    "\u259C\u2588\u2588\u2588\u259B",
    "\u259D\u259D\u2588\u2598\u2598",
    ""
};


/* ---------------------------- FUNCIONES GENERALES -------------------------- */

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void draw_at(uint8_t x, uint8_t y, char *object[])
{
    for (int i = 0; *object[i] != '\0'; i++)
    {
        gotoxy(x, y + i);
        printf("%s", object[i]);
    }
}

void clear_at(uint8_t x, uint8_t y, char *object[])
{
    for (int i = 0; *object[i] != '\0'; i++)
    {
        gotoxy(x, y + i);
        int w = strlen(object[i]) / 3;
        for (int j = 0; j < w; j++)
            printf(" ");
    }
}


/* ---------------------------------- MAIN ---------------------------------- */

int main(void)
{
    uint8_t cols, rows;
    Get_Console_Size(&cols, &rows);

    /* Alien */
    int ax = 5, ay = 3;
    int adx = 2;
    int alien_w = strlen(alien1[0])/3;

    /* Cannon */
    int cx = cols/2;
    int cy = rows - 6;
    int cannon_w = strlen(cannon[0])/3;

    Clear_Screen();
    Cursor(0);

    printf("Controles: j = izquierda, l = derecha, q = salir\n");

    /* Bucle principal */
    while (1)
    {
        /* ----- DIBUJAR OBJETOS ----- */
        draw_at(ax, ay, alien1);
        draw_at(cx, cy, cannon);

        usleep(60000);

        /* ----- BORRAR OBJETOS ----- */
        clear_at(ax, ay, alien1);
        clear_at(cx, cy, cannon);

        /* ----- MOVIMIENTO ALIEN ----- */
        ax += adx;
        if (ax <= 1 || ax >= (cols - alien_w - 1))
        {
            adx = -adx;
            ay += 1;
        }

        /* ----- LECTURA DE TECLAS ----- */
        if (kbhit())
        {
            char c = getchar();
            if (c == 'q')
                break;
            if (c == 'j' && cx > 1)
                cx -= 2;
            if (c == 'l' && cx + cannon_w < cols)
                cx += 2;
        }
    }

    Cursor(1);
    Clear_Screen();
    return 0;
}

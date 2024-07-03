#include "turtle.h"
void circulo(int c, int l, int a) {
    if(c < 1) {
        return;
    }
    else
    {
        turtle_forward(l);
        turtle_turn_left(a);
        return circulo(--c,l,a);
    }
}
void circulos(int c) {
    if(c < 1) {
        return;
    }
    else
    {
        circulo(120,c,3);
        return circulos(--c);
    }
}
void dibujo(int c)
{
    turtle_reset();
    turtle_turn_right(c*60);
    turtle_pen_down();
    circulos(7);
}
void osa(int c) {
    if(c < 1) {
        return;
    }
    else
    {
        dibujo(c);
        return osa(--c);
    }

}

int main()
{
    turtle_init(900, 900);
    osa(6);
    turtle_draw_turtle();
    turtle_save_bmp("output.bmp");
    return 0;
}


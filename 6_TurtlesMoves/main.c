#include "Turtles_mov_1.h"


int main(int argc, char const *argv[])
{
 
    turtle_init(900, 600);
    turtle_set_fill_color(350,555,455);

    dibujar(0);

    turtle_save_bmp("output.bmp");


    return 0;
}

    


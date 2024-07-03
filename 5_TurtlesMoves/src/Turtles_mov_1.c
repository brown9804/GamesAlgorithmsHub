#include "Turtles_mov_1.h"

void figura(int angulo)
{
    if (angulo==0)
    {
        
        return;
    } else {

        //turtle_backup();
        turtle_reset();
        turtle_set_pen_color(rand() %255,rand() %255,rand() %255);
        //turtle_restore();
        turtle_set_heading(angulo);

        turtle_pen_down();
        
        turtle_forward(55);
        turtle_turn_right(95);
        turtle_forward(45);
        turtle_turn_left(95);
        turtle_forward(75);
        turtle_turn_right(40);
        turtle_forward(45);
        turtle_turn_left(105);
        turtle_forward(65);
        turtle_turn_right(50);
        turtle_forward(55);
        turtle_draw_turtle();
    
    }
        
}
    
void dibujar(int ang) {
    if(ang > 360 ) {
        return;
    } else {
        figura(ang);
        return dibujar(ang+(360/15));

    }

}

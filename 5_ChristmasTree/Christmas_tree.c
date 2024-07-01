#include <stdlib.h>
#include "./turtle.h"
#include <stdio.h>

void create_tree(int m){
    if(m > 4){
        turtle_forward(m/14);
        turtle_turn_left(90);
        create_tree(m*0.4);
        turtle_turn_right(90);
        turtle_turn_right(90);
        create_tree(m*0.4);
        turtle_turn_left(90);
        create_tree(m*0.87);
        turtle_backward(m/14);
    }
}
void tree(){
    turtle_pen_up();
    turtle_goto(0, -280);
    turtle_turn_left(90);
    turtle_pen_down();
    create_tree(1200);
}
int main(){
    turtle_init(600, 600);
    tree();
    turtle_save_bmp("Christmas_tree.bmp");
    return 0;
}

#include "invaders.h"


int f_pantallaendgame(){


  sfVideoMode pj = {800, 600 , 32};
  sfRenderWindow* w3;
  w3 = sfRenderWindow_create(pj, "SPACE INVADERS", sfClose, NULL);

  sfEvent e3;

  //texto ENDGAME
  sfText* endgame;
  endgame = sfText_create();
  sfText_setString(endgame, "END GAME");
  sfText_setCharacterSize(endgame, 70);
  sfText_setPosition(endgame, (sfVector2f){240,50});
  sfText_setFont(endgame, sfFont_createFromFile("resources/Athletic.TTF"));
  sfText_setColor(endgame, sfColor_fromRGB(144,12,63) );


  //texto SCORES
  sfText* scores;
  scores = sfText_create();
  sfText_setString(scores, "SCORES");
  sfText_setCharacterSize(scores, 40);
  sfText_setPosition(scores, (sfVector2f){330,140});
  sfText_setFont(scores, sfFont_createFromFile("resources/Athletic.TTF"));
  sfText_setColor(scores, sfBlack);

  sfTexture* texture1;
  texture1 = sfTexture_createFromFile("resources/enemy2.png", NULL);
  sfSprite* enemy1;
  enemy1 = sfSprite_create();
  sfSprite_setTexture(enemy1, texture1, sfTrue);
  sfSprite_setPosition(enemy1, (sfVector2f){110, 526});
  sfSprite_setScale(enemy1, (sfVector2f){0.14,0.14});

  sfTexture* texture2;
  texture2 = sfTexture_createFromFile("resources/enemy1.png", NULL);
  sfSprite* enemy2;
  enemy2 = sfSprite_create();
  sfSprite_setTexture(enemy2, texture2, sfTrue);
  sfSprite_setPosition(enemy2, (sfVector2f){357, 522});
  sfSprite_setScale(enemy2, (sfVector2f){0.15,0.15});

  sfTexture* texture3;
  texture3 = sfTexture_createFromFile("resources/enemy3.png", NULL);
  sfSprite* enemy3;
  enemy3 = sfSprite_create();
  sfSprite_setTexture(enemy3, texture3, sfTrue);
  sfSprite_setPosition(enemy3, (sfVector2f){580, 520});
  sfSprite_setScale(enemy3, (sfVector2f){0.16,0.16});




  while(sfRenderWindow_isOpen(w3)){
    while(sfRenderWindow_pollEvent(w3, &e3)){

      if(e3.type == sfEvtClosed){
        printf("Cerrando\n");
        sfRenderWindow_close(w3);
      }//else if{

        //obtener datos del file donde se guardan los puntajes
        //hacer la comparacion de datos
        //agregar nuevo puntaje en caso de
        //imprimirlos en pantalla

      }

      sfRenderWindow_clear(w3, sfWhite);
      sfRenderWindow_drawText(w3,endgame, NULL);
      sfRenderWindow_drawText(w3, scores, NULL);
      sfRenderWindow_drawSprite(w3, enemy1, NULL);
      sfRenderWindow_drawSprite(w3, enemy2, NULL);
      sfRenderWindow_drawSprite(w3, enemy3, NULL);
      sfRenderWindow_display(w3);

    }


    sfText_destroy(endgame);
    sfText_destroy(scores);
    sfSprite_destroy(enemy1);
    sfSprite_destroy(enemy2);
    sfSprite_destroy(enemy3);
    sfRenderWindow_destroy(w3);




    return 0;
  }

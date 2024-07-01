#include "invaders.h"

sfText* SPACE;
sfText* scoretable;
//Imagenes de los enemigos y texto de los puntos
sfTexture* texture1;
sfText* score1;
sfTexture* texture2;
sfText* score2;
sfTexture* texture3;
sfText* score3;
sfTexture* texture4;
sfText* score4;
sfSprite* enemy1;
sfSprite* enemy2;
sfSprite* enemy3;
sfSprite* enemy4;
//boton PLAY
sfSprite* bplay;
sfTexture* texture5;
//boton MUltijugador
sfSprite* bmultip;
sfTexture* texture6;


int cargar_inicio(void) {
  SPACE = sfText_create();
  sfText_setString(SPACE, "SPACE INVADERS");
  sfText_setCharacterSize(SPACE, 80);
  sfText_setPosition(SPACE, (sfVector2f){100,50});
  sfText_setFont(SPACE, sfFont_createFromFile("resources/Athletic.TTF"));
  sfText_setColor(SPACE, sfColor_fromRGB(144,12,63) );

  scoretable = sfText_create();
  sfText_setString(scoretable, "SCORE ADVANCE TABLE");
  sfText_setCharacterSize(scoretable, 20);
  sfText_setPosition(scoretable, (sfVector2f){300,170});
  sfText_setFont(scoretable, sfFont_createFromFile("resources/Athletic.TTF"));
  sfText_setColor(scoretable, sfBlack);

  texture1 = sfTexture_createFromFile("resources/enemy2.png", NULL);
  enemy1 = sfSprite_create();
  sfSprite_setTexture(enemy1, texture1, sfTrue);
  sfSprite_setPosition(enemy1, (sfVector2f){300, 220});
  sfSprite_setScale(enemy1, (sfVector2f){0.1,0.1});

  score1 = sfText_create();
  sfText_setString(score1, "= 10 points");
  sfText_setCharacterSize(score1, 20);
  sfText_setPosition(score1, (sfVector2f){380,230});
  sfText_setFont(score1, sfFont_createFromFile("resources/232MKRL_.TTF"));
  sfText_setColor(score1, sfBlack);

  texture2 = sfTexture_createFromFile("resources/enemy1.png", NULL);
  enemy2 = sfSprite_create();
  sfSprite_setTexture(enemy2, texture2, sfTrue);
  sfSprite_setPosition(enemy2, (sfVector2f){295, 270});
  sfSprite_setScale(enemy2, (sfVector2f){0.12,0.12});

  score2 = sfText_create();
  sfText_setString(score2, "= 20 points");
  sfText_setCharacterSize(score2, 20);
  sfText_setPosition(score2, (sfVector2f){380,290});
  sfText_setFont(score2, sfFont_createFromFile("resources/232MKRL_.TTF"));
  sfText_setColor(score2, sfBlack);

  texture3 = sfTexture_createFromFile("resources/enemy3.png", NULL);
  enemy3 = sfSprite_create();
  sfSprite_setTexture(enemy3, texture3, sfTrue);
  sfSprite_setPosition(enemy3, (sfVector2f){293, 330});
  sfSprite_setScale(enemy3, (sfVector2f){0.13,0.13});

  score3 = sfText_create();
  sfText_setString(score3, "= 30 points");
  sfText_setCharacterSize(score3, 20);
  sfText_setPosition(score3, (sfVector2f){380,350});
  sfText_setFont(score3, sfFont_createFromFile("resources/232MKRL_.TTF"));
  sfText_setColor(score3, sfBlack);

  texture4 = sfTexture_createFromFile("resources/enemy4.png", NULL);
  enemy4 = sfSprite_create();
  sfSprite_setTexture(enemy4, texture4, sfTrue);
  sfSprite_setPosition(enemy4, (sfVector2f){300, 395});
  sfSprite_setScale(enemy4, (sfVector2f){0.17,0.17});

  score4 = sfText_create();
  sfText_setString(score4, "= 40 points ");
  sfText_setCharacterSize(score4, 20);
  sfText_setPosition(score4, (sfVector2f){380,410});
  sfText_setFont(score4, sfFont_createFromFile("resources/232MKRL_.TTF"));
  sfText_setColor(score4, sfBlack);

  texture5 = sfTexture_createFromFile("resources/playbut.jpg", NULL);
  bplay = sfSprite_create();
  sfSprite_setTexture(bplay, texture5, sfTrue);
  sfSprite_setPosition(bplay, (sfVector2f){300, 460});
  sfSprite_setScale(bplay, (sfVector2f){0.3,0.3});

//  texture6 = sfTexture_createFromFile("resources/multiplayerbut.jpg", NULL);
//  bmultip = sfSprite_create();
//  sfSprite_setTexture(bmultip, texture6, sfTrue);
//  sfSprite_setPosition(bmultip, (sfVector2f){325, 530});
//  sfSprite_setScale(bmultip, (sfVector2f){0.4,0.4});

  return 0;
}

int dibujar_inicio(sfRenderWindow* w){
  sfRenderWindow_clear(w, sfWhite);
  sfRenderWindow_drawText(w,SPACE, NULL);
  sfRenderWindow_drawText(w, scoretable, NULL);
  sfRenderWindow_drawSprite(w, enemy1, NULL);
  sfRenderWindow_drawText(w, score1, NULL);
  sfRenderWindow_drawSprite(w, enemy2, NULL);
  sfRenderWindow_drawText(w, score2, NULL);
  sfRenderWindow_drawSprite(w, enemy3, NULL);
  sfRenderWindow_drawText(w, score3, NULL);
  sfRenderWindow_drawSprite(w, enemy4, NULL);
  sfRenderWindow_drawText(w, score4, NULL);
  sfRenderWindow_drawSprite(w, bplay, NULL);
  sfRenderWindow_drawSprite(w, bmultip, NULL);
  sfRenderWindow_display(w);
}

enum pantallas eventos_inicio(sfRenderWindow* w, sfEvent *e){
  switch(e->type) {
    case sfEvtMouseButtonPressed:
      // Boton de play?
      if (e->mouseButton.x > 300 &&
          e->mouseButton.x < 495 &&
          e->mouseButton.y > 460 &&
          e->mouseButton.y < 515) {
        return JUEGO;
      }
      if (e->mouseButton.x > 325 &&
          e->mouseButton.x < 470 &&
          e->mouseButton.y > 530 &&
          e->mouseButton.y < 570){
          return JUEGO;
        }
      break;
  }

  return INICIO;
}

//
//   while(sfRenderWindow_isOpen(w)){
//     while(sfRenderWindow_pollEvent(w, &e)){
//
//       if(e.type == sfEvtClosed){
//         printf("Cerrando\n");
//         sfRenderWindow_close(w);
//       }else if(e.type ==sfEvtKeyPressed){
//
//         //if boton jugar
//         // if boton multijugador
//         // if
//
//       }
//     }
//
//     sfRenderWindow_clear(w, sfWhite);
//     sfRenderWindow_drawText(w,SPACE, NULL);
//     sfRenderWindow_drawText(w, scoretable, NULL);
//     sfRenderWindow_drawSprite(w, enemy1, NULL);
//     sfRenderWindow_drawText(w, score1, NULL);
//     sfRenderWindow_drawSprite(w, enemy2, NULL);
//     sfRenderWindow_drawText(w, score2, NULL);
//     sfRenderWindow_drawSprite(w, enemy3, NULL);
//     sfRenderWindow_drawText(w, score3, NULL);
//     sfRenderWindow_drawSprite(w, enemy4, NULL);
//     sfRenderWindow_drawText(w, score4, NULL);
//     sfRenderWindow_drawSprite(w, bplay, NULL);
//     sfRenderWindow_drawSprite(w, bmultip, NULL);
//     sfRenderWindow_display(w);
//
//   }
//
//
//   sfText_destroy(SPACE);
//   sfText_destroy(scoretable);
//   sfSprite_destroy(enemy1);
//   sfSprite_destroy(enemy2);
//   sfSprite_destroy(enemy3);
//   sfSprite_destroy(enemy4);
//   sfSprite_destroy(bmultip);
//   sfSprite_destroy(bplay);
//   sfText_destroy(score4);
//   sfText_destroy(score1);
//   sfText_destroy(score2);
//   sfText_destroy(score3);
//   sfRenderWindow_destroy(w);
//
//   return 0;
// }

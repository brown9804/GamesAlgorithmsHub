#include "invaders.h"

int score = 0;
int vidas = 3;

sfTexture* naveText;
sfTexture* naveIzquierda;
sfTexture* naveDerecha;
sfTexture* naveCentro;
sfTexture* balaText;
sfSprite* balaSprite;
sfSprite* naveSprite;
sfText* primerscore;
sfText* segundoscore;
sfText* hiscore;
sfText* credit;
sfText* life;
sfText* gameover;
sfRectangleShape* c;
sfSprite* barrier1;
sfTexture* texture;
sfSprite* barrier2;
sfTexture* texture2;
sfSprite* barrier3;
sfTexture* texture3;
sfSprite* barrier4;
sfTexture* texture4;
sfText* paused;

sfSprite* enemy1Sprite;
sfTexture* enemy1Texture;
sfSprite* enemy2Sprite;
sfTexture* enemy2Texture;
sfSprite* enemy3Sprite;
sfTexture* enemy3Texture;
sfSprite* enemy4Sprite;
sfTexture* enemy4Texture;

//?
int naveSpriteX=380;
int naveSpriteY=480;

bool pausado=false;

struct barrera {
  int x;
  int y;
  int vida;
}; 
struct barrera b[4] = {
              [0].x = 120, [0].y = 430, [0].vida = 3,
              [1].x = 280, [1].y = 430, [1].vida = 3,
              [2].x = 440, [2].y = 430, [2].vida = 3,
              [3].x = 600, [3].y = 430, [3].vida = 3};

void pausar(){

	pausado=!pausado;

}

int cargar_juego(void) {
  //Sprites y texturas de la nave y balas

  //texto SCORE <1>
  primerscore = sfText_create();
  sfText_setString(primerscore, "SCORE <1>");
  sfText_setCharacterSize(primerscore, 30);
  sfText_setPosition(primerscore, (sfVector2f){40,50});
  sfText_setFont(primerscore, sfFont_createFromFile("resources/232MKRL_.TTF"));
  sfText_setColor(primerscore, sfBlack);

  //texto SCORE <2>
  segundoscore = sfText_create();
  sfText_setString(segundoscore, "SCORE <2>");
  sfText_setCharacterSize(segundoscore, 30);
  sfText_setPosition(segundoscore, (sfVector2f){550,50});
  sfText_setFont(segundoscore, sfFont_createFromFile("resources/232MKRL_.TTF"));
  sfText_setColor(segundoscore, sfBlack);

  //texto HI-SCORE
  hiscore = sfText_create();
  sfText_setString(hiscore, "HI-SCORE");
  sfText_setCharacterSize(hiscore, 40);
  sfText_setPosition(hiscore, (sfVector2f){300,50});
  sfText_setFont(hiscore, sfFont_createFromFile("resources/232MKRL_.TTF"));
  sfText_setColor(hiscore, sfBlack);

  //texto credit
  credit = sfText_create();
  sfText_setString(credit, "Credit 00");
  sfText_setCharacterSize(credit, 20);
  sfText_setPosition(credit, (sfVector2f){650,550});
  sfText_setFont(credit, sfFont_createFromFile("resources/232MKRL_.TTF"));
  sfText_setColor(credit, sfBlack);

  life = sfText_create();
  sfText_setString(life, "Lives 3");
  sfText_setCharacterSize(life, 20);
  sfText_setPosition(life, (sfVector2f){50,550});
  sfText_setFont(life, sfFont_createFromFile("resources/232MKRL_.TTF"));
  sfText_setColor(life, sfBlack);

  //fix
  gameover = sfText_create();
  sfText_setString(gameover, "GAME OVER");
  sfText_setCharacterSize(gameover, 60);
  sfText_setPosition(gameover, (sfVector2f){250,330});
  sfText_setFont(gameover, sfFont_createFromFile("resources/Athletic.TTF"));
  sfText_setColor(gameover, sfRed);

  //linea
  c = sfRectangleShape_create();
  sfRectangleShape_setFillColor(c, sfBlack);
  sfRectangleShape_setPosition(c, (sfVector2f){ 50, 545 });
  sfRectangleShape_setSize(c, (sfVector2f){ 710, 3 });

  //Protección
  texture = sfTexture_createFromFile("resources/barrier.png", NULL);
  barrier1 = sfSprite_create();
  sfSprite_setTexture(barrier1, texture, sfTrue);
  sfSprite_setPosition(barrier1, (sfVector2f){120, 430});
  sfSprite_setScale(barrier1, (sfVector2f){0.25,0.25});

  texture2 = sfTexture_createFromFile("resources/barrier.png", NULL);
  barrier2 = sfSprite_create();
  sfSprite_setTexture(barrier2, texture2, sfTrue);
  sfSprite_setPosition(barrier2, (sfVector2f){280, 430});
  sfSprite_setScale(barrier2, (sfVector2f){0.25,0.25});

  texture3 = sfTexture_createFromFile("resources/barrier.png", NULL);
  barrier3 = sfSprite_create();
  sfSprite_setTexture(barrier3, texture3, sfTrue);
  sfSprite_setPosition(barrier3, (sfVector2f){440, 430});
  sfSprite_setScale(barrier3, (sfVector2f){0.25,0.25});

  texture4 = sfTexture_createFromFile("resources/barrier.png", NULL);
  barrier4 = sfSprite_create();
  sfSprite_setTexture(barrier4, texture4, sfTrue);
  sfSprite_setPosition(barrier4, (sfVector2f){600, 430});
  sfSprite_setScale(barrier4, (sfVector2f){0.25,0.25});

  enemy1Texture = sfTexture_createFromFile("resources/enemy1.png", NULL);
  enemy1Sprite = sfSprite_create();
  sfSprite_setTexture(enemy1Sprite, enemy1Texture, sfTrue);
  sfSprite_setScale(enemy1Sprite, (sfVector2f){0.10,0.10});

  enemy2Texture = sfTexture_createFromFile("resources/enemy2.png", NULL);
  enemy2Sprite = sfSprite_create();
  sfSprite_setTexture(enemy2Sprite, enemy2Texture, sfTrue);
  sfSprite_setScale(enemy2Sprite, (sfVector2f){0.10,0.10});

  enemy3Texture = sfTexture_createFromFile("resources/enemy3.png", NULL);
  enemy3Sprite = sfSprite_create();
  sfSprite_setTexture(enemy3Sprite, enemy3Texture, sfTrue);
  sfSprite_setScale(enemy3Sprite, (sfVector2f){0.10,0.10});

  enemy4Texture = sfTexture_createFromFile("resources/enemy4.png", NULL);
  enemy4Sprite = sfSprite_create();
  sfSprite_setTexture(enemy4Sprite, enemy4Texture, sfTrue);
  sfSprite_setScale(enemy4Sprite, (sfVector2f){0.10,0.10});

  paused = sfText_create();
  sfText_setString(paused, "PAUSED");
  sfText_setCharacterSize(paused, 60);
  sfText_setPosition(paused, (sfVector2f){300,330});
  sfText_setFont(paused, sfFont_createFromFile("resources/Athletic.TTF"));
  sfText_setColor(paused, sfRed);

  //Carga de las imagenes de la nave

  naveSprite = sfSprite_create();
  balaSprite= sfSprite_create();

  naveCentro= sfTexture_createFromFile("resources/jugador.png", NULL);
  if (!naveCentro){
    return 1;
  }


  naveIzquierda= sfTexture_createFromFile("resources/jugadorizq.png", NULL);
  if (!naveIzquierda){
    return 1;
  }

  naveDerecha= sfTexture_createFromFile("resources/jugadorder.png", NULL);
  if (!naveDerecha){
    return 1;
  }

  balaText = sfTexture_createFromFile("resources/bala.png", NULL);
  if (!balaText){
    return 1;
  }
  sfSprite_setTexture(balaSprite, balaText, sfTrue);
  sfSprite_setScale(balaSprite, (sfVector2f){0.6,0.6});


  return 0;
}

#define MAX_BALAS 350
struct bala {
  int x;
  int y;
  int pasos;
  int activa;
};

struct bala balas[MAX_BALAS];
int nbalas;

struct bala balas_enemigas[MAX_BALAS];
int nbalas_enemigas;

void agregar_bala(int x) {
  int i;
  for (i = 0; i < MAX_BALAS; i++) {
    if (balas[i].activa == 0) {
      balas[i].activa = 1;
      balas[i].x = x;
      balas[i].pasos = 0;
      nbalas++;
      return;
    }
  }
}



struct enemigo {
  int x;
  int y;
  int tipo;
  int vivo;
} enemigos[60];

void agregar_bala_enemiga(int x, int y) {
  int i;
  for (i = 0; i < MAX_BALAS; i++) {
      if (balas_enemigas[i].activa == 0) {
      balas_enemigas[i].activa = 1;
      balas_enemigas[i].x = x;
      balas_enemigas[i].y = y;
      nbalas_enemigas++;
      return;
      }
  }
}

int mover_bichos = 0;
int movimiento = -20;

bool todos_muertos(){
	int vivos=0;
	for (int i = 0; i < 61; ++i)
	{
		if (enemigos[i].vivo==1)
		{
			++vivos;
		}
	}
	if (vivos==0)
	{
		return true;
	}

	return false;
}

int reset_juego(void) {
  int i = 0;
  naveSpriteX=380;
  naveSpriteY=480;
  nbalas = 0;
  memset(balas, 0, sizeof(struct bala) * 200);
  naveText = naveCentro;
  score = 0;
  vidas = 3;
  b[0].vida =3;
  b[1].vida = 3;
  b[2].vida =3;
  b[3].vida=3;
  mover_bichos = 0;
  movimiento = -20;

  for (i = 0; i < 60; i++) {

    enemigos[i].x = ((i % 12) * 55) + 70;
    enemigos[i].y = ((i / 12) * 45) + 100;

    if ((i / 12) == 0) {
      enemigos[i].tipo = 3;
    } else if (((i / 12) == 1) || ((i / 12) == 2)) {
      enemigos[i].tipo = 2;
    } else {
      enemigos[i].tipo = 1;
    }
    enemigos[i].vivo = 1;
  }

  return 0;
}

int bala_y(int pasos) {
  return 460 - (pasos * 20);
}

int dibujar_juego(sfRenderWindow* w){
  int i, balas_dibujadas = 0;
  char *string;
  char *string2;

  sfRenderWindow_clear(w, sfWhite);
  sfRenderWindow_drawText(w,segundoscore, NULL);
  sfRenderWindow_drawText(w, primerscore, NULL);
  sfRenderWindow_drawText(w, hiscore, NULL);
  sfRenderWindow_drawText(w, credit, NULL);

  asprintf(&string, "Score <1>   %d", score);
  sfText_setString(primerscore, string);
  free(string);

  //if(multijugador == true){
   //asprintf(&string2, "Score <2>   %d", score);
   //sfText_setString(segundoscore, string2);
   //free(string2);
  //}


  

  asprintf(&string, "Lives %d", vidas);
  sfText_setString(life, string);
  free(string);
  sfRenderWindow_drawText(w, life, NULL);

  if (vidas == 0 || todos_muertos() == true){
    sfRenderWindow_drawText(w, gameover, NULL);
  }

  if(b[0].vida > 0){
    sfRenderWindow_drawSprite(w, barrier1, NULL);
  }
  if(b[1].vida > 0){
    sfRenderWindow_drawSprite(w, barrier2, NULL);
  }
  if(b[2].vida > 0){
    sfRenderWindow_drawSprite(w, barrier3, NULL);
  }
  if(b[3].vida > 0){
    sfRenderWindow_drawSprite(w, barrier4, NULL);
  }
  if (pausado){
    sfRenderWindow_drawText(w, paused, NULL);
  }
  
 
  sfRenderWindow_drawRectangleShape(w, c, NULL);

  sfSprite_setPosition(naveSprite, (sfVector2f){naveSpriteX, naveSpriteY});
  sfSprite_setTexture(naveSprite, naveText, sfTrue);
  sfSprite_setScale(naveSprite, (sfVector2f){0.4,0.4});
  sfRenderWindow_drawSprite(w, naveSprite, NULL);

  for (i = 0; i < 60; i++) {
    if (enemigos[i].vivo) {
      switch (enemigos[i].tipo) {
        case 1:
          sfSprite_setPosition(enemy1Sprite, (sfVector2f){enemigos[i].x, enemigos[i].y});
          sfRenderWindow_drawSprite(w, enemy1Sprite, NULL);
          break;
        case 2:
          sfSprite_setPosition(enemy2Sprite, (sfVector2f){enemigos[i].x, enemigos[i].y});
          sfRenderWindow_drawSprite(w, enemy2Sprite, NULL);
          break;
        case 3:
          sfSprite_setPosition(enemy3Sprite, (sfVector2f){enemigos[i].x, enemigos[i].y});
          sfRenderWindow_drawSprite(w, enemy3Sprite, NULL);
          break;
        case 4:
          sfSprite_setPosition(enemy4Sprite, (sfVector2f){enemigos[i].x, enemigos[i].y});
          sfRenderWindow_drawSprite(w, enemy4Sprite, NULL);
          break;
      }
    }
  }

  balas_dibujadas = 0;
  for (i = 0; i < MAX_BALAS; i++) {
    if (balas_dibujadas == nbalas)
      break;
    if (balas[i].activa == 1) {
      sfSprite_setPosition(balaSprite, (sfVector2f){balas[i].x, bala_y(balas[i].pasos)});
      sfRenderWindow_drawSprite(w, balaSprite, NULL);
      balas_dibujadas++;
    }
  }

  balas_dibujadas = 0;
  for (i = 0; i < MAX_BALAS; i++) {
    if (balas_dibujadas == nbalas_enemigas)
      break;
    if (balas_enemigas[i].activa == 1) {
      sfSprite_setPosition(balaSprite, (sfVector2f){balas_enemigas[i].x, balas_enemigas[i].y});
      sfRenderWindow_drawSprite(w, balaSprite, NULL);
      balas_dibujadas++;
    }
  }

  sfRenderWindow_display(w);

  return 0;
}

int impacto_jugador(int x, int y) {
  if ((naveSpriteX < x) &&
      (naveSpriteX+80 > x) &&
      (naveSpriteY < y) &&
      (naveSpriteY+80 > y)){
    return 1;
  }

  return 0;
}

int impacto_barrera(int x, int y){
  
  for(size_t i = 0; i < 4; ++i){
    if(b[i].vida > 0){
      if ((b[i].x < x) &&
          (b[i].x+80 > x) &&
          (b[i].y < y) &&
          (b[i].y+80 > y)){

          --b[i].vida;
          return 1;

        }
    }
  }

  return 0;

}

int impacto_enemigo(int x, int y) {
  int i = 0;

  for (i = 0; i < 60; i++) {
    if (enemigos[i].vivo) {
      if ((enemigos[i].x < x) &&
          (enemigos[i].x+40 > x) &&
          (enemigos[i].y < y) &&
          (enemigos[i].y+35 > y)){
        enemigos[i].vivo = 0;
        switch (enemigos[i].tipo) {
          case 1:
            score += 10;
            break;
          case 2:
            score += 20;
            break;
          case 3:
            score += 30;
            break;
          case 4:
            score += 40;
            break;
        }
        return 1;
      }
    }
  }

  return 0;
}

int animacion_juego(sfRenderWindow* w) {
  if (todos_muertos())
	{
		  for (int i = 0; i < 60; i++) {

    enemigos[i].x = ((i % 12) * 55) + 70;
    enemigos[i].y = ((i / 12) * 45) + 100;
    
    if ((i / 12) == 0) {
      enemigos[i].tipo = 3;
    } else if (((i / 12) == 1) || ((i / 12) == 2)) {
      enemigos[i].tipo = 2;
    } else {
      enemigos[i].tipo = 1;
    }
    enemigos[i].vivo = 1;
  }
	}
  int i = 0, j;
  int soy_primero;
  int y = 0;
  int balas_actualizadas = 0;
  usleep(100000);

  if (vidas == 0) {
    return 0;
  }

  // Procesar Bichos
  mover_bichos++;
  if (mover_bichos == 5) {
    mover_bichos = 0;
    movimiento *= -1;
  }
  for (i = 0; i < 60; i++) {
    if (mover_bichos == 0) {
      enemigos[i].x += movimiento;
    }
    soy_primero = 1;
    // Soy primero de mi fila?
    for (j = i + 12; j < 60; j += 12) {
      if (enemigos[j].vivo) {
        soy_primero = 0;
        break;
      }
    }
    if (soy_primero) {
      // Debo disparar?
      if ((rand() % 100) < 1) {
        if(!pausado && enemigos[i].vivo){
        agregar_bala_enemiga(enemigos[i].x+20, enemigos[i].y+40);
        }
      }
    }
  }

  // Procesar Balas
  for (i = 0; i < MAX_BALAS; i++) {
    if (balas_actualizadas == nbalas)
      break;
    if (balas[i].activa == 1) {
      balas[i].pasos++;
      if (impacto_enemigo(balas[i].x, bala_y(balas[i].pasos))) {
        // Finalizar bala
        balas[i].activa = 0;
        nbalas--;
        continue;
      }
      if (balas[i].pasos == 18) {
        balas[i].activa = 0;
        nbalas--;
      } else {
        balas_actualizadas++;
      }
    }
  }

  for (i = 0; i < MAX_BALAS; i++) {
    if (balas_actualizadas == nbalas_enemigas)
      break;
    if (balas_enemigas[i].activa == 1) {
      balas_enemigas[i].y += 20;

      // Actualiza la vida de las barreras, revisa si hubieron colisiones
      if (impacto_barrera(balas_enemigas[i].x, balas_enemigas[i].y)){
        balas_enemigas[i].activa = 0;
        nbalas_enemigas--;
      }
      else if (impacto_jugador(balas_enemigas[i].x, balas_enemigas[i].y)) {
        vidas--;
        balas_enemigas[i].activa = 0;
        nbalas_enemigas--;      }

      
      if (balas_enemigas[i].y > 480) {
        balas_enemigas[i].activa = 0;
        nbalas_enemigas--;
      } else {
        balas_actualizadas++;
      }
    }
  }

  dibujar_juego(w);
}

enum pantallas eventos_juego(sfRenderWindow* w, sfEvent *e){
  if(vidas == 0){
    return RESULTADOS;
  }

  if(e->type == sfEvtKeyPressed){
    switch(e->key.code){

      case sfKeyP:
      	pausar();
      break;

      case sfKeyEscape: 
        return INICIO;
      
      case sfKeyLeft:
      if(!pausado){
        if (naveSpriteX > 30) {
          naveSpriteX -=20;
          naveText = naveIzquierda;
        }
      }
        break;
    
      case sfKeyRight:
      if(!pausado){
        if (naveSpriteX < 730) {
          sfSprite_move(naveSprite, (sfVector2f){+20, 0});
          naveSpriteX +=20;
          naveText = naveDerecha;
        }
      }
        break;
      
      case sfKeySpace:
      if(!pausado){
        agregar_bala(naveSpriteX+22);  
      }
      break;

    }

    sfSprite_setPosition(naveSprite, (sfVector2f){naveSpriteX, naveSpriteY});
    dibujar_juego(w);

    naveText = naveCentro;
  }

  return JUEGO;
}

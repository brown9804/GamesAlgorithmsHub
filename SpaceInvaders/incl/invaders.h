#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SDL/SDL.h>

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

enum pantallas {
  INICIO = 0,
  JUEGO,
  RESULTADOS
};

extern int cargar_inicio(void);
extern int dibujar_inicio(sfRenderWindow* w);
extern enum pantallas eventos_inicio(sfRenderWindow* w, sfEvent *e);
extern int cargar_juego(void);
extern int reset_juego(void);
extern int animacion_juego(sfRenderWindow* w);
extern int dibujar_juego(sfRenderWindow* w);
extern enum pantallas eventos_juego(sfRenderWindow* w, sfEvent *e);

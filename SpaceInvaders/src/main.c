#include "invaders.h"

int main(){
    sfEvent e;
    enum pantallas pantalla_actual = INICIO;
    enum pantallas siguiente_pantalla = INICIO;

    // Cargar pantallas
    cargar_inicio();
    cargar_juego();

    // Crear pantalla
    sfVideoMode pp = {800, 600 , 32};
    sfRenderWindow* w;
    w = sfRenderWindow_create(pp, "SPACE INVADERS", sfClose, NULL);

    dibujar_inicio(w);
    while(sfRenderWindow_isOpen(w)){
      switch(pantalla_actual) {
        case JUEGO:
          animacion_juego(w);
          break;
      }
      while(sfRenderWindow_pollEvent(w, &e)){
        if(e.type == sfEvtClosed){
          printf("Cerrando\n");
          sfRenderWindow_close(w);
        } else {
          switch(pantalla_actual) {
            case INICIO:
              siguiente_pantalla = eventos_inicio(w, &e);
              break;
            case JUEGO:
              siguiente_pantalla = eventos_juego(w, &e);
              break;
            case RESULTADOS:
              pantalla_actual = eventos_resultados(w, &e);
              break;
          }

          if (pantalla_actual != siguiente_pantalla) {
            sfRenderWindow_clear(w, sfWhite);
            switch(siguiente_pantalla) {
              case INICIO:
                dibujar_inicio(w);
                dibujar_inicio(w);
                break;
              case JUEGO:
                reset_juego();
                dibujar_juego(w);
                dibujar_juego(w);
                //dibujar_scores();
                break;
              case RESULTADOS:
                dibujar_scores(w);
                break;
            }
            pantalla_actual = siguiente_pantalla;
          }
        }
      }
    }

    return 0;
}

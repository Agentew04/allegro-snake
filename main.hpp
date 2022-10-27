#ifndef MAIN_HPP
#define MAIN_HPP

#include <allegro5/allegro.h>

void init(ALLEGRO_EVENT_QUEUE **fila_eventos, ALLEGRO_DISPLAY **janela);

void handleEvent(ALLEGRO_EVENT event);
#endif // MAIN_HPP
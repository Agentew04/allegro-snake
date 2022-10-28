#ifndef MAIN_HPP
#define MAIN_HPP

#include <allegro5/allegro.h>
#include "game.hpp"

void init(ALLEGRO_EVENT_QUEUE **fila_eventos, ALLEGRO_DISPLAY **janela);
void handleEvent(ALLEGRO_EVENT event, snk::Game &game, snk::VideoOptions &video, bool &rodando);
#endif // MAIN_HPP
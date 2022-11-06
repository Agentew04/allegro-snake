#ifndef MAIN_HPP
#define MAIN_HPP

#include <allegro5/allegro.h>
#include "game.hpp"

enum class State{
    Menu,
    Game,
    GameOver,
    Options
};

void init(ALLEGRO_EVENT_QUEUE **fila_eventos, ALLEGRO_DISPLAY **janela);
void handleEvent(ALLEGRO_EVENT event, snk::Game &game, snk::VideoOptions &video, bool &rodando, State &state
);

#endif // MAIN_HPP
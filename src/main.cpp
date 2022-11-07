#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>


#include "main.hpp"
#include "game.hpp"

#define SCR_W 640
#define SCR_H 480

void init(ALLEGRO_EVENT_QUEUE **fila_eventos, ALLEGRO_DISPLAY **janela){
    srand(time(NULL));
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_install_mouse();
    al_install_keyboard();
    *fila_eventos = al_create_event_queue();

    al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    *janela = al_create_display(SCR_W, SCR_H);

    if(!*fila_eventos || !*janela){
        exit(EXIT_FAILURE);
    }
    al_register_event_source(*fila_eventos, al_get_display_event_source(*janela));
    al_register_event_source(*fila_eventos, al_get_mouse_event_source());
    al_register_event_source(*fila_eventos, al_get_keyboard_event_source());
}

int main(void){
    ALLEGRO_DISPLAY *janela = nullptr;
    ALLEGRO_EVENT_QUEUE *fila_eventos = nullptr;
    init(&fila_eventos, &janela);

    bool rodando = true;
    double lastTempo, tempo = al_get_time();
    snk::VideoOptions video (janela);
    State state = State::Game;
    snk::Game game(20, 20);

    while(rodando){
        lastTempo = tempo;
        tempo = al_get_time();
        float delta = tempo - lastTempo;

        // handle events
        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT event;
            al_wait_for_event(fila_eventos, &event);
            handleEvent(event, game, video, rodando, state);
            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                rodando = 0;
            }
        }

        // update
        if(state == State::Game)
            game.update(delta);

        // draw
        al_clear_to_color(al_map_rgb(0, 0, 0));
        if(state == State::Game)
            game.draw(video);
        else if(state == State::Menu){
            al_draw_text(video.getFont(snk::FontSize::Large), al_map_rgb(255, 255, 255), SCR_W/2, SCR_H/2, ALLEGRO_ALIGN_CENTRE, "Pressione qualquer tecla para iniciar");
        }
        else if(state == State::GameOver){
            al_draw_text(video.getFont(snk::FontSize::Large), al_map_rgb(255, 255, 255), SCR_W/2, SCR_H/2, ALLEGRO_ALIGN_CENTRE, "Game Over");
        }

        // render frame
        al_flip_display();
    }

    // destroy stuff
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    return 0;
}

void handleEvent(ALLEGRO_EVENT event, snk::Game &game, snk::VideoOptions &video, bool &rodando, State &state){
    // state independent events
    if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        rodando = 0;
    }
    if(event.type == ALLEGRO_EVENT_DISPLAY_RESIZE){
        al_acknowledge_resize(event.display.source);
        video.setWidth(event.display.width);
        video.setHeight(event.display.height);
    }

    // state dependent events
    if(event.type == ALLEGRO_EVENT_KEY_DOWN && state == State::Game){
        switch(event.keyboard.keycode){
            case ALLEGRO_KEY_F11:
                video.setFullscreen(!video.isFullscreen());
                break;
            case ALLEGRO_KEY_ESCAPE:
                rodando = false;
                break;
            case ALLEGRO_KEY_A:
            case ALLEGRO_KEY_LEFT:
                game.setDirection(snk::Vec2I::left());
                break;
            case ALLEGRO_KEY_D:
            case ALLEGRO_KEY_RIGHT:
                game.setDirection(snk::Vec2I::right());
                break;
            case ALLEGRO_KEY_W:
            case ALLEGRO_KEY_UP:
                game.setDirection(snk::Vec2I::up());
                break;
            case ALLEGRO_KEY_S:
            case ALLEGRO_KEY_DOWN:
                game.setDirection(snk::Vec2I::down());
                break;
        }
    }
}
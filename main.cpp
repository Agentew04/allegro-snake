#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>

#include "snake.hpp"

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
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    *janela = al_create_display(SCR_W, SCR_H);

    if(!*fila_eventos || !*janela){
        exit(EXIT_FAILURE);
    }
    al_register_event_source(*fila_eventos, al_get_display_event_source(*janela));
}

int main(void){
    ALLEGRO_DISPLAY *janela = nullptr;
    ALLEGRO_FONT* font = nullptr;
    ALLEGRO_EVENT_QUEUE *fila_eventos = nullptr;
    init(&fila_eventos, &janela);
    font = al_create_builtin_font();

    int rodando = 1;
    double lastTempo, tempo = al_get_time();
    Snake snake;

    while(rodando){
        lastTempo = tempo;
        tempo = al_get_time();

        // handle events
        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT event;
            al_wait_for_event(fila_eventos, &event);

            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                rodando = 0;
            }
        }
        
        // update

        // draw to screen
        al_clear_to_color(al_map_rgb(0, 0, 0));
        
        al_flip_display();
    }   

    // destroy stuff
    al_destroy_font(font);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    return 0;
}
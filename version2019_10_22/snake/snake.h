/**
 * \file main.c
 * \brief Programme principal du niveau 0
 * \author BONTE Emeline, DEBART Arthur
 * \version 0.1
 * \date 12 septembre 2019
 */


#ifndef SNAKE_H
#define SNAKE_H

#include "../sdl-light.h"


void init_data_snake(snake_t * world);
 
void update_serp(snake_t *world);


void clean_data_snake(snake_t *world);

void update_data_snake(snake_t *world);

void  init_graphics_snake(SDL_Surface *screen, snake_t *world);

int collision_snake (snake_t *world);
 
void replacement_serpent(snake_t *world);

void collision_pomme_serp(snake_t* world);

void refresh_graphics_snake(SDL_Surface *screen, snake_t *world);

void handle_events_snake(SDL_Event *event2,snake_t *snake,monde_t *world);

void boucle_snake(monde_t *world, SDL_Surface * screen);

#endif

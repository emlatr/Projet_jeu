/**
 * \file main.c
 * \brief Programme principal du niveau 0
 * \author BONTE Emeline, DEBART Arthur
 * \version 0.2
 * \date 21 octobre 2019
 */

#include "../sdl-light.h"
#include "../general.h"



/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */


void init_data_snake(snake_t * world){ 
	world-> fond = load_image( "ressources/fond.bmp" );
	world-> background = load_image( "ressources/herbe.bmp" );
	
	world-> corps.Corps = load_image("ressources/corps.bmp");
	world-> gameover = 0;
	world-> Serpent4 = load_image( "ressources/serpent_tete.bmp");
	world-> Serpent3 = load_image( "ressources/serpent_tete_4.bmp");

	world-> Serpent2 = load_image( "ressources/serpent_tete_2.bmp");
	world-> Serpent1 = load_image( "ressources/serpent_tete_3.bmp");
	world-> Serpent = load_image( "ressources/corps.bmp");//Le premier serpentserpent_tete.
	world-> x = 0.;
	world-> y = 0.;


	world->C[0].cx = 0;
	world->C[0].cy = 32;
	world->C[0].Corps = world->corps.Corps;

	for(int i = 1; i<NB_CORPS_SNAKE ; i++){
		world->C[i].cx = world->C[i-1].cx;
		world->C[i].cy = world->C[i-1].cy;
		world->C[i].Corps = world->corps.Corps;
	}
	
	world-> vx = 9;
	world-> vy = 9;
	

	world->direct = 3;
	world->nb_corps = 1;
	
	for(int i = 0; i<NB_CORPS_SNAKE ; i++){
		world->TC[i].cx = world->C[i].cx;
		world->TC[i].cy = world->C[i].cy;
		world->TC[i].Corps = world->corps.Corps;
	}
	world->TC[NB_CORPS_SNAKE] = world->C[NB_CORPS_SNAKE];

	for(int i = 0; i<NB_POMME; i++){
		world->PR[i].Pomme = load_image( "ressources/pomme.bmp" );
		world->PR[i].px = i + 7 * i;
		world->PR[i].py = i + 7 * i;
	}

	world->score = 0;
}
 


/**
 * \brief La fonction met à jour les données du serpent
 * \param world les données du monde
 */
void update_serp(snake_t *world){
	for(int i = world->nb_corps-1; i>0; i--){
		world->C[i].cx = world->C[i-1].cx;
		world->C[i].cy = world->C[i-1].cy;
	}
	world->C[0].cx = world->x;
	world->C[0].cy = world->y;
	if(world->direct == 0 ){
		world->x += world->vx;
	}
	else if(world->direct == 1){
		world->y += world->vy;
	}
	else if(world->direct == 2){
		world->x -= world->vx;
	}
	else if(world->direct == 3){
		world->y -= world->vy;
	}

}




/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */


void clean_data_snake(snake_t *world){
	SDL_FreeSurface(world->background);
	SDL_FreeSurface(world->fond);
	SDL_FreeSurface(world->PR[NB_POMME].Pomme);
	SDL_FreeSurface(world->corps.Corps);
	SDL_FreeSurface(world->Serpent);
	SDL_FreeSurface(world->Serpent1);
	SDL_FreeSurface(world->Serpent2);
	SDL_FreeSurface(world->Serpent3);
	SDL_FreeSurface(world->Serpent4);
}



/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param les données du monde
 */

void update_data_snake(snake_t *world){
	update_serp(world);
}


/**
 * \brief La fonction initialise les transparences des différentes surfaces
 * \param screen la surface correspondant à l'écran de jeu
 * \param world les données du monde
 */

void  init_graphics_snake(SDL_Surface *screen, snake_t *world){
	for(int i = 0; i<NB_POMME; i++){
		set_transparence(screen, world->PR[i].Pomme, 255,255,255);
	}
	set_transparence(screen, world->Serpent, 255,255,255);
	set_transparence(screen, world->Serpent1, 255,255,255);
	set_transparence(screen, world->Serpent2, 255,255,255);
	set_transparence(screen, world->Serpent3, 255,255,255);
	set_transparence(screen, world->Serpent4, 255,255,255);
	set_transparence(screen, world->corps.Corps, 255,255,255);

   
}

int collision_snake (snake_t *world){
	if(world->x+32 > SCREEN_WIDTH_SNAKE + 30){
		//world->x = 0.1;
		return 1;
	}
	if(world->x < 0. - 30){
		//world->x = SCREEN_WIDTH - 20;
		return 2;
	}
	if(world->y+32 > SCREEN_HEIGHT_SNAKE  + 60){
		//world->y = 0.1;
		return 3;
	}
	if(world->y < 0. - 30){
		//world->y = SCREEN_HEIGHT - 20;
		return 4;
	}
	return 0;
}
 
void replacement_serpent(snake_t *world){
	if(collision_snake(world) == 1){
		world->x = 0.1;
		return;
	}
	if(collision_snake(world) == 2){
		world->x = SCREEN_WIDTH_SNAKE - 32;
		return;
	}
	if(collision_snake(world) == 3){
		world->y = 0.1;
		return;
	}
	if(collision_snake(world) == 4){
		world->y = SCREEN_HEIGHT_SNAKE;
		return;
	}
	return;
}

int collision_pomme_serp(snake_t* world){
	for(int i = 0; i<NB_POMME; i++){
		if(world->PR[i].px + 4 >= world->x + 2 && world->PR[i].px + 4 <= world->x + 30 && world->PR[i].py + 1 <= world->y + 30 && world->PR[i].py + 1 >= world->y + 2){
			world->nb_corps += 2;
			world->score += 1;
			printf("Votre score est de : %i", world->score);
			return 1;
		}
		if(world->PR[i].px + 28 >= world->x + 2 && world->PR[i].px + 28 <= world->x + 30 && world->PR[i].py + 1 <= world->y + 30 && world->PR[i].py + 1 >= world->y + 2){
			world->nb_corps += 2;
			world->score += 1;
			printf("Votre score est de : %i", world->score);
			return 1;
		}
		if(world->PR[i].px + 4 >= world->x + 12 && world->PR[i].px + 4 <= world->x + 30 && world->PR[i].py + 29 <= world->y + 30 && world->PR[i].py + 29 >= world->y + 2){
			world->nb_corps += 2;
			world->score += 1;
			printf("Votre score est de : %i", world->score);
			return 1;
		}
		if(world->PR[i].px + 28 >= world->x + 2 && world->PR[i].px + 28 <= world->x + 30 && world->PR[i].py + 29 <= world->y + 30 && world->PR[i].py + 29 >= world->y + 2){
			world->nb_corps += 2;
			world->score += 1;
			printf("Votre score est de : %i", world->score);
			return 1;
		}
	}
	return 0;
}







/**
 * \brief La fonction rafrachit l'écran en fonction de l'état des données du monde
 * \param screen la surface de l'écran de jeu
 * \param world les données du monde
 */

void refresh_graphics_snake(SDL_Surface *screen, snake_t *world){
	apply_surface(world->fond, screen, 0, 0);
	apply_surface(world->background,screen,0,0);
	for(int i = 0; i<NB_POMME; i++){
		apply_surface(world->PR[i].Pomme, screen, world->PR[i].px, world->PR[i].py);
	}
	apply_surface(world->Serpent, screen, world->x , world->y);
	for(int i = 0; i<world->nb_corps; i++){
		apply_surface(world->C[i].Corps, screen, world->C[i].cx , world->C[i].cy);
	}
  
	refresh_surface(screen);
}

/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */


void handle_events_snake(SDL_Event *event2,snake_t *snake,world_t *world){
  Uint8 *keystates;
  //update_data(world);

	while( SDL_PollEvent( event2 ) ) {
		//Si l'utilisateur a cliqué sur le X de la fenêtre
		if( event2->type == SDL_QUIT ) {
		  //On quitte le programme
			world->gameover = 1;
			snake->ouvert = false;
		}
		collision_pomme_serp(snake);
		/* gestion des evenements clavier */
		keystates = SDL_GetKeyState( NULL );
	
		printf("Votre score est de : %i", snake->score);

		/* Si l'utilisateur appuie sur les flèches, le personnage se déplace */
		if( keystates[ SDLK_UP])
		{
			snake->direct = 3;
			//snake->Serpent = snake->Serpent4;

		}
		else if( keystates[ SDLK_DOWN])
		{
			snake->direct = 1;
			//snake->Serpent = snake->Serpent1;
		}
		else if( keystates[ SDLK_RIGHT])
		{
			snake->direct = 0;
			//snake->Serpent = snake->Serpent2;
		}
		else if( keystates[ SDLK_LEFT])
		{
			snake->direct = 2;
			//snake->Serpent = snake->Serpent3;

		}
		
	}
	

}



/**
 *  \brief programme principal qui implémente la boucle du jeu
 */


void boucle_snake(world_t *world, SDL_Surface * screen)
{
	
  SDL_Event event2;
  //monde_t world;
  //SDL_Surface *screen;

  //screen = init_sdl(SCREEN_WIDTH, SCREEN_HEIGHT);
  SDL_WM_SetCaption("Fenêtre de jeu de snake !", NULL);
    
  init_data_snake(&world->snake);
  init_graphics_snake(screen,&world->snake);
  
 
  int cnt=0;
  while(world->snake.ouvert == true){

    handle_events_snake(&event2,&world->snake, world);
    update_data_snake(&world->snake);
    refresh_graphics_snake(screen,&world->snake);
    SDL_Delay(100);

	if(collision_snake(&world->snake)){
		replacement_serpent(&world->snake);
		//replacement_corps(&world->snake);
	}

//	if (cnt++>1) break;
  }

  clean_data_snake(&world->snake);
    
    
  return;
}

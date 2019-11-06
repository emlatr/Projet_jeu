/**
 * \file main.c
 * \brief Programme principal du niveau 0
 * \author BONTE Emeline, DEBART Arthur
 * \version 0.2
 * \date 21 octobre 2019
 */

#include "../sdl-light.h"
#include "../general.h"
#include <time.h>



/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */


void init_data_snake(snake_t * world){ 
	world-> fond = load_image( "ressources/fond.bmp" );
	world-> background = load_image( "ressources/herbe.bmp" );
	
	world-> corps.Corps = load_image("ressources/corps.bmp");
	world-> gameover = 0;
	
	world-> Serpent = load_image( "ressources/tete2.bmp");//Le premier serpentserpent_tete.
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
	

	world->score = 0;
}

void init_data_pomme(snake_t * world){ 
	srand((unsigned)time(NULL));

	for(int i = 0; i<NB_POMME; i++){
		world->PR[i].Pomme = load_image( "ressources/pomme.bmp" );
		world->PR[i].px = rand() % 830 + 0;
		world->PR[i].py = rand() % 430 + 0;
		world->PR[i].exist = 1;
		world->PV[i].Pomme = load_image( "ressources/pomme_verte.bmp" );
		world->PV[i].px = rand() % 830 + 0;
		world->PV[i].py = rand() % 430 + 0;
		world->PV[i].exist = 1;
		
	}

	
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
	printf("truc\n");
	SDL_FreeSurface(world->background);
	printf("truc\n");
	SDL_FreeSurface(world->fond);
	printf("truc\n");
	SDL_FreeSurface(world->PR[NB_POMME].Pomme);
	printf("truc\n");
	//SDL_FreeSurface(world->PV[NB_POMME].Pomme);
	printf("truc\n");
	//SDL_FreeSurface(world->corps.Corps);
	printf("truc\n");
	SDL_FreeSurface(world->Serpent);
	printf("truc\n");
	/*SDL_FreeSurface(world->Serpent1);
	SDL_FreeSurface(world->Serpent2);
	SDL_FreeSurface(world->Serpent3);
	SDL_FreeSurface(world->Serpent4);*/
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
		set_transparence(screen, world->PV[i].Pomme, 255,255,255);
	}
	set_transparence(screen, world->Serpent, 255,255,255);
	/*set_transparence(screen, world->Serpent1, 255,255,255);
	set_transparence(screen, world->Serpent2, 255,255,255);
	set_transparence(screen, world->Serpent3, 255,255,255);
	set_transparence(screen, world->Serpent4, 255,255,255);*/
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

void collision_pomme_serp(snake_t* snake, pomme_t* p, int i ){
	if( (snake->x + SIZE_RIGHT_SNAKE >= p->px + SIZE_LEFT_POMME ) && (snake->x + SIZE_LEFT_SNAKE <= p->px + SIZE_RIGHT_POMME ) ){
		if( (snake->y + SIZE_BOTTOM_SNAKE >= p->py + SIZE_LEFT_POMME ) && (snake->y <= p->py + SIZE_POMME ) ){
			if( i == 1){
				snake->nb_corps += 2;
				snake->score += 1;
				printf("Votre score est de : %i\n", snake->score);
				p->exist = 0;
				return;
			}
			if( i == 2 ){
				snake->nb_corps += 1;
				snake->score += 1;
				printf("Votre score est de : %i\n", snake->score);
				p->exist = 0;
				return;
			}
			//...
		}

	}
	return;
}

void collision_pomme(snake_t* snake){
	for(int i = 0; i<NB_POMME; i++){
		if(snake->PR[i].exist == 1){
			collision_pomme_serp(snake, &snake->PR[i], 1);
		}
		if(snake->PV[i].exist == 1){
			collision_pomme_serp(snake, &snake->PV[i], 2);
		}
	}
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
		if(world->PR[i].exist == 1){
			apply_surface(world->PR[i].Pomme, screen, world->PR[i].px, world->PR[i].py);
		}
		if(world->PV[i].exist == 1){
			apply_surface(world->PV[i].Pomme, screen, world->PV[i].px, world->PV[i].py);
		}
	}
	apply_surface(world->Serpent, screen, world->x , world->y);
	for(int i = 0; i<world->nb_corps; i++){
		apply_surface(world->C[i].Corps, screen, world->C[i].cx , world->C[i].cy);
	}
  	collision_pomme(world);
	if(world->score == 1){
		world->ouvert = false;
		world->score = 0;
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
		
		/* gestion des evenements clavier */
		keystates = SDL_GetKeyState( NULL );


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
	
	printf("CROTTE1\n");
	init_data_snake(&world->snake);
	printf("CROTTE2\n");
	init_data_pomme(&world->snake);
	//init_data_pomme_verte(&world->snake);
	printf("CROTTE3\n");
	init_graphics_snake(screen,&world->snake);

	printf("CROTTE4\n");
	//int cnt=0;
	while(world->snake.ouvert == true){
		printf("AIIIIIIIIIIIIIIe\n");
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
	printf("BLOUBLOU\n");
	
	world->snake.ouvert = true ; 
	clean_data_snake(&world->snake);


	return;
}

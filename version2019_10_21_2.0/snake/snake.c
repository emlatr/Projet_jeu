/**
 * \file main.c
 * \brief Programme principal du niveau 0
 * \author BONTE Emeline, DEBART Arthur
 * \version 0.1
 * \date 12 septembre 2019
 */

#include "../sdl-light.h"
#include "../general.h"



/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */


void init_data_snake(snake_t * world){ 
  world-> background = load_image( "ressources/herbe.bmp" );
  world-> Pomme_rouge.Pomme = load_image( "ressources/pomme.bmp" );
  world-> corps.Corps = load_image("ressources/corps.bmp");
  world-> gameover = 0;
  world-> Serpent4 = load_image( "ressources/serpent_tete.bmp");
  world-> Serpent3 = load_image( "ressources/serpent_tete_4.bmp");

  world-> Serpent2 = load_image( "ressources/serpent_tete_2.bmp");
  world-> Serpent1 = load_image( "ressources/serpent_tete_3.bmp");
  world-> Serpent = load_image( "ressources/serpent_tete.bmp");//Le premier serpent
  world-> x = 0.;
  world-> y = 0.;


  world->C[0].cx = 0;
  world->C[0].cy = 32;
  world->C[0].Corps = world->corps.Corps;

	for(int i = 1; i<NB_CORPS_SNAKE ; i++){
		world->C[i].cx = world->C[i-1].cx;
		world->C[i].cy = world->C[i-1].cy + 9;
		world->C[i].Corps = world->corps.Corps;
	}
	
	world-> vx = 0.02;
	world-> vy = 0.02;
	

  world->direct = 3;
  world->nb_corps = 27;
}
 


/**
 * \brief La fonction met à jour les données du serpent
 * \param world les données du monde
 */
void update_serp(snake_t *world){
	if(world->direct == 0 ){ //droite
		world->x+= world->vx;
		for(int i = 0; i<world->nb_corps ; i++){
			world->C[i].cx += world->vx;
		}
	}
	if(world->direct == 1){//bas
		world->y+= world->vy;
		for(int i = 0; i<world->nb_corps ; i++){
			world->C[i].cy += world->vy;
		}
	}
	if(world->direct == 2){//gauche
		world->x-= world->vx;
		for(int i = 0; i<world->nb_corps ; i++){
			world->C[i].cx -= world->vx;
		}
	}
	if(world->direct == 3){//haut
		world->y-= world->vy;
		for(int i = 0; i<world->nb_corps ; i++){
			world->C[i].cy -= world->vy;
		}
	}
  /*world->vx = world->vx *(1-FREIN_COEF);
  world->vy = world->vy *(1-FREIN_COEF);*/

  //int touch = touch_bordure_b(&world->boule_blanche);
  //miroir_rebond(&world->boule_blanche, touch);
}




/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */


void clean_data_snake(snake_t *world){
  SDL_FreeSurface(world->background);
  SDL_FreeSurface(world->Pomme_rouge.Pomme);
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
  set_transparence(screen, world->Pomme_rouge.Pomme, 255,255,255);
  set_transparence(screen, world->Serpent, 255,255,255);
  set_transparence(screen, world->Serpent1, 255,255,255);
  set_transparence(screen, world->Serpent2, 255,255,255);
  set_transparence(screen, world->Serpent3, 255,255,255);
  set_transparence(screen, world->Serpent4, 255,255,255);
  set_transparence(screen, world->corps.Corps, 255,255,255);

   
}

int collision_snake (snake_t *world){
	if(world->x+32 > SCREEN_WIDTH_SNAKE){
		//world->x = 0.1;
		return 1;
	}
	if(world->x < 0.){
		//world->x = SCREEN_WIDTH - 20;
		return 2;
	}
	if(world->y+32 > SCREEN_HEIGHT_SNAKE){
		//world->y = 0.1;
		return 3;
	}
	if(world->y < 0.){
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
		world->y = SCREEN_HEIGHT_SNAKE - 32;
		return;
	}
	return;
}

void collision_pomme_serp(snake_t* world){
}









/**
 * \brief La fonction rafrachit l'écran en fonction de l'état des données du monde
 * \param screen la surface de l'écran de jeu
 * \param world les données du monde
 */

void refresh_graphics_snake(SDL_Surface *screen, snake_t *world){
  apply_surface(world->background,screen,0,0);
  apply_surface(world->Pomme_rouge.Pomme, screen, 50, 50);
  //apply_surface(world->corps.Corps, screen, world->corps.cx , world->corps.cy);
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
        
    /* gestion des evenements clavier */
    keystates = SDL_GetKeyState( NULL );

    /* Si l'utilisateur appuie sur les flèches, le personnage se déplace */
    if( keystates[ SDLK_UP])
      {
	snake->direct = 3;
	snake->Serpent = snake->Serpent4;
	snake->y-=10;
	snake->C[0].cx = snake->x;
	snake->C[0].cy = snake->y + 32 ;
	for(int i = 1; i<snake->nb_corps ; i++){
		snake->C[i].cx = snake->C[i-1].cx;
		snake->C[i].cy = snake->C[i-1].cy + 9;
		/*world->C[i].cx = world->x;
		world->C[i].cy = world->y + 32 ;*/
	}
	/*world->corps.cx = world->x;
	world->corps.cy = world->y + 32 ;*/

      }
    else if( keystates[ SDLK_DOWN])
      {
	snake->direct = 1;
	snake->Serpent = snake->Serpent1;
	snake->y+=8;
	snake->C[0].cx = snake->x + 1;
	snake->C[0].cy = snake->y - 32 + 23;
	for(int i = 1; i<snake->nb_corps ; i++){
		snake->C[i].cx = snake->C[i-1].cx;
		snake->C[i].cy = snake->C[i-1].cy - 9;
		/*world->C[i].cx = world->x + 1;
		world->C[i].cy = world->y - 32 + 23;*/
	}
	/*world->corps.cx = world->x + 1;
	world->corps.cy = world->y - 32 + 23;*/
	
      }
    else if( keystates[ SDLK_RIGHT])
      {
	snake->direct = 0;
	snake->Serpent = snake->Serpent2;
	snake->x+=8;
	snake->C[0].cx = snake->x - 32 + 12 ;
	snake->C[0].cy = snake->y + 11 ;
	for(int i = 1; i<snake->nb_corps ; i++){
		snake->C[i].cx = snake->C[i-1].cx - 9;
		snake->C[i].cy = snake->C[i-1].cy;
		
		/*world->C[i].cx = world->x - 32 + 12 ;
		world->C[i].cy = world->y + 11 ;*/
	}
	/*world->corps.cx = world->x - 32 + 12 ;
	world->corps.cy = world->y + 11 ;*/
      }
    else if( keystates[ SDLK_LEFT])
      {
	snake->direct = 2;
	snake->Serpent = snake->Serpent3;
	snake->x-=8;
	snake->C[0].cx = snake->x + 32 - 11;
	snake->C[0].cy = snake->y + 12;
	for(int i = 1; i<snake->nb_corps ; i++){
		snake->C[i].cx = snake->C[i-1].cx + 9;
		snake->C[i].cy = snake->C[i-1].cy;
		
		/*world->C[i].cx = world->x + 32 - 11;
		world->C[i].cy = world->y + 12;*/
	}
	/*world->corps.cx = world->x + 32 - 11;
	world->corps.cy = world->y + 12;*/
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
  
 
  
  while(world->snake.ouvert == true){
    
    handle_events_snake(&event2,&world->snake, world);
    update_data_snake(&world->snake);
    refresh_graphics_snake(screen,&world->snake);
    //SDL_Delay(10);
	/*if(touch_bordure_b(&world)!=0){
		replacement_mur(&world);
	}*/
	if(collision_snake(&world->snake)){
		replacement_serpent(&world->snake);
	}

  }

  clean_data_snake(&world->snake);
    
    
  return;
}

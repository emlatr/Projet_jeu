/**
 * \file main.c
 * \brief Programme principal du niveau 0
 * \author BONTE Emeline, DEBART Arthur
 * \version 0.1
 * \date 12 septembre 2019
 */


#include "general.h"



/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */


void init_data(world_t * world){ 
	world-> background = load_image( "ressources/labyrinthe3.bmp" );
	world-> Lampe = load_image( "ressources/pixil-frame-0(2).bmp" );//
	world-> Lampe_droite = load_image( "ressources/pixil-frame-0(3).bmp" );//
	world-> Lampe_gauche = load_image( "ressources/pixil-frame-0(4).bmp" );//.
	world-> Lampe_haut = load_image( "ressources/pixil-frame-0(5).bmp" );//
	world-> Lampe_bas = load_image( "ressources/pixil-frame-0(2).bmp" );//
	world-> intero  = load_image( "ressources/point.bmp" );



	world-> gameover = 0;
	world-> Jean4 = load_image( "ressources/Jean_dos2.bmp");
	world-> Jean3 = load_image( "ressources/Jean_cote_gauche2.bmp");

	world-> Jean2 = load_image( "ressources/Jeancopie.bmp");
	world-> Jean1 = load_image( "ressources/Jean_face2.bmp");
	world-> Jean = load_image( "ressources/Jean_face2.bmp");//Le premier pers
	world-> x = 0.;
	world-> y = 0.;
	world->deplace = 1;

	for(int i = 0; i<NB_COFFRE; i++){
		world->Co[i].Coffre = load_image("ressources/coffre.bmp");
		world->Co[i].cx = i + i*2;
		world->Co[i].cy = i + i*2;
	}
	
	world->Co[0].cx = 4 + 12;
	world->Co[0].cy = 532 - 4 - 14;

	world->Co[1].cx = 264 + 4 + 12;
	world->Co[1].cy = 532 - 4 - 14;

	world->Co[2].cx = 264 + 4 + 12;
	world->Co[2].cy = 4;

	world->Co[3].cx = 396 + 4 + 12;
	world->Co[3].cy = 176 - 14;

	world->Co[4].cx = 396 + 4 + 12;
	world->Co[4].cy = 532 - 4 - 14;
}
 
 
 /**
 * \brief La fonction initialise les données des murs
 * \param world les données du monde
 */


void init_mur(world_t * world){ 
	world->M[0].x = 0;
	world->M[0].y = 0;
	world->M[0].larg = 4;
	world->M[0].haut = 532;
	
	world->M[1].x = 0;
	world->M[1].y = 528;
	world->M[1].larg = 532;
	world->M[1].haut = 4;
	
	world->M[2].x = 528;
	world->M[2].y = 0;
	world->M[2].larg = 4;
	world->M[2].haut = 532;
	
	world->M[3].x = 44;
	world->M[3].y = 0;
	world->M[3].larg = 488;
	world->M[3].haut = 4;
	int i;
	for(i = 4; i<33; i++){
		world->M[i].larg = 4;
	}
	
	for(i = 4; i<6; i++){
		world->M[i].x = 44;
	}
	
	for(i = 6; i<9; i++){
		world->M[i].x = 88;
	}
	
	for(i = 9; i<13; i++){
		world->M[i].x = 132;
	}
	
	for(i = 13; i<18; i++){
		world->M[i].x = 176;
	}
 
	for(i = 18; i<20; i++){
		world->M[i].x = 220;
	}

	for(i = 20; i<22; i++){
		world->M[i].x = 264;
	}

	for(i = 22; i<25; i++){
		world->M[i].x = 308;
	}
	
	for(i = 25; i<27; i++){
		world->M[i].x = 352;
	}
	
	world->M[27].x = 396;
	world->M[27].y = 44;
	world->M[27].haut = 488;
	
	for(i = 28; i<31; i++){
		world->M[i].x = 440;
	}
	
	for(i = 31; i<33; i++){
		world->M[i].x = 484;
	}
	
	for(i = 13; i<16; i++){
		world->M[i].haut = 48;
	}
	
	for(i = 16; i<19; i++){
		world->M[i].haut = 92;
	}
	
	world->M[4].y = 0;
	world->M[4].haut = 136;
	
	world->M[5].y = 176;
	world->M[5].haut = 356;
	
	world->M[6].y = 0;
	world->M[6].haut = 48;
	
	world->M[7].y = 88;
	world->M[7].haut = 92;
	
	world->M[8].y = 264;
	world->M[8].haut = 224;
	
	world->M[9].y = 0;
	world->M[9].haut = 136;
	
	world->M[10].y = 176;
	world->M[10].haut = 92;
	
	world->M[11].y = 308;
	world->M[11].haut = 48;
	
	world->M[12].y = 396;
	world->M[12].haut = 136;
	
	world->M[13].y = 0;
		
	world->M[14].y = 88;

	world->M[15].y = 176;
	
	world->M[16].y = 264;
	
	world->M[17].y = 396;
	
	world->M[18].y = 0;
	
	world->M[19].y = 176;
	world->M[19].haut = 312;
	
	world->M[20].y = 0;
	world->M[20].haut = 268;
	
	world->M[21].y = 308;
	world->M[21].haut = 224;
	
	world->M[22].y = 0;
	world->M[22].haut = 136;
	
	world->M[23].y = 176;
	world->M[23].haut = 48;
	
	world->M[24].y = 264;
	world->M[24].haut = 268;
	
	world->M[25].y = 0;
	world->M[25].haut = 312;
	
	world->M[26].y = 352;
	world->M[26].haut = 136;

	world->M[28].y = 0;
	world->M[28].haut = 48;
	
	world->M[29].y = 88;
	world->M[29].haut = 92;
	
	world->M[30].y = 352;
	world->M[30].haut = 180;
	
	world->M[31].y = 0;
	world->M[31].haut = 136;
	
	world->M[32].y = 176;
	world->M[32].haut = 312;
	
	for(i = 33; i<52; i++){
		world->M[i].haut = 4;
	}
	
	for(i = 33; i<52; i++){
		world->M[i].larg = 48;
	}
	
	world->M[34].larg = 92;
	world->M[36].larg = 92;
	world->M[51].larg = 92;
	
	for(i = 36; i<41; i++){
		world->M[i].x = 132;
	}
	
	world->M[38].x = 176;
	
	world->M[33].x = 44;
	world->M[33].y = 132;
	
	world->M[34].x = 44;
	world->M[34].y = 220;
	
	world->M[35].x = 88;
	world->M[35].y = 264;
	
	world->M[36].y = 132;	
	
	world->M[37].y = 172;

	world->M[38].y = 264;

	world->M[39].y = 352;

	world->M[40].y = 396;
	
	world->M[41].x = 264;
	world->M[41].y = 88;
	
	world->M[42].x = 308;
	world->M[42].y = 172;
	
	world->M[43].x = 220;
	world->M[43].y = 308;
	
	world->M[44].x = 264;
	world->M[44].y = 352;
	
	world->M[45].x = 396;
	world->M[45].y = 88;
	
	world->M[46].x = 396;
	world->M[46].y = 172;
	
	world->M[47].x = 484;
	world->M[47].y = 172;
	
	world->M[48].x = 440;
	world->M[48].y = 220;
	
	world->M[49].x = 396;
	world->M[49].y = 264;
	
	world->M[50].x = 440;
	world->M[50].y = 308;
	
	world->M[51].x = 352;
	world->M[51].y = 352;
	
}
 
 

/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */


void clean_data(world_t *world){
	SDL_FreeSurface(world->background);
	SDL_FreeSurface(world->Lampe);
	SDL_FreeSurface(world->Jean);
	SDL_FreeSurface(world->Jean2);
	SDL_FreeSurface(world->Jean3);
	SDL_FreeSurface(world->Jean4);
}


int collision_mur_Jean(world_t *world){
	for(int i = 0; i< NB_MUR; i++){
		if(world->deplace == 1){//le bas
			if(world->M[i].x <= world->x + 21  &&  world->M[i].x >= world->x + 12 ){
				for(int j = world->M[i].y; j < (world->M[i].y + world->M[i].haut); j++){
					if(j <= (world-> y + 20 + 8) && j >= world->y + 20 + 8){
						return 1;
					}
				}
			}
		
			if(world->M[i].y + world->M[i].haut <= world->y + 23 + 8  &&  world->M[i].y >= world->y + 8){/////////////////////////////////////////////////////
				for(int k = world->M[i].x; k < (world->M[i].x + world->M[i].larg); k++){
					if(k <= (world-> x + 21) && k >= world->x + 12){
						return 1;
					}
				}
			}
		}
		
		if(world->deplace == 0){
			if(world->M[i].x <= world->x + 21  &&  world->M[i].x >= world->x + 12 ){
				for(int j = world->M[i].y; j < (world->M[i].y + world->M[i].haut); j++){
					if(j <= (world-> y + 9 - 8) && j >= world->y - 8){
						return 1;
					}
				}
			}
		
			if(world->M[i].y <= world->y + 9 - 8  &&  world->M[i].y >= world->y - 8){
				for(int k = world->M[i].x; k < (world->M[i].x + world->M[i].larg); k++){
					if(k <= (world-> x + 21) && k >= world->x + 12){
						return 1;
					}
				}
			}
		}

		if(world->deplace == 2){
			if(world->M[i].x <= world->x + 21 +8 &&  world->M[i].x >= world->x + 12 +8){
				for(int j = world->M[i].y; j < (world->M[i].y + world->M[i].haut); j++){
					if(j <= (world-> y + 9) && j >= world->y){
						return 1;
					}
				}
			}
		
			if(world->M[i].y <= world->y + 9   &&  world->M[i].y >= world->y){
				for(int k = world->M[i].x; k < (world->M[i].x + world->M[i].larg); k++){
					if(k <= (world-> x + 21 + 8) && k >= world->x + 12 + 8){
						return 1;
					}
				}
			}
		}

		if(world->deplace == 3){
			if(world->M[i].x <= world->x + 21  - 8 &&  world->M[i].x >= world->x + 12  - 8){
				for(int j = world->M[i].y; j < (world->M[i].y + world->M[i].haut); j++){
					if(j <= (world-> y + 9) && j >= world->y){
						return 1;
					}
				}
			}
		
			if(world->M[i].y <= world->y + 9 &&  world->M[i].y >= world->y){
				for(int k = world->M[i].x; k < (world->M[i].x + world->M[i].larg); k++){
					if(k <= (world-> x + 21 - 8) && k >= world->x + 12 - 8){
						return 1;
					}
				}
			}
		}
	}
	return 0;
}


int collision_coffre_Jean(world_t *world){
	for(int i = 0; i<NB_COFFRE; i++){
		if(world->Co[i].cx >= world->x + 12 && world->Co[i].cx <= world->x + 21){
			if(world->Co[i].cy <= world->y + 26 && world->Co[i].cy >= world->y){
				return 1;
			}
		}
		if(world->Co[i].cx + 16 >= world->x + 12 && world->Co[i].cx + 16 <= world->x + 21){
			if(world->Co[i].cy <= world->y + 26 && world->Co[i].cy >= world->y){
				return 1;
			}
		}
		if(world->Co[i].cx >= world->x + 12 && world->Co[i].cx <= world->x + 21){
			if(world->Co[i].cy + 14 <= world->y + 26 && world->Co[i].cy + 14 >= world->y){
				return 1;
			}
		}
		if(world->Co[i].cx + 16 >= world->x + 12 && world->Co[i].cx + 16 <= world->x + 21){
			if(world->Co[i].cy + 14 <= world->y + 26 && world->Co[i].cy + 14 >= world->y){
				return 1;
			}
		}
	}
	return 0;
}


void collision_teleportation(world_t *world){
	if(world->deplace == 0){
		if(world->M[33].y <= world->y + 23 - 8 &&  world->M[33].y >= world->y - 8){
			for(int k = world->M[33].x + 4; k < (world->M[33].x + world->M[33].larg - 4); k++){
				if(k <= (world-> x + 21) && k >= world->x + 12){
					world-> x = world->M[44].x + 16;//16 : taille pour centrer un minimum le Jean
					world-> y = world->M[44].y + world->M[44].haut + 10;
					return ;
				}
			}
		}
		if(world->M[44].y <= world->y + 23 - 8 &&  world->M[44].y >= world->y - 8){
			for(int k = world->M[44].x + 4; k < (world->M[44].x + world->M[44].larg - 4); k++){
				if(k <= (world-> x + 21) && k >= world->x + 12){
					world-> x = world->M[33].x + 16;//16 : taille pour centrer un minimum le Jean
					world-> y = world->M[33].y + world->M[33].haut + 10;
					return ;
				}
			}
		}
		if(world->M[40].y <= world->y + 23 - 8 &&  world->M[40].y >= world->y - 8){
			for(int k = world->M[40].x + 4; k < (world->M[40].x + world->M[40].larg - 8); k++){
				if(k <= (world-> x + 21 - 10) && k >= world->x + 12 - 10){
					world-> x = world->M[51].x + 44 + 16;//16 : taille pour centrer un minimum le Jean
					world-> y = world->M[51].y + world->M[51].haut + 10;
					return ;
				}
			}
		}
		if(world->M[51].y <= world->y + 23 - 8 &&  world->M[51].y >= world->y - 8){
			for(int k = world->M[51].x + 4; k < (world->M[51].x + world->M[51].larg - 8); k++){
				if(k <= (world-> x + 21 - 10) && k >= world->x + 12 - 10){
					world-> x = world->M[40].x + 16;//16 : taille pour centrer un minimum le Jean
					world-> y = world->M[40].y + world->M[40].haut + 10;
					return ;
				}
			}
		}
		if(world->M[42].y <= world->y + 23 - 8 &&  world->M[42].y >= world->y - 8){
			for(int k = world->M[42].x + 4; k < (world->M[42].x + world->M[42].larg - 8); k++){
				if(k <= (world-> x + 21 - 10) && k >= world->x + 12 - 10){
					world-> x = world->M[45].x + 16;//16 : taille pour centrer un minimum le Jean
					world-> y = world->M[45].y + world->M[45].haut + 10;
					return ;
				}
			}
		}
		if(world->M[45].y <= world->y + 23 - 8 &&  world->M[45].y >= world->y - 8){
			for(int k = world->M[45].x + 4; k < (world->M[45].x + world->M[45].larg - 8); k++){
				if(k <= (world-> x + 21 - 10) && k >= world->x + 12 - 10){
					world-> x = world->M[42].x + 16;//16 : taille pour centrer un minimum le Jean
					world-> y = world->M[42].y + world->M[42].haut + 10;
					return ;
				}
			}
		}
		if(world->M[47].y <= world->y + 23 - 8 &&  world->M[47].y >= world->y - 8){
			for(int k = world->M[47].x + 4; k < (world->M[47].x + world->M[47].larg -4); k++){
				if(k <= (world-> x + 21 - 10) && k >= world->x + 12 - 10){
					world-> x = world->M[41].x + 16;//16 : taille pour centrer un minimum le Jean
					world-> y = world->M[41].y - 21 - 10;
					return ;
				}
			}
		}
		
	}
	if(world->deplace == 1){
		if(world->M[41].y <= world->y + 23 + 8 &&  world->M[41].y >= world->y + 8){
			for(int k = world->M[41].x + 4; k < (world->M[41].x + world->M[41].larg - 8); k++){
				if(k <= (world-> x + 21 - 10) && k >= world->x + 12 - 10){
					world-> x = world->M[47].x + 16;//16 : taille pour centrer un minimum le Jean
					world-> y = world->M[47].y + world->M[47].haut + 10;
					return ;
				}
			}
		}
	}
	
	
}





/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde
 * \param world les données du monde
 * \return 1 si le jeu est fini, 0 sinon
 */

int is_game_over(world_t *world){
	return world->gameover;
}


/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param les données du monde
 */

void update_data(world_t *world){
}


/**
 * \brief La fonction initialise les transparences des différentes surfaces
 * \param screen la surface correspondant à l'écran de jeu
 * \param world les données du monde
 */

void  init_graphics(SDL_Surface *screen, world_t *world){
	set_transparence(screen, world->intero, 255,255,255);
	set_transparence(screen, world->Lampe, 255,255,255);
	set_transparence(screen, world->Lampe_droite, 255,255,255);
	set_transparence(screen, world->Lampe_gauche, 255,255,255);
	set_transparence(screen, world->Lampe_bas, 255,255,255);
	set_transparence(screen, world->Lampe_haut, 255,255,255);
	set_transparence(screen, world->Jean, 255,255,255);
	set_transparence(screen, world->Jean1, 255,255,255);
	set_transparence(screen, world->Jean2, 255,255,255);
	set_transparence(screen, world->Jean3, 255,255,255);
	set_transparence(screen, world->Jean4, 255,255,255);
	for(int i = 0; i<NB_COFFRE;i++){
		set_transparence(screen, world->Co[i].Coffre, 255,255,255);
	}

   
}
 

/**
 * \brief La fonction applique la surface de l'image de fond à quatre positions différentes sur l'écran de jeu, de sorte de complètement couvrir ce dernier
 * \param screen l'écran de jeu
 * \param bg la surface de l'image de fond
 */
void apply_background(SDL_Surface *bg, SDL_Surface *screen){
	apply_surface(bg,screen,0,0);

	
}





/**
 * \brief La fonction rafrachit l'écran en fonction de l'état des données du monde
 * \param screen la surface de l'écran de jeu
 * \param world les données du monde
 */

void refresh_graphics(SDL_Surface *screen, world_t *world){
	apply_background(world->background,screen);
	apply_surface(world->Jean, screen, world->x , world->y);
	//apply_surface(world->intero, screen, 4 + 12, 532 - 4 - 14);
	for( int i = 0; i< NB_COFFRE; i++){
		apply_surface(world->Co[i].Coffre, screen, world->Co[i].cx, world->Co[i].cy);
	}
	apply_surface(world->Lampe, screen, world->x-740, world->y - 760);
	apply_surface(world->intero, screen, world->Co[0].cx-5, world->Co[0].cy-8);
	refresh_surface(screen);
}

/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */


void handle_events(SDL_Event *event,world_t *world, SDL_Surface* screen){
	Uint8 *keystates;

	while( SDL_PollEvent( event ) ) {
	//Si l'utilisateur a cliqué sur le X de la fenêtre
		if( event->type == SDL_QUIT ) {
		  //On quitte le programme
		  world->gameover = 1;
		}
			
		/* gestion des evenements clavier */
		keystates = SDL_GetKeyState( NULL );

		//printf("%i",collision_coffre_Jean(world));

		if(/* 1 || */keystates[ SDLK_e ]){
			if(/*1 || */collision_coffre_Jean(world) == 1){
				boucle_snake(world, screen);
			}
		}
		
		
		
		/* Si l'utilisateur appuie sur les flèches, le personnage se déplace */
		if( keystates[ SDLK_UP])
		  {
			world->deplace = 0;
			if(collision_mur_Jean(world) != 1){
				world->Jean = world->Jean4;
				world->Lampe = world->Lampe_haut;
				world->y-=10;
			}

		  }
		else if( keystates[ SDLK_DOWN])
		{
			world->deplace = 1;
			if(collision_mur_Jean(world) != 1){
				world->Jean = world->Jean1;
				world->Lampe = world->Lampe_bas;
				world->y+=10;
			}
		}
		else if( keystates[ SDLK_RIGHT])
		{
			world->deplace = 2;
			if(collision_mur_Jean(world) != 1){
				world->Jean = world->Jean2;
				world->Lampe = world->Lampe_droite;
				world->x+=10;
			}
		}
		else if( keystates[ SDLK_LEFT])
		{
			world->deplace = 3;
			if(collision_mur_Jean(world) != 1){
				world->Jean = world->Jean3;
				world->Lampe = world->Lampe_gauche;
				world->x-=10;
			}
		}
		
		
	}
}





/**
 *  \brief programme principal qui implémente la boucle du jeu
 */


int main( int argc, char* args[] )
{
	SDL_Event event;
	world_t world;
	SDL_Surface *screen;

	screen = init_sdl(SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_WM_SetCaption("Fenêtre de jeu de labyrinthe !", NULL);

	init_data(&world);
	init_mur(&world);
	init_graphics(screen,&world);

	SDL_EnableKeyRepeat(100, 100); //active la répétition des touches


	while(!is_game_over(&world)){

		collision_teleportation(&world);
		handle_events(&event,&world, screen);
		update_data(&world);
		refresh_graphics(screen,&world);
		SDL_Delay(10);

	}

	clean_data(&world);
	quit_sdl();


	return 0;
}

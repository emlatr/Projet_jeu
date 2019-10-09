/**
 * \file main.c
 * \brief Programme principal du niveau 0
 * \author BONTE Emeline, DEBART Arthur
 * \version 0.1
 * \date 12 septembre 2019
 */

#include "sdl-light.h"
//#include "lab.c"

/**
 * \brief Largeur de l'écran de jeu
 */
#define SCREEN_WIDTH 365

/**
 * \brief Hauteur de l'écran de jeu
 */
#define SCREEN_HEIGHT 335

/**
 * \brief Taille d'un parchemin
 */
#define BUB_SIZE 40

/**
 * \brief Taille du bonhomme (sprite)
 */
#define SPRITE_SIZE 32

/**
 * \brief Pas de déplacement du sprite (bonhomme)
 */

#define MOVING_STEP 1




/**
 * \brief Représentation du monde du jeu
 */

struct world_s{
  SDL_Surface* lab_blanc;
  SDL_Surface* lab_noir;
  SDL_Surface* Jean;
  SDL_Surface* Jean1;
  SDL_Surface* Jean2;
  SDL_Surface* Jean3;
  SDL_Surface* Jean4;
  int gameover;
  int x,y;

    
};

typedef struct world_s world_t;



/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */


void init_data(world_t * world){
  world->lab_blanc = load_image( "ressources/blanc.bmp" ); 
	 world->lab_noir = load_image( "ressources/noir.bmp" ); 
  world->gameover = 0;
  world-> Jean4 = load_image( "ressources/Jean_dos2.bmp");
  world-> Jean3 = load_image( "ressources/Jean_cote_gauche2.bmp");

  world-> Jean2 = load_image( "ressources/Jean.bmp");
  world-> Jean1 = load_image( "ressources/Jean_face3.bmp");
  world-> Jean = load_image( "ressources/Jean_face3.bmp");//Le premier pers
  world-> x = 5.;
  world-> y = 0.;
}


/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */


void clean_data(world_t *world){
  SDL_FreeSurface(world->lab_blanc);
	SDL_FreeSurface(world->lab_noir);
  SDL_FreeSurface(world->Jean);
  SDL_FreeSurface(world->Jean1);
  SDL_FreeSurface(world->Jean2);
  SDL_FreeSurface(world->Jean3);
  SDL_FreeSurface(world->Jean4);
    
}








int **tab_lab (int tab[365][335]){
	//int tab[365][335];
	int i, j;

	//mur gauche
	for(i=0; i<5; i++){
		for(j=0; j<335; j++){
			tab[i][j] = 1;//blanc (mur)
		}
	}
	//mur bas
	for(i=0; i<365; i++){
		for(j=330; j<335; j++){
			tab[i][j] = 1;//blanc (mur)
		}
	}
	//mur haut
	for(i=30; i<365; i++){
		for(j=0; j<5; j++){
			tab[i][j] = 1;//blanc (mur)
		}
	}
	//mur droit
	for(i=360; i<365; i++){
		for(j=0; j<335; j++){
			tab[i][j] = 1;//blanc (mur)
		}
	}

	//chemin horizontal sont fait pendant la verticale
	//chemin 1
	for(i=5; i<30; i++){
		for(j=0; j<330; j++){
			tab[i][j] = 0;//noir
		}
		for(j=330; j<335; j++){
			tab[i][j] = 1;
		}
	}
	//mur 2
	for(i=30; i<35; i++){
		for(j=5; j<95; j++){
			tab[i][j] = 1;
		}
		for(j=95; j<120; j++){
			tab[i][j] = 0;
		}
		for(j=120; j<335; j++){
			tab[i][j] = 1;
		}
	}
	//chemin 2
	for(i=35; i<60; i++){
		for(j=5; j<90; j++){
			tab[i][j] = 0;
		}
		for(j=90; j<95; j++){
			tab[i][j] = 1;
		}
		for(j=95; j<150; j++){
			tab[i][j] = 0;
		}
		for(j=150; j<155; j++){
			tab[i][j] = 1;
		}
		for(j=155; j<330; j++){
			tab[i][j] = 0;
		}
	}
	//mur 3
	for(i=60; i<65; i++){
		for(j=5; j<35; j++){
			tab[i][j] = 1;
		}
		for(j=35; j<60; j++){
			tab[i][j] = 0;
		}
		for(j=60; j<125; j++){
			tab[i][j] = 1;
		}
		for(j=125; j<150; j++){
			tab[i][j] = 0;
		}
		for(j=150; j<155; j++){
			tab[i][j] = 1;
		}
		for(j=155; j<180; j++){
			tab[i][j] = 0;
		}
		for(j=180; j<305; j++){
			tab[i][j] = 1;
		}
		for(j=305; j<330; j++){
			tab[i][j] = 0;
		}
	}
	//chemin 3
	for(i=65; i<90; i++){
		for(j=5; j<150; j++){
			tab[i][j] = 0;
		}
		for(j=150; j<155; j++){
			tab[i][j] = 1;
		}
		for(j=155; j<180; j++){
			tab[i][j] = 0;
		}
		for(j=180; j<185; j++){
			tab[i][j] = 1;
		}
		for(j=185; j<330; j++){
			tab[i][j] = 0;
		}
	}
	//mur 4
	for(i=90; i<95; i++){
		for(j=5; j<95; j++){
			tab[i][j] = 1;
		}
		for(j=95; j<120; j++){
			tab[i][j] = 0;
		}
		for(j=120; j<185; j++){
			tab[i][j] = 1;
		}
		for(j=185; j<210; j++){
			tab[i][j] = 0;
		}
		for(j=210; j<245; j++){
			tab[i][j] = 1;
		}
		for(j=245; j<270; j++){
			tab[i][j] = 0;
		}
		for(j=270; j<330; j++){
			tab[i][j] = 1;
		}
	}
	//chemin 4
	for(i=95; i<120; i++){
		for(j=5; j<90; j++){
			tab[i][j] = 0;
		}
		for(j=90; j<95; j++){
			tab[i][j] = 1;
		}
		for(j=95; j<120; j++){
			tab[i][j] = 0;
		}
		for(j=120; j<125; j++){
			tab[i][j] = 1;
		}
		for(j=125; j<240; j++){
			tab[i][j] = 0;
		}
		for(j=240; j<245; j++){
			tab[i][j] = 1;
		}
		for(j=245; j<270; j++){
			tab[i][j] = 0;
		}
		for(j=270; j<275; j++){
			tab[i][j] = 1;
		}
		for(j=275; j<330; j++){
			tab[i][j] = 0;
		}
	}
	//mur 5
	for(i=120; i<125; i++){
		for(j=5; j<35; j++){
			tab[i][j] = 1;
		}
		for(j=35; j<60; j++){
			tab[i][j] = 0;
		}
		for(j=60; j<95; j++){
			tab[i][j] = 1;
		}
		for(j=95; j<120; j++){
			tab[i][j] = 0;
		}
		for(j=120; j<150; j++){
			tab[i][j] = 1;
		}

		for(j=150; j<180; j++){
			tab[i][j] = 0;
		}
		for(j=180; j<210; j++){
			tab[i][j] = 1;
		}
		for(j=210; j<245; j++){
			tab[i][j] = 1;
		}
		for(j=245; j<270; j++){
			tab[i][j] = 0;
		}
		for(j=270; j<305; j++){
			tab[i][j] = 1;
		}
		for(j=305; j<330; j++){
			tab[i][j] = 0;
		}
	}
	//chemin 5
	for(i=125; i<150; i++){
		for(j=5; j<90; j++){
			tab[i][j] = 0;
		}
		for(j=90; j<95; j++){
			tab[i][j] = 1;
		}
		for(j=95; j<180; j++){
			tab[i][j] = 0;
		}
		for(j=180; j<185; j++){
			tab[i][j] = 1;
		}
		for(j=185; j<330; j++){
			tab[i][j] = 0;
		}
	}
	//mur 6
	for(i=150; i<155; i++){
		for(j=5; j<65; j++){
			tab[i][j] = 1;
		}
		for(j=65; j<90; j++){
			tab[i][j] = 0;
		}
		for(j=90; j<95; j++){
			tab[i][j] = 1;
		}
		for(j=95; j<120; j++){
			tab[i][j] = 0;
		}
		for(j=120; j<305; j++){
			tab[i][j] = 1;
		}
		for(j=305; j<330; j++){
			tab[i][j] = 0;
		}
	}
	//chemin 6
	for(i=155; i<180; i++){
		for(j=5; j<210; j++){
			tab[i][j] = 0;
		}
		for(j=210; j<215; j++){
			tab[i][j] = 1;
		}
		for(j=215; j<330; j++){
			tab[i][j] = 0;
		}
		
	}
	//mur 7
	for(i=180; i<185; i++){
		for(j=5; j<185; j++){
			tab[i][j] = 1;
		}
		for(j=185; j<210; j++){
			tab[i][j] = 0;
		}
		for(j=210; j<330; j++){
			tab[i][j] = 1;
		}
	}
	//chemin 7
	for(i=185; i<210; i++){
		for(j=5; j<60; j++){
			tab[i][j] = 0;
		}
		for(j=60; j<65; j++){
			tab[i][j] = 1;
		}
		for(j=65; j<240; j++){
			tab[i][j] = 0;
		}
		for(j=240; j<245; j++){
			tab[i][j] = 1;
		}
		for(j=245; j<305; j++){
			tab[i][j] = 0;
		}
	}
	//mur 7
	for(i=210; i<215; i++){
		for(j=5; j<65; j++){
			tab[i][j] = 1;
		}
		for(j=65; j<90; j++){
			tab[i][j] = 0;
		}
		for(j=90; j<95; j++){
			tab[i][j] = 1;
		}
		for(j=95; j<120; j++){
			tab[i][j] = 0;
		}
		for(j=120; j<155; j++){
			tab[i][j] = 1;
		}
		for(j=155; j<180; j++){
			tab[i][j] = 0;
		}
		for(j=180; j<330; j++){
			tab[i][j] = 1;
		}
	}
	//chemin 8
	for(i=215; i<240; i++){
		for(j=5; j<330; j++){
			tab[i][j]=0;
		}
	}
	//mur 9
	for(i=240; i<245; i++){
		for(j=5; j<215; j++){
			tab[i][j]=1;
		}
		for(j=215; j<240; j++){
			tab[i][j]=0;
		}
		for(j=240; j<305; j++){
			tab[i][j]=1;
		}
		for(j=305; j<330; j++){
			tab[i][j]=0;
		}
	}
	//chemin 9
	for(i=245; i<270; i++){
		for(j=5; j<240; j++){
			tab[i][j]=0;
		}
		for(j=240; j<245; j++){
			tab[i][j]=1;
		}
		for(j=245; j<330; j++){
			tab[i][j]=0;
		}
	}
	//mur 10
	for(i=270; i<275; i++){
		for(j=5; j<35; j++){
			tab[i][j]=0;
		}
		for(j=35; j<330; j++){
			tab[i][j]=1;
		}
	}
	//chemin 10
	for(i=275; i<300; i++){
		for(j=5; j<60; j++){
			tab[i][j]=0;
		}
		for(j=60; j<65; j++){
			tab[i][j]=1;
		}
		for(j=65; j<120; j++){
			tab[i][j]=0;
		}
		for(j=120; j<125; j++){
			tab[i][j]=1;
		}
		for(j=125; j<180; j++){
			tab[i][j]=0;
		}
		for(j=180; j<185; j++){
			tab[i][j]=1;
		}
		for(j=185; j<240; j++){
			tab[i][j]=0;
		}
		for(j=240; j<245; j++){
			tab[i][j]=1;
		}
		for(j=245; j<330; j++){
			tab[i][j]=0;
		}
	}
	//mur 11
	for(i=300; i<305; i++){
		for(j=5; j<35; j++){
			tab[i][j]=1;
		}
		for(j=35; j<60; j++){
			tab[i][j]=0;
		}
		for(j=60; j<125; j++){
			tab[i][j]=1;
		}
		for(j=125; j<150; j++){
			tab[i][j]=0;
		}
		for(j=150; j<155; j++){
			tab[i][j]=1;
		}
		for(j=155; j<180; j++){
			tab[i][j]=0;
		}
		for(j=180; j<185; j++){
			tab[i][j]=1;
		}
		for(j=185; j<210; j++){
			tab[i][j]=0;
		}
		for(j=210; j<215; j++){
			tab[i][j]=1;
		}
		for(j=215; j<240; j++){
			tab[i][j]=0;
		}
		for(j=240; j<330; j++){
			tab[i][j]=1;
		}
	}
	//chemin 11
	for(i=305; i<330; i++){
		for(j=5; j<150; j++){
			tab[i][j]=0;
		}
		for(j=150; j<155; j++){
			tab[i][j]=1;
		}
		for(j=155; j<210; j++){
			tab[i][j]=0;
		}
		for(j=210; j<215; j++){
			tab[i][j]=1;
		}
		for(j=215; j<330; j++){
			tab[i][j]=0;
		}
	}
	//mur 12
	for(i=330; i<335; i++){
		for(j=5; j<95; j++){
			tab[i][j]=1;
		}
		for(j=95; j<120; j++){
			tab[i][j]=0;
		}
		for(j=120; j<305; j++){
			tab[i][j]=1;
		}
		for(j=305; j<330; j++){
			tab[i][j]=0;
		}
	}
	//chemin 12
	for(i=335; i<360; i++){
		for(j=5; j<120; j++){
			tab[i][j]=0;
		}
		for(j=120; j<125; j++){
			tab[i][j]=1;
		}
		for(j=125; j<330; j++){
			tab[i][j]=0;
		}
	}
	return tab;
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
  set_transparence(screen, world->Jean, 255,255,255);
  set_transparence(screen, world->Jean1, 255,255,255);
  set_transparence(screen, world->Jean2, 255,255,255);
  set_transparence(screen, world->Jean3, 255,255,255);
  set_transparence(screen, world->Jean4, 255,255,255);

}





/**
 * \brief La fonction applique la surface de l'image de fond à quatre positions différentes sur l'écran de jeu, de sorte de complètement couvrir ce dernier
 * \param screen l'écran de jeu
 * \param bg la surface de l'image de fond
 */
void apply_background(SDL_Surface *bgn, SDL_Surface *bgb, SDL_Surface *screen){
	int i,j;	
	int tab[365][335];
	tab_lab(tab);
	for(i = 0; i<365; i++){
		for(j = 0; j<335; j++){
			if(tab[i][j] == 1){
				apply_surface(bgb,screen,i,j);
			}
   			else{
				apply_surface(bgn,screen,i,j);
			}
		}
	}

	
}





/**
 * \brief La fonction rafrachit l'écran en fonction de l'état des données du monde
 * \param screen la surface de l'écran de jeu
 * \param world les données du monde
 */

void refresh_graphics(SDL_Surface *screen, world_t *world){
  apply_background(world->lab_noir,world->lab_blanc,screen);
  apply_surface(world->Jean, screen, world->x , world->y);
    
    
    
  refresh_surface(screen);
}

void affichage (world_t *world){
  //printf("x = %d, y = %d", world->x,world->y);
}

/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */


void handle_events(SDL_Event *event,world_t *world){
  Uint8 *keystates;
	
  	affichage(world);  

  while( SDL_PollEvent( event ) ) {
    //Si l'utilisateur a cliqué sur le X de la fenêtre
    if( event->type == SDL_QUIT ) {
      //On quitte le programme
      world->gameover = 1;
    }
        
    /* gestion des evenements clavier */
    keystates = SDL_GetKeyState( NULL );

    /* Si l'utilisateur appuie sur les flèches, le personnage se déplace */
    if( keystates[ SDLK_UP])
      {
	world->Jean = world->Jean4;
	world->y-=10;

      }
    if( keystates[ SDLK_DOWN])
      {
	world->Jean = world->Jean1;
	world->y+=10;
	
      }
    if( keystates[ SDLK_RIGHT])
      {
	world->Jean = world->Jean2;
	world->x+=10;
      }
    if( keystates[ SDLK_LEFT])
      {
	world->Jean = world->Jean3;
	world->x-=10;
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
  init_graphics(screen,&world);
  
  SDL_EnableKeyRepeat(100, 100); //active la répétition des touches
 
  
  while(!is_game_over(&world)){
    
    handle_events(&event,&world);
    update_data(&world);
    refresh_graphics(screen,&world);
    SDL_Delay(10);


  }

  clean_data(&world);
  quit_sdl();
    
    
  return 0;
}

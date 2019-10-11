/**
 * \file main.c
 * \brief Programme principal du niveau 0
 * \author BONTE Emeline, DEBART Arthur
 * \version 0.1
 * \date 12 septembre 2019
 */

#include "sdl-light.h"

/**
 * \brief Largeur de l'écran de jeu
 */
#define SCREEN_WIDTH 640

/**
 * \brief Hauteur de l'écran de jeu
 */
#define SCREEN_HEIGHT 450

/**
 * \brief Taille d'un parchemin
 */
#define SIZEH 45

/**
 * \brief Taille du bonhomme (sprite)
 */
#define SIZEL 45

/**
 * \brief Pas de déplacement du sprite (bonhomme)
 */

#define MOVING_STEP 1

/**
 * \brief Bordure droite de la table
 */
#define RIGHT_LIMIT 540

/**
 * \brief Bordure gauche de la table
 */
#define LEFT_LIMIT 0

/**
 * \brief Bordure haute de la table
 */
#define TOP_LIMIT 0

/**
 * \brief Bordure basse de la table
 */
#define BOTTOM_LIMIT 540

/**
 * \brief Bordure basse de la table
 */
#define SIZE_MOITIER 16

/**
 * \brief Bordure basse de la table
 */
#define NB_CORPS 2






struct pomme_s{
	SDL_Surface* Pomme;
	int px,py;
};

typedef struct pomme_s pomme_t;

struct corps_s{
	SDL_Surface* Corps;
	int cx,cy;
};

typedef struct corps_s corps_t;




/**
 * \brief Représentation du monde du jeu
 */

struct world_s{
  SDL_Surface* background;
  SDL_Surface* Serpent;
  SDL_Surface* Serpent1;
  SDL_Surface* Serpent2;
  SDL_Surface* Serpent3;
  SDL_Surface* Serpent4;
  pomme_t Pomme_rouge;
  corps_t corps;
  corps_t C[NB_CORPS];
  int gameover;
  int x,y;
    
};

typedef struct world_s world_t;


/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */


void init_data(world_t * world){ 
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

  world-> corps.cx = 0;
  world-> corps.cy = 32;

  world->C[0].cx = world->corps.cx;
  world->C[0].cy = world->corps.cy + 9;
  world->C[0].Corps = world->corps.Corps;

	for(int i = 1; i<NB_CORPS ; i++){
		world->C[i].cx = world->C[i-1].cx;
		world->C[i].cy = world->C[i-1].cy + 9;
		world->C[i].Corps = world->corps.Corps;
	}

  
}
 

/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */


void clean_data(world_t *world){
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
  set_transparence(screen, world->Pomme_rouge.Pomme, 255,255,255);
  set_transparence(screen, world->Serpent, 255,255,255);
  set_transparence(screen, world->Serpent1, 255,255,255);
  set_transparence(screen, world->Serpent2, 255,255,255);
  set_transparence(screen, world->Serpent3, 255,255,255);
  set_transparence(screen, world->Serpent4, 255,255,255);
  set_transparence(screen, world->corps.Corps, 255,255,255);

   
}

int collision (world_t *world){
	if(world->x+32 > SCREEN_WIDTH){
		//world->x = 0.1;
		return 1;
	}
	if(world->x < 0.){
		//world->x = SCREEN_WIDTH - 20;
		return 2;
	}
	if(world->y+32 > SCREEN_HEIGHT){
		//world->y = 0.1;
		return 3;
	}
	if(world->y < 0.){
		//world->y = SCREEN_HEIGHT - 20;
		return 4;
	}
	return 0;
}
 
void replacement_serpent(world_t *world){
	if(collision(world) == 1){
		world->x = 0.1;
		return;
	}
	if(collision(world) == 2){
		world->x = SCREEN_WIDTH - 32;
		return;
	}
	if(collision(world) == 3){
		world->y = 0.1;
		return;
	}
	if(collision(world) == 4){
		world->y = SCREEN_HEIGHT - 32;
		return;
	}
	return;
}

void collision_pomme_serp(world_t* world){
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
  apply_surface(world->Pomme_rouge.Pomme, screen, 50, 50);
  apply_surface(world->corps.Corps, screen, world->corps.cx , world->corps.cy);
  apply_surface(world->Serpent, screen, world->x , world->y);
  //apply_surface(world->C[NB_CORPS].Corps, screen, world->C[NB_CORPS].cx , world->C[NB_CORPS].cy);
  
  refresh_surface(screen);
}

/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */


void handle_events(SDL_Event *event,world_t *world){
  Uint8 *keystates;

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
	world->Serpent = world->Serpent4;
	world->y-=10;
	world->corps.cx = world->x;
	world->corps.cy = world->y + 32 ;

      }
    if( keystates[ SDLK_DOWN])
      {
	world->Serpent = world->Serpent1;
	world->y+=8;
	world->corps.cx = world->x + 1;
	world->corps.cy = world->y - 32 + 23;
	
      }
    if( keystates[ SDLK_RIGHT])
      {
	world->Serpent = world->Serpent2;
	world->x+=8;
	world->corps.cx = world->x - 32 + 12 ;
	world->corps.cy = world->y + 11 ;
      }
    if( keystates[ SDLK_LEFT])
      {
	world->Serpent = world->Serpent3;
	world->x-=8;
	world->corps.cx = world->x + 32 - 11;
	world->corps.cy = world->y + 12;
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
	/*if(touch_bordure_b(&world)!=0){
		replacement_mur(&world);
	}*/
	if(collision(&world)){
		replacement_serpent(&world);
	}

  }

  clean_data(&world);
  quit_sdl();
    
    
  return 0;
}

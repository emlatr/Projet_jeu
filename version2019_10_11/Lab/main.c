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
#define SCREEN_WIDTH 550

/**
 * \brief Hauteur de l'écran de jeu
 */
#define SCREEN_HEIGHT 550

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
 * \brief Représentation du monde du jeu
 */

struct world_s{
  SDL_Surface* background;
  SDL_Surface* Lampe;
  SDL_Surface* Lampe_droite;
  SDL_Surface* Lampe_gauche;
  SDL_Surface* Lampe_bas;
  SDL_Surface* Lampe_haut;
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
  world-> background = load_image( "ressources/pixil-frame-0(6).bmp" );
  world-> Lampe = load_image( "ressources/pixil-frame-0(2).bmp" );
world-> Lampe_droite = load_image( "ressources/pixil-frame-0(3).bmp" );
world-> Lampe_gauche = load_image( "ressources/pixil-frame-0(4).bmp" );
world-> Lampe_haut = load_image( "ressources/pixil-frame-0(5).bmp" );
world-> Lampe_bas = load_image( "ressources/pixil-frame-0(2).bmp" );  



  world-> gameover = 0;
  world-> Jean4 = load_image( "ressources/Jean_dos2.bmp");
  world-> Jean3 = load_image( "ressources/Jean_cote_gauche2.bmp");

  world-> Jean2 = load_image( "ressources/Jeancopie.bmp");
  world-> Jean1 = load_image( "ressources/Jean_face2.bmp");
  world-> Jean = load_image( "ressources/Jean_face2.bmp");//Le premier pers
  world-> x = 0.;
  world-> y = 0.;
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
  apply_surface(world->Lampe, screen, world->x-740, world->y - 760);
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
	world->Jean = world->Jean4;
	world->Lampe = world->Lampe_haut;
	world->y-=10;

      }
    if( keystates[ SDLK_DOWN])
      {
	world->Jean = world->Jean1;
	world->Lampe = world->Lampe_bas;
	world->y+=10;
	
      }
    if( keystates[ SDLK_RIGHT])
      {
	world->Jean = world->Jean2;
	world->Lampe = world->Lampe_droite;
	world->x+=10;
      }
    if( keystates[ SDLK_LEFT])
      {
	world->Jean = world->Jean3;
	world->Lampe = world->Lampe_gauche;
	world->x-=10;
      }
        
        
  }
    
}



int touch_bordure_b(world_t* Jean)
{
  int x,y;
  x=Jean->x;
  y=Jean->y;
  if(y<=TOP_LIMIT)
    {
      return 1;
    }
  if(y+SIZEH>=BOTTOM_LIMIT)
    {
      return 2;
    }
  if(x<=LEFT_LIMIT)
    {
      return 3;
    }
  if(x+SIZEL>=RIGHT_LIMIT)
    {
      return 4;
    }
  return 0;
}


void replacement_mur(world_t* Jean)
{
  int x,y;
  x=Jean->x;
  y=Jean->y;
	if(y<TOP_LIMIT)
	    {
		Jean->y=TOP_LIMIT;
	    }
	else if(y>BOTTOM_LIMIT)
	    {
		Jean->y=BOTTOM_LIMIT-SIZEH;
	    }
	if(x<LEFT_LIMIT)
	{
		Jean->x=LEFT_LIMIT;
	}
	else if(x>RIGHT_LIMIT)
	{
	  Jean->x=RIGHT_LIMIT-SIZEL;
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
	if(touch_bordure_b(&world)!=0){
		replacement_mur(&world);
	}

  }

  clean_data(&world);
  quit_sdl();
    
    
  return 0;
}

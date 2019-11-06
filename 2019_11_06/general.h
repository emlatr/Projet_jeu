/**
 * \file general.h
 * \brief Programme general pour toutes les valeurs stables et les structures
 * \author Emeline BONTE, Brian PETIT
 * \version 0.1
 * \date 21 mars 2019-27 mai 2019
 */

#include "sdl-light.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * \brief Largeur de l'écran de jeu
 */
#define SCREEN_WIDTH 850

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
 * \brief Taille du bonhomme (sprite)
 */
#define SIZE 40

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
#define NB_MUR 52

/**
 * \brief Nombre maximum de coffre
 */
#define NB_COFFRE 5

/**
 * \brief Taille du coffre a droite
 */
#define SIZE_RIGHT_COFFRE 16

/**
 * \brief Taille du  coffre à gauche
 */
#define SIZE_LEFT_COFFRE 0

/**
 * \brief Taille du coffre en bas
 */
#define SIZE_BOTTOM_COFFRE 14

/**
 * \brief Taille du  coffreen haut
 */
#define SIZE_TOP_COFFRE 0







/**
 * \brief Largeur de l'écran de jeu du Snake
 */
#define SCREEN_WIDTH_SNAKE 850

/**
 * \brief Hauteur de l'écran de jeu du Snake
 */
#define SCREEN_HEIGHT_SNAKE 550

/**
 * \brief Bordure droite de la table
 */
#define RIGHT_LIMIT_SNAKE 850

/**
 * \brief Bordure gauche de la table
 */
#define LEFT_LIMIT_SNAKE 0.

/**
 * \brief Bordure haute de la table
 */
#define TOP_LIMIT_SNAKE 0.

/**
 * \brief Bordure basse de la table
 */
#define BOTTOM_LIMIT_SNAKE 450

/**
 * \brief Nombre maximum de corps 
 */
#define NB_CORPS_SNAKE 200

/**
 * \brief Nombre maximum de pomme
 */
#define NB_POMME 3

/**
 * \brief Taille de la pomme
 */
#define SIZE_POMME 20

/**
 * \brief Taille de la limite a droite de la pomme
 */
#define SIZE_RIGHT_POMME 17

/**
 * \brief Taille de la limite a gauche de la pomme
 */
#define SIZE_LEFT_POMME 4

/**
 * \brief Taille du serpent a droite
 */
#define SIZE_RIGHT_SNAKE 20

/**
 * \brief Taille du serpent à gauche
 */
#define SIZE_LEFT_SNAKE 11

/**
 * \brief Taille du serpent en bas
 */
#define SIZE_BOTTOM_SNAKE 9

/**
 * \brief Taille du serpent en haut
 */
#define SIZE_TOP_SNAKE 0











struct mur_s{
	int x,y;
	int larg, haut;

};
typedef struct mur_s mur_t;



/**
 * \brief Représentation du monde du jeu
 */


struct pomme_s{
	SDL_Surface* Pomme;
	int px,py;
	int exist;
};
typedef struct pomme_s pomme_t;

struct corps_s{
	SDL_Surface* Corps;
	double cx,cy;

};
typedef struct corps_s corps_t;


struct coffre_s{
	SDL_Surface* Coffre;
	double cx,cy;
};
typedef struct coffre_s coffre_t;



/**
 * \brief Représentation du monde du jeu
 */

struct snake_s{
	SDL_Surface* background;
	SDL_Surface* fond;
	SDL_Surface* Serpent;
	SDL_Surface* Serpent1;
	SDL_Surface* Serpent2;
	SDL_Surface* Serpent3;
	SDL_Surface* Serpent4;
	pomme_t PR[NB_POMME];
	corps_t corps;
	corps_t C[NB_CORPS_SNAKE];
	int gameover;
	double x,y;
	double vx, vy;
	int direct;
	int nb_corps;
	bool ouvert;
	int score;
	pomme_t PV[NB_POMME];
	SDL_Surface* pause;
	
    
};

typedef struct snake_s snake_t;

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
	SDL_Surface* intero;
	int gameover;
	int x,y;
	mur_t M[NB_MUR];
	int deplace;
	int compt;
	coffre_t Co[NB_COFFRE];
	snake_t snake;
    
};

typedef struct world_s world_t;


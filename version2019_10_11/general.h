/**
 * \file general.h
 * \brief Programme general pour toutes les valeurs stables et les structures
 * \author Emeline BONTE, Brian PETIT
 * \version 0.1
 * \date 21 mars 2019-27 mai 2019
 */

#include<math.h>
#include "sdl-light.h"

/**
 * \brief Largeur de l'écran de jeu
 */
#define SCREEN_WIDTH 1288

/**
 * \brief Hauteur de l'écran de jeu
 */
#define SCREEN_HEIGHT 725

/**
 * \brief Taille d'une boule
 */
#define BALL_SIZE 42

/**
 * \brief rayon d'une boule
 */
#define RAYON 24

/**
 * \brief Vitesse boule blanche
 */
#define SPEED_COEF 0.09

/**
 * \brief coef ralentissement boule blanche
 */
#define FREIN_COEF 0.03

/**
 * \brief Bordure droite de la table
 */
#define RIGHT_LIMIT 1160

/**
 * \brief Bordure gauche de la table
 */
#define LEFT_LIMIT 85

/**
 * \brief Bordure haute de la table
 */
#define TOP_LIMIT 68

/**
 * \brief Bordure basse de la table
 */
#define BOTTOM_LIMIT 620

/**
 * \brief rayon d'un trou de la table
 */
#define HOLE_RADIUS 35

/**
 * \brief nombre de trou de la table
 */
#define NB_HOLES 6

/**
 * \brief nombre de balles colorés
 */
#define NB_BALLS 15

/**
 * \brief limite gauche pour l'ouverture du trou
 */
#define LEFT 625

/**
 * \brief limite droite pour l'ouverture du trou
 */
#define RIGHT 663

/**
 * \brief Nombre de joueurs
 */
#define NB_JOUEUR 2


/**
 * \brief structure d'un joueur
 */
struct joueur_s
{
  int S[NB_JOUEUR];
  int main;
  int jouer;
};
typedef struct joueur_s joueur_t;

/**
 * \brief structure d'un trou
 */
struct hole_s
{
  double tr;
  double x,y;
};
typedef struct hole_s hole_t;

/**
 * \brief structure d'une balle
 */
struct ball_s
{
  double x, y;
  double vx, vy;
  int ici;
  int pos;
  int temp;
};
typedef struct ball_s ball_t;

/**
 * \brief structure du monde
 */
struct world_s{
  int gameover;
  SDL_Surface* table;
  SDL_Surface* boules;
  ball_t boule_blanche;
  ball_t balls[NB_BALLS];
  hole_t T[NB_HOLES];
  joueur_t J;
};
typedef struct world_s world_t;

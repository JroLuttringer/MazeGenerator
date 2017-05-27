#ifndef _MAT_H_
#define _MAT_H_


/**
 * \file matrice.h
 * \brief Contient les déclarations du type matrice, ainsi que les en-têtes et commentaires des fonctions sur matrice
 * \author Cyrille Muller
 * */ 

#include <stdio.h>
#include <stdlib.h>

typedef int Bool;
#define FAUX 0
#define VRAI 1
#define MAX_LINE 2048

/**
 * \struct strmat
 * \brief Structure représentant un matrice, composé d'un tableau 2D de booléens et de deux entiers
 * */
typedef struct strmat{
	Bool** mat; /*!<Tableau de booléen contenant les valeurs de la matrice*/
	int h; /*!< hauteur du tableau*/
	int	l; /*! largeur du tableau*/
}*Matrice;
/**
 * \struct Matrice
 * \brief Pointeur sur strmat
 * */


/**
 * \fn MatAlloc(h,l)
 * \brief renvoie une matrice h x l
 * \param int h hauteur de la matrice
 * \param int l largeur de la matrice
 * \return Matrice
 * */
Matrice MatAlloc(int h, int l);

/**
 * \fn MatFree
 * \brief Libère l'espace occupé par la matrice
 * \param Matrice Matrice à libérer
 * \return Matrice (NULL)
 * */
Matrice MatFree(Matrice);

/**
 * \fn MatVal
 * \brief revoie la valeur de la case de la matrice aux coordonnées x,y
 * \param x abscisse de la case
 * \param y coordonnées de la case
 * \param m Matrice contenant la case
 * \return Bool
 * */
Bool MatVal(int x, int y, Matrice m);

/**
 * \fn MatSet
 * \brief Met la valeur de la variable aux coordonées (x,y) à b
 * \param x Abscisse de la case
 * \param y Ordonnées de la case
 * \param b Valeur que doit prendre la case
 * \param m Matrice dont on veut modifier la case
 * \return Matrice
 * */
Matrice MatSet(int x, int y, Bool b , Matrice m);

/**
 * \fn MatSauve
 * \brief Sauvegarde une matrice dans un fichier
 * \param m matrice à sauvegarder
 * \param f nom du fichier dans lequel sauvegarder la matrice
 * \return -
 * */
void MatSauve(Matrice m, char* f);

/**
 * \fn MatLit
 * \brief Lit un fichier et stocke son contenu dans une structure matrice
 * \param fd File Descriptor du fichier contenant la matrice
 * \return Matrice
 * 
 * Le fichier à lire doit être formaté de la manière suivante :
 * <hauteur> <largeur>
 * <matrice>
 * */
Matrice MatLit(FILE* fd);

/**
 * \fn remplirrangee
 * \brief copie le contenu d'une ligne d'un fichier dans une matrice
 * \param m Matrice dont on souhaite remplir la rangée
 * \param h indice de la ligne à remplir
 * \param liste ligne du fichier à stocker dans la matrice
 * */
Matrice remplirrangee(Matrice m , int h , char* liste);

#endif

#ifndef _LAB_H_
#define _LAB_H_


/**
 * \file labyrinth.h
 * \brief Contient les en têtes des fonctions concernant la création d'un labyrinthe,
 * l'affichage et la construction de labyrinths et de chemins
 * \author Jean-Romain Luttringer et Cyrille Muller (spécifié pour chaque fonction)
 * */ 

#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
#include "ensemble.h"
#include "graph.h"

/**
 * \fn InitBord
 * \author  Cyrille Muller
 * \brief Initialise les bords de la matrice à VRAI
 * \param m Matrice dont on veut initialiser les bords
 * \return Matrice
 * Permet de créer les murs autour du labyrinthe
 * Laisse deux cases vides représentant l'entrée et la sortie
 * */
Matrice InitBord(Matrice m);

/**
 * \fn EstConstructible
 * \author Cyrille Muller
 * \brief Renvoie un booléen indiquant si une case est constructible ou non
 * \param m Matrice contenant la case à tester
 * \param e Ensemble contenant les coordonées des graines du labyrinthe
 * \param x Abscisse de la case à tester
 * \param y Ordonnée de la case à tester
 * \return Bool
 * */
Bool EstConstructible (Matrice m, ens e, int x, int y);

/**
 * \fn InitConstructible
 * \author Cyrille Muller
 * \brief Initialise l'ensemble des cases constructibles
 * \param m Matrice dont on veut initialiser les cases constructibles
 * \param e Ensembles des graines de la Matrice m
 * \return ens
 * */
ens InitConstructible(Matrice m, ens e);

/**
 * \fn InitGraines
 * \author Jean-Romain Luttringer
 * \brief Initialise un ensemble de graines
 * \param m Matrice pour laquelle sera initialisé les graines
 * \param k Nombre de graines à initialiser
 * \return ens
 * */
ens InitGraines(Matrice m, int k);

/**
 * \fn dessincase
 * \author Jean-Romain Luttringer
 * \brief dessine une case sur une fenetre graphique initialisée au préalable
 * \param x abscisse de la case
 * \param y ordonnée de la case
 * \param t taille de la case
 * \return affichage
 * */
void dessincase(int x,int y,int t);

/**
 * \fn taille_case
 * \author Jean-Romain Luttringer
 * \brief renvoie la taille d'une case adaptée pour une matrice
 * \param m Matrice pour laquelle on souhaite connaitre la taille que doit faire une case
 * \return int
 * */
int taille_case(Matrice m);

/**
 * \fn affiche_lab
 * \author Cyrille Muller et  Jean-Romain Luttringer
 * \brief affiche le labyrithe
 * \param m Matrice que l'on souhaite afficher
 * \param t taille que doit faire une case
 * \return -
 * */
void affiche_lab(Matrice m,int t);

/**
 * \fn ConstruireMur
 * \author Cyrille Muller
 * \brief construit une case du labyrinth
 * \param m Matrice du labyrinth, l'ensemble des graines, 
 * un pointeur sur l'ensemble des cases constructibles(car elles vont changer), puis un flag si on a demandé l'affichage
 * \return un affichage / modification de la matrice
 * */
void ConstruireMur(Matrice , ens , ens*,int);

/**
 * \fn BoucleGen
 * \author Cyrille Muller
 * \brief fonction qui appelle la fonction Construire mur tant qu'il reste des cases constructibles
 * \param m Matrice du lab, l'ensebmel de graines, le pointeur sur l'ensemble
 * des cases constructibles et le flag d'affichage
 * \return un affichage / modification de la matrice
 * */
void BoucleGen(Matrice, ens, ens*,int);

/**
 * \fn Chemin
 * \author Cyrille Muller et Jean-Romain Luttringer
 * \brief trouve un chemin avec des deplacements au hasard pour aller de l'entrée à la sortie du labyrinth
 * \param m Matrice (labyrinth) , flag d'affichage de recherche
 * \return L'ensemble des cases qui ont été visitées
 * ainsi qu'éventuellement l'affichage
 * */
ens Chemin(Matrice , Bool );

/**
 * \fn affiche_chemin
 * \author Cyrille Muller
 * \brief affiche le chemin parcourus
 * \param ensemble des cases parcourus pour résoudre le labyrinth
 * \param t taille que doit faire une case
 * \return un affichage
 * */
void affiche_chemin(ens , int);


#endif

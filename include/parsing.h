#ifndef _PARS_H_
#define _PARS_H_


/**
 * \file parsing.h
 * \brief Contient les deux fonctions de parsing des programmes
 * genlab et chemin
 * \author Jean-Romain Luttringer
 * */ 

#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
#include "ensemble.h"
#include "graph.h"


/**
 * \fn parsingGenlab
 * \brief fait le parsing des arguments du lancement de genlab
 * \param argc et argv ainsi que des pointeurs sur les flags à actualiser
 * \return le couple de la taille de la matrice à initialiser
 * fais le parsing des arguments de genlab et vérifie s'il y a des erreures
 * renvoie la taille standard si la taille n'est pas indiquée dans les arguments
 * */
couple parsingGenlab(int , char** , Bool*  ,Bool* );

/**
 * \fn parsingGenlab
 * \brief fait le parsing des arguments du lancement de chemin
 * \param argc et argv
 * \return le vflag
 * fais le parsing des arguments de chemin et vérifie s'il y a des erreures
 * renvoi le vflag (si l'option -v est demandée par l'utilisateur)
 * */
Bool parsingChemin(int , char**);

#endif

#ifndef DEF_ENSEMBLE
#define DEF_ENSEMBLE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * \file ensemble.h
 * \brief Contient les déclarations des types couple & ensemble, ainsi que les en-têtes des fonctions sur ensemble
 * \author Jean-Romain Luttringer
 * */ 

/**
 * \struct couple
 * \brief Structure de deux entiers x et y 
 * */
typedef struct couple{int x;int y;}couple;

/**
 * \struct ensemble
 * \brief Structure représentant un ensemble sur la forme d'une file de couple
 * */
typedef struct ensemble{
	couple c; /*!< Couple d'entiers */
	struct ensemble *suiv; /*!< Pointeur sur ensemble : permet d'accéder au couple suivant */
}ensemble,*ens;


/**
 * \fn EnsAlloc
 * \brief Creer un ensemble vide
 * \return ens
 * */
ens EnsAlloc(void);

/**
 * \fn EnsFree(ens)
 * \brief Libère la mémoire ayant été alloué pour un ensemble
 * \param ens Ensemble que l'ont veut free
 * \return ens (NULL)
 * */
ens EnsFree(ens);

/**
 * \fn EnsEstVide(ens)
 * \brief Renvoie un entier indiquant si un ensemble est vide ou non
 * \param ens Ensemble dont on veut tester la vacuité
 * \return int
 * */
int EnsEstVide(ens);


/**
 * \fn EnsAjoute(ens,couple)
 * \brief Ajoute un couple à un ensemble
 * \param ens Ensemble auquel on souhaite ajouter un élément
 * \param couple Couple que l'on souhaite ajouter
 * \return ens
 * */
ens EnsAjoute(ens,couple);

/**
 * \fn EnsSuppr(ens,couple)
 * \brief Supprime un élément d'un ensemble
 * \param ens Ensemble dont on souhaite supprimer un élément
 * \param couple Couple que l'on souhaite retirer à l'ensemble
 * \return ens
 * */
ens EnsSuppr(ens,couple);

/**
 * \fn EnsEstDans(ens,couple)
 * \brief Vérifie l'appartenance d'un couple à un ensemble
 * \param ens Ensemble dans lequel on va vérifier la présence du couple
 * \param couple Couple dont on veut vérifier la présence dans l'ensemble
 * \return int
 * */
int EnsEstDans(ens,couple);
/**
 * \fn EnsTaille(ens)
 * \brief renvoie le nombre d'éléments d'un ensemble
 * \param ens Ensemble dont on veut connaitre la taille
 * \return int
 * */
int EnsTaille(ens);

/**
 * \fn EnsTirage(ens)
 * \brief Retire un élément aléatoire d'un ensemble et renvoie le couple de l'élément retiré
 * \param ens Ensemble dans le quel le couple va être tiré
 * \return couple
 * Cette fonction génère un nombre aléatoire I entre 0 et la taille de l'ensemble 
 * elle renvoie le Ieme couple, et le retire de l'ensemble
 * 
 * */
couple EnsTirage(ens*);

/**
 * \fn EnsAffiche(ens)
 * \brief Affiches les couples d'entiers (x,y) présents dans l'emsemble passé en argument
 * \param ens Ensemble dont on veut afficher le contenue
 * \return void
 * */
void EnsAffiche(ens);

/**
 * \fn coupleEgal
 * \brief renvoie un booléen indiquant l'égalité entre deux couples
 * \param a Premier couple à comparer
 * \param b Deuxieme couple à comparer
 * \return int
 * */
int coupleEgal(couple ,couple );

/**
 * \fn NewCouple
 * \brief créer un nouveau couple
 * \param x Premier élément du nouveau couple
 * \param y Deuxieme élément du nouveau couple
 * \return couple
 * */
couple NewCouple(int, int);

/**
 * \fn DernierCouple
 * \brief cherche le dernier couple d'un ensemble
 * \param ensemble
 * \return couple
 * */
couple DernierCouple(ens);
#endif

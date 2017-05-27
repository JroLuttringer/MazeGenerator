#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "matrice.h"
#include "ensemble.h"
#include "labyrinth.h"
#include "graph.h"
#include "parsing.h"

/**
 * \file genlab.c
 * \brief Génère un labyrinthe suivant les options passées en arguments
 * */




int main(int argc, char* argv[]){
	srand( (unsigned) time(NULL));
	int tcase;
	Bool vflag = FAUX,dflag = FAUX;	
	Bool *vflagp = &vflag;
	Bool *dflagp = &dflag;
	
	couple dim = parsingGenlab(argc,argv,vflagp,dflagp);
	char *fichier = argv[ argc-1 ];
	Matrice m = MatAlloc(dim.x,dim.y);
	
	m = InitBord(m);
	ens graines = InitGraines(m,20);
	ens cons = InitConstructible(m, graines);
	BoucleGen(m, graines, &cons,dflag);	
	
	if(vflag && !dflag){
		tcase=taille_case(m);
		initgraph( (m->l)*tcase ,(m->h)*tcase );
		affiche_lab(m,tcase);
	}
	
	graines=EnsFree(graines);
	MatSauve(m, fichier);
	m = MatFree(m);
	if(vflag || dflag){
		waitgraph();
		closegraph();
	}
	return 0;
}
	

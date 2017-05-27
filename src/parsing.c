#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "matrice.h"
#include "ensemble.h"
#include "labyrinth.h"
#include "graph.h"
/**
 * \file parsing.c
 * \brief contient les fonctions permettant de gérer les options des fonction genlab et chemin
 * */



couple parsingGenlab(int argc, char** argv, Bool* vf ,Bool* df){
	couple dimension;
	int opt,nbropt=0;
	dimension.x=200;
	dimension.y=300;
	while(( opt = getopt(argc,argv,"vdh:l:")) != -1){
		switch (opt){
			case 'h':
				dimension.x = atoi(optarg);
				nbropt+=2;
				break;
			case 'l':
				dimension.y = atoi(optarg);
				nbropt+=2;
				break;
			case 'v':
				*vf = VRAI;
				nbropt+=1;
				break;
			case 'd':
				*df = VRAI;
				*vf = VRAI; 
				nbropt+=1;
				break;
			default:
				printf("Usage : %s [-v] [-d] [-l <largeur>] [-h <hauteur] <fichier>",argv[0]);
				exit(EXIT_FAILURE);
		}
	}
	if(nbropt == (argc-1)){
		printf("Mauvais Usage : \n Usage : %s [-v] [-d] [-l <largeur>] [-h <hauteur] <fichier>\n",argv[0]);
		exit(EXIT_FAILURE);		
	}
	if( (*vf || *df) && (dimension.x > 800 || dimension.y > 1000)){
		printf("Erreur paramètres  : La hauteur doit être inférieure à 800 et la largeur inférieure à 1000 ");
		exit(EXIT_FAILURE);
	}
	
	return dimension;
}

Bool parsingChemin(int argc, char** argv){
	Bool vflag = FAUX;
	int opt,nbropt=0;
	while(( opt = getopt(argc,argv,"v")) != -1){
		switch (opt){
			case 'v':
				vflag = VRAI;
				nbropt+=1;
				break;
			default:
				printf("Usage : %s [-v] <fichier>\n",argv[0]);
				exit(EXIT_FAILURE);
		}
	}
	if(nbropt == (argc-1)){
		printf("Mauvais Usage : \n Usage : %s [-v] <fichier>\n",argv[0]);
		exit(EXIT_FAILURE);		
	}
	return vflag;
}

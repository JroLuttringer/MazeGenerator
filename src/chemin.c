
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "matrice.h"
#include "ensemble.h"
#include "graph.h"
#include "labyrinth.h"
 
/**
*\file chemin.c
*\brief Cherche un chemin à l'intérieur du labyrinthe passé en argument
* */


int main(int argc, char* argv[]){
	
	

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

	
	FILE *fd;
	fd = fopen(argv[argc-1],"r");
	Matrice m = MatLit(fd);
	fclose(fd);
	printf("lecture finie");
	ens chemin = Chemin(m, vflag);
	if (!vflag)
	{
		int taille = taille_case(m);
		initgraph(m->l*taille, m->h*taille);
		affiche_lab(m, taille);
		affiche_chemin(chemin, taille);
		refresh();
	}
	waitgraph();
	closegraph();
	m = MatFree(m);
	EnsFree(chemin);
	return 0;
}

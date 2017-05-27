#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "matrice.h"
#include "ensemble.h"
#include "labyrinth.h"
#include "graph.h"


/*! \mainpage Documentation des programmes labyrinthe/chemin
 *
 * Ces deux programmes gèrent respectivement la création d'un labyrinthe
 * et la recherche d'un chemin solutionnant ce dernier.
 *
 * Afin de fonctionner, les fichiers utilisés contenant les matrices doivent être
 * formatés de cette manière : 
 * <hauteur> <largeur>
 * <matrice>
*/

/**
 * \file labyrinth.c
 * \brief contient toutes les fonctions gérant la création/la résolution de labyrinthe
 * */



Matrice InitBord(Matrice m){
	int i, j;
	for (i=0; i<m->h; i++)
	{
		for (j=0; j<m->l; j++)
		{
			if (i==0 || i==m->h-1) m->mat[i][j]=VRAI;
			if (j==0 || j==m->l-1) m->mat[i][j]=VRAI;
		}
	}
	m->mat[1][0]=FAUX;
	m->mat[m->h-1][m->l-2]=FAUX;
	return m;	
}

Bool EstConstructible (Matrice m, ens graine, int x, int y){
	int a, b, i, j, k=0, g=0;
	if (m->mat[x][y]==VRAI) return FAUX;
	if (x==0 || y == 0 || x==m->h-1 || y==m->l-1) return FAUX;
	if (EnsEstDans(graine, NewCouple(x-1,y))) {a=-1; b=0; g++;}
	if (EnsEstDans(graine, NewCouple(x+1,y))) {a=1; b=0; g++;}
	if (EnsEstDans(graine, NewCouple(x,y-1))) {a=0; b=-1; g++;}
	if (EnsEstDans(graine, NewCouple(x,y+1))) {a=0; b=1; g++;}
	if (m->mat[x-1][y] == VRAI) {a=-1; b=0; k++;}
	if (m->mat[x+1][y] == VRAI) {a=1; b=0; k++;}
	if (m->mat[x][y-1] == VRAI) {a=0; b=-1; k++;}
	if (m->mat[x][y+1] == VRAI) {a=0; b=1; k++;}
	if ((k==1)||(k==0 && g>0))
	{
		k=0;
		for (i=-1; i<2; i++)
		{
			for (j=-1; j<2; j++)
			{
				if ((i!=0 || j!=0) && ((i!=a || a==0) && (b==0 || j!=b)))
				{
					if (m->mat[x+i][y+j] == FAUX) k++;
					
				}
			}
		}
		if (k==5) return VRAI;
		else return FAUX;
	}	
	return FAUX;
}

ens InitConstructible(Matrice m, ens graine){
	
	ens cons = NULL;
	ens grainetemp = graine;
	int i, j, k;
	for (i=0; i<m->h; i++)
	{
		for (j=0; j<m->l; j++)
		{
			if (((i==1||i==m->h-2) && j >=2 && j<m->l-2)||((j==1||j==m->l-2) && i >1 && i<m->h-2))
			{
				couple c = NewCouple(i,j);
				cons = EnsAjoute(cons, c);
			}
		}
	}
	while (grainetemp!=NULL)
	{
		
		couple c = grainetemp->c;
		for (i=-1;i<2;i++)
		{
			for (j=-1;j<2;j++)
			{
				if (i!=0 || j!=0)
				{
					k=1;
					couple test = NewCouple(c.x+i,c.y+j);
					if (!EstConstructible(m, graine, test.x, test.y)) k=0;
					if (m->mat[c.x+i][c.y+j] == VRAI) k=0;
					if (EnsEstDans(cons, test)) k=0;
					if (k) EnsAjoute(cons, test);
				}
			}
		}
		
		grainetemp = grainetemp->suiv;
	}	
	return cons;
}

ens InitGraines(Matrice m,int k){
	ens grainestires = NULL;
	couple c;
	int maxi = (m->h-2);
	int maxj = (m->l-2);
	int i;
	for(i=0;i<k;i++)
	{
		  c.x=(int) (((double) rand() / (double) RAND_MAX) * maxi) +1;
		  c.y=(int) (((double) rand() / (double) RAND_MAX) * maxj) +1;
		  grainestires = EnsAjoute(grainestires,c);
	}
	return grainestires;
}


void dessincase(int i,int j,int taille){
	int k= i * taille;
	int m = j * taille;
	int g,l;
	for(g=0;g<taille;g++,k++)
	{
		for(l=0;l<taille;l++)
		{
			putpixel(k,m+l);
		}
	}
}

int taille_case(Matrice m){
	int taille = 5;
	while( (m->h*taille > 800) || (m->l*taille > 1000))
	{
		taille--;
	}
	return taille;
}

void affiche_lab(Matrice m,int tcase){
	int i,j;	
	for(i=0;i<m->l;i++)
	{
		for(j=0;j<m->h;j++)
		{
				if(m->mat[j][i]) dessincase(i,j,tcase);
		}
	}
	refresh();
}


void ConstruireMur(Matrice m, ens graine, ens* cons,int flag){
	int i, j,tcase;
	couple c = EnsTirage(cons);
	m->mat[c.x][c.y]=VRAI;
	if(flag)
	{
		tcase=taille_case(m);
		dessincase(c.y, c.x, tcase);
		refresh();
	}
	for (i=-1;i<2;i++)
	{
		for (j=-1;j<2;j++)
		{
			if (i!=0 || j!=0)
			{
				couple test = NewCouple(c.x+i,c.y+j);
				if ((EstConstructible(m, graine, test.x, test.y))&& !(EnsEstDans(*cons, test))) *cons = EnsAjoute(*cons, test);
				else
				{
					if (!(EstConstructible(m, graine, test.x, test.y))&&EnsEstDans(*cons, test)) *cons = EnsSuppr(*cons, test);
				}
			}
		}
	}	

}


void BoucleGen(Matrice m, ens graine, ens* cons,int flag){
	int tcase;	
	if(flag)
	{
		tcase = taille_case(m);
		initgraph( (m->l)*tcase ,(m->h)*tcase );	
		affiche_lab(m,tcase);
	}
	
	while (*cons != NULL)
	{
		ConstruireMur(m, graine, cons,flag);		
	}
		
}



ens Chemin(Matrice m, Bool vflag){
	couple joueur = NewCouple(1,0);
	couple arrive = NewCouple(m->h-1, m->l-2);
	ens chemin = EnsAjoute(NULL, joueur);
	couple destination = NewCouple(0, 0);
	ens deplacement_impossibles = NULL;	
	ens cases_alentours = NULL;
	couple c;
	int i,j;
				
	int k;
	int taille = taille_case(m);
	if (vflag)
		{
			initgraph(m->l*taille, m->h*taille);
			affiche_lab(m,taille);
			refresh();
		}



	while (!coupleEgal(joueur, arrive))
	{
		k=1;	
		cases_alentours = NULL;
		if (coupleEgal(joueur, NewCouple(1,0)))
		{
			destination = NewCouple(1,1);
			if (vflag)
			{
				setcolor(newcolor(255,0,0));
				dessincase(joueur.y, joueur.x, taille);
				dessincase(destination.y, destination.x, taille);
				refresh();
			}
			k=0;
			deplacement_impossibles = EnsAjoute(deplacement_impossibles,joueur);
			deplacement_impossibles = EnsAjoute(deplacement_impossibles,destination);
		}
		if (k)
		{
			i=joueur.x;
			j=joueur.y;
			if (!EnsEstDans(deplacement_impossibles,NewCouple(i-1,j))&&(m->mat[i-1][j]==FAUX)) cases_alentours = EnsAjoute(cases_alentours, NewCouple(i-1,j));
			if (!EnsEstDans(deplacement_impossibles,NewCouple(i+1,j))&&(m->mat[i+1][j]==FAUX)) cases_alentours = EnsAjoute(cases_alentours, NewCouple(i+1,j));
			if (!EnsEstDans(deplacement_impossibles,NewCouple(i,j-1))&&(m->mat[i][j-1]==FAUX)) cases_alentours = EnsAjoute(cases_alentours, NewCouple(i,j-1));
			if (!EnsEstDans(deplacement_impossibles,NewCouple(i,j+1))&&(m->mat[i][j+1]==FAUX)) cases_alentours = EnsAjoute(cases_alentours, NewCouple(i,j+1));
		}
		if ((cases_alentours == NULL) && k)
		{
			c = DernierCouple(chemin);
			chemin = EnsSuppr(chemin,c);
			if (vflag)
			{
				setcolor(newcolor(255,255,255));
				dessincase(c.y, c.x, taille);
				refresh();
			}
			destination = DernierCouple(chemin);
			
			
		}
		if (cases_alentours != NULL )
		{
			destination = EnsTirage(&cases_alentours);
			chemin = EnsAjoute(chemin, destination);

			if (vflag)
			{			
				setcolor(newcolor(255,0,0));
				dessincase(destination.y, destination.x, taille);
				refresh();
			}
			deplacement_impossibles = EnsAjoute(deplacement_impossibles,destination);
		}		
		joueur = destination;
		EnsFree(cases_alentours);
		
	}
	EnsFree(deplacement_impossibles);
	return chemin;
}



void affiche_chemin(ens chemin, int taille){
	
	
	while(chemin != NULL)
	{
		setcolor(newcolor(0,255,255));
		dessincase(chemin->c.y, chemin->c.x, taille);
		chemin = chemin->suiv;
	}
	return;	
	
}

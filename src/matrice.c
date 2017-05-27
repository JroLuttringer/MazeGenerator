#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

/**
 * \file matrice.c
 * \brief contient toutes les fonctions concernant les Matrices
 * */


Matrice MatAlloc(int h, int l){
	Matrice m = (Matrice) malloc (sizeof(struct strmat));
	m->mat = (Bool**) malloc (h * sizeof(Bool*));
	int i,j;
	for (i=0;i<h;i++)
	{
		m->mat[i] = (Bool*) malloc (l * sizeof(Bool));
		for (j=0;j<l;j++) m->mat[i][j] = FAUX;
	}
	m->h=h;
	m->l=l;
	return m;
}

Matrice MatFree(Matrice m){
	int i;
	for (i=m->h-1;i>=0;i--)
	{
		free(m->mat[i]);
	}
	free(m->mat);
	free(m);
	return NULL;
}

Bool MatVal(int x, int y, Matrice m){
	return m->mat[y][x];
}

Matrice MatSet(int x, int y, Bool b, Matrice m){
	m->mat[y][x]=b;
	return m;
}

void MatSauve(Matrice m, char* name){
	int i, j;
	FILE *f = fopen(name, "w+");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	fprintf(f,"%d %d\n",m->h,m->l);
	for (i=0;i<m->h;i++)
	{
		for (j=0;j<m->l;j++) fprintf(f,"%d ", m->mat[i][j]);
		fprintf(f,"\n");
	}
	fclose(f);
}

Matrice MatLit (FILE* fd){
	int compteur=0;
	Matrice m;
	int h, l;
	char line[MAX_LINE];
	if(fd==NULL) 
	{ 
		perror("Erreur sur le fichier entrée");
		exit(1);
	}
	while(1)
	{
		//~ if( feof(fd) ) break;
		fgets(line,MAX_LINE,fd);
		if (compteur == 0) 
		{
			sscanf(line, "%d  %d", &h, &l );
			m = MatAlloc(h,l);			
		}
		if( compteur == h+1 ) break;
		if (compteur > 0)
		{
				m = remplirrangee(m, compteur-1, line);
		}
		compteur++;
	}
	
	return m;
}

Matrice remplirrangee(Matrice m, int h, char* liste){
	int i=0;
	char *p = liste;
	while (i<m->l) 
	{ 
		Bool val = strtol(p, &p, 10);
		p++;
		m->mat[h][i] = val;
		i++;
	}
	return m;	
}






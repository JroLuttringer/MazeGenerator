#include "ensemble.h"

/**
 * \file ensemble.c
 * \brief contient les fonctions gérant les Ensembles
 * */

ens EnsAlloc(){
	ens nvens=malloc(sizeof(ensemble));
	return nvens;
}

ens EnsFree(ens E){
	ens tmp = E;
	ens tmpnxt;		
	while (tmp != NULL){
		tmpnxt = tmp -> suiv;
		free(tmp);
		tmp=tmpnxt;
	}
	return NULL;	
}


int EnsEstVide(ens E){
	return (E==NULL);		
}

ens EnsAjoute(ens e, couple p){
	ens nvens=EnsAlloc();
	nvens->c = p;
	nvens->suiv=NULL;
	if(e == NULL){
		return nvens;
	}
	else{
		ens tmp = e;
		while(tmp->suiv != NULL){
			tmp=tmp->suiv;
		}
		tmp->suiv=nvens;
		return e;
	}
}

couple NewCouple(int x, int y){
	couple c;
	c.x=x;
	c.y=y;
	return c;
}

int coupleEgal(couple c,couple d){
	return ( (c.x==d.x)&&(c.y == d.y));
}

ens EnsSuppr(ens e,couple p){
	ens tmp = e;
	if (e==NULL) return NULL;
	if (coupleEgal(p, e->c)) 
	{
		e = e->suiv;
		free(tmp);
		return e;
	}
	while (tmp->suiv != NULL)
	{
		if (coupleEgal(p, tmp->suiv->c))
		{
			ens sup=tmp->suiv;
			tmp->suiv=tmp->suiv->suiv;
			free(sup);
			return e;
		}
		tmp=tmp->suiv;
	}
	if (coupleEgal(tmp->c, p)) tmp = NULL;
	return e;
}

int EnsTaille(ens e){
	ens tmp=e;
	int i;
	for(i=0;(tmp!= NULL);i++,tmp=tmp->suiv);
	return i;	
}


int EnsEstDans(ens e,couple p){
	
	ens tmp =e;
	int resultat=0;
	int i;
	for(i=0;(tmp != NULL);i++)
	{
		if (coupleEgal(tmp->c,p)) resultat=1;
		tmp=tmp->suiv;
	}
	return resultat;
	
}

couple EnsTirage(ens*  e){
	int i;
	int alea =  (int) (((double) rand() / (double) RAND_MAX) * ( EnsTaille(*e) ));
	//~ printf("Nombre aleatoire = %d\n", alea);
	ens tmp = *e;
	for(i=0;i!=alea;i++)
	{
		tmp = tmp -> suiv;
	}
	couple ret = tmp->c;
	*e=EnsSuppr(*e,(tmp->c)); 
	return ret;	
}


void EnsAffiche(ens e){
	ens tmp2=e;
	while(tmp2 != NULL){
	printf("%d %d \n",tmp2->c.x,tmp2->c.y);
	tmp2=tmp2->suiv;	
	}
	return ;
}

couple DernierCouple(ens e){
	ens tmp = e;
	while(tmp->suiv != NULL) {tmp=tmp->suiv ; } return tmp->c;
}

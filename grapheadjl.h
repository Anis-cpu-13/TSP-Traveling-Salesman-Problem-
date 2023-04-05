#ifndef __GRAPHEADJL_H_
#define __GRAPHEADJL_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "tools.h"



/*liste de successeurs*/

/*structure d'un noeud*/
struct  noeud 
{
    int num;
    struct aretes *next;
};

typedef struct noeud noeud;
typedef struct noeud *ptr_noeud;

/*Tableau de touts les neouds*/

struct l_graphe 
{
    ptr_noeud *ne;
    int nbsMax;
    int nbs;
};

typedef struct l_graphe  l_graphe;
typedef struct l_graphe  * ptr_l_graphe;

/*structure d'une liste de successeurs*/

struct aretes
{
    ptr_noeud ptr;
    double edge_weight;  
    struct aretes * suiv;
};

typedef struct aretes aretes;
typedef struct aretes *ptr_aretes;

l_graphe* GraphsCreateListe (int );
void destroyGrapheList(l_graphe* );
void initGraphsList(l_graphe *, int );
void addNodeList (l_graphe* , int i);
void addVerticeList(l_graphe *, int , int , int );
double getWeightElt (noeud *, int );
double weightAllElt(int *, l_graphe *, int  );
Bool isSucces( l_graphe *, int , int );
Bool swap(l_graphe *, int* , int , int );
double checkMemoryList (l_graphe );


#endif  
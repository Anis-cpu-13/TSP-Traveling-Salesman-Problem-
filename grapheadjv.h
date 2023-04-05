#ifndef __GRAPHEADJV_H_
#define __GRAPHEADJV_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "tools.h" 


struct v_noeud
{
    int num;
    int nbs;
    struct v_noeud * * succ;
    float  poids;
    
};
typedef struct v_noeud v_noeud;
typedef struct v_noeud * ptr_v_noeud;

struct v_graphe
{
    ptr_v_noeud  *ne;
    int nbs;
    int nbsMax;
};

typedef struct v_graphe  v_graphe;
typedef struct v_graphe  * ptr_v_graphe;



v_graphe* GraphsCreateVec (int );
void destroyGrapheVec (v_graphe* );
void addNodeVec(v_graphe *, int );
void addVerticeVec(v_graphe *, int src, int , int  );
float getWeightEltVec(v_noeud * , int );
float weightAllEltVec(int [], v_graphe *, int );
void initGraphsVec(v_graphe * , int );
Bool isSuccesVec (v_graphe *, int , int );
Bool swapVec(v_graphe *, int [], int  , int );
double checkMemoryVect(v_graphe );




#endif
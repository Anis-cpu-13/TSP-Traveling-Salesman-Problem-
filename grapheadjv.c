#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "tools.h"      
#include "grapheadjv.h"
#include "opt2list.h"
#include "assert.h"


/* Fonction qui alloue un graphe */
v_graphe* GraphsCreateVec(int nMax)
{
    v_graphe *G= tools_malloc(sizeof(v_graphe));
    G->ne = tools_malloc(sizeof(v_noeud) * nMax);
    G->nbsMax = nMax;
    G->nbs = 0;
    return G;
}

/* Fonction qui permet de compter la consomation mémoire */
double checkMemoryVect(v_graphe A)
{
    double memory; 
    memory = sizeof(struct  v_graphe) + sizeof (struct v_noeud) * A.nbsMax + sizeof(int) * A.nbsMax;
    return memory;
}
/*Fonctin qui désaloue un graphe */
void destroyGrapheVec (v_graphe* GG)
{
    tools_free(GG->ne, sizeof(v_noeud) * GG->nbsMax); 
    tools_free(GG, sizeof(v_graphe));
    GG = NULL;
    
}

/* Fonction qui ajoute un neoud */
void addNodeVec(v_graphe *g, int i)
{
    if (g->nbsMax < i + 1)
    {
        fprintf(stderr, "Erreur : Probleme creation Graphe.\n");
        exit(EXIT_FAILURE);
    }
    
    while (!g->ne[i])
    {
        g->ne[i] = tools_malloc(sizeof(v_noeud));
        ptr_v_noeud n = g->ne[i];
        n->num = i;
        n->nbs = 0;
        n->succ = tools_malloc(g->nbsMax* sizeof(v_noeud*));
        g->nbs++;
    }
    
}
/*Fonction qui ajoute une aretes */
void addVerticeVec(v_graphe *g, int src, int target, int weigth )
{
    v_noeud *v = g->ne[src];

    v_noeud *n = v;
    for (int i = 0; i < n->nbs; i++)
    {
        v_noeud *s = n->succ[i];

        if (s == NULL) continue;
        if (s->num == target)
        {
            return;
        }
        
        
    }

    if (v->nbs >= g->nbsMax)
    {
        fprintf(stderr,"Vous essayer d'acceder un emplacement mémoire non autorisée");
        exit(EXIT_FAILURE);
    }

    v_noeud *e = tools_malloc(sizeof(v_noeud));
    e->num = target;
    e->poids = weigth;
    e->succ = NULL;
    e->nbs = 0;

    v->succ[v->nbs] = e;
    v->nbs++;    

}

/* Focntion qui permet d'initialiser un graphe */
void initGraphsVec(v_graphe *GL , int nMax)
{
    
    for (int i = 1; i < nMax+1; i++)
        {
           for (int j = 1; j < nMax+1; j++)
           {
               if ( i != j)
               {
                    addNodeVec(GL, i -1);
                    addNodeVec(GL, j -1);
                    addVerticeVec(GL, i-1 , j-1, genrate_random_value(nMax));
                    addVerticeVec(GL, j-1, i-1, genrate_random_value(nMax));
               }
           }
        }
}
/* Fonction qui retorune de le poids du parcour */
float getWeightEltVec(v_noeud *courant , int id_suivant)
{
    float pds = -1;
    for (int i = 0; i < courant->nbs ; i++)
    {
        v_noeud *s = courant->succ[i];
        if (s->num == id_suivant)
        {
            pds = s->poids;
            return pds;
        }
    }

    if (pds == 0)
    {
        fprintf(stderr, "Vous essayer d'acceder un element NULL");
        exit(EXIT_FAILURE);
    }
    
    return pds;
    
}

/* Foncion qui permet de calculer le poids du parcour */
float weightAllEltVec(int chemin [], v_graphe *GL, int taille)
{
    v_noeud *elt = NULL;
    float pds = 0;
    
    int i = 0;
    while ( i < taille-1)
    {
        elt = GL->ne[chemin[i]-1];
        pds = pds + getWeightEltVec(elt, chemin[i+1]-1);
        i++;
    }
    return pds;
}


/* Fonction qui detrmine si deux sommets sans successeur*/

Bool isSuccesVec (v_graphe *GV, int a, int b)
{
    v_noeud *n = GV->ne[a-1];
    v_noeud *next = NULL;

    for (int i = 0; i < n->nbs; i++)
    {
        next = n->succ[i];
        if (next->num == b - 1)
        {
            return true;
        }
        
    }
    return false;
}

/*Fonction qui permet d'echanger deux element sur le même chemin*/
Bool swapVec(v_graphe *GV, int chemin[], int a , int b)
{
    swapInt(&chemin[a], &chemin[b]);

    if ( isSuccesVec( GV,chemin[a], chemin[a+1] ) && isSuccesVec ( GV,chemin[a-1], chemin[a] )   &&
            isSuccesVec( GV,chemin[b], chemin[b+1] ) && isSuccesVec ( GV,chemin[b-1], chemin[b] ))
    {
        return true;
    }
    else
    {
        return false;
    }

}


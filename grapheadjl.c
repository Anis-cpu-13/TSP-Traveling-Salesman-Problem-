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
l_graphe* GraphsCreateListe(int nMax)
{
    l_graphe *G= tools_malloc(sizeof(l_graphe));
    G->ne = tools_malloc(sizeof(noeud) * nMax);
    G->nbsMax = nMax;
    G->nbs = 0;
    return G;
}
/*Fonctin qui désaloue un graphe */
void destroyGrapheList(l_graphe* GG)
{
    tools_free(GG->ne, sizeof(noeud) * sizeof(int) * GG->nbsMax); 
    tools_free(GG, sizeof(l_graphe));
    GG = NULL;
    
}

/* Fonction qui permet de compter la consomation mémoire */
double checkMemoryList (l_graphe A)
{
    double memory;
    memory = sizeof(struct l_graphe) + (sizeof (struct noeud) * A.nbsMax) + sizeof(int) * A.nbsMax;
    return memory; 
}
/* Fonction qui ajoute un neoud */
void addNodeList(l_graphe* G, int i)
{
	if (G->nbsMax < i + 1)
    {
        fprintf(stderr, "Erreur : Probleme creation Graphe.\n");
	    exit(EXIT_FAILURE);
    }
    
    while(!(G->ne[i])){
        G->ne[i] = tools_malloc(sizeof(noeud));
        ptr_noeud n = G->ne[i];
        n->num = i;
        n->next = NULL;
        G->nbs++;
    }
}

/*Fonction qui ajoute une aretes */
void addVerticeList(l_graphe *GL, int src, int target, int weight)
{
    noeud *v = GL->ne[src];
    aretes *a =  v->next;

    while (a)
    {
        ptr_noeud node = a->ptr;
        if (node->num == target)
        {
        return;
        }
        a = a->suiv;
    }
    aretes *e_next = v->next;
    aretes *e = tools_malloc(sizeof(aretes));

    e->edge_weight = weight;
    e->suiv = e_next;
    e->ptr = GL->ne[target];
    v->next = e;
}

/* Focntion qui permet d'initialiser un graphe */
void initGraphsList(l_graphe * GL, int nMax)
{
    for (int i = 1; i < nMax+1; i++)
        {
           for (int j = 1 ; j < nMax+1; j++)
           {
               if ( i != j)
               {
                    addNodeList(GL, i -1);
                    addNodeList(GL, j -1);

                    addVerticeList(GL, i-1 , j-1, genrate_random_value(nMax));
                    addVerticeList(GL, j-1, i-1, genrate_random_value(nMax));
               }
           }
        }
}

/* Fonction qui retorune de le poids */
double getWeightElt (noeud *elt, int id_next)
{
    double pds = -1;
    aretes *a = elt->next;
    ptr_noeud ptr = NULL;
    while (a != NULL)
    {
        ptr = a->ptr;
        if (ptr->num == id_next)
        {
            pds = a->edge_weight;
            return pds;
        }
        a = a->suiv;
    }
    
    
    if(pds == -1)
    {
        fprintf(stderr, "Vous essayer d'acceder un element NULL");
        exit(EXIT_FAILURE);
    }

    return pds;
}



/* Foncion qui permet de calculer le poids du parcour */
double weightAllElt(int *chemin, l_graphe *GL, int taille )
{
    double pds = 0;
    noeud *elt = NULL;

    
    int i = 0;
    while ( i < taille-1)
    {
        elt = GL->ne[chemin[i]-1];
        pds = pds + getWeightElt(elt, chemin[i+1]-1);
        i++;
    }
    return pds;
}

/* Fonction qui detrmine si deux sommets sans successeur*/
Bool isSucces( l_graphe *GL, int a, int b)
{
    noeud *n = GL->ne[a - 1];
    aretes *suces = n->next;
    ptr_noeud ptr = NULL;

    while (suces != NULL)
    {
        ptr = suces->ptr;
        if (ptr->num == b - 1)
        {
            return true;
        }
        suces = suces->suiv;
        
    }
    return false;
}

/*Fonction qui permet d'echanger deux element sur le même chemin*/
Bool swap(l_graphe *GL, int chemin[], int a , int b)
{
    swapInt(&chemin[a], &chemin[b]);

    if ( isSucces (GL, chemin[a], chemin[a+1]) && isSucces(GL, chemin[a-1], chemin[a])&&
         isSucces(GL, chemin[b], chemin[b+1]) && isSucces (GL, chemin[b-1], chemin[b]))
         {
            return true;
         }
         else
         {
            return false;
         }    
}





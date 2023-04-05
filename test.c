#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "tools.h"      
#include "grapheadjv.h"
#include "opt2list.h"
#include "assert.h"


v_graphe* creeGrapheVec(int nMax)
{
    v_graphe *G= tools_malloc(sizeof(v_graphe));
    G->ne = tools_malloc(sizeof(v_noeud) * nMax);
    G->nbsMax = nMax;
    G->nbs = 0;
    return G;
}


void detruireGrapheVec (v_graphe* GG)
{
    tools_free(GG->ne, sizeof(v_noeud) * GG->nbsMax); 
    tools_free(GG, sizeof(v_graphe));
    GG = NULL;
    
}
double check_memory_vector(v_graphe *G)
{
    return sizeof(v_graphe) + sizeof (ptr_v_noeud) * G->nbsMax;
}

void ajouterSommetVec (v_graphe *G, int i)
{
 

    while (G->ne[i] == NULL)
    {
        //assert(G->nbs < i + 1);
        G->ne[i] = tools_malloc(sizeof(v_noeud));
        ptr_v_noeud n  = G->ne[i];
        n->num = i;
        n->nbs = 0;
        n->succ = tools_malloc(G->nbsMax * sizeof(ptr_v_noeud));
        n->nbs = G->nbs;
        G->nbs++;
        
    }
    
}


Bool cheakIdVec (v_graphe *G, int src, int target)
{

    noeud *v = G->ne[src];
    aretes *x = v->next;
    Bool test;

    ptr_noeud node = x->ptr;
    if ( x == NULL && node->num != target)
    {
            fprintf(stderr, "Erreur : Vous essayer d'acceder un element nul.\n");
            exit(EXIT_FAILURE);
            return false;
    
    }else{

            x = x->suiv;
            return true;
    }

}

void ajouterUnArcVec(v_graphe *g, int src, int target, int weight)
{
    v_noeud *v = g->ne[src];
    v_noeud *n = v;

    for (int i = 0; i < n->nbs; i++)
    {
        v_noeud  *s = n->succ[i];
        if (s == NULL)
        {
            continue;
        }
        if (s->num == target)
        {
            return;
        }
        
        
    }
    
    //Bool test = cheakIdVec(g, src, target);
    
    //if (test == true)
    //{
    //    v_noeud *s = n->succ++;
    //}

    v_noeud *e = tools_malloc(sizeof(v_noeud));
    e->num = target;
    e->poids = weight;
    e->succ = NULL;
    e->nbs = 0;
    e->link_size = 0;
    v->succ[v->nbs] = e;
    v->nbs++;
}

void initialiserGrapheVec(v_graphe *g , int nMax)
{
    
    for (int i = 1; i < nMax+1; i++)

    {

       for (int j = 1; j < nMax+1; j++)

       {

           if ( i != j)

           {

                ajouterSommetVec(g, i - 1 );

                ajouterSommetVec(g, j - 1 );

                ajouterUnArcVec(g, i - 1 , j - 1 , genrate_random_value(nMax));

                ajouterUnArcVec(g, j - 1, i - 1, genrate_random_value(nMax));            
           }

           

       }
                

    }

}

float getPoidArcVec (v_noeud *courant, int id_suivant)
{
    float pds = -1;

    for (int i = 0; i < courant->nbs; i++)
    {
        v_noeud *s = courant->succ[i];
        if (s->num == id_suivant)
        {
            pds = s->poids;
            //printf("element -------->%f\n", pds);
            return pds;
        }
        
        if (pds == -1)
        {
            //printf("element -------->%f\n", pds);
            fprintf(stderr, "ERREUR\n");
            exit(EXIT_FAILURE);
        }
    }
    

    return pds;   
}


float poids_du_cheminVec (int chemin [], v_graphe *g, int taille )
{
    v_noeud *trouve = NULL;
    float pds = 0;
    //int i = 0;
    //while ( i < taille - 1)
    //{
    //    //printf("%f\n", pds);
    //    trouve = g->ne[chemin[i] - 1];
    //    printf("le pds debut %f\n", pds);
    //    pds = getPoidArcVec(trouve, chemin[i + 1] - 1);
    //    //printf(" \n%d element -------->%f\n", pds);
    //    printf("le pds %f\n", pds);
    //    //printf("test ------------> %d\n", i);   
    //    i++;
    //}

    for (int i = 0; i < taille-1; i++)
    {
        trouve = g->ne[chemin[i] - 1];
        pds = pds + getPoidArcVec(trouve, chemin[i+1] - 1);
    }
       
    
    
    return pds;
}



        for (int  i = 0; i < 5; i++)
        {
            //printf("nombre de villes est %d\n", villes[i]);
            g = creeGrapheVec(villes[i]);
            initialiserGrapheVec(g, villes[i]);
            taille = (villes[i] +1) - 1;
            chemin = cheminDepart(taille);
            printf("chemin de depart\n");
            displayElt(chemin, taille);

            r=weightAllEltVec( chemin, g, taille);
            printf("\nLe poids de départ est %.f \n", r);
            opt2Vec(g, chemin, taille);
        }
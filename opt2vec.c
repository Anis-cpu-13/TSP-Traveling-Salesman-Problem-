#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "tools.h"
#include "grapheadjv.h"
#include "grapheadjl.h"
#include "opt2vec.h"
#include "string.h"


void opt2Vec( v_graphe *g, int chemin[], int tailletab)
{
    float new_distance;
    int *newroute=NULL;
    int nb_iteration=0;
    int taille= sizeof( int ) * tailletab;
    newroute = (int *) tools_malloc( taille );

    float best_distance = weightAllEltVec(chemin,g,tailletab);

startagain:
    for( int i =1 ; i < tailletab-2 ; i++)
    {
        for( int j =i+1 ; j < tailletab; j++)
        {
            nb_iteration=nb_iteration+1;
            memcpy( newroute, chemin, taille );
            swapVec(g,newroute,i,j) ;
            new_distance = weightAllEltVec(newroute,g, tailletab);

            if (new_distance < best_distance)
            {
                memcpy( chemin, newroute, taille );
                best_distance = new_distance;
                goto startagain;
            }
        }
    }

    printf ("Le couts du  plus court chemin est est %.f \n", best_distance);
    printf("Le meilleur chemin\n");
    displayElt(chemin, tailletab);
    free(newroute);

}
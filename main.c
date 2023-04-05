#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "grapheadjl.h"
#include "tools.h"
#include "opt2list.h"
#include "grapheadjv.h"
#include "opt2vec.h"


/* make && ./prog pour compiler et exécuter le programme */

int main (int argc, char** argv)

{
    v_graphe *g = NULL;
    int taille;
    int *chemin;
    float r;
    int villes[15] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 150, 200, 250, 300, 350};
    double memory;
    double time_1;

    tools_memmory_init ();
    {
    for (int  i = 0; i < 15 ; i++)
    {
        printf("\nnombre de villes est %d\n", villes[i]);
        g = GraphsCreateVec(villes[i]);
        initGraphsVec(g, villes[i]);
        taille = (villes[i] +1) - 1;
        chemin = cheminDepart(taille);
        printf("Trajet initial\n");
        displayElt(chemin, taille);
        r=weightAllEltVec( chemin, g, taille);
        printf("\nLe couts du chemin de départ est %.f \n", r);
        init_time();
        opt2Vec(g, chemin, taille);
        time_1 = get_time();
        printf("le temps que prend la recherche du plus courts chemin est de %f secondes\n", time_1);
        memory =  checkMemoryVect(*g);
        printf("La consomation mémoire de la structure vect est %f octect\n", memory);
        destroyGrapheVec(g);
    }
    
    

    tools_memory_check_at_end_of_app();
    }
    return EXIT_SUCCESS;
}



/*
int main (int argc, char** argv)
{

    int villes[14] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 150, 200, 250, 300};
    
    l_graphe *g = NULL;
    int taille;
    int *chemin;
    float r;
    double memoryList;
    double timeList; 
    tools_memmory_init();
    {
    for (int  i = 0; i < 14 ; i++)
    {
        printf("\nnombre de villes est %d\n", villes[i]);
        g = GraphsCreateListe(villes[i]);
        initGraphsList(g, villes[i]);
        taille = (villes[i] +1) - 1;
        chemin = cheminDepart(taille);
        printf("Trajet initial\n");
        displayElt(chemin, taille);
        r=weightAllElt( chemin, g, taille);
        printf("\nLe couts du chemin de départ est %.f \n", r);
        init_time();
        opt2list(g, chemin, taille);
        timeList = get_time();
        printf("le temps que prend la recherche du plus courts chemin est de %f secondes\n", timeList);
        memoryList =  checkMemoryList(*g);
        printf("La consomation mémoire de la structure liste est %f octect\n", memoryList);
        destroyGrapheList(g);
    }
    

    }


    tools_memory_check_at_end_of_app();
    
    


    return EXIT_SUCCESS;
}
*/






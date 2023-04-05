 #include <stdio.h>
 #include <stdlib.h>
 #include "tools.h"
 #include "time.h"

static struct timeval ti;

int _GLOBAL_ALLOC_MEMORY;

 /* Géstion des fuites mémoire */
void tools_memmory_init(void)
{
	_GLOBAL_ALLOC_MEMORY = 0;
}

void* tools_malloc (int alloc)
{
	void* ptr = malloc(alloc);
	_GLOBAL_ALLOC_MEMORY += alloc;
	return ptr;	
}

void tools_free(void* ptr, int alloc)
{
	free(ptr);
	_GLOBAL_ALLOC_MEMORY -= alloc;
}

void tools_memory_check_at_end_of_app(void)
{
	if (_GLOBAL_ALLOC_MEMORY != 0)
		printf("Attention ce programme a une ou des fuites de mémoire.\n %d octects n'ont pas était liberer\n", _GLOBAL_ALLOC_MEMORY);
}



/* Fonction qui permet de calcuer le temps d'execution */

void init_time(void) {
  gettimeofday(&ti, (struct timezone*) 0);
}
double get_time(void) {
  struct timeval t;
  double diff;
  gettimeofday(&t, (struct timezone*) 0);
  diff = (t.tv_sec - ti.tv_sec) * 1000000
    + (t.tv_usec - ti.tv_usec);
  return diff/1000000.;
}



/* génration du de valeur de maniere aleatoire*/
double genrate_random_value(double max){   
  srand((unsigned int)clock());
  return  ((double)rand()/(double)(RAND_MAX)) * 10.0; 
}

/* Fonction qui permet d'echnager deux valeur */
void swapInt (int *a, int *b)
{
    (*a) = (*a) ^ (*b);
    (*b) = (*a) ^ (*b);
    (*a) = (*a) ^ (*b);
}

/* Fonction qui nous permet d'afficher le chemin du voyageur*/
void displayElt(int *chemin, int taille )
{
    for (int i = 0; i < taille; i++)
    {
       if(taille != i && i != 0) {printf("->");}
        printf("%d", chemin[i]);
    }
    printf("\n");
    
}

/* Génération d'un chemin initial */
int * cheminDepart (int taille)
{
    int *chemin;
    int nb = sizeof(int) * taille;
    chemin =  tools_malloc(nb);

    for ( int i = 0; i < taille; i++)
    {
        chemin[i] = 1 + i;
    }
    
    return chemin;
}

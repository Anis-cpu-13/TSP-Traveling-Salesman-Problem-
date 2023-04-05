#ifndef __OPT2LIST_H_
#define __OPT2LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "tools.h"
#include "grapheadjl.h"




/* Implementation de l'algorithme 2 opt */

///void opt2Vec( l_graphe *g, int chemin[], int tailletab);
void opt2list( l_graphe *g, int chemin[], int tailletab);
#endif
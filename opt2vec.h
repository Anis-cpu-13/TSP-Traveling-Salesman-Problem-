#ifndef __OPT2VEC_H_
#define __OPT2VEC_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "tools.h"
#include "grapheadjv.h"




/* Implementation de l'algorithme 2 opt */
void opt2Vec( v_graphe *g, int chemin[], int taille);
#endif
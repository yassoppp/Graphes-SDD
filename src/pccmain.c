#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define P 90000000000

#define NOM_MAXIMALE 500
#include "f1.h"
#include "f2.h"


int main(int argc,char* argv[]){
  int t,d,a;
  graph_t* g1=f(argv[1]);
  printf("donnez le numero du sommet de depart :");
  scanf("%d",&d);
  printf("donnez le numero du sommet de arrivee :");
  scanf("%d",&a);
  t=clock();
  printf("\n\n\n");
  if ((d<g1->size_vertices) && (a<g1->size_vertices)){
    int u=dijkstra(d,a,g1);
    t=clock()-t;
    printf("le temps d'exécution de Dijkstra est : %lf\n",t/(double)CLOCKS_PER_SEC );
    if (u==1)
    afficher_pcc(a,g1);
    printf("le plus court chemin proposé par dijkstra: \n");
    printf("=================================================================================================================================\n");
    lechemin(* g1,d,a);
    printf("=================================================================================================================================\n\n\n\n");
    free_graph(g1);
    g1=f(argv[1]);
    t=clock();
    u=Astar(d,a,g1);
    t=clock()-t;
    printf("le temps d'exécution de Astra est : %lf\n",t/(double)CLOCKS_PER_SEC );
    if (u==1)
    afficher_pcc(a,g1);
    printf("le plus court chemin proposé par Astra: \n ");
    printf("================================================================================================================================\n");
    lechemin(* g1,d,a);
    printf("================================================================================================================================\n");
    free_graph(g1);
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "f1.h"
#include "f2.h"
#define P 90000000000

#define NOM_MAXIMALE 500
double Heuristique(int j,int a,graph_t m){
  double xj,xa,yj,ya,h;
  xa=m.data[a].x;
  xj=m.data[j].x;
  ya=m.data[a].y;
  yj=m.data[j].y;
  h=((fabs(xa-xj)+fabs(ya-yj))/2);
  return h ;
}
void init_sommet_depart(int nsd,graph_t* g){
  (g->data+nsd)->pcc=0;
  (g->data+nsd)->Cout=0;
}
void changer_pcc(graph_t* g, int numsommet, double c){
      g->data[numsommet].pcc=c;
}
void changer_Cout(graph_t* g, int numsommet, double c){
      g->data[numsommet].Cout=c;
}
int dijkstra(int nsd,int nsa,graph_t* g){
  listvertex_t liste_atraiter=initliste();
  listvertex_t liste_atteint=initliste();
  maillon_vertex* u=malloc(sizeof(maillon_vertex));
  listedge_t cour;
  maillon_vertex* v;
  listvertex_t tmp ;
  maillon_vertex**prec;
  double DistTMP;
  int z;
  init_sommet_depart(nsd,g);
  u->val=*(g->data+nsd);
  inser_maillon_vertex(&liste_atraiter,&u);
  while (est_vide(liste_atraiter)==0){
      u=liste_atraiter;
      liste_atraiter=liste_atraiter->next;
      if (u->val.numero==nsa)
      {
        return 1;
      }
      else
      {
        inser_maillon_vertex(&liste_atteint,&u);
        cour=listedge_du_sommet(g,u->val.numero);
        while (cour!=NULL) {
          DistTMP=g->data[u->val.numero].pcc + cour->val.coutt;
          z=in(cour->val.arrivee,liste_atteint);
          if((z==0) && (DistTMP < g->data[cour->val.arrivee].pcc))
          {
            changer_pcc(g, cour->val.arrivee, DistTMP);
            changer_Cout (g,cour->val.arrivee , DistTMP);
            v=so_maillonvertex(g->data[cour->val.arrivee]);
            Pere(v->val.numero,u->val.numero,*g);
            prec=recherche(&liste_atraiter,g->data[cour->val.arrivee].Cout);
            inser_maillon_vertex(prec,&v);
          }
            cour=cour->next;
        }
      }
    }
    freelistevertices(&liste_atteint);
    freelistevertices(&liste_atraiter);
if (((g->data)+nsa)->Cout!=P+1)
  return 1;
else
  return 0;
}
int Astar(int nsd,int nsa,graph_t* g){
  listvertex_t liste_atraiter=initliste();
  listvertex_t liste_atteint=initliste();
  maillon_vertex* u=malloc(sizeof(maillon_vertex));
  listedge_t cour;
  maillon_vertex* v;
  listvertex_t tmp ;
  maillon_vertex**prec;
  double DistTMP;
  int z;
  init_sommet_depart(nsd,g);
  u->val=*(g->data+nsd);
  inser_maillon_vertex(&liste_atraiter,&u);
  while (est_vide(liste_atraiter)==0){
      u=liste_atraiter;
      liste_atraiter=liste_atraiter->next;
      if (u->val.numero==nsa)
      {
        return 1;
      }
      else
      {
        inser_maillon_vertex(&liste_atteint,&u);
        cour=(g->data[u->val.numero]).edges;
        while (cour!=NULL) {
          DistTMP=g->data[u->val.numero].pcc + cour->val.coutt;
          z=in(cour->val.arrivee,liste_atteint);
          if((z==0) && (DistTMP < g->data[cour->val.arrivee].pcc))
          {
            changer_Cout (g,cour->val.arrivee , DistTMP+Heuristique(cour->val.arrivee,nsa,*g));
            changer_pcc(g, cour->val.arrivee, DistTMP);
            v=so_maillonvertex(g->data[cour->val.arrivee]);
            Pere(v->val.numero,u->val.numero,*g);
            prec=recherche(&liste_atraiter,g->data[cour->val.arrivee].Cout);
            inser_maillon_vertex(prec,&v);
          }
            cour=cour->next;
        }
      }
    }
    freelistevertices(&liste_atteint);
    freelistevertices(&liste_atraiter);
if (((g->data)+nsa)->Cout!=P+1)
  return 1;
else
  return 0;
}
void lechemin(graph_t g,int nsd,int nsa){
  int x=nsa;
  while (x!=nsd)
  {
    printf("(%d)<-",x );
    x=g.data[x].pere;
  }
  printf("(%d)\n",nsd );
}

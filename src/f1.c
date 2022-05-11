
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "f1.h"
#define P 90000000000

#define NOM_MAXIMALE 500
void freelistedge(maillon_edge*l){
  maillon_edge* tmp=NULL;
  while(l){
  tmp=l->next;
  free(l);
  l=tmp;
  }
}

void Pere(int a, int b,graph_t g){
  g.data[a].pere=b;
}
void freelistevertices(listvertex_t*l){
  maillon_vertex* tmp=NULL;
  while(l){
    tmp=(*l)->next;
    free(*l);
    *l=tmp;
  }
}
void printlist(listvertex_t l)
{
  while(l){
  printf("%lf,",l->val.Cout);
  l = l->next;
}
}
void free_graph(graph_t* g){
  for (int i=0;i<g->size_vertices;i++)
  {
    freelistedge(g->data[i].edges);
  }
  free(g->data);
  free(g);
}
void afficher_pcc(int numsommet_arrivee,graph_t* g){
  printf("le cout est :%lf\n",((g->data)+numsommet_arrivee)->pcc);
}
listvertex_t initliste(void){
  return NULL;
}
int est_vide(listvertex_t l){
  return l==NULL;
}
listedge_t arc_du_sommet(graph_t* g,int numsommet){
  return (g->data+numsommet)->edges;
}
void inser_maillon_vertex(listvertex_t* l,listvertex_t* s)
  {
    //listvertex_t stock
    (*s)->next=*l;
    (*l)=*s;
}
int in(int n,listvertex_t l){
  maillon_vertex* c=l;
  int m=0;
  if (l!=NULL){
    while (c!=NULL){
      if ((c->val.numero)==n)
      {
        m=1;
      }
      c=c->next;
    }
  }
  return m;
}
listvertex_t* recherche(listvertex_t* a,double c)
{
  maillon_vertex** precc=a ;
  maillon_vertex* courr=*a;
  //if (courr!=NULL)
    {
        while ((courr!= NULL) && (courr->val.Cout<c))
        {
          precc=&(courr->next);
          courr=courr->next;
        }

    }
  return precc;
}

maillon_vertex* so_maillonvertex(vertex_t s){
  maillon_vertex* v=malloc(sizeof(maillon_vertex));
  v->val=s;
  return v;
}
listedge_t listedge_du_sommet(graph_t* g,int numsommet){
  return (g->data[numsommet]).edges;
}
graph_t* f(char* fichier){
char s[NOM_MAXIMALE];
char nom[NOM_MAXIMALE];
char ligne[NOM_MAXIMALE];
int i,sommet,y,n,n1,n2;
listedge_t k;
listedge_t* prek;
float x1,y1;
double v;
graph_t* g=malloc(sizeof(graph_t));
if (g==NULL){
  printf("erreur de creation graphe\n");
  exit(0);
}
struct maillon_edge* stock ;
FILE* f=fopen(fichier,"r");
if (f==NULL){
  printf("erreur d ouverture de fichier**\n");
  exit(0);
}
fscanf(f,"%d %d\n",&sommet,&y);
//printf("%d %d\n",sommet,y);
//
g->size_vertices=sommet;
g->size_egdes=y;
//
fgets(s,NOM_MAXIMALE,f);
g->data=malloc(sizeof(vertex_t)*sommet);
if(g->data==NULL){
  printf("erreur d allocation de listsommets**\n");
  exit(0);
}
//creation des sommet
for(i=0;i<sommet;i++){
fscanf(f,"%d %f %f %s %s\n",&n,&x1,&y1,ligne,nom);
g->data[i].numero=n;
g->data[i].x=x1;
g->data[i].y=y1;
g->data[i].ligne=ligne;
g->data[i].nom=nom;
g->data[i].edges=NULL;
g->data[i].pcc=P+1;
g->data[i].Cout=P+1;
//printf("%d %s\n",g->data[i].numero,g->data[i].nom);
}
//printf("%s\n",s);
//
//liste des arcs
fgets(s,NOM_MAXIMALE,f);
//printf("%s\n",s);
for(int j=0;j<y;j++)
{
  fscanf(f,"%d %d %lf\n",&n1,&n2,&v);
  //printf("%lf\n",v);
  //printf("%lf\n",*sc);
  //printf("hqhqhqhq\n");
  k=malloc(sizeof(maillon_edge));
  if (k==NULL){
    printf("erreur d allocation de listedge**\n");
    exit(0);
  }
  k->val.arrivee=n2;
  k->next=g->data[n1].edges;
  k->val.coutt=v;
  //printf("%d %lf\n",k->val.arrivee,k->val.coutt);
  //insertion_arc(g->data[n1].edges,l);
  g->data[n1].edges=k;
  //printf("%d %lf\n",g->data[n1].edges->val.arrivee,g->data[n1].edges->val.coutt);
  //printf("jojo");
}
//free(listsommets);
fclose(f);
return g;
}

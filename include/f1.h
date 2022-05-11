#ifndef _F1_H
#define _F1_H

typedef struct {
    int arrivee;
    double coutt;
}edge_t;

typedef struct maillon_edge {
    edge_t val;
    struct maillon_edge * next;
}* listedge_t,maillon_edge;

typedef struct vertex {
    int numero;
    int pere;
    char* nom;
    char* ligne;
    double x,y;
    listedge_t edges;
    double pcc;
    double Cout;
}vertex_t;
typedef struct maillon_vertex{
  vertex_t val;
  struct maillon_vertex* next;
}* listvertex_t,maillon_vertex;

typedef struct {
    int size_vertices;
    int size_egdes;
    vertex_t* data;
}graph_t;

void freelistedge(maillon_edge*);
void Pere(int, int,graph_t);
void freelistevertices(listvertex_t*);
void printlist(listvertex_t );
void afficher_pcc(int,graph_t*);
void free_graph(graph_t* );
listedge_t listedge_du_sommet(graph_t*,int);
listvertex_t initliste(void);
int est_vide(listvertex_t);
listedge_t arc_du_sommet(graph_t*,int);
void inser_maillon_vertex(listvertex_t*,listvertex_t*);
int in(int ,listvertex_t );
listvertex_t* recherche(listvertex_t*,double);
maillon_vertex* so_maillonvertex(vertex_t );
graph_t* f(char*);
void lechemin(graph_t,int,int);


#endif

#ifndef _F2_H
#define _F2_H
double Heuristique(int ,int ,graph_t);
void changer_pcc(graph_t*, int, double);
void changer_Cout(graph_t*,int,double);
void init_sommet_depart(int,graph_t*);
int Astar(int,int,graph_t*);
int dijkstra(int,int,graph_t*);
#endif

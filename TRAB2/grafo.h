#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <bits/stdc++.h>

using namespace std;

struct vertice;

struct vertice{
    int codigo;
    int peso;
    vector<vertice> adj;
};

typedef map<int,vertice> grafo;

void criar_vertices(grafo& g, string filename);
void criar_arestas(grafo& g, string filename);
void print_grafo(grafo& g);

#endif
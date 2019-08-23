#ifndef __GRAFO_H__
#define __GRAFO_H__

    #include <bits/stdc++.h>
    using namespace std;

    typedef vector<vector<int>> grafo;
    typedef vector<vector<int>> cliques;

    void adicionar_aresta(grafo& g, int origem, int destino);

    void bfsAuxiliar(grafo g, int vertice, vector<bool> visitados);

    void bfs(grafo g, int vertice);

    void criar_grafo(grafo& g);

#endif
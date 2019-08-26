#ifndef __GRAFO_H__
#define __GRAFO_H__

    #include <bits/stdc++.h>
    using namespace std;

    typedef vector<vector<int>> grafo;
    typedef vector<vector<int>> cliques;

    void adicionar_aresta(grafo& g, int origem, int destino);

    void bfsAuxiliar(grafo g, int vertice, vector<bool>& visitados);

    void bfs(grafo g, int vertice);

    void criar_grafo(grafo& g);

    vector<int> intersecao(vector<int> a, vector<int> b);

    void bronkerbosch(grafo& g, cliques& q, vector<int>& R, vector<int>& P, vector<int>& X);

    void startcliques(grafo& g, cliques& q);

    void printcliques(cliques& q);

    void aglomeracao(cliques& q, grafo& g);

#endif
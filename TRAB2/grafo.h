#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <bits/stdc++.h>

using namespace std;

struct vertice;

struct vertice{
    int codigo;
    int peso;
    int num;
    int grauDeChegada;
    int grauDeSaida;
    string nome;
    vector<vertice> adj;
};

typedef map<int,vertice> grafo;

void criar_vertices(grafo& g, string filename);
void criar_arestas(grafo& g, string filename);
void print_grafo(grafo& g);
vector<int> dfs(grafo& g);
void dfs_auxiliar(grafo& g, int v, map<int,bool>& visitados, vector<int>& dfsResultado);
void graus_de_chegada(grafo& g);
void caminho_critico(grafo& g, vector<int>& topologia);
void todos_os_caminhos(grafo& g, int partida, map<int, bool>& visitados, map<int, int>& pesos, vector<int>& caminho, list<pair<vector<int>,int>>& todosCaminhos);

#endif
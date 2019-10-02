#include <bits/stdc++.h>
#include "grafo.h"

using namespace std;

void criar_vertices(grafo& g, string filename){
    fstream file;
    int a, b;
    string line;
    file.open(filename);
    while(getline(file, line)){
        stringstream formato(line);
        formato >> a >> b;
        vertice v;
        v.codigo = a;
        v.peso = b;
        g[a] = v;
    }
}

void criar_arestas(grafo& g, string filename){
    fstream file;
    int orig, dest;
    string line;
    file.open(filename);
    while(getline(file, line)){
        stringstream formato(line);
        formato >> orig >> dest;
        g[dest].adj.push_back(g[orig]);
    }
}

void print_grafo(grafo& g){
    for(auto d:g){
        cout << d.first << ": ";
        for (auto adj : d.second.adj) {
            cout << adj.codigo << " ";
        }
        cout << "\n";
     }
}

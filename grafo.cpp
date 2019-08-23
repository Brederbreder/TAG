#include "grafo.h"
#include <bits/stdc++.h>
using namespace std;

void adicionar_aresta(grafo& g, int origem, int destino){
    g[origem].push_back(destino);
    g[destino].push_back(origem);
}

void bfs(grafo g, int vertice){
    vector<bool> visitados(g.size(), false);  
    bfsAuxiliar(g, vertice, visitados);
}

void bfsAuxiliar(grafo g, int vertice, vector<bool> visitados){
    queue<int> fila;
    fila.push(vertice);
    visitados[vertice] = true;

    while(fila.size()){
        int w = fila.front();
        fila.pop();

        cout << "vertice: " << w << " de grau: " << g[w].size() << "\n";

        for(auto p : g[w]){
            if(!visitados[p]){
                fila.push(p);
                visitados[p] = true;
            }
        }
    }
    
    for(int i=1; i<visitados.size(); i++){
        if(visitados[i] == false){
            bfsAuxiliar(g, i, visitados);
        }
    }

}

void criar_grafo(grafo& g){
    fstream file;
    int a, b;
    string line;
    file.open("grafo.txt");
    while(getline(file, line)){
        stringstream formato(line);
        formato >> a >> b;
        adicionar_aresta(g,a,b);
    }
}
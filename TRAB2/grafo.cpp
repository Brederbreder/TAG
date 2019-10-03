#include <bits/stdc++.h>
#include "grafo.h"

using namespace std;

void criar_vertices(grafo& g, string filename){
    fstream file;
    int a, b, c;
    string line;
    file.open(filename);
    while(getline(file, line)){
        stringstream formato(line);
        formato >> a >> b >> c;
        vertice v;
        v.codigo = a;
        v.peso = b;
        v.num = c;
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

void graus_de_chegada(grafo& g){
    for(auto p:g){
        p.second.grauDeChegada = 0;
    }   

    for(auto p:g){
        for(auto x:p.second.adj){
            g[x.codigo].grauDeChegada++;
        }
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

void dfs_auxiliar(grafo& g, int v, map<int, bool>& visitados, vector<int>& dfsResultado){
    visitados[v] = true;

    for(auto p:g[v].adj){
        if(!visitados[p.codigo]){
            dfs_auxiliar(g, p.codigo, visitados, dfsResultado);
        }
    }

    dfsResultado.push_back(v);
}

void dfs(grafo& g){
    map<int, bool> visitados;
    vector<int> dfsResultado;
    for(auto p:g){
        visitados[p.first] = false;
    }

    for(int i=0; i < g.size(); i++){
        for(auto p:g){
            if(p.second.num == i){
                dfs_auxiliar(g, p.first, visitados, dfsResultado);
            }
        }
    }

    cout << "dfs";
    for(auto x:dfsResultado){
        cout << "->" << x;
    }
    cout << "\n";
}
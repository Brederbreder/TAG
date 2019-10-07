#include <bits/stdc++.h>
#include "grafo.h"

using namespace std;

void criar_vertices(grafo& g, string filename){
    fstream file;
    int a, b, c;
    string d;
    string line;
    file.open(filename);
    while(getline(file, line)){
        stringstream formato(line);
        formato >> a >> b >> c >> d;
        vertice v;
        v.codigo = a;
        v.peso = b;
        v.num = c;
        v.nome = d;
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
    for(int i=1; i<=g.size(); i++){
        for(auto d:g){
            if(d.second.num == i){
                cout << d.second.nome << ": ";
                for (auto adj : d.second.adj){
                    cout << adj.nome << ", ";
                }
                cout << "\n";
            }
        }
    }
}

void dfs_auxiliar(grafo& g, int v, map<int, bool>& visitados, vector<int>& dfsResultado){
    visitados[v] = true;

    auto x = find(dfsResultado.begin(), dfsResultado.end(), v);
    if(x == dfsResultado.end()){
        dfsResultado.push_back(v);
    }

    for(auto p:g[v].adj){
        if(visitados[p.codigo] == false){
            dfs_auxiliar(g, p.codigo, visitados, dfsResultado);
        }
    }
}

vector<int> dfs(grafo& g){
    map<int, bool> visitados;
    vector<int> dfsResultado;

    for(auto p:g){
        visitados[p.first] = false;
    }

    for(int i=1; i <= g.size(); i++){
        for(auto p:g){
            if(p.second.num == i){
                dfs_auxiliar(g, p.first, visitados, dfsResultado);
            }
        }
    }

    cout << "dfs:\n";
    for(auto x:dfsResultado){
        cout << " -> " << g[x].nome << "\n";
    }
    cout << "\n";

    return dfsResultado;
}

void caminho_critico(grafo& g, vector<int>& topologia){
    map<int,int> finalizar;
    vector<int> caminho;

    for(auto p:g){
        finalizar[p.first] = 0; 
    }

    for(auto p:topologia){
        for(auto x:g){
            for(auto y:x.second.adj){
                if(x.first == p){
                    finalizar[y.codigo] = max(finalizar[y.codigo], finalizar[x.first] + y.peso);
                }
            }
        }
    }

    cout << "peso do caminho critico: ";

    cout << "\n\n";
}
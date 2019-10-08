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
        v.grauDeChegada = 0;
        v.grauDeSaida = 0;
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
        g[orig].grauDeChegada++;
        g[dest].grauDeSaida++;
    }
}

void print_grafo(grafo& g){
    for(int i=1; i<=g.size(); i++){
        for(auto d:g){
            if(d.second.num == i){
                cout << d.second.nome << "(" << d.second.codigo << ")" << ": ";
                for (auto adj : d.second.adj){
                    cout << adj.nome << "(" << adj.codigo << ")" << ", ";
                }
                cout << "\n\n";
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
        cout << " -> " << g[x].nome << "(" << g[x].codigo << ")" << "\n";
    }
    cout << "\n";

    return dfsResultado;
}

void todos_os_caminhos(grafo& g, int partida, map<int, bool>& visitados, map<int, int>& pesos, vector<int>& caminho, list<pair<vector<int>,int>>& todosCaminhos){
    visitados[partida] = true;
    caminho.push_back(partida);
    
    for(auto p:g[partida].adj){
        pesos[p.codigo] = max(pesos[p.codigo], pesos[g[partida].codigo] + p.peso);
        if(!visitados[p.codigo]){
            todos_os_caminhos(g, p.codigo, visitados, pesos, caminho, todosCaminhos);
        }
    }

    if(g[partida].grauDeSaida == 0){
        pair<vector<int>, int> x;
        x.first = caminho;
        x.second = pesos[partida];
        todosCaminhos.push_back(x);
    }

    visitados.clear();
    caminho.pop_back();
}

void caminho_critico(grafo& g, vector<int>& topologia){
    map<int, bool> visitados;
    map<int, int> pesos;
    vector<int> caminho;
    list<pair<vector<int>, int>> todosCaminhos;
    map<int, int> finalizar;

    for(auto p:g){
        finalizar[p.first] = 0;
    }

    for(auto x:topologia){
        for(auto y:g){
            for(auto p:y.second.adj){
                finalizar[p.codigo] = max(finalizar[p.codigo], finalizar[y.second.codigo] + g[y.first].peso);
            }
        }
    }

    for(auto p:g){
        pesos[p.first] = p.second.peso;
    }

    for(auto x:topologia){
        if(g[x].grauDeChegada != 0){
            continue;
        }
        todos_os_caminhos(g, x, visitados, pesos, caminho, todosCaminhos);
    }

    int max = 0;
    int max2 = 0;

    for(auto x:finalizar){
        if(x.second > max){
            max = x.second;
        }
    }

    for(auto x:finalizar){
        if(x.second > max2 && x.second < max){
            max2 = x.second;
        }
    }

    cout << "caminho de maiores pesos: " << max << " e " << max2 << "\n\n";

    for(auto x:todosCaminhos){
        if((x.second - g[x.first.back()].peso) == max){
            for(auto p: x.first){
                cout << p << " -> ";
            }
            cout << "com peso total = " << x.second - g[x.first.back()].peso  << "\n";
        } 
    }

    for(auto x:todosCaminhos){
        if((x.second - g[x.first.back()].peso) == max2){
            for(auto p: x.first){
                cout << p << " -> ";
            }
            cout << "peso = " << x.second - g[x.first.back()].peso  << "\n";
            break;
        } 
    }

    cout << "\n\n";

}
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

void bfsAuxiliar(grafo g, int vertice, vector<bool>& visitados){
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

vector<int> intersecao(vector<int> a, vector<int> b){
    vector<int> resultado;

    for(int i=0; i<a.size(); i++){
        int aux = a[i];
        for(int j=0; j<b.size(); j++){
            if(aux == b[j]){
                resultado.push_back(b[j]);
            }
        }
    }
    return resultado;
}

void bronkerbosch(grafo& g, cliques& q, vector<int>& R, vector<int>& P, vector<int>& X){
    if(P.empty() && X.empty()){
        sort(R.begin(), R.end());
        q.push_back(R);
        return;
    }

    for(int i=0; P.size()>0; i++){
        int v = P[0];

        vector<int> newR = R, newP = P, newX = X;

        newR.push_back(v);          
        newP = intersecao(P,g[v]);  
        newX = intersecao(X,g[v]);  

        bronkerbosch(g, q, newR, newP, newX);

        P.erase(P.begin());
        X.push_back(v);
    }
}

void startcliques(grafo& g, cliques& q){
    if(q.empty()){
        vector<int> r, p, x;
        for(int i=1; i<g.size(); i++){
            p.push_back(i);
        }
        bronkerbosch(g, q, r, p, x);
    }
}

void printcliques(cliques& q){
    sort(q.begin(), q.end(), 
        [](const vector<int>& x, const vector<int>& y) -> bool {
            return x.size() > y.size();
    });

    for(int i=0; i<q.size(); i++){
        cout << "tamanho do clique = " << q[i].size() << " com os vertices: [ ";
        for(int j=0; j<q[i].size(); j++){
            cout << q[i][j] << " ";
        }
        cout << "]\n";
    }
}

void aglomeracao(cliques& q, grafo& g){
    cliques t;

    for(int i=0; i<q.size(); i++){
        if(q[i].size() == 3){
            t.push_back(q[i]);
        }
    }

    double media_aglomeracao = 0;
    for (int i = 1; i < g.size(); i++) {
        int qtdt = 0;
        for (auto &ti : t) {
            auto pertence = find(ti.begin(), ti.end(), i) != ti.end();
            if (pertence) {
                qtdt++;
            }
        }
        int len = g[i].size();
        double aglomeracao;
        if (qtdt == 0) {
            aglomeracao = 0.0f;
        } else {
            aglomeracao = (2.0f*qtdt)/(len*(len - 1));
        }
        media_aglomeracao += aglomeracao; 
        cout << "coeficiente de aglomeracao do vertice " << i << " = " << aglomeracao << "\n";
    }

    cout << "\ncoeficiente de aglomeracao medio do grafo = " << media_aglomeracao / ((double)(g.size()-1)) << "\n"; 

}

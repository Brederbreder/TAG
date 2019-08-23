#include <bits/stdc++.h>
#include "grafo.h"

using namespace std;

int main(){

    grafo g(63);

    adicionar_aresta(g,1,2);
    adicionar_aresta(g,1,3);
    adicionar_aresta(g,1,4);
    adicionar_aresta(g,2,3);
    adicionar_aresta(g,2,4);

    criar_grafo(g);

    bfs(g, 1);

    return 0;
}
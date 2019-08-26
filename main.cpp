#include <bits/stdc++.h>
#include "grafo.h"

using namespace std;

int main(){

    grafo g(63);
    cliques q;

    criar_grafo(g);

    cout << "BFS NO GRAFO: \n\n";
    bfs(g, 1);
    cout << "\n";

    startcliques(g, q);

    cout << "CLIQUES DO GRAFO: \n\n";
    printcliques(q);
    cout << "\n";

    cout << "COEFICIENTES DE AGLOMERACAO DOS VERTICES: \n\n";
    aglomeracao(q, g);
    cout << "\n";

    return 0;
}
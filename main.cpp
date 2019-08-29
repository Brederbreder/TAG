#include <bits/stdc++.h>
#include "grafo.h"

using namespace std;

int main(){

    grafo g(63);
    cliques q;

    criar_grafo(g);

    cout << "\n##################################\n";
    cout << "########## BFS NO GRAFO ##########\n";
    cout << "##################################\n\n";

    bfs(g, 1);
    cout << "\n";

    startcliques(g, q);

    cout << "######################################\n";
    cout << "########## CLIQUES DO GRAFO ##########\n";
    cout << "######################################\n\n";

    printcliques(q);
    cout << "\n";

    cout << "##############################################################\n";
    cout << "########## COEFICIENTES DE AGLOMERACAO DOS VERTICES ##########\n";
    cout << "##############################################################\n\n";

    aglomeracao(q, g);
    cout << "\n";

    return 0;
}
#include <bits/stdc++.h>
#include "grafo.h"

using namespace std;

int main(){

    grafo g;

    criar_vertices(g, "vertices.txt");
    criar_arestas(g, "arestas.txt");

    cout << "\n";

    cout << "###############################\n";
    cout << "#### CIENCIA DA COMPUTACAO ####\n";
    cout << "###############################\n";

    cout << "\n\n";

    cout << "###############################\n";
    cout << "######### DAG DO CURSO ########\n";
    cout << "###############################\n\n\n";
    print_grafo(g);

    cout << "\n\n";

    cout << "################################\n";
    cout << "####### ORDEM TOPOLOGICA #######\n";
    cout << "################################\n\n\n";

    vector<int> topologia;
    topologia = dfs(g);

    cout << "\n\n";

    caminho_critico(g, topologia);

    return 0;
}
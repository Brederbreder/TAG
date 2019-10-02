#include <bits/stdc++.h>
#include "grafo.h"

using namespace std;

int main(){

    grafo g;

    criar_vertices(g, "vertices.txt");
    criar_arestas(g, "arestas.txt");

    print_grafo(g);



    return 0;
}
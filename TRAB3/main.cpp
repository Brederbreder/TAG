#include <bits/stdc++.h>
#include "professor.h"
#include "escola.h"
#include "grafo.h"

using namespace std;

int main(){
    auto grafo = Grafo();
    grafo.criar_professores();
    grafo.criar_escolas();

    cout << "############################## GRAFO DE ENTRADA #########################\n";
    grafo.print_grafo();
    cout << "#########################################################################\n\n\n";

    grafo.gale_shapley();

    cout << "############################## RESULTADO ################################\n";
    grafo.print_resultado();
    cout << "#########################################################################\n";
}
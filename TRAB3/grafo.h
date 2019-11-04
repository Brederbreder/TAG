#ifndef __GRAFO_H__
#define __GRAFO_H__

#include "escola.h"
#include "professor.h"
#include <bits/stdc++.h>

using namespace std;

class Grafo{
    // private:
    public:
        vector<Escola> escolas;
        vector<Professor> professores;
        vector<pair<string, string>> resultado;
        map<string, vector<int>> match;

        void criar_professores();
        void criar_escolas();
        void print_grafo();
        void gale_shapley();
        void print_resultado();

};

#endif
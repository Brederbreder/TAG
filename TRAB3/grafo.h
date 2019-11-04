#ifndef __GRAFO_H__
#define __GRAFO_H__

#include "escola.h"
#include "professor.h"
#include <bits/stdc++.h>

using namespace std;

class Grafo{
    private:
        vector<Escola> escolas;
        vector<Professor> professores;

    public:
        void criar_professores();
        void criar_escolas();

};

#endif
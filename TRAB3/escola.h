#ifndef __ESCOLA_H__
#define __ESCOLA_H__

#include <bits/stdc++.h>

using namespace std;

struct Escola{
    string nome;
    int vagas;
    vector<int> habilitacoes;
    vector<string> professores;

    Escola(string nome, int vagas, vector<int> &habilitacoes){
        this->nome = nome;
        this->vagas = vagas;
        this->habilitacoes = habilitacoes;
    }
};

#endif
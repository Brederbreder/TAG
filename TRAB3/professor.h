#ifndef __PROFESSOR_H__
#define __PROFESSOR_H__

#include <bits/stdc++.h>

using namespace std;

struct Professor{
    string nome;
    int habilitacao;
    vector<string> interesse;

    Professor(string nome, int habilitacao, vector<string> &interesse) {
        this->nome = nome;
        this->habilitacao = habilitacao;
        this->interesse = interesse;
    }

};

#endif
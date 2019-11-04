#include <bits/stdc++.h>
#include "escola.h"
#include "professor.h"
#include "grafo.h"

using namespace std;

void Grafo::criar_professores(){
    fstream file;
    string line;
    string nome;
    int habilitacao;
    string preferencia;

    file.open("professor.txt");

    while(getline(file, line)){
        vector<string> vs;
        if(line == "professor"){
            getline(file, line);
            nome = line;
            getline(file, line);
            habilitacao = stoi(line);
            while(getline(file, line)){
                if(line == "fim"){
                    break;
                }else{
                    vs.push_back(line);
                }
            }
            auto p = Professor(nome, habilitacao, vs);
            this->professores.push_back(p);
        }
    }
}

void Grafo::criar_escolas(){
    fstream file;
    string line;
    string nome;
    int habilitacao;
    int vagas;

    file.open("escola.txt");

    while(getline(file, line)){
        vector<int> vi;
        if(line == "escola"){
            getline(file, line);
            nome = line;
            getline(file, line);
            vagas = stoi(line);
            while(getline(file, line)){
                if(line == "fim"){
                    break;
                }else{
                    habilitacao = stoi(line);
                    vi.push_back(habilitacao);
                }
            }
            auto p = Escola(nome, vagas, vi);
            this->escolas.push_back(p);
        }
    }
}

void Grafo::print_grafo(){
    for(auto p:this->professores){
        cout << "professor de nome: " << p.nome << " com habilitacao: " << p.habilitacao << " e com preferencia nas escolas: ";
        for(auto x:p.interesse){
            cout << x << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";

    for(auto p:this->escolas){
        cout << "nome da escola:" << p.nome << " ";
        cout << "com " << p.vagas << " vagas e com habilitacoes requisitadas: ";
        for(auto x:p.habilitacoes){
            cout <<  x << " ";
        }
        cout << "\n";
    }
}

void Grafo::gale_shapley(){

    for(auto &p:this->professores){
        for(auto &e:this->escolas){
            for(auto &x:p.interesse){
                for(auto &y:e.habilitacoes){
                    if(p.habilitacao == y && x == e.nome && e.vagas > 0 && p.contratado == 0){
                        this->resultado.push_back(make_pair(e.nome, p.nome));
                        e.vagas--;
                        p.contratado = 1;
                        break;
                    }
                }
            }
        }
    }
}

void Grafo::print_resultado(){
    for(auto p:this->resultado){
        cout << p.first << " -> " << p.second << "\n";
    }
}
#include<iostream>
#include "aluno.h"
using namespace std;

struct No{
    Aluno aluno;
    No* filhoesquerda;
    No* filhodireita;
};

class ArvoreBinariadeBusca{
    private:
    No* raiz;

    public:
    ArvoreBinariadeBusca();
    ~ArvoreBinariadeBusca();
    void deletarArvore(No* );
};
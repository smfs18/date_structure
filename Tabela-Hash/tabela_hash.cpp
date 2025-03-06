#include<iostream>
#include "tabela_hash.h"

using namespace std;

int Hash::FuncaoHash(Aluno aluno)
{
    return (aluno.ObterRa() % max_posicoes);
}

Hash::Hash(int tam_vetor, int max)
{
   quant_itens = 0;
   max_itens = max;
   max_posicoes = tam_vetor;
   estrutura = new Aluno[tam_vetor];

}
Hash::~Hash()
{
    delete [] estrutura;
}
bool Hash::estacheio()
{
    return(quant_itens == max_itens);
}
int Hash::obterTamanhoAtual()
{
    return(quant_itens);
}
void Hash::inserir(Aluno aluno)
{
    int local = FuncaoHash(aluno);
    while(estrutura[local].ObterRa() > 0){
        local = (local + 1) % max_posicoes; //Enquanto não achar espaço vazio, vai para o próximo espaço, se caso passe do número máx de posições, tiramos o módulo.
    }
    estrutura[local] = aluno;
    quant_itens++;
}
void Hash::deletar(Aluno aluno)     
{
    int local = FuncaoHash(aluno);
    bool teste = false;
    while(estrutura[local].ObterRa() != -1){
        if(estrutura[local].ObterRa() == aluno.ObterRa()){
            cout<<"Elemento Removido"<<endl;
            estrutura[local] = Aluno(-2, " ");
            quant_itens--;
            teste = true;
            break;
        }
        local = (local+1) % max_posicoes;
    }
    if(!teste){
        cout << "Elemento não encontrado"<< endl;
        cout << "Nenhum elemento removido" << endl;
    }

}
void Hash::buscar(Aluno& aluno, bool& busca)
{
    int local = FuncaoHash(aluno);
    busca = false;
    while (estrutura[local].ObterRa() != -1){
        if(estrutura[local].ObterRa() == aluno.ObterRa()){
            busca = true;
            aluno = estrutura[local];
            break;
        }
        local = (local + 1) % max_posicoes;
    }
}
void Hash::imprimir()
{
    cout << "Tabela Hash: "<<endl;
    for (int i =0; i < max_posicoes; i++){
        if (estrutura[i].ObterRa() > 0){
            cout<< i << ":" << estrutura[i].ObterRa();
            cout<< estrutura[i].ObterNome()<<endl;
        }
    }
}
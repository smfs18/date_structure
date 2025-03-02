#include<iostream> //inclusão da biblioteca de entrada e saída
#include "stack.h" //chamar o módulo da pilha

using namespace std; //um espécie de falar por um nome específico.



    stack::stack() //construtor
    {
        tamanho = 0;
        estrutura = new tipoitem[max_itens];

    }
    stack::~stack() //destrutor
    {
        delete [] estrutura;
    }
    bool stack::is_empty() // verifica se a pulha está vazia
    {
        return(tamanho == 0);
    }
    bool stack::is_full() // verifica se a pilha está cheio
    {
        return(tamanho == max_itens);
    }
    void stack::push(tipoitem item) //colocar elementos na pilha
    {
        if(is_full()){
            cout << "A pilha está cheia!\n";
            cout << "Não é possível inserir este elemento!\n";
        }else{
            estrutura[tamanho] = item;
            tamanho++;
        }

    }
    tipoitem stack::pop() //remover o último adicionado
    {
        if(is_empty()){
            cout << "A pilha está vazia!\n";
            cout << "Não tem elemento para ser removido!\n";
        }else{
            return estrutura[tamanho -1];
            tamanho--;
        }
    }
    void stack::print() //imprimir na tela
    {
        cout <<"Pilha: [";
        for (int i =0; i<tamanho; i++){
            cout << estrutura[i] << " ";
        }
        cout << "]\n";
    }
    tipoitem stack::lenght() //Tamanho da pilha
    {
        return tamanho;
    }

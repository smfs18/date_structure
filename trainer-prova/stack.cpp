#include<iostream>
using namespace std;

struct No{
    int data;
    No* proximo;

    No(int d) : data(d), proximo(nullptr){}
};

class stack{
    private:
    No* topo;
    int tamanho;
    
    public:
    //Construtor da Pilha.
    stack() : topo(nullptr), tamanho(0){}
    //Destrutor da pilha.
    ~stack(){
        while(!vazia()){
            desempilhar();
        }
    }
    //Verificar se a pilha está vazia.
    bool vazia(){
        return topo == nullptr;
    }
    //Retorna o tamanho da pilha;
    int getTamanho(){
        return tamanho;
    }
    //Empilhar(push):
    void empilhar(int data){
        No* novoNo = new No(data);
        if(vazia()){
            topo = novoNo;
        }
        No* temp = topo;
        novoNo->proximo = topo;
        topo = novoNo;
        delete temp;
        tamanho++;
    }
    //Desempilhar (Pop)
    int desempilhar(){
        if (vazia()){
            cout<<"A pilha está vazia"<<endl;
            return -1;
        }
        No* temp = topo;
        int valor_apagado = temp->data;
        topo = topo->proximo;
        delete temp;
        tamanho--;
        return valor_apagado;
    }
    int verTop(){
        if(vazia()){
            cout<<"A pilha está vazia"<<endl;
            return -1;
        }
        return topo->data;
    }
};
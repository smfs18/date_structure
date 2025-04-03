#include<iostream>
using namespace std;

struct No{
    int data;
    No* proximo; 
    No(int d) : data(d), proximo(nullptr){}
};

class queue{
    private:
    No* frente; // Nó da frente (tem data e o ponteiro para o próximo)
    No* tras; //Nó da trás (tem a data e o ponteiro para o próximo é nulo)
    int tamanho; //Tamanho da fila.
    
    public:
    //Construtor
    queue() : frente(nullptr), tras(nullptr), tamanho(0){} //Padrão de Inicialização
    //Destrutor
    ~queue(){
        while (!vazia()) //Enquanto a fila não for vazia;
        {
            dequeue(); //Desenfilerar;
        }
    }
    //Verifica se a fila está fazia;
    bool vazia(){
        return frente == nullptr;
    }
    //Retornar o tamanho da fila.
    int getTamanho(){
        return tamanho;
    }
    //Adicionar elemento na fila;
    void enqueue(int data){
        No* novoNo = new No(data);
        //Verifica se a fila esta vazia.
        if(tras == nullptr){
            frente = tras = novoNo;
        }else{
            tras->proximo = novoNo;
            tras = novoNo;
        }
        tamanho++; //Aumenta o tamanho da fila;
    }
    //Remove elementos da pilha.
    int dequeue(){
        if(vazia()){
            cout<<"Fila vazia"<<endl;
            return -1; //valor de erro.
        }
        No* temp = frente;
        int data = temp->data;
        frente = frente->proximo;
        //Se a fila ficou vazia depois da remoção;
        if(frente == nullptr){
            tras = nullptr;
        }
        delete temp; //Liberar memória do nó temporário;
        tamanho--; //Decrementa o tamanho da fila;
    }
    int primeiro(){
        if (vazia()){
            cout<<"Fila está vazia"<<endl;
            return -1; //valor de erro;
        }
        return frente->data;

    }
    void printar(){
        No* atual = frente;
        cout<<"Fila: [";
        while(atual != nullptr){
            cout<< atual->data;
            if(atual->proximo != nullptr){
                cout<<", ";
            }
            atual = atual->proximo;
        }
    }
    bool buscar(int data){
        No* atual = frente;
        while (atual != nullptr){
            if(atual->data == data){
                return true;
            }
            atual = atual->proximo;
        }
        return false;
    }

};
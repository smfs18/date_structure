#include<iostream>
#include "queue.h"

using namespace std;

    queue::queue()
    {
        primeiro = 0;
        ultimo = 0;
        estrutura = new tipoitem[max_itens];
    }

    queue::~queue()
    {
        delete estrutura;
    }

    bool queue::isempty()
    {
        return(primeiro == ultimo);
    }

    bool queue::isfull()
    {
        return (ultimo - primeiro == max_itens);
    }
        
    void queue::enqueue(tipoitem item)
    {
        if(isfull()){
            cout << "A fila está cheia\n";
        }else{
            estrutura[ultimo % max_itens] = item;
            ultimo++;
        }
    }
    
    tipoitem dequeue(){
        
    }
    
    void print();
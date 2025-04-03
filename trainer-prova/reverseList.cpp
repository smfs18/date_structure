#include<iostream>
using namespace std;

struct No
{
    int data;
    No* proximo;

    No(int d) : data(d), proximo(nullptr){}
};

No* reverseList(No* head){
    No* anterior = nullptr;
    No* atual = head;
    No* proximo = nullptr;

    while(atual != nullptr){
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }
    return anterior;
}
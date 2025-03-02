#include<iostream> 
#include "stack.h"
using namespace std;

int main(){
    stack pilha1;
    tipoitem item;
    int opcao;
    cout << "Programa gerador de pilha:\n";

    do{
        cout << "Digite 0 para parar o programa!"<< endl;
        cout << "Digite 1 para inserir elemento!"<< endl;
        cout << "Digite 2 para remover elemento!"<< endl;
        cout << "Digite 3 para imprimir a pilha!"<< endl;
        cin >> opcao;
        if (opcao ==1){
            cout << "Digite o elemento a ser inserido:\n";
            cin >> item;
            pilha1.push(item);
        }else if (opcao == 2){
            item = pilha1.pop();
            cout << "Elemento removido: " << item<< endl;
        }else if (opcao ==3){
            pilha1.print();
        }
    }while (opcao != 0);

    return 0;
}
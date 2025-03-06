#include <iostream>
#include "tabela_hash.h"

using namespace std;

int main(){
    int tam_vetor, max;
    cout << "Programa gerador de Hash!"<<endl;
    cout << "Digite o tamanho da Hash"<<endl;
    cin >> tam_vetor;
    cout << "Digite o número máximo de elementos"<<endl;
    cin >> max;
    cout << "O fator de carga é: "<< (float)max/(float)tam_vetor << endl;
    Hash alunohash(tam_vetor, max);
    int opcao;
    int ra;
    string nome;
    bool busca;
    do{
        cout << "Digite 0 para parar o algoritmo"<<endl;
        cout << "Digite 1 para inserir um elemento"<<endl;
        cout << "Digite 2 para remover um elemento"<<endl;
        cout << "Digite 3 para buscar um elemento"<<endl;
        cout << "Digite 4 para imprimir a Hash"<<endl;
        cin >> opcao;
        if (opcao == 1){
            cout << "Qual o RA do aluno?"<<endl;
            cin >> ra;
            cout << "Qual o nome do aluno?"<<endl;
            cin >> nome;
            Aluno aluno(ra, nome);
            alunohash.inserir(aluno);
        }else if (opcao == 2){
            cout << "Qual o RA do aluno removido?"<< endl;
            cin >> ra;
            Aluno aluno(ra, " ");
            alunohash.deletar(aluno);
        }else if(opcao == 3){
            cout << "Qual o RA do aluno que deseja buscar? "<< endl;
            cin >> ra;
            Aluno aluno(ra, " ");
            alunohash.buscar(aluno, busca);
            if (busca){
                cout << "Aluno encontrado: "<< endl;
                cout << "RA: " << aluno.ObterRa()<< endl;
                cout << "Nome: "<< aluno.ObterNome()<< endl;
            }else{
                cout << "Aluno não encntrado."<<endl;

            }

        }else if(opcao == 4){
            alunohash.imprimir();
        }
    } while(opcao != 0);
    return 0;
}

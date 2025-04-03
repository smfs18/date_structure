#ifndef GENOME_PROCESSOR_H
#define GENOME_PROCESSOR_H

#include "GenomeHashTable.h" //chamar o arquivo GenomaHashTable
#include "constants.h" //chamar o arquivo constantes
//definição da classe GenomaProcessor
class GenomeProcessor { 
private: //membro privado 
    GenomeHashTable hashTable; //chama a tabela Hash do arquivo GenomaHashTable

public: //membros públicos
    void getUserInput(char input[][BLOCK_SIZE + 1]); //método para obter o input do usuário
    void processInput(const char input[][BLOCK_SIZE + 1]); //método para processar o input, ajustar as entrada
    void showResults() const; //método para mostrar os resultados
};

#endif //GENOME_PROCESSOR_H
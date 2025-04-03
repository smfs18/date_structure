#ifndef GENOME_HASH_TABLE_H
#define GENOME_HASH_TABLE_H

#include "HashNode.h" //chama o arquivo HashNode
#include "constants.h" //chama o arquivo constantes
//criação da classe GenomaHashTable
class GenomeHashTable { 
private: //membros privados
    HashNode** table; //ponteiro da tabela
    unsigned int hashFunction(const char* key); //declaração da função hash, a entrada é a chave

public:
    GenomeHashTable(); //construtor da classe
    ~GenomeHashTable(); //destrutor da classe para liberar
    void insert(const char* block); //inserir o bloco na tabela
    void printResults() const; //imprimir os resultados
};

#endif // GENOME_HASH_TABLE_H
#ifndef HASH_NODE_H
#define HASH_NODE_H

#include "constants.h" //chama o arquivo constantes, que contém o BLOCK_SIZE
//criação da classe HashNode (nó da Hash)
class HashNode {
public: //membros públicos
    char key[BLOCK_SIZE + 1]; //armazena uma chave(string) como um array de caracteres e o "+1" é para acomodar o caractere nulo (/0)
    int count; //contador
    HashNode* next; //ponteiro para o "próximo"

    HashNode(const char* block); //construtor da classe
};

#endif // HASH_NODE_H
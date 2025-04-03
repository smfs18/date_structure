//inclusão do header
#include "GenomeHashTable.h" 
#include <iostream>
#include <cstring>
//criação de uma nova tabela Hash
GenomeHashTable::GenomeHashTable() {
    table = new HashNode*[HASH_SIZE]();
}
//destrutor, para liberar memória
GenomeHashTable::~GenomeHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* current = table[i];
        while (current != nullptr) {
            HashNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}
//função Hash
unsigned int GenomeHashTable::hashFunction(const char* key) {
    unsigned int hash = 0;
    for (int i = 0; i < BLOCK_SIZE; i++) {
        hash = (hash * 31 + key[i]) % HASH_SIZE; //espalha melhor os bits do valor, incorpora o valor ASCII do caractere no hash e garante que o resultado seja um índice válido na tabela.
    }
    return hash; //retorna a hash que é um inteiro
}
//método para inserir na tabela hash o bloco do genoma
void GenomeHashTable::insert(const char* block) {
    unsigned int index = hashFunction(block);
    HashNode* current = table[index];

    while (current != nullptr) {
        if (strcmp(current->key, block) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    HashNode* newNode = new HashNode(block);
    newNode->next = table[index];
    table[index] = newNode;
}
//função para imprimir na tela os resultados
void GenomeHashTable::printResults() const {
    std::cout << "\nResultados:\n";
    std::cout << "Bloco\tOcorrencias\n";
    std::cout << "----------------\n";
    
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* current = table[i];
        while (current != nullptr) {
            std::cout << current->key << "\t" << current->count << "\n";
            current = current->next;
        }
    }
}
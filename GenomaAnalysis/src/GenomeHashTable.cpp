#include "GenomeHashTable.h"
#include <iostream>
#include <cstring>

GenomeHashTable::GenomeHashTable() {
    table = new HashNode*[HASH_SIZE]();
}

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

unsigned int GenomeHashTable::hashFunction(const char* key) {
    unsigned int hash = 0;
    for (int i = 0; i < BLOCK_SIZE; i++) {
        hash = (hash * 31 + key[i]) % HASH_SIZE;
    }
    return hash;
}

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
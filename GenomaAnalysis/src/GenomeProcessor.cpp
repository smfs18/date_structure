//inclusão dos headers
#include "GenomeProcessor.h" 
#include <iostream>
#include <cstring>
//função para obter o input do usuário
void GenomeProcessor::getUserInput(char input[][BLOCK_SIZE + 1]) {
    std::cout << "Digite " << INPUT_SIZE << " blocos de " << BLOCK_SIZE << " caracteres cada (A/T/C/G):\n";

    for (int i = 0; i < INPUT_SIZE; i++) {
        std::cout << "Bloco " << i+1 << ": ";
        std::cin >> input[i];
        
        while (strlen(input[i]) != BLOCK_SIZE) {
            std::cout << "Erro: O bloco deve ter exatamente " << BLOCK_SIZE << " caracteres.\n";
            std::cout << "Bloco " << i+1 << ": ";
            std::cin >> input[i];
        }
    }
}
//função para processar a entrada
void GenomeProcessor::processInput(const char input[][BLOCK_SIZE + 1]) {
    for (int i = 0; i < INPUT_SIZE; i++) {
        hashTable.insert(input[i]);
    }
}
//função para chamar outra função para imprimir na tela
void GenomeProcessor::showResults() const {
    hashTable.printResults();
}
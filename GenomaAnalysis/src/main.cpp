//inclusão dos headers
#include "GenomeProcessor.h"
#include "constants.h"
//função principal
int main() {
    GenomeProcessor processor; //como se fosse um apelido da classe 
    char userInput[INPUT_SIZE][BLOCK_SIZE + 1]; //entrada do usuário vai ser uma char(tamanho de bits)

    processor.getUserInput(userInput); //chama a função para obter a entrada
    processor.processInput(userInput); //chama a função para processar a entrada
    processor.showResults(); //chama a função para imprimir na tela

    return 0;
}
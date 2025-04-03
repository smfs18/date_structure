#include <bits/stdc++.h> // Inclusão de todas as bibliotecas padrão

typedef long long ll; // Defini 'll' como long long
typedef long double ld; // Defini 'ld' como long double

#define el '\n' // Define quebra de linha
#define Beevo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); // Otimiza entrada/saída, útil para o problema, devido ao volume grande de entrada e sáida.

using namespace std;

// Função que gera operações para um número e conta as adições
int resolver(int n, string &s) {
    // Verifica cada bit do número (do bit 29 ao 0)
    for(int bit = 29; bit >= 0; bit--) {
        // Se a string não estiver vazia, adiciona 'd' e '+'
        if(s.size()) {
            s += 'd', s += '+';
        }
        // Verifica se o bit atual está ativo no número
        if(n & (1 << bit)) {
            s += '1'; // Adiciona o número 1 à pilha
            
            // Se já tiver mais de uma operação, adiciona '+'
            if(s.size() > 1) {
                s += '+';
            }
        }
    }
    // Retorna a quantidade de operações de adição
    return count(s.begin(), s.end(), '+');
}

// Função que processa cada caso de teste
void casoDeTeste() {
    int n;
    cin >> n; // Lê o tamanho do array
    int a[n]; // Cria array para os números
    
    // Lê os números do array
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int soma = 0;
    string b[n]; // Array para armazenar as sequências de operações
    
    // Processa os números do último para o primeiro
    for(int i = n-1; i >= 0; i--) {
        int atual = a[i] + soma;
        // Gera as operações e atualiza a soma de adições
        soma += resolver(atual, b[i]);
    }
    
    // Imprime todas as sequências de operações
    for (int i = 0; i < n; i++) {
        cout << b[i];
    }
}

// Função principal
int main() {
    Beevo // Otimização de IO
    
    int t = 1;
    // Loop para casos de teste (neste código só executa uma vez)
    while(t--) {
        casoDeTeste();
    }
    return 0;
}
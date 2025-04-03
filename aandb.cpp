#include <iostream>

struct NoFila {
    std::string programa;
    int* pilha;
    int tamanho_pilha;
    NoFila* proximo;
};

class FilaSimples {
public:
    FilaSimples() : inicio(nullptr), fim(nullptr) {}
    ~FilaSimples() {
        while (!vazia()) {
            std::string dummy;
            int* dummy_pilha;
            int dummy_tamanho;
            desenfileirar(dummy, dummy_pilha, dummy_tamanho);
            delete[] dummy_pilha;
        }
    }
    
    void enfileirar(std::string prog, int* p, int tamanho) {
        NoFila* novoNo = new NoFila;
        novoNo->programa = prog;
        
        novoNo->pilha = new int[tamanho];
        for (int i = 0; i < tamanho; i++) {
            novoNo->pilha[i] = p[i];
        }
        novoNo->tamanho_pilha = tamanho;
        novoNo->proximo = nullptr;
        
        if (fim == nullptr) {
            inicio = fim = novoNo;
        } else {
            fim->proximo = novoNo;
            fim = novoNo;
        }
    }
    
    bool desenfileirar(std::string& prog, int*& p, int& tamanho) {
        if (inicio == nullptr) return false;
        
        NoFila* temp = inicio;
        prog = temp->programa;
        tamanho = temp->tamanho_pilha;
        p = new int[tamanho];
        for (int i = 0; i < tamanho; i++) {
            p[i] = temp->pilha[i];
        }
        
        inicio = inicio->proximo;
        if (inicio == nullptr) {
            fim = nullptr;
        }
        
        delete[] temp->pilha;
        delete temp;
        return true;
    }
    
    bool vazia() {
        return inicio == nullptr;
    }
    
private:
    NoFila* inicio;
    NoFila* fim;
};

bool simular(const std::string& programa, int*& pilha_resultado, int& tamanho_resultado) {
    int pilha[1000];
    int tamanho_pilha = 0;
    
    for (char op : programa) {
        if (op == '1') {
            pilha[tamanho_pilha++] = 1;
        } else if (op == 'd') {
            if (tamanho_pilha == 0) return false;
            pilha[tamanho_pilha] = pilha[tamanho_pilha - 1];
            tamanho_pilha++;
        } else if (op == '+') {
            if (tamanho_pilha < 2) return false;
            
            int a = pilha[--tamanho_pilha];
            int b = pilha[--tamanho_pilha];
            
            int novo_tamanho = 0;
            for (int i = 0; i < tamanho_pilha; i++) {
                if (pilha[i] - 1 > 0) {
                    pilha[novo_tamanho++] = pilha[i] - 1;
                }
            }
            
            pilha[novo_tamanho++] = a + b;
            tamanho_pilha = novo_tamanho;
        }
    }
    
    pilha_resultado = new int[tamanho_pilha];
    for (int i = 0; i < tamanho_pilha; i++) {
        pilha_resultado[i] = pilha[i];
    }
    tamanho_resultado = tamanho_pilha;
    return true;
}

bool compararPilhas(int* pilha1, int tamanho1, int* pilha2, int tamanho2) {
    if (tamanho1 != tamanho2) return false;
    for (int i = 0; i < tamanho1; i++) {
        if (pilha1[i] != pilha2[i]) return false;
    }
    return true;
}

std::string gerar_programa(int* pilha_alvo, int tamanho_alvo) {
    const int tamanho_maximo = 100000;
    
    FilaSimples fila;
    fila.enfileirar("", nullptr, 0);
    
    while (!fila.vazia()) {
        std::string programa;
        int* pilha_atual;
        int tamanho_atual;
        
        if (!fila.desenfileirar(programa, pilha_atual, tamanho_atual)) {
            break;
        }
        
        if (compararPilhas(pilha_atual, tamanho_atual, pilha_alvo, tamanho_alvo)) {
            delete[] pilha_atual;
            return programa;
        }
        
        if (programa.length() >= tamanho_maximo) {
            delete[] pilha_atual;
            continue;
        }
        
        char operacoes[] = {'1', 'd', '+'};
        for (char op : operacoes) {
            std::string novo_programa = programa + op;
            int* nova_pilha;
            int novo_tamanho;
            
            if (simular(novo_programa, nova_pilha, novo_tamanho)) {
                fila.enfileirar(novo_programa, nova_pilha, novo_tamanho);
                delete[] nova_pilha;
            }
        }
        
        delete[] pilha_atual;
    }
    
    return "Não encontrado.";
}

int main() {
    int n;
    std::cin >> n;
    
    if (n < 1 || n > 1000) {
        std::cerr << "Erro" << std::endl;
        return 1;
    }
    
    int* pilha_alvo = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> pilha_alvo[i];
        if (pilha_alvo[i] < 1 || pilha_alvo[i] > 1000000) {
            std::cerr << "Erro" << std::endl;
            delete[] pilha_alvo;
            return 1;
        }
    }
    
    std::string programa = gerar_programa(pilha_alvo, n);
    std::cout << programa << std::endl;
    
    delete[] pilha_alvo;
    return 0;
}
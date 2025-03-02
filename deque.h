#ifndef DEQUE_H
#define DEQUE_H


typedef int tipoitem;

// Estrutura do Nó
struct Node {
    char data;
    Node* next;
    Node* prev;
    
    Node(char val);
};

// Implementação da Deque
class Deque {
private:
    Node* head;
    Node* tail;
    
public:
    Deque();

    // Adiciona no início
    void push_front(char val);

    // Adiciona no final
    void push_back(char val);

    // Remove do início
    void pop_front();

    // Remove do final
    void pop_back();

    // Imprime a Deque
    void print();
    // Destrutor para liberar memória
    ~Deque();
};
#endif

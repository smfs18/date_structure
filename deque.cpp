#include "deque.h"  // Inclui apenas a definição
#include<iostream>

using namespace std;
// Construtor da Deque
Deque::Deque() {
    head = tail = nullptr;
}

// Adiciona no início
void Deque::push_front(char val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Adiciona no final
void Deque::push_back(char val) {
    Node* newNode = new Node(val);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Remove do início
void Deque::pop_front() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
}

// Remove do final
void Deque::pop_back() {
    if (!tail) return;
    Node* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
}

// Imprime a Deque
void Deque::print() {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

// Destrutor para liberar memória
Deque::~Deque() {
    while (head) pop_front();
}

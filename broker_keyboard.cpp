#include <iostream>
#include <vector>

struct Node {
    char data;
    Node* prev;
    Node* next;
    Node(char val) : data(val), prev(nullptr), next(nullptr) {}
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

   
    void insertFront(char val) {
        Node* newNode = new Node(val);
        if (!front) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    
    void insertRear(char val) {
        Node* newNode = new Node(val);
        if (!rear) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    
    void print() {
        Node* temp = front;
        while (temp) {
            std::cout << temp->data;
            temp = temp->next;
        }
        std::cout << "\n";
    }

    ~Deque() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    std::string line;
    
    while (std::getline(std::cin, line)) {
        Deque dq;
        std::vector<char> tempBuffer; 
        bool insertAtFront = false;   

        for (char c : line) {
            if (c == '[') {
                
                for (auto it = tempBuffer.rbegin(); it != tempBuffer.rend(); ++it) {
                    dq.insertFront(*it);
                }
                tempBuffer.clear(); 
                insertAtFront = true; 
            } else if (c == ']') {
                                for (auto it = tempBuffer.rbegin(); it != tempBuffer.rend(); ++it) {
                    dq.insertFront(*it);
                }
                tempBuffer.clear();
                insertAtFront = false; 
            } else {
                if (insertAtFront) {
                    tempBuffer.push_back(c); 
                } else {
                    dq.insertRear(c); 
                }
            }
        }

        
        for (auto it = tempBuffer.rbegin(); it != tempBuffer.rend(); ++it) {
            dq.insertFront(*it);
        }

        dq.print(); 
    }

    return 0;
}
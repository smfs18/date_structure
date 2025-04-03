#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) { //Pega a raiz
        if (root == NULL){ //Se a raiz estiver vazia
            return -1; //Retorna -1, basicamente dizer que a árvore está vazia.
        }else{ //Se a raiz não estiver fazia, vamos pecorrer a árvore.
            int he = height(root->left); //Pegar o valor do caminho pecorrido pela esquerda.
            int hr = height(root->right); // Pega o valor do caminho pecorrido pela direita.
            if(he < hr){ //Compara as alturas, caso a da esquerda for maior.
                return hr + 1; //Adicionamos 1 ao valor da altura da esquerda, pois é o caminho da raiz para o 1º nó filho pela esquerda.
            }else{//Compara as alturas, caso a da direita for maior.
                return he + 1;//Adicionamos 1 ao valor da altura da direita, pois é o caminho da raiz para o 1º nó filho pela direita.
            }
        }
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    int height = myTree.height(root);
    
  	std::cout << height;

    return 0;
}

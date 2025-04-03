#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void preOrder(Node* root, vector<int>& result) {
    if (root) {
        result.push_back(root->value);
        preOrder(root->left, result);
        preOrder(root->right, result);
    }
}

void inOrder(Node* root, vector<int>& result) {
    if (root) {
        inOrder(root->left, result);
        result.push_back(root->value);
        inOrder(root->right, result);
    }
}

void postOrder(Node* root, vector<int>& result) {
    if (root) {
        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->value);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    Node* root = nullptr;
    for (int value : data) {
        root = insert(root, value);
    }

    vector<int> preOrderResult;
    preOrder(root, preOrderResult);
    cout << "Pre order :";
    for (int val : preOrderResult) {
        cout << " " << val;
    }
    cout << endl;

    vector<int> inOrderResult;
    inOrder(root, inOrderResult);
    cout << "In order  :";
    for (int val : inOrderResult) {
        cout << " " << val;
    }
    cout << endl;

    vector<int> postOrderResult;
    postOrder(root, postOrderResult);
    cout << "Post order:";
    for (int val : postOrderResult) {
        cout << " " << val;
    }
    cout << endl;

    return 0;
}
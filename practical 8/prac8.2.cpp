#include <iostream>
using namespace std;

struct Node {
    int code;
    Node* left;
    Node* right;

    Node(int c) {
        code = c;
        left = nullptr;
        right = nullptr;
    }
};



Node* Insert(Node* root, int code) {


    if (root == nullptr)
        {
        return new Node(code);
    }
    if (code < root->code) {
        root->left = Insert(root->left, code);
    }


    else if (code > root->code) {
        root->right = Insert(root->right, code);
    }

    return root;
}


void inorder(Node* root) {

    if (root == nullptr) {
        return;
    }

    inorder(root->left);

    cout << root->code << " ";

    inorder(root->right);
}





int main() {

    Node* root = nullptr;

    int n;

    cout << "Enter number of books: ";
    cin >> n;

    cout << "Enter book codes: ";

    for (int i = 0; i < n; i++) {

        int code;
        cin >> code;

        root = Insert(root, code);
    }

    cout << "Inorder sequence: ";
    inorder(root);

    cout << endl;

    return 0;
}

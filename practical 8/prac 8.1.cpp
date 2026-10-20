#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* left;
    Node* right;

    Node(string n) {

        left = nullptr;
        right = nullptr;
         name = n;
    }
};

void in(Node* root)
{
    if (root == nullptr)
        {
        return;
    }

    in(root->left);

    cout << root->name << " ";

    in(root->right);
}
void pre(Node* root)
{
    if (root == nullptr)
        {
        return;
    }

    cout << root->name << " ";

    pre(root->left);

    pre(root->right);
}
void post(Node* root) {
    if (root == nullptr) {
        return;
    }

    post(root->left);

    post(root->right);

    cout << root->name << " ";
}
void level(Node* root) {
    if (root == nullptr) {
        return;
    }

    Node* Queue[100];

    int Front = 0;
    int Rear = 0;

    Queue[Rear] = root;
    Rear++;

    while (Front < Rear) {
        Node* current = Queue[Front];
        Front++;

        cout << current->name << " ";

        if (current->left != nullptr) {
            Queue[Rear] = current->left;
            Rear++;
        }

        if (current->right != nullptr) {
            Queue[Rear] = current->right;
            Rear++;
        }
    }
}


int main() {

    Node* root = new Node("CEO");

    root->left = new Node("HR");
    root->right = new Node("IT");


    root->left->left = new Node("A");
    root->left->right = new Node("B");


    root->right->left = new Node("C");
    root->right->right = new Node("D");

    cout << "Inorder of : ";
    in(root);
    cout << endl;
    cout << "Preorder: ";
    pre(root);
    cout << endl;
    cout << "Postorder: ";
    post(root);
    cout << endl;
    cout << "Level Order: ";
    level(root);
    cout << endl;

    return 0;
}


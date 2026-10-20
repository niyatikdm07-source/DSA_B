#include <iostream>
using namespace std;

struct Node {
    int code;
    Node* next;

    Node(int c) {
        code = c;
        next = nullptr;
    }
};

int main() {
    Node* shelves[10];

    for (int i = 0; i < 10; i++) {
        shelves[i] = nullptr;
    }

    int n;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        int code;

        cout << "Enter book code: ";
        cin >> code;

        int shelf = code % 10;

        Node* newNode = new Node(code);

        newNode->next = shelves[shelf];
        shelves[shelf] = newNode;
    }
    cout << endl;
    cout << "Final Shelves:" << endl;

    for (int i = 1; i < 10; i++) {

        cout << "Shelf " << i << ": ";

        if (shelves[i] == nullptr) {
            cout << "Empty";
        }
        else {
            Node* current = shelves[i];

            while (current != nullptr) {
                cout << current->code << " ";
                current = current->next;
            }
        }

        cout << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    string page;
    Node* next;
};

int main() {
    Node* current = NULL;

    int choice;
    string page;

    cout << "Enter first page: ";
    cin >> page;

    current = new Node;
    current->page = page;
    current->next = NULL;

    cout << "Current page: " << current->page << endl;

    while (true) {
        cout << "1- Visit new page"<<endl;
        cout << "2- Back"<<endl;
        cout << "3- Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter page names ";
            cin >> page;

            Node* newNode = new Node;
            newNode->page = page;
            newNode->next = current;

            current = newNode;

            cout << "Current page is " << current->page << endl;
        }
        else if (choice == 2) {
            if (current->next == NULL) {
                cout << "No previous page" << endl;
            }
            else {
                Node* temp = current;

                current = current->next;

                delete temp;

                cout << "Current page: " << current->page << endl;
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}

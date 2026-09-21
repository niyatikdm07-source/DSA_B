#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void addAtFirst(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void addAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
    }

        temp->next = newNode;
    }

    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1) {
            insertFront(value);
            return;
        }

        Node* temp = head;


        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }


        if (temp == nullptr) {
            cout << "Position is greater than the current length. "
                 << "Insertion not possible." << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }


    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    LinkedList queue;

    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int choice, value, position;

        cout << "1. Add critical patient at front"<<endl;
        cout << "2. Add routine patient at end"<<endl;
        cout << "3. Insert patient at specific position"<<endl;
        cout << "Enter choice: "<<endl;
        cin >> choice;

        cout << "Enter patient token number: ";
        cin >> value;

        switch (choice) {
            case 1:
                queue.addAtFront(value);
                break;

            case 2:
                queue.addAtEnd(value);
                break;

            case 3:
                cout << "Enter position: ";
                cin >> position;
                queue.insertAtPosition(value, position);
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

        cout << "Queue after operation: ";
        queue.display();
    }

    cout << "\nFinal Queue: ";
    queue.display();

    return 0;
}

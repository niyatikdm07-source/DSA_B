#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;


    void reversePrint(Node* temp) {
        if (temp == nullptr)
            return;

        reversePrint(temp->next);
        cout << temp->data << " ";
    }

public:
    LinkedList() {
        head = nullptr;
    }


    void insertFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }


    void insertEnd(int value) {
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


    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }


        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << "Patient token " << value << " deleted." << endl;
            return;
        }

        Node* current = head;


        while (current->next != nullptr &&
               current->next->data != value) {
            current = current->next;
        }


        if (current->next == nullptr) {
            cout << "Patient token " << value << " not found." << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;

        cout << "Patient token " << value << " deleted." << endl;
    }


    void displayForward() {
        if (head == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = head;

        cout << "Queue (front to back): ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }


    void displayReverse() {
        if (head == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue (back to front): ";
        reversePrint(head);
        cout << endl;
    }
};

int main() {
    LinkedList queue;


    queue.insertEnd(101);
    queue.insertEnd(102);
    queue.insertFront(100);
    queue.insertAtPosition(105, 4);

    cout << "Initial queue:" << endl;
    queue.displayForward();


    int token;
    cout << "\nEnter patient token to delete: ";
    cin >> token;

    queue.deleteByValue(token);


    cout << "\nAfter deletion:" << endl;
    queue.displayForward();


    cout << "\nEnd-of-day audit:" << endl;
    queue.displayReverse();

    return 0;
}

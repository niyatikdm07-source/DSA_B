
#include <iostream>
using namespace std;


struct SNode {
    int data;
    SNode* next;

    SNode(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyCircularList {
private:
    SNode* head;

public:
    SinglyCircularList() {
        head = nullptr;
    }
    void insert(int value, int position) {
        SNode* newNode = new SNode(value);


        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }


        if (position <= 1) {
            SNode* last = head;

            while (last->next != head) {
                last = last->next;
            }

            newNode->next = head;
            head = newNode;
            last->next = head;
            return;
        }

        SNode* temp = head;


        for (int i = 1; i < position - 1; i++) {
            if (temp->next == head)
                break;

            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }


    void remove(int value) {
        if (head == nullptr) {
            cout << "Circle is empty." << endl;
            return;
        }


        if (head->data == value && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }


        if (head->data == value) {
            SNode* last = head;

            while (last->next != head) {
                last = last->next;
            }

            SNode* temp = head;
            head = head->next;

            last->next = head;
            delete temp;
            return;
        }


        SNode* current = head;

        while (current->next != head &&
               current->next->data != value) {
            current = current->next;
        }

        if (current->next == head) {
            cout << "Student not found." << endl;
            return;
        }

        SNode* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    // Display circle
    void display() {
        if (head == nullptr) {
            cout << "Empty circle" << endl;
            return;
        }

        SNode* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};



int main() {
    SinglyCircularList singly;


    int n;

    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        int choice;

        cout << "\n1. Join student";
        cout << "\n2. Leave student";
        cout << "\n3. Display circle";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int value, position;

            cout << "Enter student number: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            singly.insert(value, position);


            cout << "Singly circular list: ";
            singly.display();

           }

        else if (choice == 2) {
            int value;

            cout << "Enter student number to leave: ";
            cin >> value;

            singly.remove(value);


            cout << "Singly circular list: ";
            singly.display();

           }

        else if (choice == 3) {
            cout << "Singly circular list: ";
            singly.display();

           }

        else {
            cout << "Invalid operation!" << endl;
        }
    }

    return 0;
}

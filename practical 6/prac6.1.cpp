#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter stack size: ";
    cin >> n;

    int Stack[100];
    int top = -1;

    int choice, value;

    while (true) {
        cout << "1- Place tray (Push)"<<endl;
        cout << "2- Take tray (Pop)"<<endl;
        cout << "3- Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter tray number: ";
            cin >> value;


            if (top == n - 1) {
                cout << "Stack is full"<<endl;
            } else {
                top++;
                Stack[top] = value;

                cout << "Top tray: " << Stack[top] << endl;
            }
        }
        else if (choice == 2) {


            if (top == -1) {
                cout << "Stack is empty"<<endl;
            } else {
                cout << "Taken tray: " << Stack[top] << endl;
                top--;

                if (top == -1)
                    cout << "Stack is now empty"<<endl;
                else
                    cout << "Top tray: " << Stack[top] << endl;
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice"<<endl;
        }
    }

    return 0;
}

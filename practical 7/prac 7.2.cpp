#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node* Front = NULL;
    Node* rear = NULL;

    int choice;
    int value;

    do
    {
        cout << "1- Arrive Patient"<<endl;
        cout << "2- Attend Patient"<<endl;
        cout << "3- Display Front"<<endl;
        cout << "4- Display Queue"<<endl;
        cout << "5- Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "Enter patient token: ";
            cin >> value;

            Node* newNode = new Node();

            newNode->data = value;
            newNode->next = NULL;

            if(Front == NULL)
            {
                Front = newNode;
                rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }

            cout << "Patient added" << endl;
        }

        else if(choice == 2)
        {
            if(Front == NULL)
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                Node* temp = Front;

                cout << "Attended patient: " << front->data << endl;

                Front = Front->next;

                if(Front == NULL)
                {
                    rear = NULL;
                }

                delete temp;
            }
        }

        else if(choice == 3)
        {
            if(Front == NULL)
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                cout << "Front patient: " << front->data << endl;
            }
        }

        else if(choice == 4)
        {
            if(Front == NULL)
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                Node* temp = Front;

                cout << "Queue: ";

                while(temp != NULL)
                {
                    cout << temp->data << " ";
                    temp = temp->next;
                }

                cout << endl;
            }
        }

    } while(choice != 5);

    return 0;
}

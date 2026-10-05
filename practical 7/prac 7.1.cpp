#include <iostream>
using namespace std;

int main()
{
    int Size;

    cout << "Enter queue size: ";
    cin >> Size;

    int Queue[100];

    int Front = -1;
    int rear = -1;

    int choice;
    int value;

    do
    {
        cout << "1- Join Queue"<<endl;
        cout << "2- Serve Visitor"<<endl;
        cout << "3- Display Front"<<endl;
        cout << "4- Display Queue"<<endl;
        cout << "5- Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "Enter token number: ";
            cin >> value;

            if((rear + 1) % Size == Front)
            {
                cout << "Queue is full" << endl;
            }
            else
            {
                if(Front == -1)
                {
                    Front = 0;
                }

                rear = (rear + 1) % Size;
                Queue[rear] = value;

                cout << "Token added." << endl;
            }
        }

        else if(choice == 2)
        {
            if(Front == -1)
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                cout << "Served token: " << Queue[Front] << endl;

                if(Front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else
                {
                    front = (front + 1) % size;
                }
            }
        }

        else if(choice == 3)
        {
            if(Front == -1)
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                cout << "Front token: " << Queue[Front] << endl;
            }
        }

        else if(choice == 4)
        {
            if(Front == -1)
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                cout << "Queue: ";

                int i = Front;

                while(true)
                {
                    cout << Queue[i] << " ";

                    if(i == rear)
                        break;

                    i = (i + 1) % Size;
                }

                cout << endl;
            }
        }

    } while(choice != 5);

    return 0;
}

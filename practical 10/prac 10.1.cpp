#include <iostream>
using namespace std;

int main() {

    string parking[10];

    for (int i = 0; i < 10; i++) {
        parking[i] = "";
    }

    int n;

    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        string registration;

        cout << "Enter registration number: ";
        cin >> registration;
        char lastDigit = registration[registration.length() - 1];


        int slot = lastDigit - '0';

        int originalSlot = slot;

        while (parking[slot] != "") {

            slot = (slot + 1) % 10;
            if (slot == originalSlot) {
                cout << "Parking lot is full." << endl;
                break;
            }
        }
        if (parking[slot] == "") {
            parking[slot] = registration;
        }
    }

    cout << endl;
    cout << "Final Parking Lot:" << endl;

    for (int i = 0; i < 10; i++) {

        if (parking[i] == "") {
            cout << "Slot " << i << ": Empty" << endl;
        }
        else {
            cout << "Slot " << i << ": "
                 << parking[i] << endl;
        }
    }

    return 0;
}

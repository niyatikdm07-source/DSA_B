#include <iostream>
using namespace std;

int Search(int codes[9], int l, int h, int key) {
    if (l>h) {
        return -1;
    }

    int mid = (l+h) / 2;

    if (codes[mid] == key) {
        return mid;
    }
    else if (key < codes[mid]) {
        return Search(codes, l, mid - 1, key);
    }
    else {
        return Search(codes, mid + 1, h, key);
    }
}

int main() {
    int codes[9] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int key = 70;


    int Position = Search(codes, 0, 8, key);


    cout << "Binary search found " <<key<< " at index " << Position << endl;

    cout << "Binary search found " <<key<< " at position " << Position+1 << endl;

    return 0;
}

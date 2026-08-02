#include <iostream>
using namespace std;

int Find(int plates[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int middle = (low +high) / 2;

    if (plates[middle] == target) {
        return middle;
    }
    else if (target < plates[middle]) {
        return Find(plates, low, middle - 1, target);
    }
    else {
        return Find(plates, middle + 1,high, target);
    }
}

int main() {
    int plates[6] = {111,123,222,333,456,789};
    int Target = 222;


    int Posi = Find(plates, 0, 5, Target);

    cout << "Binary index: " << Posi<< endl;
    cout << "Binary search position: " << Posi+1<< endl;

    return 0;
}

#include <iostream>
using namespace std;


void bubbleSort(int arr[]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void selectionSort(int arr[]) {
    for (int i = 0; i < 5; i++) {
        int minimum = i;

        for (int j = i + 1; j < 6; j++) {
            if (arr[j] < arr[minimum]) {
                minimum = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minimum];
        arr[minimum] = temp;
    }
}


void insertionSort(int arr[]) {
    for (int i = 1; i < 6; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
void display(int arr[]) {
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int marks[6] = {72, 45, 90, 56, 38, 81};


    bubbleSort(marks);
    cout << "Bubble Sort:    ";
    display(marks);

    selectionSort(marks);
    cout << "Selection Sort: ";
    display(marks);

    insertionSort(marks);
    cout << "Insertion Sort: ";
    display(marks);

    return 0;
}

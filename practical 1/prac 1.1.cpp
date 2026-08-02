#include<iostream>
using namespace std;

int main(){
    int n,i,j,hrs;
    cout<<"enter number of item: ";
    cin>>n;
    int arr[n];

    cout<<"Enter no. of hours: ";
    cin>>hrs;


    cout<<"Enter elements: ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

     for(int j = 0; j < hrs; j++)
        {
    int first = arr[0];

    for(int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = first;
}
    cout<<"Array= ";
    for(i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
}


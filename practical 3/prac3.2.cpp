#include<iostream>
using namespace std;

int main(){
int arr[5]={2,1,2,0,1};
int n,i,j,t;
n=5;
for(i=0;i<n;i++){


        }
        for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                t= arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
  cout<<"Array is: ";
for(i=0;i<n;i++){
    cout<<" "<<arr[i];
}
return 0;

}

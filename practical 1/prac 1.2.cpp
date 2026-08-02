#include<iostream>
using namespace std;

 void Display(int no,int ID){
        cout<<no<<" Students borrow book of ID : "<<ID<<endl;
    }

int main(){
    int ID;
    int n,i, no;

     cout<<"Enter no. of books issued: ";
    cin>>n;
   for(int i=0;i<n;i++)
    {
    cout<<"Enter book IDS: ";
    cin>>ID;

    cout<<"Enter no. of students borrowed the book of ID: ";
    cin>>no;

    if(no>=1){
        Display(no,ID);
    }
    }
}

#include<iostream>
using namespace std;


int Sort(int s[5])
{ int i,j;
    for(i=0;i<=4;i++)
    {
        for (j=0;j<=5-i;j++)
        {
          if(s[i]>s[i+1])
            {
            swap(s[i],s[i+1]);
            }
         }

         cout<<s[i];
    }
        return 0;
    }

int main()
{
    int sheet[5]={5,4,3,2,1};
    Sort(sheet);
    return 0;
}

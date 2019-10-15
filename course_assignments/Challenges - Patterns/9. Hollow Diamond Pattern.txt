#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int half=(n+1)/2;
    int equi,equj;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i<=half)
            {
                equi=i;
                cout<<" ";
            }
            else
           {
               equi=n-i+1;
               cout<<" ";
           }
           if(j<=half)
           {
               equj=j;
           }
           else
           {
               equj=n-j+1;
           }
         if(equi+equj<=half+1)
         {
             cout<<"*";
         }
         else
         {
             cout<<" ";
         }
        }
        cout<<endl;
    }
}

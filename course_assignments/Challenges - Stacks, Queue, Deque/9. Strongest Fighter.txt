#include<iostream>
#include<deque>

using namespace std;

void strongestfighter(int a[],int n,int k)
{
    deque <int> Q(k);
    int i;
    for( i = 0;i<k;i++)
    {
        while(!Q.empty() && a[i]>a[Q.back()])
        {
            Q.pop_back();
        }
        Q.push_back(i);
    }


    for(;i<=n;i++)
    {
        cout<<a[Q.front()]<<" ";

        while(!Q.empty() && Q.front()<=i-k)
        {
            Q.pop_front();
        }

        while(!Q.empty() && a[i]>a[Q.back()])
        {
            Q.pop_back();
        }

        Q.push_back(i);
    }
    return ;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    strongestfighter(arr,n,k);
    return 0;
}
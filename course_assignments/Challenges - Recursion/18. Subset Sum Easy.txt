#include<iostream>
using namespace std;
int sum=0;
bool subSum(int *a, int *arr, int n, int i,int j){
    if(i==n){
        int ans=0;
        for(int k=0;k<j;k++){
            ans+=arr[k];
            if(ans==0)
                return true;
        }
    return false;
    }
    int ans=0;
    for(int k=0;k<j;k++){
        ans+=arr[k];
        if(ans==0)
            return true;
    }
    if(ans==0&&j!=0)
        return 1;
    arr[j]=a[i];
    if(subSum(a,arr,n,i+1,j+1))
        return true;
    if(subSum(a,arr,n,i+1,j))
        return true;
    return false;
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        if(subSum(a,arr,n,0,0))
            cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
    return 0;
}
------------------------------------------------------------------------

#include <iostream>
using namespace std;
bool subset(int *a, int n, int i, int sum,int cnt){
    if(i==n){
        if(sum==0 && cnt>0)
            return true;
        else
            return false;
    }
    return subset(a, n, i+1, sum+a[i],cnt+1) || subset(a, n,i+1, sum,cnt);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n, a[10];
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        if(subset(a,n,0,0,0))
        cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
    return 0;
}
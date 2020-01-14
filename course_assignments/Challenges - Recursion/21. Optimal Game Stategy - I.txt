#include <iostream>
#include <climits>
using namespace std;
int maxval = INT_MIN;

void optimalGamestrategy(int arr[],int size, int start, int end,int sum){
    if(size<=0){
        maxval = max(maxval,sum);
        return;
    }

    sum += arr[start];
    optimalGamestrategy(arr,size-3,start+2,end-1,sum);
    sum-= arr[start];

    sum+=arr[end];
    optimalGamestrategy(arr,size-3,start+1,end-2,sum);
    sum -= arr[end];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    optimalGamestrategy(arr,n,0,n-1,0);
    cout<<maxval<<endl;
}
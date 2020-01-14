#include <bits/stdc++.h>
using namespace std;
#define loop(x,n) for(ll x=0; x<n; ++x)
#define hashmap map<char,node*>
#define ll long long

int xor_arr(int arr[], int i, int j){
    int xor1 = arr[i];

    for(int k=i+1; k<=j; k++){
        xor1 = xor1^arr[k];
    }
    return xor1;
}

int maxXORsubarr(int arr[], int s, int e){
    int max = INT_MIN;
    for(int i=s; i<=e; i++){
        for(int j=i; j<=e; j++){
            if(xor_arr(arr,i,j)>max) max = xor_arr(arr,i,j);
        }
    }
    return max;
}

int main(){
    int n; cin>>n;
    int arr[n];
    loop(i,n){
        cin>>arr[i];
    }
    cout << maxXORsubarr(arr,0,n-1);
}

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n,k;
    cin>>n>>k;
    long long arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    for(int i=0; i<n-1; i++){
        //max in the array --> #algorithm
        long long *mx = max_element(arr+i+1,arr+n);
        if(arr[i] < *mx){
            swap(arr[i],*mx);
            k--;
            if(k==0){
                break;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
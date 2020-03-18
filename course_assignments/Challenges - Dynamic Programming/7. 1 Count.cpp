#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    deque<int> dq;

    int curr_zeros = 0;
    int i=0;

    while(i<n && curr_zeros < k) {

        dq.push_back(arr[i]);
        if(arr[i] == 0) curr_zeros++;
        i++;
    }

    while(i<n && arr[i] != 0) {
        dq.push_back(arr[i]);
        i++;
    }

    if(i==n) {
        cout <<  n << endl;
        for(int j=0; j<n; j++) cout << 1 <<" ";
        return 0;
    }

    int max_size = dq.size();
    int max_index = i;

    while(i<n){
        dq.push_back(arr[i]);
        i++;

        while(i<n && arr[i] != 0) {
            dq.push_back(arr[i]);
            i++;
        }

        while(dq.front() != 0) dq.pop_front();
        dq.pop_front();

        if(dq.size() > max_size) {
            max_size = dq.size();
            max_index = i;
        }
    }

    cout << max_size <<endl;

    for(int j=0; j<max_index-max_size; j++) cout<<arr[j]<<" ";
    for(int j=max_index-max_size; j<max_index; j++) cout << 1 <<" ";
    for(int j=max_index; j<n; j++) cout<<arr[j]<<" ";

}
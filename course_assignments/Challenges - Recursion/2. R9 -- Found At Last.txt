#include<iostream>
using namespace std;

int foundAtLast(long* arr, int n, long m) {
    for (int i = n; i >= 0; i--) {
        if(arr[i] == m) {
            return i;
        }
        else {
            foundAtLast(arr+1, n-1, m);
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    long arr[1000000000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long m;
    cin >> m;
    cout << foundAtLast(arr, n, m);
    return 0;
}
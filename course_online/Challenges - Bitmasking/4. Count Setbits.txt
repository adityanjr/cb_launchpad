#include<iostream>
using namespace std;

int countSetbits(int n){
    int count = 0;
    while(n>0){
        n = n & (n-1);
        count++;
    }
    return count;
}
int main() {
    int t, x;
    cin>>t;
    while(t--){
        cin>>x;
        cout<<countSetbits(x)<<endl;
    }
	return 0;
}
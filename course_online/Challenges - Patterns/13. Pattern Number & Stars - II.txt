#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            cout<<j;
        }
        for (int k=n-i; k>0; k--){
            cout<<"*";
        }
        cout<<endl;
    }
	return 0;
}
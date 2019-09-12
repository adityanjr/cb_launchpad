#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=n; i>0; i--){
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        for(int k=i; k<n; k++){
            cout<<"* ";
        }
        for(int k=i-1; k<n-2; k++){
            cout<<"* ";
        }
        cout<<endl;
    }
	return 0;
}
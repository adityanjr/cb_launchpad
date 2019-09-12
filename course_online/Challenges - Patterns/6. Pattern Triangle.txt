#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for (int i=1; i<=n; i++){
        for (int space=n-i; space>0; space--){
            cout<<"  ";
        }
        for (int k=0; k<i; k++){
            cout<<k+i<<" ";
        }
        for (int j=i-1; j>0; j--){
            cout<<j+i-1<<" ";
        }    
    cout<<endl;
    }
	return 0;
}
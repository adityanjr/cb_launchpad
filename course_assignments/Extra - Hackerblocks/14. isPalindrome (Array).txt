#include<iostream>
using namespace std;

bool pal(int* a,int size){
    for(int i=0;i<(size/2);i++){
        if(a[i]==a[size-i-1])
            return true;
        else
            return false;
	}
}
int  main(){
    int n; cin>>n;
	int*a = new int[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
	}
    cout<<boolalpha<<pal(a,n);
}

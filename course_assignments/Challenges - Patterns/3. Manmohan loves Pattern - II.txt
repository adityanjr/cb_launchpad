#include<iostream>
using namespace std;
int main() {
int n;
cin >> n;
cout<<"1"<<endl;
for(int i=1;i<n;i++){
    cout<<i ;
    for (int k=0;k<i-1;k++)
    	cout<<"0" ;  
    cout<<i;
cout<<endl;	
}	
 return 0;
}
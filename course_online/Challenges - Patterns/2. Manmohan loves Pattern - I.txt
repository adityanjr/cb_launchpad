#include<iostream>
using namespace std;
int main() {
int n;
cin >> n;
for(int i=1;i<=n;i++){
    if(i%2==0 && i!=2){
    	cout << "1" ;
        for (int k=0;k<i-2;k++)
    		cout<<"0" ;  
    	cout<<"1";
	}
    else {
    	for(int j=1; j<=i; j++)
            cout<<"1";
	}
	cout<<endl;		
}
 return 0;
}
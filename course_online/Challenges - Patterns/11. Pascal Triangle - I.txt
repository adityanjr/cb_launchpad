#include <iostream>
using namespace std;

int fact(int num) {
	int fac = 1;
	for (int i = 1; i <= num; i++) {
		fac = fac * i;
	}
	return fac;
}

int nCr( int n , int r){
	int result = fact(n) / (fact(r) * fact(n - r));
	return result;
}

int main(int argc, char const *argv[])
{
	int x;
	cin>>x;
    for (int row=0; row<x; row++){
        for(int space=x-row; space>=0; space--){
            cout<<" ";
        }
    	for(int col=0; col<=row; col++){
    		cout<<nCr(row, col)<<" ";
    	}
    	cout<<endl;
    }
	return 0;
}
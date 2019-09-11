#include<iostream>
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

int main() {
	int n, r;
	cin >> n >> r;
	cout<<nCr(n, r);
	return 0;
}

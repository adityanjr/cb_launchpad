#include<iostream>
using namespace std;
int main() {
	int n,x;
	cin>>n;
	int arr[n];
	int xor_res = 0;
	for(int i=0; i<n; i++){
		cin>>x;
		arr[i]=x;
		xor_res ^= arr[i];
	}
	cout<<xor_res;
	return 0;
}
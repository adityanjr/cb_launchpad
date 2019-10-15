#include<iostream>
using namespace std;

int findUnique(int* arr, int n){
	int count[64] = {0};
	for(int j=0; j<n; j++){
		int i=0;
		int num = arr[j];
		while(num>0){
			count[i] += (num&1);
			i++;
			num >>= 1;
		}
	}
	int p=1, ans=0;
	for(int i=0; i<64; i++){
		count[i] %= 3;
		ans += count[i]*p;
		p <<= 1;
	}
	return ans;
}
int main() {
	int n,x;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>x;
		arr[i]=x;
	}
	cout<<findUnique(arr, n);
	return 0;
}
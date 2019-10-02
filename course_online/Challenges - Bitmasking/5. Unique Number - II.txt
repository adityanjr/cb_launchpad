#include<iostream>
using namespace std;

void findUnique(int* arr, int n){
	int res = 0;
	for(int i=0; i<n; i++){
		res ^= arr[i];
	}
	int temp=res, i=0;
	while(temp>0){
		if(temp&1) break;
		i++;
		temp >>= 1;
	}
	int mask = (1<<i);
	int firstNo = 0;
	for(i=0; i<n; i++){
		if((mask&arr[i])!=0){
			firstNo ^= arr[i];
		}
	}
	int secondNo = res^firstNo;
	cout<<secondNo<<" "<<firstNo<<endl;
}
int main() {
	int n,x;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>x;
		arr[i]=x;
	}
	findUnique(arr, n);
	return 0;
}
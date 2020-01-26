#include<iostream>
using namespace std;

bool isSorted(int *arr,int n){
	//Base Case
	if(n==1){
		return true;
	}
	//Rec Case
	if(arr[0]<arr[1] and isSorted(arr+1,n-1)){
		return true;
	}
	return false;
}

int main(){

	int n; cin>>n;
	int* arr = new int[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	cout<<boolalpha<<isSorted(arr,n);
	return 0;
}
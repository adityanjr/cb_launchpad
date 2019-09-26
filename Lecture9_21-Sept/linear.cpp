#include <iostream>
using namespace std;

int linear(int* arr, int k, int n, int i){
	if(i==n){
		return -1;
	}
	if(arr[i]==k){
		return i;
	}
	return linear(arr, k, n, i+1);
}

int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n;
	int* arr = new int [n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cin>>k;
	int ind = linear(arr, k, n, 0);
	cout<<ind;
	delete [] arr;
	return 0;
}
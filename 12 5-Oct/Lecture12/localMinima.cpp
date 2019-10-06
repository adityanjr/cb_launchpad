#include <bits/stdc++.h>
using namespace std;

int localMinima(int* arr, int low, int high, int n){	

	int mid = low + (high-low)/2;
	if( ((mid==0) || (arr[mid-1]>arr[mid])) && ((mid==n) || (arr[mid+1]>arr[mid])) ){
		return mid;
	}
	else if(arr[mid-1] < arr[mid]){
		return localMinima(arr, low, mid-1, n);
	}
	return localMinima(arr, mid+1, high, n); 

}


int main(int argc, char const *argv[])
{
	int arr[] ={9, 3, 15, 4, 7, 10, 16, 1, 8};
	int lm = localMinima(arr, 0, 8, 8);
	cout<<lm<<endl;
	return 0;
}
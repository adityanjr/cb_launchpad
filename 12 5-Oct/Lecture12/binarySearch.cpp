#include <bits/stdc++.h>
using namespace std;
	
int binarySearch(int* arr, int low, int high, int target){

	while(low<=high){
		//int mid = (low+high)/2;
		int mid = low+(high-low)/2;
		if(arr[mid] == target){
			return mid;
		}
		else if(arr[mid]<target){
			low = mid+1;
		}
		else{
			high = mid-1;
		}

	}
	return -1;
}

int binarySearchFirstOcc(int* arr, int low, int high, int target){
	int result =-1;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid] == target){
			result = mid;
			high = mid-1;

		}
		else if(arr[mid]<target){
			low = mid+1;
		}
		else{
			high = mid-1;
		}

	}
	return result;
}

// lastOcc homework

int main(int argc, char const *argv[])
{
	int arr[8] = {1,4, 5, 18, 20, 200, 500, 1880};
	int result = binarySearch(arr, 0, 7, 200);
	cout<<result<<endl;
	int result1 = binarySearch(arr, 0, 7, 1200);
	cout<<result1<<endl;
	int arr1[10] = {1,4, 5, 18, 20, 20, 20, 200, 500, 1880};
	int result2 = binarySearchFirstOcc(arr1, 0, 9, 20);
	cout<<result2<<endl;
	return 0;
}











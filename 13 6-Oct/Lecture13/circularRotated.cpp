#include <bits/stdc++.h>
using namespace std;

int rotations(int* arr, int N){
	int low =0, high = N-1;
	while(low<=high){
		int mid = low+(high-low)/2;

		if(mid == 0){ // if mid is 0, check it's right 
			if(arr[mid+1]> arr[mid]){
				return mid;
			}
		}
		else if(mid == N-1){// if mid is last index, check it's left 
			if(arr[mid-1] > arr[mid]){
				return mid;
			}
		}
		else if(arr[mid-1] > arr[mid] && arr[mid+1]> arr[mid]){// otherwise, check left and right both
			return mid;
		}

		else if(arr[high]<arr[mid]){ // if high < mid, then result exist in right
			low=mid+1;
		}
		else{ // else result exist in left
			high=mid-1;
		}

	}
	return 0;

}

int main(int argc, char const *argv[])
{
	int arr[8] = {500, 1880, 1,4, 5, 18, 20, 200};
	int result = rotations(arr, 8);
	cout<<result<<endl;
	
	return 0;
}


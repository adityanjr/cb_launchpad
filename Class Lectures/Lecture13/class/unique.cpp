#include <bits/stdc++.h>
using namespace std;


int unique(int* arr, int N){
	int low = 0, high = N-1;
	while(low <= high){
		int mid = low+(high-low)/2;
		// mid element is unique
		if(arr[mid]!= arr[mid-1] && arr[mid]!= arr[mid+1]){
			return arr[mid];
		}
		//if mid is even
		if(mid%2 == 0){
			// if mid is equal to mid+1, search in right
			if(arr[mid]==arr[mid+1]){
				low = mid+2;
			}
			// if mid is not equal to mid+1, search in left
			else{
				high =mid-1;
			}
		}
		//if mid is odd
		else{
			// if mid is not equal to mid-1, search in left
			if(arr[mid]!=arr[mid-1]){
				high = mid-1;
			}
			else{
				low=mid+1;
			}
		}

	}
	return -1;

}


int main(int argc, char const *argv[])
{
	int arr[] = {1,1,2,2,5,5,9,9,10};

	int N=9;
	cout<<unique(arr, 9)<<endl;

	return 0;
}
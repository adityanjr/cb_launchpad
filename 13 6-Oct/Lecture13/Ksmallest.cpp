#include <bits/stdc++.h>
using namespace std;


int partition(int* arr, int low, int high){
	int pivot = arr[high];
	int idx = low, i = low;
	while(i<high){
		if(arr[i]<pivot){
			swap(arr[i], arr[idx]);
			idx++;
		}
		i++;
	}
	swap(arr[idx], arr[high]);
	return idx;
}

int kSmallest(int* arr, int low, int high, int k){
	if(low > high){
		return -1;
	}
	int pidx = partition(arr, low, high);
	if(pidx == k){
		return arr[pidx];
	}
	else if(pidx<k){// FOR RIGHT ARRAY
		return kSmallest(arr, pidx+1, high, k);
	}
	else{
		return kSmallest(arr, low, pidx-1, k); // FOR LEFT ARRAY
	}
	
}
int main(int argc, char const *argv[])
{
	int arr[] = {9, 6, 3, 4, 15, 5};
	int k = 1;
	cout<<kSmallest(arr, 0, 5, k-1)<<endl;
	

	return 0;
}










